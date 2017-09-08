/* 
 * File:   main.c
 * Author: student
 *
 * Created on October 30, 2013, 7:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

/*
 * 
 */

#define TRUE 1
#define FALSE 0
// #define EXIT_SUCCESS
#define CokeColaPrice 1.45
#define SpritePrice 1.35
#define MountainDewPrice 1.25
#define DrPepperPrice 1.55
#define JoltPrice 1.65
#define RcColaPrice 1.15
#define SlurrPrice 2.45
#define SurgeColaPrice 1.50
#define MonsterPrice 1.75

typedef enum
{
    CokeCola, 
    Sprite, 
    MountainDew,
    DrPepper,
    Jolt,
    RcCola,
    Slurr,
    SurgeCola,
    Monster
} drinks;

typedef enum
{
    A0, A1, A2, A3,
    B0, B1, B2, B3,
    C0, C1, C2, C3,
    D0, D1, D2, D3,
    E0, E1, E2, E3,
    F0, F1, F2, F3        
} dispense;

typedef enum
{
    A, B, C, D, E, F
} row;

typedef struct
{
    int Quarters;
    int Dimes;
    int Nickels;
    int Pennies;    
} change;

typedef struct
{
    drinks      Drink;
    dispense    Location;
    int         Capacity;
    int         Stock;
    float       Price;
} vend;

vend locations[6][4];

/******************************************************/
/*                 Declare Functions                  */
/******************************************************/

void InitializeLocations(vend (*locs)[6][4]);
void vendItem(vend item);
void returnMoney(double money, int purchase, float price);
void makeSelection(vend (*locs)[6][4], double money);
change findChange(double money);
void returnQuarters(int quarters);
void returnDimes(int dimes);
void returnNickels(int nickels);
void returnPennies(int pennies);

/******************************************************/
/*                  Define Functions                  */
/******************************************************/

void InitializeLocations(vend (*locs)[6][4])
{
    (*locs)[A][0].Capacity = 10;
    (*locs)[A][0].Drink    = CokeCola;
    (*locs)[A][0].Location = A0;
    (*locs)[A][0].Stock    = 10;
    (*locs)[A][0].Price    = CokeColaPrice;
    
    (*locs)[A][1].Capacity = 10;
    (*locs)[A][1].Drink    = Jolt;
    (*locs)[A][1].Location = A1;
    (*locs)[A][1].Stock    = 10;
    (*locs)[A][1].Price    = JoltPrice;
    
    (*locs)[A][2].Capacity = 10;
    (*locs)[A][2].Drink    = Sprite;
    (*locs)[A][2].Location = A2;
    (*locs)[A][2].Stock    = 10;
    (*locs)[A][2].Price    = SpritePrice;

    (*locs)[A][3].Capacity = 10;
    (*locs)[A][3].Drink    = MountainDew;
    (*locs)[A][3].Location = A3;
    (*locs)[A][3].Stock    = 10;
    (*locs)[A][3].Price    = MountainDewPrice;
    
    (*locs)[B][0].Capacity = 10;
    (*locs)[B][0].Drink    = CokeCola;
    (*locs)[B][0].Location = B0;
    (*locs)[B][0].Stock    = 10;
    (*locs)[B][0].Price    = CokeColaPrice;
    
    (*locs)[B][1].Capacity = 10;
    (*locs)[B][1].Drink    = Jolt;
    (*locs)[B][1].Location = B1;
    (*locs)[B][1].Stock    = 10;
    (*locs)[B][1].Price    = JoltPrice;
    
    (*locs)[B][2].Capacity = 10;
    (*locs)[B][2].Drink    = SurgeCola;
    (*locs)[B][2].Location = B2;
    (*locs)[B][2].Stock    = 10;
    (*locs)[B][2].Price    = SurgeColaPrice;
    
    (*locs)[B][3].Capacity = 10;
    (*locs)[B][3].Drink    = Slurr;
    (*locs)[B][3].Location = B3;
    (*locs)[B][3].Stock    = 10;
    (*locs)[B][3].Price    = SlurrPrice;

    (*locs)[C][0].Capacity = 10;
    (*locs)[C][0].Drink    = DrPepper;
    (*locs)[C][0].Location = C0;
    (*locs)[C][0].Stock    = 10;
    (*locs)[C][0].Price    = DrPepperPrice;
    
    (*locs)[C][1].Capacity = 10;
    (*locs)[C][1].Drink    = Monster;
    (*locs)[C][1].Location = C1;
    (*locs)[C][1].Stock    = 10;
    (*locs)[C][1].Price    = MonsterPrice;
    
    (*locs)[C][2].Capacity = 10;
    (*locs)[C][2].Drink    = SurgeCola;
    (*locs)[C][2].Location = C2;
    (*locs)[C][2].Stock    = 10;
    (*locs)[C][2].Price    = SurgeColaPrice;
    
    (*locs)[C][3].Capacity = 10;
    (*locs)[C][3].Drink    = Slurr;
    (*locs)[C][3].Location = C3;
    (*locs)[C][3].Stock    = 10;
    (*locs)[C][3].Price    = SlurrPrice;
    
    (*locs)[D][0].Capacity = 10;
    (*locs)[D][0].Drink    = DrPepper;
    (*locs)[D][0].Location = D0;
    (*locs)[D][0].Stock    = 10;
    (*locs)[D][0].Price    = DrPepperPrice;
    
    (*locs)[D][1].Capacity = 10;
    (*locs)[D][1].Drink    = Monster;
    (*locs)[D][1].Location = D1;
    (*locs)[D][1].Stock    = 10;
    (*locs)[D][1].Price    = MonsterPrice;
    
    (*locs)[D][2].Capacity = 10;
    (*locs)[D][2].Drink    = SurgeCola;
    (*locs)[D][2].Location = D2;
    (*locs)[D][2].Stock    = 10;
    (*locs)[D][2].Price    = SurgeColaPrice;
    
    (*locs)[D][3].Capacity = 10;
    (*locs)[D][3].Drink    = Slurr;
    (*locs)[D][3].Location = D3;
    (*locs)[D][3].Stock    = 10;
    (*locs)[D][3].Price    = SlurrPrice;
    
    (*locs)[E][0].Capacity = 10;
    (*locs)[E][0].Drink    = RcCola;
    (*locs)[E][0].Location = E0;
    (*locs)[E][0].Stock    = 10;
    (*locs)[E][0].Price    = RcColaPrice;
    
    (*locs)[E][1].Capacity = 10;
    (*locs)[E][1].Drink    = Monster;
    (*locs)[E][1].Location = E1;
    (*locs)[E][1].Stock    = 10;
    (*locs)[E][1].Price    = MonsterPrice;
    
    (*locs)[E][2].Capacity = 10;
    (*locs)[E][2].Drink    = Jolt;
    (*locs)[E][2].Location = E2;
    (*locs)[E][2].Stock    = 10;
    (*locs)[E][2].Price    = JoltPrice;
   
    (*locs)[E][3].Capacity = 10;
    (*locs)[E][3].Drink    = Slurr;
    (*locs)[E][3].Location = E3;
    (*locs)[E][3].Stock    = 10;
    (*locs)[E][3].Price    = SlurrPrice;
    
    (*locs)[F][0].Capacity = 10;
    (*locs)[F][0].Drink    = Sprite;
    (*locs)[F][0].Location = F0;
    (*locs)[F][0].Stock    = 10;
    (*locs)[F][0].Price    = SpritePrice;
    
    (*locs)[F][1].Capacity = 10;
    (*locs)[F][1].Drink    = MountainDew;
    (*locs)[F][1].Location = F1;
    (*locs)[F][1].Stock    = 10;
    (*locs)[F][1].Price    = MountainDewPrice;
    
    (*locs)[F][2].Capacity = 10;
    (*locs)[F][2].Drink    = RcCola;
    (*locs)[F][2].Location = F2;
    (*locs)[F][2].Stock    = 10;
    (*locs)[F][2].Price    = RcColaPrice;
    
    (*locs)[F][3].Capacity = 10;
    (*locs)[F][3].Drink    = Monster;
    (*locs)[F][3].Location = F3;
    (*locs)[F][3].Stock    = 10;
    (*locs)[F][3].Price    = MonsterPrice;
}

void vendItem(vend item)
{
    if (item.Drink == CokeCola)
        printf("\nVend Coke A Cola\n");
    else if (item.Drink == DrPepper)
        printf("\nVend Dr. Pepper\n");
    else if (item.Drink == Jolt)
        printf("\nVend Jolt\n");
    else if (item.Drink == Monster)
        printf("\nVend Monster\n");
    else if (item.Drink == MountainDew)
        printf("\nVend Mountain Dew\n");
    else if (item.Drink == RcCola)
        printf("\nVend Rc Cola\n");
    else if (item.Drink == Slurr)
        printf("\nVend Slurr\n");
    else if (item.Drink == Sprite)
        printf("\nVend Sprite\n");
    else if (item.Drink == SurgeCola)
        printf("\nVend Surge Cola\n");
    else
        printf("\nError item invalid.\n");
    
    printf("The number of drinks left is %d.\n", 
            item.Stock);
}

void returnMoney(double money, int purchase, float price)
{
    // Note you would probably want to add the cost of each item into the 2d 
    // array and then subtract and test against that instead.  As it stands all
    // items in the vending machine are $1.45
    if (money >= price && purchase == TRUE)
    {
        money -= price;
        change Coins = findChange(money);
        returnQuarters(Coins.Quarters);
        returnDimes(Coins.Dimes);
        returnNickels(Coins.Nickels);
        returnPennies(Coins.Pennies);
    }
    else
    {
        if (money < price)
            printf("\nError not enough money was inputed to purchase this item.\n");
        if (purchase == FALSE)
            printf("\nItem is out of stock.\n");
        
        change Coins = findChange(money);
        returnQuarters(Coins.Quarters);
        returnDimes(Coins.Dimes);
        returnNickels(Coins.Nickels);
        returnPennies(Coins.Pennies);
    }
}

void makeSelection(vend (*locs)[6][4], double money)
{
    char letter         = ' ';
    int  num            = -999;
    int  selectRow      = 0;
    int  error          = 1;
    
    printf("Enter the letter: ");
    // scanf("%c%*c", &letter);
    letter = getchar();
    printf("Enter the number: ");
    scanf("%d%*c", &num);
    
    if (letter == 'A' || letter == 'a')
        selectRow = A;
    else if (letter == 'B' || letter == 'b')
        selectRow = B;
    else if (letter == 'C' || letter == 'c')
        selectRow = C;
    else if (letter == 'D' || letter == 'd')
        selectRow = D;
    else if (letter == 'E' || letter == 'e')
        selectRow = E;
    else if (letter == 'F' || letter == 'f')
        selectRow = F;
    else
        error = 0;
    
    if (error)
    {
        if((*locs)[selectRow][num].Stock > 0)
        {
            if (money >= (*locs)[selectRow][num].Price)
            {
                (*locs)[selectRow][num].Stock -= 1;
                vendItem((*locs)[selectRow][num]);
                returnMoney(money, TRUE, (*locs)[selectRow][num].Price);
            }
            else
            {
                if (money < (*locs)[selectRow][num].Price)
                {
                    printf("\nError not enough money was inputed to purchase this item.\n");
                    returnMoney(money, FALSE, (*locs)[selectRow][num].Price);
                }
            }
        }
        else
            returnMoney(money, FALSE, (*locs)[selectRow][num].Price);
    }
    else
        returnMoney(money, FALSE, (*locs)[selectRow][num].Price);        
}

change findChange(double money)
{
    int         leftover        = 0;
    int         moneyInt        = 0;
    change      Coins;
    
    // moneyInt = (int) rint(money * 100);
    moneyInt = (int) (money * 100);
    
    Coins.Quarters = (int)(moneyInt / 25);
    leftover = (int) (moneyInt % 25);
    Coins.Dimes    = (int)(leftover / 10);
    leftover = leftover % 10;
    Coins.Nickels  = (int)(leftover / 5);
    leftover = leftover % 5;
    Coins.Pennies  = (int) leftover;
    
    printf("Return %d Quarters, %d Dimes, %d Nickels, %d Pennies.\n", 
            Coins.Quarters, Coins.Dimes, Coins.Nickels, Coins.Pennies);
    
    return Coins;
}

void returnQuarters(int quarters)
{
    int count = 0;
    
    for (count = 0; count < quarters; count++)
    {
        printf("Dispense Quarter.\n");
        printf("Wait 1 seconds. \n");
    }
}

void returnDimes(int dimes)
{
    int count = 0;
    
    for (count = 0; count < dimes; count++)
    {
        printf("Dispense Dime.\n");
        printf("Wait 1 seconds. \n");
    }
}

void returnNickels(int nickels)
{
    int count = 0;
    
    for (count = 0; count < nickels; count++)
    {
        printf("Dispense Nickel.\n");
        printf("Wait 1 seconds. \n");
    }
}

void returnPennies(int pennies)
{
    int count = 0;
    
    for (count = 0; count < pennies; count++)
    {
        printf("Dispense Penny.\n");
        printf("Wait 1 seconds. \n");
    }
}

int main(int argc, char** argv) 
{
    double machineMoney = 0.0;
    
    InitializeLocations(&locations);
    
    printf("Enter the amount of money: ");
    scanf("%lf%*c", &machineMoney);
    
    makeSelection(&locations, machineMoney);

    return (EXIT_SUCCESS);
}

