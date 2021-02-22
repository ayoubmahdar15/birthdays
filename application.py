import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        stock = lookup(request.form.get("symbol"))
        if not stock:
            return apology("Error, invalid symbol inputted")

        try:
            shares = int(request.form.get("shares"))
        except:
            return apology("Error, enter a positive number of shares you would like to buy")

        if shares <= 0:
            return apology("Error, enter a positive number of shares you would like to buy")

        #Select specific user.
        row = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])

        # Check cash amount of specific user
        total_cash = row[0], ["cash"]

        # Total money needed
        cost = shares * stock["price"]

        # Purchasing Process
        if cost > total_cash:
            return apology ("Error, not enough money to purchase this amount of stocks")
        else:
            # UPDATE CASH OF USER
            db.execute("UPDATE users SET cash = :cash WHERE id = :id",
            cash = total_cash - cost, id=session["user_id"])

            # Check current Stock Portfolio
            users_current_shares = db.execute("SELECT shares FROM Stock_Portfolio WHERE id = :id AND symbol = :symbol",
            id=session["user_id"], symbol=request.form.get("symbol"))

            if not users_current_shares:
                # Add into Stock Portfolio
                db.execute("INSERT INTO Stock_Portfolio VALUES (:id, :symbol, :shares, :share_price, :time", id=session["user_id"], symbol=request.form.get("symbol"), shares=shares, share_price=stock["price"], time=timestamp.now())
            else:
                # Update Stock Portfolio
                db.execute("UPDATE Stock_Portfolio SET shares = shares + :shares WHERE id = :id AND symbol = :symbol",
                id=session["user_id"], symbol=request.form.get("symbol"))

        # Return Back to Index
        return redirect(url_for("index"))

    else:
        #Display buy page
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("stock_quote.html")

    else: # (POST Method)
        estimate = lookup(request.form.get("symbol"))   #LOOKUP FUNCTION

        if not estimate:
            return apology("Error, invalid symbol")

        #DISPLAY RESULTS
        return render_template("stock_quoted.html", stock=estimate) #either quote or stock = ???

## pk_f02bbd6fb650460dbdc22d63365bff6d

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":

        # Valid Username Input
        if not request.form.get("username"):
            return apology("Please provide a valid username")
        # Valid Password Input
        elif not request.form.get("password"):
            return apology("Please provide a valid password")
        # Valid Second Password
        elif not request.form.get("confirmation"):
            return apology("Please confirm your password correctly")
        # Valid Password Match Confirmation
        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("Passwords do not match")

        #Hash password for security
        hashed_password = generate_password_hash(request.form.get("password"))

        #Add User Into Database
        result = db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)",
            username=request.form.get("username"), hashed_password=hash)

        # Invalid Username
        if not result:
            return apology("Sorry, your account registration has failed (username already taken). Please try again!")

        rows = db.execute("SELECT * FROM users WHERE username = ?",
            username = request.form.get("username"))

        # User Log In/Session Remembered
        session["user_id"] = rows[0]["id"]

        return redirect("/")

    else: # Via GET pathway
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
