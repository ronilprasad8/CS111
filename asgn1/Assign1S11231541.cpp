//Name: Ronil Prasad
//Student ID: S11231541
//Tutorial Group: Tuesday(11am-1pm)

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

int main(){
	const int CURRENT_YR = 2024;
	const int LOWEST_BIRTH_YR = 1950;
	
	//Chargeable income range
	const int LB_FIRST=0, UB_FIRST=30000;
	const int LB_SECOND=30000, UB_SECOND=50000;
	const int LB_THIRD=50000, UB_THIRD=270000;
	const int LB_FOURTH=270000, UB_FOURTH=300000;
	const int LB_FIFTH=300000, UB_FIFTH=350000;
	const int LB_SIXTH=350000, UB_SIXTH=400000;
	const int LB_SEVENTH=400000, UB_SEVENTH=450000;
	const int LB_EIGHTH=450000, UB_EIGHTH=500000;
	const int LB_NINTH=500000, UB_NINTH=1000000;
	const int LB_TENTH=1000000;
	
	//Tax rates
	const double TAX_RATE1=0.18;
	const double TAX_RATE2=0.20;
	const double TAX_RATE3=0.33;
	const double TAX_RATE4=0.34;
	const double TAX_RATE5=0.35;
	const double TAX_RATE6=0.36;
	const double TAX_RATE7=0.37;
	const double TAX_RATE8=0.38;
	const double TAX_RATE9=0.39;
	
	//Residential flat rates
	const int RFR1=3600;
	const int RFR2=47600;
	const int RFR3=57500;
	const int RFR4=74500;
	const int RFR5=92000;
	const int RFR6=110000;
	const int RFR7=128500;
	const int RFR8=318500;
	
	//Non-Residential flat rates
	const int NFR1=6000;
	const int NFR2=10000;
	const int NFR3=54000;
	const int NFR4=63900;
	const int NFR5=80900;
	const int NFR6=98400;
	const int NFR7=116400;
	const int NFR8=134900;
	const int NFR9=324900;
	
	int birth_yr, age;
	
	char residence, gender, UserInput, initial;
	
	double tax=0, income= 0;//Variable initialization.
	
	string EmployeeID, fname, lname;
	
		//Welcoming the user.
		cout << "*********************************************************\n";
		cout << "*\t\tWelcome to Tax Calculator\t\t*\n";
		cout << "*********************************************************\n\n";
		
		do{
			cout<<"Please enter your Firstname: \n";
			cin>>fname;
			initial=fname.at(0);//extracting the initial of user's firstname.
			cout<<"Please enter your Lastname: \n";
			cin>>lname;
		
			
			do{
				cout<<"Please select your gender: M for male, F for female and O for optional.\n";
				cin>>gender;
		}
			while(gender != 'M' && gender != 'F' && gender!='O');
			
			cout<<"Enter your Employee ID: \n";
	    	cin >> EmployeeID;
	    	
	    	while (true) {
		        cout << "Please enter your year of birth: ";
		        cin >> birth_yr;
	
	        	if (cin.fail()) {
	            cin.clear(); 
	            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	            cout << "Invalid input. Please enter an integer.\n";
				} 
				else if (birth_yr <= LOWEST_BIRTH_YR || birth_yr > CURRENT_YR) {
	            cout << "Invalid year. Please enter a year between "<<LOWEST_BIRTH_YR<<" and "<<CURRENT_YR<<".\n";
	        	} 
				else {
	        		break; 
	        	}
	    }	
	    	age=CURRENT_YR-birth_yr;//calculating user's age.
			 
	    	while (true) {
		        cout << "Enter your residential status (R for resident, N for non-resident): ";
		        cin >> residence;
				if (residence == 'R' || residence == 'N') {
		            break;
		        }
				else {
		            cout << "Invalid input. Please try again.\n";
		        }
	    }
				 
	        while (true) {
	        	cout << "Enter Chargeable Income: $";
	        	cin >> income;
	            if (cin.fail()) {
	                cin.clear();
	                cin.ignore(numeric_limits<streamsize>::max(), '\n');
	                cout << "Invalid input. Please enter a numeric value for Chargeable Income.\n";
	            }
	            else if(income<LB_FIRST){
	            	cout<<"Please enter an amount greater than "<<LB_FIRST<<".\n";
				}
				else{	
	        		break; 
	        	}
	    }
			cout<<"*********************************************************\n\n\n";
			
			//Resident tax calculation.
		    if (residence == 'R') {
		        if (income>=LB_FIRST && income <= UB_FIRST)
					tax = tax;
		        else if (income <= UB_SECOND) 
					tax = (income - LB_SECOND) * TAX_RATE1;
		        else if (income <= UB_THIRD) 
					tax = RFR1 + (income - LB_THIRD) * TAX_RATE2;
		        else if (income <= UB_FOURTH) 
					tax = RFR2 + (income - LB_FOURTH) * TAX_RATE3;
				else if (income <= UB_FIFTH) 
					tax = RFR3 + (income - LB_FIFTH) * TAX_RATE4;
				else if (income <= UB_SIXTH) 
					tax = RFR4 + (income - LB_SIXTH) * TAX_RATE5;
				else if (income <= UB_SEVENTH) 
					tax = RFR5 + (income - LB_SEVENTH) * TAX_RATE6;
				else if (income <= UB_EIGHTH) 
					tax = RFR6 + (income - LB_EIGHTH) * TAX_RATE7;
				else if (income <= UB_NINTH) 
					tax = RFR7 + (income - LB_NINTH) * TAX_RATE8;
				else if (income > LB_TENTH) 
					tax = RFR8 + (income - LB_TENTH) * TAX_RATE9;
		} 
		        
		        // Non-Resident tax calculation
			else if (residence == 'N') {
		        if (income>=LB_FIRST && income <= UB_FIRST)
					tax = income*TAX_RATE2;
		        else if (income <= UB_SECOND) 
					tax = NFR1*(income - LB_SECOND) * TAX_RATE2;
		        else if (income <= UB_THIRD) 
					tax = NFR2 + (income - LB_THIRD) * TAX_RATE2;
		        else if (income <= UB_FOURTH) 
					tax = NFR3 + (income - LB_FOURTH) * TAX_RATE3;
				else if (income <= UB_FIFTH) 
					tax = NFR4 + (income - LB_FIFTH) * TAX_RATE4;
				else if (income <= UB_SIXTH) 
					tax = NFR5 + (income - LB_SIXTH) * TAX_RATE5;
				else if (income <= UB_SEVENTH) 
					tax = NFR6 + (income - LB_SEVENTH) * TAX_RATE6;
				else if (income <= UB_EIGHTH) 
					tax = NFR7 + (income - LB_EIGHTH) * TAX_RATE7;
				else if (income <= UB_NINTH) 
					tax = NFR8 + (income - LB_NINTH) * TAX_RATE8;
				else if (income > LB_TENTH) 
					tax = NFR9 + (income - LB_TENTH) * TAX_RATE9;
		} 	
			
		// Display result
	    cout << "Dear " << ((gender == 'M') ? "Mr. " : (gender == 'F') ? "Ms. " : (gender=='O') ? "Mx. " : "") <<initial<<". "<< lname;
		cout << " (Employee ID: " << EmployeeID << ")\n\n" ;
	    cout << "You are " << age << " years old and a " << ((residence=='R') ? "Resident" : (residence=='N') ? "Non-Resident":"")  << " of Fiji.";
	    cout << " Based on your provided income of $" << income << ", you are required to pay an Income Tax of $" << tax << ".\n\n" ;
	    cout << "Best Regards.\n\n\n";
	    cout << "*********************************************************\n\n";
	    	
	    cout << "Enter 'Q' to quit or press any key to re-calculate: ";
	    cin >> UserInput;
	    cout << "*********************************************************\n\n";
	}
	while(UserInput != 'Q');
		
	return 0;
}
