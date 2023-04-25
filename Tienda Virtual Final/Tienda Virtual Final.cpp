// Tienda Virtual Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <cmath>
#include <string>
using namespace std;

void kartMenu(string itemsName[10], float itemsPrice[10], float itemsAmount[10]) {

    //Variables
    bool exitKart = false;
    int option, amount;
    float totalPrice = 0;

    //Loop that identifies if the user wants to leave
    while (exitKart == false) {

        //Clears the text on screen
        system("cls");

        //The name of the menu
        cout << "Your Shopping Kart\n--------------------------------\n";
        cout << "ID:  Price:   Amount:  Name:\n\n";


        //Loop que crea la lista
        for (int i = 0; i < 10; i++) {
            if (itemsAmount[i] > 0) {
                cout << i << ":   " << itemsPrice[i] << " gp     " << itemsAmount[i] << "       " << itemsName[i] << "\n";
            }
        }

        //Calculates and Write the total amount of money
        totalPrice = 0;
        for (int i = 0; i < 10; i++) {
            totalPrice = totalPrice + (itemsPrice[i] * itemsAmount[i]);
        }
        cout << "\nThe total price is: " << totalPrice << " gp";

        //El usuario elige la opcion del usuario
        cout << "\n--------------------------------\nPlease choose one of these options:\n 1: Remove an item from the kart\n 2: Exit to main menu\n > ";
        cin >> option;

        //Switch case que hace lo que el usuario elige
        switch (option) {
            //Remove an item from the kart
        case 1:

            //The user give the items ID
            cout << "Please write the ID number of the item you which to remove\n > ";
            cin >> option;

            //The program ask how many will you remove
            cout << "Please write the amount of that item that you which to remove\n > ";
            cin >> amount;

            //If the amount is negative, it makes it 0
            if (amount < 0) {
                amount = 0;
            }

            //Removes the items of the ID
            itemsAmount[option] = itemsAmount[option] - amount;

            //To make sure the amount does not go negative
            if (itemsAmount[option] < 0) {
                itemsAmount[option] = 0;
            }

            break;

            //Exit to main menu
        case 2:
            exitKart = true;

            break;

            //ERROR
        default:
            cout << "This is not a valid option\n";
            system("pause");

            break;
        }


    }


}

void storeMenu(string itemsName[10], float itemsPrice[10], float itemsAmount[10]) {

    //variables
    bool exitStoreMenu = false;
    int option1 = 0, amount, option;
    //loop de opciones que se asegura que se tome una opcion
    while (option1 != 2) {

        //Clears the text on screen
        system("cls");

        //The name of the menu
        cout << "Store Menu";

        //print welcome to the user
        cout << "Welcome to The blacksmith shop!\n--------------------------------\nID:  Price:  Name:\n";

        //Loop que crea la lista
        for (int i = 0; i < 10; i++) {
            cout << "\n" << i << ":   " << itemsPrice[i] << " gp    - " << itemsName[i];
        }

        //tells the user to choose an option
        cout << "\n\n--------------------------------\nPlease choose one option\n ";
        cout << "1. Buy items\n ";
        cout << "2. Exit to main menu\n > ";

        cin >> option1;
        //opcion para continuar comprando
        if (option1 == 1) {
            cout << "Please write the ID number of the item you wish to buy\n > ";
            cin >> option;
            //The program ask how many will you add
            cout << "Please write the amount of the item that you which to add\n > ";
            cin >> amount;

            //If the amount is negative, it makes it 0
            if (amount < 0) {
                amount = 0;
            }

            //add the items of the ID
            itemsAmount[option] = itemsAmount[option] + amount;

            cout << "The items have been added to your kart\n";
            system("pause");


        }
        //option para regresar al menu principal
        else if (option1 == 2) {


        }
        //option que se asegura que se 1 de las 2 optionen
        else
        {
            cout << "Error this is not a valid option\n ";
            system("pause");
        }


    }




}

void checkMenu(string itemsName[10], float itemsPrice[10], float itemsAmount[10], bool& endShop) {
    //Variables
    bool exitKart = false, exitCheck = false, couponActive = false, exitCheckReceipt = true, checkFinal = false;
    int option = 0, optionTwo = 0, amount = 0;
    float totalPrice = 0;
    string couponCode = "30250", couponInput, name;

    while (exitKart == false) {

        //Clears the text on screen
        system("cls");

        //The name of the menu
        cout << "Store Menu\n--------------------------------\n";
        cout << "ID:  Price:   Amount:  Name:\n\n";


        //Loop que crea la lista
        for (int i = 0; i < 10; i++) {
            if (itemsAmount[i] > 0) {
                cout << i << ":   " << itemsPrice[i] << " gp     " << itemsAmount[i] << "       " << itemsName[i] << "\n";
            }
        }

        //Calculates and Write the total amount of money
        totalPrice = 0;
        for (int i = 0; i < 10; i++) {
            totalPrice = totalPrice + (itemsPrice[i] * itemsAmount[i]);
        }
        cout << "\nThe total price is: " << totalPrice << " gp";

        //If coupon is active, then write the price with the discount
        if (couponActive == true && totalPrice > 0) {
            cout << "\nThe total price with coupon is: " << totalPrice * 0.80 << " gp";
        }

        //El usuario elige la opcion del usuario
        cout << "\n--------------------------------\nPlease choose one of these options:\n 1: Comfirm purchase \n 2: Activate Coupon\n 3: Exit to main menu\n > ";
        cin >> option;

        //Switch case que hace lo que el usuario elige
        switch (option) {
            //Remove an item from the kart
        case 1:
            //Checks if the user even has any items to comfirm a purchase
            if (totalPrice > 0) {

                //Get the name of the user for the receite
                cout << "Please write your name for the receipt\n > ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, name);

                //Receipt Menu
                exitCheckReceipt = false;
                while (exitCheckReceipt != true) {
                    //Write the receipt-------------------------
                    system("cls");
                    //The name of the menu
                    cout << "     Virtual Store Receipt\n--------------------------------\n";
                    cout << "ID:  Price:   Amount:  Name:\n\n";
                    //Loop que crea la lista
                    for (int i = 0; i < 10; i++) {
                        if (itemsAmount[i] > 0) {
                            cout << i << ":   " << itemsPrice[i] << " gp     " << itemsAmount[i] << "       " << itemsName[i] << "\n";
                        }
                    }
                    //Calculates and Write the total amount of money
                    totalPrice = 0;
                    for (int i = 0; i < 10; i++) {
                        totalPrice = totalPrice + (itemsPrice[i] * itemsAmount[i]);
                    }
                    cout << "\nThe total price is: " << totalPrice << " gp";
                    //If coupon is active, then write the price with the discount
                    if (couponActive == true && totalPrice > 0) {
                        cout << "\nThe total price with coupon is: " << totalPrice * 0.80 << " gp";
                    }
                    //Name of the order
                    cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxx\nOrder Name: " << name << endl;

                    //Ask the user if they want to finalize the purchase
                    cout << "\n--------------------------------\nDo you wish to finalize your purchase?\n 1: Finalize purchase\n 2: Change name\n 3: Go back to Check-out Menu\n > ";
                    cin >> optionTwo;

                    //This determines if the purchase has been finalized
                    switch (optionTwo) {
                    case 1: //The purchase has been finalized
                        //Write the receipt-------------------------
                        system("cls");
                        //The name of the menu
                        cout << "     Virtual Store Receipt\n--------------------------------\n";
                        cout << "ID:  Price:   Amount:  Name:\n\n";
                        //Loop que crea la lista
                        for (int i = 0; i < 10; i++) {
                            if (itemsAmount[i] > 0) {
                                cout << i << ":   " << itemsPrice[i] << " gp     " << itemsAmount[i] << "       " << itemsName[i] << "\n";
                            }
                        }
                        //Calculates and Write the total amount of money
                        totalPrice = 0;
                        for (int i = 0; i < 10; i++) {
                            totalPrice = totalPrice + (itemsPrice[i] * itemsAmount[i]);
                        }
                        cout << "\nThe total price is: " << totalPrice << " gp";
                        //If coupon is active, then write the price with the discount
                        if (couponActive == true && totalPrice > 0) {
                            cout << "\nThe total price with coupon is: " << totalPrice * 0.80 << " gp";
                        }
                        //Name of the order
                        cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxx\nOrder Name: " << name << endl;

                        //Ask the user if they want to finalize the purchase
                        cout << "\n--------------------------------\n\n >> Thank you for shopping with us!!! <<\n\n";

                        exitCheckReceipt = true;
                        exitKart = true;
                        endShop = true;

                        break;

                    case 2: //The user chooses to rewrite their name

                        //Get the name of the user for the receite
                        cout << " Please write your name for the receipt\n > ";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, name);

                        break;

                    case 3:
                        exitCheckReceipt = true;

                        break;
                    };

                };


                break;
            }
            else {
                cout << " >> YOU DO NOT HAVE ANY ITEMS IN YOUR KART TO PURCHASE<<\n\n";

                system("pause");

                break;
            }

            break;
        case 2: //Activate Cooupon
            //For the loop to work
            exitCheck = false;

            //That writes the coupon menu
            do {
                //Erases screen
                system("cls");

                //Write the menu and receives the users input
                cout << "Redeem coupon\n--------------------------------\n";
                cout << "Please write the coupon code\nIf you wish to exit, write B\n > ";
                cin >> couponInput;

                //Check if the input of the user is valid

                if (couponInput == couponCode && couponActive == false) {//Activate the coupon if it has not been activated
                    cout << "\nYour coupon has been activated \n\n";
                    couponActive = true;

                    system("pause");
                }
                else if (couponInput == couponCode && couponActive == true) { //Tells user that the coupon is already active
                    cout << "\nThis coupon is already active \n\n";

                    system("pause");

                }
                else if (couponInput == "B" || couponInput == "b") { //This is for returning to the menu
                    exitCheck = true;
                }
                else { //Error or not valid option
                    cout << "\n >> This is not a valid coupon code << \n\n";

                    system("pause");
                }

            } while (exitCheck == false);


            break;

            //Exit to main menu
        case 3:
            exitKart = true;

            break;

            //ERROR
        default:
            cout << "This is not a valid option\n";
            system("pause");

            break;
        }


    }


}


int main()
{
    //Variables
    bool endShop = false;
    int option = 0;


    //Array
    //Name of the items
    string itemsName[10] = {
        {"Mace"},
        {"Crossbow"},
        {"Battleaxe"},
        {"Greataxe"},
        {"Lance"},
        {"Morningstar"},
        {"Warhammer"},
        {"Longbow"},
        {"Shortsword"},
        {"Trident"},
    };

    //Price of the items
    float itemsPrice[10] = {
        {5},
        {25},
        {10},
        {10},
        {10},
        {15},
        {15},
        {10},
        {5},
        {10},
    };
    //Amount of the items
    float itemsAmount[10] = {
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
    };

    //Title Screen
    cout << "Welcome to the Virtual Weapon Shop!\n\n- In this virtual store, you will be able to purshace weapons from the comfort of your home\n"
        << "- The currency used is Golden Piece (GP) \n\n ";

    //Pause until a key has been pressed
    system("pause");

    //Menu Screen
    do {
        //Clear the screen
        system("cls");

        //The Menu
        cout << "Main Menu\n--------------------------------\n";
        cout << "Options:\n 1: Your Shopping Kart \n 2: Store \n 3: Check-out \n 4: Exit\n\n";

        //Collects the option that the user selectedd
        cout << "Please choose an option\n > ";
        cin >> option; //Captura option

        //Loop that check if the option is valid
        while ((option != 1) && (option != 2) && (option != 3) && (option != 4)) {
            system("cls");

            cout << "Menu Screen\n--------------------------------\n";
            cout << "Options:\n 1: Your Shopping Kart \n 2: Store \n 3: Check-out \n 4: Exit\n\n";

            cout << ">> You have enterend an invalid option <<\n";
            cout << "Please choose an option\n > ";
            cin >> option;
        }

        //Switch case that determines where on the shop you are going to be taken
        switch (option) {
            //Shopping Kart
        case 1:
            kartMenu(itemsName, itemsPrice, itemsAmount);

            break;

            //Store Menu
        case 2:
            storeMenu(itemsName, itemsPrice, itemsAmount);

            break;

            //Check Out Menu
        case 3:
            checkMenu(itemsName, itemsPrice, itemsAmount, endShop);

            break;

            //Exit
        case 4:

            //The endShop make the loop end, which end the program
            endShop = true;

            break;

            //Default which would be the Shooping Kart
        default:
            kartMenu(itemsName, itemsPrice, itemsAmount);

        }
    } while (endShop == false);




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
