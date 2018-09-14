

/*
Workshop 3

Name: Callum Dodge
Date: May 25,2018
Section: D

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "CRA_Account.h"

using namespace std;

namespace sict{

	//Set all data members to safe empty states using the constructor 
	CRA_Account::CRA_Account() {
		*familyName = '\0';
		*givenName = '\0';
		sin = 0;
		year[max_yrs] = 0;
		balance[max_yrs] = 0;

		cnt = 0;
	}

	void CRA_Account::set(const char* n_familyName, const char* n_givenName, int n_sin) {
		
		//Copy the values into the Data Members in the Class
		sin = n_sin;
		strncpy(familyName, n_familyName, max_name_length);
		strncpy(givenName, n_givenName, max_name_length);

		bool value = isEmpty();
		
		//If the value is empty, empty the values
		if (value == true) {
			*familyName = '\0';
			*givenName = '\0';
			sin = 0;
		}

	}

	bool CRA_Account::isEmpty() const {
		bool value;

		//Compare to see if the SIN is between the 9 digit range
		if (CRA_Account::sin < sict::min_sin || CRA_Account::sin > sict::max_sin) {
			value = true;
		}

		//Check to see if the SIN is valid
		else {
			int max = 8;
			int sinArray[9];
			int checkArray[9];
			int tempArray[9];
			int temp_sin = sin;
			int total = 0;
			int total_SIN = 0;
			int div;

			//Loop through each digit and insert it into an element of an array
			for (int cnt = 0; cnt <= max; cnt++) {
				sinArray[cnt] = temp_sin % 10;
				temp_sin = temp_sin / 10;
			}

			//Loop through each element of the sinArray
			for (int j = 0; j <= max; j++) {

				//Using the following formula, 121 212 121. 
				//Loop and multiply each digit with the corresponding digit above. 
				int one_zero = 0;
				one_zero = j % 2;

				//Compare to see if j is either, even or odd. If even one_zero will equal 1.
				//If odd one_zero will equal 2.
				if (one_zero == 0) {
					one_zero = 1;
				}
				else {
					one_zero = 2;
				}
				
				//Multiply each digit with its corresponding value. (1 or 2)
				checkArray[j] = sinArray[j] * one_zero;
	
				//Since a single digit can only hold numbers 0-9. Check to see if the number equals or 
				//greater than 10.
				if (checkArray[j] >= 10) {
			
					//Seperate each digit back into a sperate array.
					total = 0;
					for (int cnt = 0; cnt <= 1; cnt++) {
						tempArray[cnt] = checkArray[j] % 10;
						checkArray[j] = checkArray[j] / 10;
						
						//Instead of multiplying, add each digit together.
						total = total + tempArray[cnt];
					}
					//Add the digit back to the orignal array.
					checkArray[j] = total;
				}
				//Add all digits together. 
				total_SIN = total_SIN + checkArray[j];

			}
			
			div = total_SIN % 10;

			//Check to see if the value is divisible by 10. The SIN would be a valid SIN if it is. 
			//Compare to see if any states are empty.
			if (div == 0) {
				if (strcmp(familyName, "") == 0 || strcmp(givenName, "")==0) {
					value = true;
				}
				else {
					value = false;
				}		
			}
			else {
				value = true;
			}
		}

		return value;
	}

	void CRA_Account::display() const {

		//Display each values
		cout << "Family Name: " << familyName << endl;
		cout << "Given Name : " << givenName << endl;
		cout << "CRA Account: " << sin << endl;

		for (int cnt = 0; cnt < CRA_Account::cnt; cnt++) {
			
			if (balance[cnt] > 2) {
				cout << "Year " << "(" << year[cnt] << ")" << " balance owing: " << fixed << setprecision(2) << balance[cnt] << endl;
			}
			else if (balance[cnt] < -2) {
				double refund = balance[cnt] + -(balance[cnt] * 2);
				cout << "Year " << "(" << year[cnt] << ")" << " refund due: " << fixed << setprecision(2) << refund << endl;
			}
			else if (balance[cnt] < 2 && balance[cnt] > -2) {
				cout << "Year " << "(" << year[cnt] << ")" << " No balance owing or refund due!" << endl;
			}
			else {
				cout << "Account object is empty!" << endl;
			}
			
		}
	}

	void CRA_Account::set(int n_year, double n_balance) {

		//Have a counter till the max_number_of_years is achieved. If not store each value. 
		if (cnt != 4) {
			year[cnt] = n_year;
			balance[cnt] = n_balance;

			cnt++;
		}

		else {
			cout << "Invalid! Tax return is full." << endl;
		}
	}
	
}