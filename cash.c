#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{   //Get Input from User
    float dollar_change;
    int cent_change;
    int coins = 0;

    do
    {
        dollar_change = get_float("Enter the change amount: ");
    }
    while (dollar_change < 0.00);

    //Convert Dollar Change to Cent Change
    cent_change = round(dollar_change * 100);

    while (cent_change >= 25)
    {
        cent_change = cent_change - 25;
        coins++;
    }
    while cent_change >= 10
    {
        cent change = cent_change - 10;
        coins++;
    }
    while cent_change >= 5
    {
        cent change = cent_change - 5;
        coins++;
    }
    while (cent_change >= 1)
    {
        cent change = cent_change - 1;
        coins++;
    }

    printf("You will recive %i\n coins," coins);
}