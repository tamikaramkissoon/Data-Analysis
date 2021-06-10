#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Symbol {
	int StockID;
	string symbol;
};

struct Date {
	int DateID;
	int Day;
	int Month;
	int Year;
};

struct StockData {
	float open;
	float high;
	float low;
	float close;
	int volume;
};

int ReadSymbol (Symbol StockSymbols[]){ // reading from symbol.txt
	
	int i = 0;	
	int ID = -1;
	string symbols;
	ifstream in;
	in.open("Symbol.txt");
	
	// if statement to check whether the input file was successfully opened.
	if (!in.is_open())
	{
		cout << "There was an error opening the data file!  Operation aborting!!..." << endl;
		exit(1);
	}
	else 
		cout << "Symbol file sucessfully opened...  reading data from file" << endl;
	
	in >> ID >> symbols;	
	while (ID != -1 && i < 100){
		StockSymbols[i].StockID = ID;
		StockSymbols[i].symbol = symbols;
		
		in >> ID >> symbols;
		i = i + 1;
	}
	in.close();
	return i;
}

int ReadDate (Date StockDates[]){ // reading from date.txt
	
	int i = 0;	
	int ID = -1, day =0, month =0, year = 0;
	
	ifstream in;
	in.open("date.txt");
	
	// if statement to check whether the input file was successfully opened.
	if (!in.is_open())
	{
		cout << "There was an error opening the data file!  Operation aborting!!..." << endl;
		exit(1);
	}
	else 
		cout << "\nDate file sucessfully opened... reading from file" << endl;
	
	in >> ID >> day >> month >> year;	
	while (ID != -1 && i < 30){
		StockDates[i].DateID = ID;
		StockDates[i].Day = day;
		StockDates[i].Month = month;
		StockDates[i].Year = year;		
		in >> ID >> day >> month >> year;
		i = i + 1;
	}
	in.close();
	return i;
}

void ReadStock (StockData stock[][30], int m, int n){// fix function
	
	string symbol; 
	
	ifstream in;
	in.open("Stock.txt");
	
	// if statement to check whether the input file was successfully opened.
	if (!in.is_open())
	{
		cout << "There was an error opening the data file!  Operation aborting!!..." << endl;
		exit(1);
	}
	else 
		cout << "\nStock file sucessfully opened...   reading " << m << " rows and " << n << " columns of data from file" << endl;
		
	in >> symbol;
	while (symbol != "END"){
	
	for (int i = 0; i < m; i = i + 1){
		for (int j = 0; j < n; j = j + 1){
			in >> stock[i][j].open >> stock[i][j].high >> stock[i][j].low >> stock[i][j].close >> stock[i][j].volume;
		}
		in >> symbol;
	}
	
}
	in.close();
	
}



void menu() {// function displaying the menu options;

  cout << "	 Analysis of Company Stocks" << endl;
  cout << "	===========================" << endl;
  cout << "       	 M E N U" << endl;
  cout << endl;
  cout << "  1.  Find the highest closing price of a given stock and the date on which it occurred" << endl;
  cout << "  2.  Find the total volume traded of a given stock" << endl;
  cout << "  3.  Find the date of the biggest difference between high and low prices of a given stock " << endl;
  cout << "  4.  Find the stock with the biggest difference between high and low prices on a given date" << endl;
  cout << "  5.  Find the biggest changing stock price between a previous day's close and next day's open" << endl;
  cout << "  6.  Find the percentage increase/decrease of each stock based on first day / last day prices" << endl;
  cout << "  7.  Plot a graph showing the price of a given stock on each day" << endl;
  cout << "  8.  Quit" << endl;
  cout << endl;

}

void DisplayStockSymbol (Symbol StockSymbols[], int m){
	
	cout <<"\nThe following is a list of all the stock available." << endl;
	for(int i = 0; i < m; i = i + 1){
		cout << i+1 << ". " << StockSymbols[i].symbol <<endl;
	}

}

int findSymbolLoc (Symbol StockSymbols[], int m, string StockChoice){
	for (int i = 0; i < m; i = i + 1){
		if(StockSymbols[i].symbol == StockChoice)
			return StockSymbols[i].StockID;
	}
	return - 1;
}

int findDateLoc (Date StockDates[], int n, int day, int month, int year){
	for (int i = 0; i < n; i = i + 1){
		if (StockDates[i].Day == day && StockDates[i].Month == month && StockDates[i].Year == year)
			return StockDates[i].DateID;
	}
	return -1;
}

void Option1 (Symbol StockSymbols[], int m, StockData stock[][30], int n, Date StockDates[]){
	
	int i = 0;
	bool found = false;
	double highestC_Price = 0.0;
	Date HighestPriceDate;
	string StockChoice = "";
	
	cout << "\nPlease enter a stock symbol ";
	cin.ignore();
	getline(cin, StockChoice);
	
	while (i < m && found == false){
		if (StockChoice == StockSymbols[i].symbol){
			found = true;
		}
		else 
			i = i + 1;
	}
	
	
	if (found == false){
		cout << "\nThe Stock Symbol entered was not found!" <<endl;
		DisplayStockSymbol (StockSymbols, m);
	}
	
	else {
		if (found == true){
			int	row = findSymbolLoc (StockSymbols, m, StockChoice);
		 	highestC_Price = INT_MIN;
		
			for (int i = 0; i < n; i = i + 1){
				if (stock[row][i].close > highestC_Price){
				
					highestC_Price = stock[row][i].close;
					HighestPriceDate.Day = StockDates[i].Day;
					HighestPriceDate.Month = StockDates[i].Month;
					HighestPriceDate.Year = StockDates[i].Year;
				}
			}
		}

	cout << "\nThe highest closing price of " << StockChoice << " is " << highestC_Price << endl;
	cout << "The stock was traded at this price on " << HighestPriceDate.Day << "/" << HighestPriceDate.Month << "/" << HighestPriceDate.Year << endl;
	}
	system("pause");
	system("cls");
}

void Option2 (Symbol StockSymbols[], int m, StockData stock[][30], int n){
	
	int i = 0;
	bool found = false;
	int totalVolume = 0;
	string StockChoice= "";

	cout << "\nPlease enter a stock symbol ";
	cin.ignore();
	getline(cin, StockChoice);
	
	while (i < m && found == false){
		if (StockChoice == StockSymbols[i].symbol){
			found = true;
		}
		else 
			i = i + 1;
	}
	
	
	if (found == false){
		cout << "\nThe Stock Symbol entered was not found!" <<endl;
		DisplayStockSymbol (StockSymbols, m);
	}
	
	else {
	
		if (found == true){
			int	row = findSymbolLoc (StockSymbols, m, StockChoice);
		
		
			for (int i = 0; i < n; i = i + 1){		
					totalVolume = totalVolume + stock[row][i].volume;
				
				}
		}
		
		cout << "\nThe total volume traded for " << StockChoice << " is " << totalVolume << endl;	
	}
	system("pause");
	system("cls");
}

void Option3 (Symbol StockSymbols[], int m, StockData stock[][30], int n, Date StockDates[]){  

	int i = 0;
	bool found = false;
	double difference = 0.0, Biggest_difference = 0.0;
	double diff_high = 0.0, diff_low = 0.0;
	Date Difference_Date;
	string StockChoice = "";

	cout << "\nPlease enter a stock symbol ";
	cin.ignore();
	getline(cin, StockChoice);
	
	while (i < m && found == false){
		if (StockChoice == StockSymbols[i].symbol){
			found = true;
		}
		else 
			i = i + 1;
	}
	
	
	if (found == false){
		cout << "\nThe Stock Symbol entered was not found!" <<endl;
		DisplayStockSymbol (StockSymbols, m);
	}
	
	else {
	
	if (found == true){
		int	row = findSymbolLoc (StockSymbols, m, StockChoice);
		 Biggest_difference = INT_MIN;
		
			for (int i = 0; i < n; i = i + 1){
				difference = abs (stock[row][i].high - stock[row][i].low);
				
				if (difference > Biggest_difference){
					Biggest_difference = difference;
					diff_high = stock[row][i].high;
					diff_low = stock[row][i].low;
					Difference_Date.Day = StockDates[i].Day;
					Difference_Date.Month = StockDates[i].Month;
					Difference_Date.Year = StockDates[i].Year;
				}
			}
	}
	
	cout << "\nThe date with the biggest difference between the high and low price is " << Difference_Date.Day << "/" << Difference_Date.Month << "/" << Difference_Date.Year << endl;
	cout << "The biggest difference is " << setprecision(2) << Biggest_difference << endl;
	cout << "The high price was " << setprecision(4) << diff_high << endl;
	cout << "The low price was " << setprecision(4) <<diff_low << endl;
	}	
	system("pause");
	system("cls");
}

void Option4 (Symbol StockSymbols[], int m, StockData stock[][30], int n, Date StockDates[]){
	
	int day = 0, month = 0, year = 0, col= 0;
	double Biggest_difference = INT_MIN, difference = 0.0, diff_high = 0.0, diff_low = 0.0;
	string BiggestDiffStock = "";
	
	cout << "\nPlease enter the date in the format (day month year) ";
	cin >> day >> month >> year;
	
	col = findDateLoc (StockDates, n, day, month, year);
	
	if (col == -1){
		cout << "\nThe Date entered is not a valid trading day!! " <<endl;
	}
	else {
	
		if (col != -1 ){
			for (int i = 0; i < m ; i = i + 1){
		
				difference = abs (stock[i][col].high - stock[i][col].low);
		
				
				for (int j = 0; j<n; j = j + 1){
					if (StockDates[j].Day == day && StockDates[j].Month == month && StockDates[j].Year == year){
						if (difference > Biggest_difference){
							Biggest_difference = difference;
							diff_high = stock[i][j].high;
							diff_low = stock[i][j].low;
							BiggestDiffStock = StockSymbols[i].symbol;
						}		
					}
				}
			}
		}
		
		cout << "\nThe stock with the biggest difference between the high and low prices is " << BiggestDiffStock << endl;
		cout << "The high price is " << diff_high << endl;
		cout << "The low price is " << diff_low << endl;
		cout << "The difference between the high and low price is " << Biggest_difference << endl;
	}
	system("pause");
	system("cls");
}

void Option5 (StockData stock[][30], int m, int n, Date StockDates[], Symbol StockSymbols[]){ 
	
	double difference = 0.0, Biggest_difference = INT_MIN;
	string BiggestDiffStock = "";
	double previousClose = 0.0, nextOpen = 0.0;
	Date previousDay, previousMonth, previousYear ;
	Date nextDay, nextMonth, nextYear;
	
	for (int i =0; i < m; i = i + 1){
		for (int j = 0; j < n-1; j = j + 1){
			difference = abs (stock[i][j].close - stock[i][j+1].open);
				
				if (difference > Biggest_difference){
					Biggest_difference = difference;
					BiggestDiffStock = StockSymbols[i].symbol;
					previousClose = stock[i][j].close;
					nextOpen = stock[i][j+1].open;
					previousDay.Day = StockDates[j].Day;
					previousMonth.Month = StockDates[j].Month;
					previousYear.Year = StockDates[j].Year;
					nextDay.Day = StockDates[j+1].Day;
					nextMonth.Month = StockDates[j+1].Month;
					nextYear.Year = StockDates[j+1].Year;
				}
		}
	}
	cout <<"\nThe biggest difference between closing price and opening price is  " << Biggest_difference << " for " << BiggestDiffStock << endl;
	cout <<"The closing price was " << previousClose << " on " << previousDay.Day << "/" << previousMonth.Month << "/" << previousYear.Year;
	cout <<" and the opening price was " << nextOpen << " on " << nextDay.Day << "/" << nextMonth.Month << "/" << nextYear.Year << endl;

	system("pause");
	system("cls");
}

void Option6 (Symbol StockSymbols[], StockData stock[][30], int m, int n){
	
	double percentage = 0.0, difference = 0.0;
	
	cout << "\nStock Symbol	Increase/Decrease" <<endl;
	
	for(int i = 0; i < m; i = i + 1){
		difference = stock[i][n-1].close - stock[i][0].close;
		percentage = difference * 100.0 / stock[i][0].close;

		if (percentage > 0){
			cout << StockSymbols[i].symbol << "		" <<  fixed << setprecision(1) << percentage << "% (increase)" << endl;
		}
		else 
			if (percentage < 0)
				cout << StockSymbols[i].symbol << "		"<< fixed << setprecision(1) << percentage  << "% (Decrease)" << endl;
	}
	system("pause");
	system("cls");
}

void Option7 (Symbol StockSymbols[], int m, StockData stock[][30], int n){

	int i = 0;
	bool found = false;
	string StockChoice = "";
	
	int yaxis[100];
	for(int i=0; i < 100; i = i + 1){
		yaxis[i] = 0;
	}
	
	int highestClosePrice = 0;
	char graph[100][100];
	
	for(int i =0; i < 100; i = i + 1){
		for (int j = 0; j < 100; j = j + 1){
			graph[i][j]= ' ';
		}
	}

	cout << "\nPlease enter a stock symbol ";
	cin.ignore();
	getline(cin, StockChoice);
	
	while (i < m && found == false){
		if (StockChoice == StockSymbols[i].symbol){
			found = true;
		}
		else 
			i = i + 1;
	}
	
	
	if (found == false){
		cout << "\nThe Stock Symbol entered was not found!" <<endl;
		DisplayStockSymbol (StockSymbols, m);
	}
	
	else {
		if (found == true){
			int	row = findSymbolLoc (StockSymbols, m, StockChoice);
		
			for (int i = 0; i < n; i = i + 1){
				yaxis[i]= (float) round (stock[row][i].close);
				
				if (yaxis[i] > highestClosePrice)
					highestClosePrice = yaxis[i];
			}
			cout <<"The graph of closing price of " << StockChoice << endl;
			for (int  i = highestClosePrice + 1 ; i >= 0; i = i - 1){
				cout << i;
				for (int j = 0; j < n; j = j + 1){
					if (yaxis[j] == i ){
						graph[i][j] = '*';
						cout << graph[i][j];
					}	
					else{
						graph[i][j] = ' ';
						cout << graph[i][j];
					} 
				}
				cout << endl;
			}
	
		}
	}
	system("pause");
	system("cls");
}


void Option8 (){

	cout << "\n	Menu quit!!" <<endl;
	cout <<"\n\n\t\tEnd of Program" << endl;

}

int main(){
	Symbol StockSymbols[100];
	Date StockDates[30];
	StockData stock[100][30];
	int m = 0, n = 0, choice =0;
	
	for (int i =0; i < 100; i = i + 1){ // initializations
		StockSymbols[i].StockID = 0;
		StockSymbols[i].symbol = "";
	}
	
	for (int i= 0; i <30; i = i + 1){
		StockDates[i].DateID = 0;
		StockDates[i].Day = 0;
		StockDates[i].Month = 0;
		StockDates[i].Year = 0;
	}
	for (int i= 0; i <100; i = i + 1){
		for(int j=0; j<30; j = j + 1){
		stock[i][j].close = 0.0;
		stock[i][j].high = 0.0;
		stock[i][j].low = 0.0;
		stock[i][j].open = 0.0;
		stock[i][j].volume = 0;
		}	
	}
	
	
	m = ReadSymbol(StockSymbols);// holds the amount of stock symbols in the file. ROWS
	cout <<  m <<" stock symbols read from file!" << endl;
	n = ReadDate(StockDates); // holds the amount of trading days in feb 2021. COL
	cout << n <<" dates read from file!" << endl;
	
	ReadStock (stock, m,  n); // reads the data into a 2D array.
	cout << "Data for " << m << " rows and " << n << " columns read" <<endl << endl;
	
	system ("pause");
	system("cls");
	
	choice = 1;
	while (choice >=1 && choice <= 7){
		
		menu();
		cout << "  Please choose an option or 8 to quit: ";
  		cin >> choice;
  	
  		
  		if(choice == 1)
  			Option1 (StockSymbols, m, stock, n, StockDates);
  				else if (choice == 2)
  					Option2 (StockSymbols, m, stock, n);
  						else if (choice == 3)
  							Option3 (StockSymbols, m, stock, n, StockDates);
  								else if (choice == 4)
  									Option4 (StockSymbols, m, stock, n, StockDates);
  										else if (choice == 5)
  											Option5 (stock, m, n, StockDates, StockSymbols);
  												else if (choice == 6)
  													Option6 (StockSymbols, stock, m, n);
  														else if (choice == 7) 
  															Option7 (StockSymbols, m, stock, n);
  																else if (choice == 8)
  																	Option8(); 
  																	else 
  																		cout << "\n INVALID INPUT!! ... \n	Sorry, The Program Has Ended!!" << endl;
  
  															
  	}

	return 0;
}
