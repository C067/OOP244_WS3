

/*
Workshop 3

Name: Callum Dodge
Date: May 25,2018
Section: D

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict{

	CRA_Account::CRA_Account() {
		*familyName = '\0';
		*givenName = '\0';
		sin = 0;
	}

	void CRA_Account::set(const char* n_familyName, const char* n_givenName, int n_sin) {

		bool value = isEmpty();

		if (value == true) {

			strcpy(familyName, n_familyName);
			strcpy(givenName, n_givenName);
			sin = n_sin;

		}

		else {
			*familyName = '\0';
			*givenName = '\0';
			sin = 0;
		}

	}

	bool CRA_Account::isEmpty() const {

		if (sin < sict::min_sin || sin > sict::max_sin) {
			return true;
		}

		else {
			return false;
		}

	}

	void CRA_Account::display() const {

		cout << "Family Name: " << familyName << endl;
		cout << "Given Name: " << givenName << endl;
		cout << "CRA Account: " << sin << endl;

	}
	
}