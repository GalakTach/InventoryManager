// InventoryManager.cpp : main project file.
// Programmer Arthur Sulian
// This program allows the user to choose 5 options from a menu and continue doing those actions
// until they press enter to exit the program. The user will be able to, view the current inventory,
// input transaction data which is automatically subtracted from inventory, view a transaction report,
// view an updated inventory report and clear the screen.

//#include "stdafx.h"
#include <iostream>
//using namespace System;

int main()
{
	int x, y; //declares x and y as integers
	int itemnum[] = { 1112,1212,1241,1562,1822,1900,2100 }; //defines itemnum as integer array and fills it with data
	int stock[] = { 32,15,7,25,106,12,48 }; //defines stock as integer array and fills it with data
	int transItem[50]; //defines transItem as integer array and allocates 50 memory spaces
	int transStock[50]; //defines transStock as integer array and allocates 50 memory spaces
	int howMany = 0; //defines the counter that will be used when filling the transaction arrays
	int tItem = 0; //defines tItem as integer and initializes value to 0 //will be used for transaction array
	int tStock; //defines tStock as integer //used for transaction array
	int user; //defines user as integer for the menu
	char menu; //defines menu as character will be used for switch statement
	bool transactions = false; //declares transactions as boolean

	printf("\n");
	printf(" Enter 1 to print an inventory report.\n");
	printf(" Enter 2 to input transaction data and subtract it from inventory.\n");
	printf(" Enter 3 to print a transaction report.\n");
	printf(" Enter 4 to print an updated inventory report.\n");
	printf(" Enter 5 to clear the screen.\n\n");
	printf(" Press enter to quit or input a number and press enter to continue.\n");

	while ((user = getchar()) != '\n') //loop that continues untill the user presses enter
	{
		if (user == '1') //if else if statements used for menu
			menu = 'A';
		else if (user == '2')
			menu = 'B';
		else if (user == '3')
			menu = 'C';
		else if (user == '4')
			menu = 'D';
		else if (user == '5')
			menu = 'E';
		else
			menu = 'F';

		switch (menu) //switch statement using the variable held in menu
		{
		case 'A': //prints the current stock

			printf("\n");
			printf("\n\t\tWidget Corporation\n");
			printf("\tInventory Report as of November 30, 2013\n\n");
			printf("\tItem Number\tAmount in Stock\n");
			for (x = 0; x < 7; x++)
			{
				printf("\t%d\t\t%d", itemnum[x], stock[x]);
				if (stock[x] == 0)
					printf(" -- Out Of Stock");
				printf("\n");
			}
			break;

		case 'B': //allows the user to input transaction data until they type 99 for both the item and stock. Transaction data is also subtracted from main inventory

			for (x = 0; x < howMany; x++) //Clears out the transaction array to prevent duplicate transactions
			{
				transItem[x] = 0;
				transStock[x] = 0;
			}

			howMany = 0;
			transactions = false;

			printf("\n");
			printf("\nType in the inventory number and ammount sold.\n\nType 99 for the item number and stock when finished\n\n");
			//transactions = true; //when transaction data input is selected "transactions" is given the boolean value true
			while (tItem != 99) //loop continues until the user types 99 for tItem and tStock
			{
				scanf_s("%d %d", &tItem, &tStock); //gets the data from the user 

				if (tItem != 99) //if the number inputed by the user is not 99 the data is placed into the appropriate array
				{
					transItem[howMany] = tItem;
					transStock[howMany] = tStock;
					howMany++;
					printf("\n\tTransaction Recorded.\n\n");
					if (howMany > 0 && howMany < 2)
						transactions = true; //when transaction data is inputed "transactions" is given the boolean value true
				}
			}

			tItem = 0; //tItem reinitialized to 0 to allow the user to input more transaction data later if they wish to
			if (transactions == true)
			{
				for (x = 0; x < 7; x++) //nested counting loops that subtract the transaction data from the inventory
				{
					for (y = 0; y < howMany; y++)
					{
						if (itemnum[x] == transItem[y])
						{
							if (stock[x] - transStock[y] >= 0)
								stock[x] = stock[x] - transStock[y];
							else
								printf("\n Sorry not enough stock to process item: %d\n\n", itemnum[x]);
						}
					}
				}

				//if (transactions == true)
				printf("\n  Transaction Completed.\n\n");
			}
			else
				printf("\tNo transaction data has been inputed.\n\n");


			break;

		case 'C': //prints the transaction data

			printf("\n");
			if (transactions == false) //if no transaction data has been inputed the user recieves the following message
			{
				printf("\tNo transaction data has been inputed.\n\n");
				break;
			}
			printf("\n\t\tWidget Corporation\n");
			printf("\tTransaction Report as of December 4, 2013\n\n");
			printf("\tItem Number\tAmount in Stock\n");
			for (x = 0; x < howMany; x++) //prints the transaction report
			{
				printf("\t%d\t\t%d", transItem[x], transStock[x]);
				printf("\n");
			}
			break;

		case 'D': //prints the updated inventory report

			printf("\n");
			printf("\n\t\tWidget Corporation\n");
			printf("\tUpdated Inventory Report as of December 5th, 2013\n\n");
			printf("\tItem Number\tAmount in Stock\n");
			for (x = 0; x < 7; x++)
			{
				printf("\t%d\t\t%d", itemnum[x], stock[x]);
				if (stock[x] == 0)
					printf(" -- Out Of Stock");
				printf("\n");
			}
			break;

		case 'E': //clears the screen
			system("cls");
			break;

		case 'F': //prints error messsage when user inputs something other that menu numbers or enter key
			printf("\n\n\tPlease enter a valid menu number only or press enter to quit.\n\n");
			break;
		}

		while (getchar() != '\n') //removes enter key held in buffer
			continue;

		printf("\n\tWhat would you like to do?\n");
		printf(" Enter 1 to print an inventory report.\n");
		printf(" Enter 2 to input transaction data and subtract it from inventory.\n");
		printf(" Enter 3 to print a transaction report.\n");
		printf(" Enter 4 to print an updated inventory report.\n");
		printf(" Enter 5 to clear the screen.\n\n");
		printf(" Press enter to quit or input a number and press enter to continue.\n");
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}