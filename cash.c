#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
float dollars;
int coin_change;
int coins = 0;

    //Get Input from User
    do
    {
     dollars = get_float("What is the total change?: \n");
    }
    while (dollars <= 0.00);

    //Convert Dollars to Cent Change
    coin_change = round(dollars * 100);

    while (coin_change > 0)
    {
        //Quarters
        if (coin_change >= 25)
        {
            coin_change = (coin_change - 25);
            coins++;
        }
        //Dimes
        else if (coin_change >= 10)
        {
           coin_change = (coin_change - 10);
           coins++;
        }
        //Nickles
        else if (coin_change >= 5)
        {
            coin_change = (coin_change - 5);
            coins++;
        }
        //Pennies
        else
        {
            coin_change = (coin_change - 1);
            coins++;
        }
    }
    printf("You will recive a total of: %i coins \n", coins);

}