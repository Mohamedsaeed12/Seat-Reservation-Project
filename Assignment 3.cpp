// Zainab Kazwini & Mohamed Saeed //
// Seat Reservation Project //
// 28 November 2021 //

// Global initialization //
#include <iostream> 
#include <cctype>  // used for upper command
using namespace std;

int menuSelection; // what selection chosen from the menu 
int dollarValue = 0; // cost of tickets
int ticketsSold = 0; //number of tickets sold
void printSeats(void);  // print a table of the whole Auditorium
char confirmation(int, int);  // feed back to manager to confirm if the row and column enter is correct
void menuSetting(void); // menu funciton where the user give input for commands
char seats[10][30]; // 2D table of the auditoium with 10 rows and 30 seats in each column

// main function to execute program requirements //
int main()
{
	cout << endl;
	for (int i = 0; i < 10; i++) { //sets up the table with all #
		for (int j = 0; j < 30; j++) {
			seats[i][j] = '#';
		}

	}
	do {
		menuSetting(); //repeats menu selection until they chose to exit the program
	} while (menuSelection != 7);

}

 /* 
purpose == menu interface for the user
input == n/a
output == gets everthing user needs from price to seats avaiable and more
*/
void menuSetting()
{
	// local initialization //
	int avaiable;//the row enter to see what seats are avaiable in that row
	int sum;//calculates each ticket purchased
	int row;  
	int column;

	// menu selections //
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Please select which menu option you would like to continue with" << endl;
	cout << "1. Sell Tickets" << endl;
	cout << "2. Display the total dollar value of all tickets sold" << endl;
	cout << "3. Display the total number of tickets sold" << endl;
	cout << "4. Display the number of seats available in each row" << endl;
	cout << "5. Display the number of seats available in the entire auditorium" << endl;
	cout << "6. Display the current seating chart" << endl;
	cout << "7. Exit the system" << endl;
	// user input to select which option they would like //
	cout << "Please enter the number that corresponds with the action you would like to take" << endl;
	cin >> menuSelection;
	// conditional statement if the user wants to sell ticket //
	if (menuSelection == 1)
	{
		int bulkBuy; // if the user wants to buy multiple tickets at a time
		int check; //used to print error if the row and column entered is wrong
		char check2; //used to see if the user says y or n on confirmation
		check = 0;
		// asking user how many tickets they would like to sell //
		cout << "How many do you want to buy: ";
		cin >> bulkBuy;
		for (int i = 0; i < bulkBuy; i++) { // bulk buying for loop
			// nested do-while loops //
			do { //yes or no confirmaiton
				do { //gets row and columm

					// conditional statement if user enters invalid input //
					if (check > 0)
						cout << "Error, please re-enter ";
					// asking user to re-enter valid input //
					cout << "What row is the ticket in (must be between 1-10)?";
					cin >> row;

					cout << "What column is the ticket in?";
					cin >> column;
					check = 1;

				} while ((row > 10 || row < 1) || (column > 30 || column < 1));
				check = 0;
				check2 = confirmation(row, column);
			} while (check2 != 'Y');
			// conditional statement to output current seating chart //
			if (seats[row - 1][column - 1] != '*') { // check if seats is aviable
				seats[row - 1][column - 1] = '*';
				sum = (row - 1) * 5 + 10;
				// calculating the price of the ticket //
				dollarValue = sum + dollarValue;
				// output of price //
				cout << "Your cost is $" << sum << endl;
				// counter for tickets sold //
				ticketsSold += 1;
			}
			else {
				// output if user enters taken seat //
				cout << "Seat already taken please try again! \n ";
				if (i != 0)
					i--;
			}
		}
	}
	// conditional statement if user wants to view the amount of money made //
	if (menuSelection == 2)
	{
		cout << "Total dollar value of all tickets is: $" << dollarValue << endl;

	}
	// conditional statement if user wants to view number of tickets sold //
	if (menuSelection == 3)
	{
		cout << "Total number of tickets sold is: " << ticketsSold << endl;
	}
	// conditional statement if user would like to view available seats by row //
	if (menuSelection == 4)
	{
		// setting counter to 0 //
		int sumOfSeats = 0;//sum of all the seats taken in row so it can be subtracted from total
		cout << "What row do you want to see: ";
		cin >> avaiable;
		// if user enters invalid row //
		while (avaiable > 10 || avaiable < 1) {
			cout << "Error, please re-enter ";
			cout << "What row do you want to see: ";
			cin >> avaiable;
		}
		for (int i = 0; i < 30; i++) { //check each seat aviable in a specific row
			cout << seats[avaiable - 1][i];
			if (seats[avaiable - 1][i] == '*')
				sumOfSeats++;
		}
		// output of seats available in row //
		cout << "\nYou have " << 30 - sumOfSeats << " seats avaiable in row " << avaiable << endl;


	}
	// conditional statement if user would like to see how mant seats are available in the entire auditorium //
	if (menuSelection == 5)
	{
		int sumOfAll = 0; // all the seats not avaiable so it can be minised from total
		for (int j = 0; j < 10; j++) {//checks every seat avaiable
			for (int i = 0; i < 30; i++) {
				if (seats[j][i] == '*')
					sumOfAll++;
			}
		}
		cout << "\nYou have " << 300 - sumOfAll << " seats avaiable in the entire auditorium" << endl;
	}
	// conditional statement if user would like to view current seating chart //
	if (menuSelection == 6)
	{
		printSeats();
	}
	// conditional statement if user would like to exit the program //
	if (menuSelection == 7)
	{
		cout << "Thank you for using the seat reservation program. Goodbye!" << endl;
	}
}
/*
purpose == confimation of seats selected
input == row and column
output == get user input if what they entered is correct or not
*/
char confirmation(int a, int b) {
	char check; //basic used to return y or no
	do {
		cout << "Did you mean " << a << ", " << b << "? (y/n)";
		cin >> check;
		check = toupper(check);//make the letter capital
	} while (check != 'Y' && check != 'N');
	return check;
}
/* 
purpose == function for seating chart
input == na 
output == prints entire chart of seats
*/
void printSeats() {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 10; i++)
			cout << i;
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 30; j++) {
			cout << seats[i][j] << "";
		}
		cout << "Row " << i + 1 << endl;
	}
	cout << "     * = sold    # = avaiable" << endl;

}