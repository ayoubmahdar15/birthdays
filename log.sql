-- 1. Description of Crime Scene (Theft July 28th, at chamberlin street)
    SELECT description
    FROM crime_scene_reports
    WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";

-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
-- Interviews were conducted today with three witnesses who were present at the time
-- each of their interview transcripts mentions the courthouse.

-- 2. Raymond, Eugene, Ruth && Jose, Barbara
    SELECT * FROM interviews
    WHERE month = 7 AND day = 28;

German Accent (Barbara suggested)
Security footage of courthouse parking lot within 10 minutes of theft (Ruth)
ATM at Fifer Street earlier in morning withdrawing moneys, seen him before (Eugene)
One minute call, purchased earliest flight out of Fiftyville tomorrow (Raymond)

-- 2. Read Transcripts of Witnesses at Courthouse (10:15 am at Chamberlin Street Courthouse; Access interviews) German Accent
    SELECT transcript
    FROM interviews
    WHERE month = 7 AND day = 28;

-- 3. Just Overview of Courthouse Footage
    SELECT * FROM courthouse_security_logs
    WHERE month = 7 AND day = 28;

-- 4. Suspect exited at around 10:15-10:25, now we have possibile license plates.
    SELECT license_plate
    FROM courthouse_security_logs
    WHERE month = 7 AND day = 28 AND hour = 10; -- 10:15-10:25

260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95
261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55
268 | 2020 | 7 | 28 | 10 | 35 | exit | 1106N58

-- 5. Retrieve Account Numbers of People Who Withdrew Money that day
    SELECT * FROM atm_transactions WHERE atm_location = "Fifer Street" AND day = 28 AND month = 7 AND transaction_type = "withdraw"

246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35

-- 6. Use Bank Account Numbers to Figure Out Name of People and Their Info
    SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number
    IN (28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199);

--account #                                -- phone number -- Pssport number
49610011 | 686048 | 2010 | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X -- exit 10:18    -- account withdraw
26013199 | 514354 | 2012 | 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE -- exit 10:23   -- account withdraw
16153065 | 458378 | 2012 | 458378 | Roy | (122) 555-4581 | 4408372428 | QX4YZN3                     -- account withdraw
28296815 | 395717 | 2014 | 395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN                   -- account withdraw
25506511 | 396669 | 2014 | 396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ -- exit 10:21 -- account withdraw
28500762 | 467400 | 2014 | 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8 -- exit 10:19  -- account withdraw
76054385 | 449774 | 2015 | 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58 -- exit 10:35 (prob not him) -- account withdraw
81061156 | 438727 | 2018 | 438727 | Victoria | (338) 555-6650 | 9586786673 | 8X428L0                -- account withdraw


-- 7. One minute phone call (figure out ally)
    SELECT *
    FROM phone_calls
    WHERE day = 28 AND month = 7 AND duration <= 60;
      -- caller         -- reciever
221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45  -- Ernest Calling
234 | (609) 555-5876 | (389) 555-5198 | 2020 | 7 | 28 | 60  -- Danielle Receiving (ally???); jk has to be incoming call
251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43  -- Madison Calling
255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49  -- Russell Calling
261 | (031) 555-6622 | (910) 555-3251 | 2020 | 7 | 28 | 38
279 | (826) 555-1652 | (066) 555-9701 | 2020 | 7 | 28 | 55  -- Bobby Calling
281 | (338) 555-6650 | (704) 555-2131 | 2020 | 7 | 28 | 54  -- Victoria Calling

Suspects: Ernest, Russell, Madison

--8. Who were they calling?
    SELECT name, license_plate FROM people WHERE phone_number IN ("(375) 555-8161", "(725) 555-3243", "(676) 555-6554");

Berthold | 4V16VO0 (Ernest Called) 
James | Q13SVG6 (Madison Called)
Philip | GW362R6 (Russell Called)


Passport Numbers of Suspects and Passageners
    SELECT * FROM airports WHERE city = "Fiftyville";

-- 9. Determine Flights From Fiftyville and their Destinations

8 | CSF | Fiftyville Regional Airport | Fiftyville

    SELECT * FROM flights JOIN airports ON flights.origin_airport_id = airports.id WHERE day = 29 AND month = 7;

id | origin_airport_id | destination_airport_id | year | month | day | hour | minute | id | abbreviation | full_name | city
-- 18 | 8 | 6 | 2020 | 7 | 29 | 16 | 0 | 8 | CSF | Fiftyville Regional Airport | Fiftyville
-- 23 | 8 | 11 | 2020 | 7 | 29 | 12 | 15 | 8 | CSF | Fiftyville Regional Airport | Fiftyville
36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20 | 8 | CSF | Fiftyville Regional Airport | Fiftyville TO LONDON
43 | 8 | 1 | 2020 | 7 | 29 | 9 | 30 | 8 | CSF | Fiftyville Regional Airport | Fiftyville TO CHICAGO
-- 53 | 8 | 9 | 2020 | 7 | 29 | 15 | 20 | 8 | CSF | Fiftyville Regional Airport | Fiftyville
                          -- Hour Minute (Early in Morning )
    SELECT * FROM flights JOIN airports ON flights.destination_airport_id = airports.id WHERE day = 29 AND month = 7;

id | origin_airport_id | destination_airport_id | year | month | day | hour | minute | id | abbreviation | full_name | city
18 | 8 | 6 | 2020 | 7 | 29 | 16 | 0 | 6 | BOS | Logan International Airport | Boston
23 | 8 | 11 | 2020 | 7 | 29 | 12 | 15 | 11 | SFO | San Francisco International Airport | San Francisco
36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20 | 4 | LHR | Heathrow Airport | London
43 | 8 | 1 | 2020 | 7 | 29 | 9 | 30 | 1 | ORD | O'Hare International Airport | Chicago
53 | 8 | 9 | 2020 | 7 | 29 | 15 | 20 | 9 | HND | Tokyo International Airport | Tokyo

-- List of Airports
1 | ORD | O'Hare International Airport | Chicago
2 | PEK | Beijing Capital International Airport | Beijing
3 | LAX | Los Angeles International Airport | Los Angeles
4 | LHR | Heathrow Airport | London
5 | DFS | Dallas/Fort Worth International Airport | Dallas
6 | BOS | Logan International Airport | Boston
7 | DXB | Dubai International Airport | Dubai
8 | CSF | Fiftyville Regional Airport | Fiftyville
9 | HND | Tokyo International Airport | Tokyo
10 | CDG | Charles de Gaulle Airport | Paris
11 | SFO | San Francisco International Airport | San Francisco
12 | DEL | Indira Gandhi International Airport | Delhi

-- 10. Passegners on Flights

    SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE passport_number IN (5773159633, 3592750733, 1988161715);

flight_id | passport_number | seat | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute

18 | 3592750733 | 4C | 18 | 8 | 6 | 2020 | 7 | 29 | 16 | 0      Russell -- (prob not him cause he would have left earlier )
-- 24 | 3592750733 | 2C | 24 | 7 | 8 | 2020 | 7 | 30 | 16 | 27     Russell (DOESNT MATTER)
36 | 5773159633 | 4A | 36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20      ERNEST
36 | 1988161715 | 6D | 36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20      Madison
-- 54 | 3592750733 | 6C | 54 | 8 | 5 | 2020 | 7 | 30 | 10 | 19     Russell (DOESNT MATTER)

-- Thief left on the 29th Morning

Suspects remaining = Ernest/Madison
Going to LONDON
-- 36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20 | 4 | LHR | Heathrow Airport | London

-- Ally one of these guys
James | Q13SVG6 (Ernest Called)
Berthold | 4V16VO0 (Madison Called) -- German Name

SELECT passport_number FROM people WHERE name = "James";
-- passport_number
2438825627

SELECT passport_number FROM people WHERE name = "Berthold";
-- passport_number
Cant Find?

-- Who the thief is = Madison
-- Where the thief escaped too = London
-- Who the thief accomplice was = Berthold