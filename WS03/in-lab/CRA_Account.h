#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

/*
Workshop 3

Name: Callum Dodge
Date: May 25,2018
Section: D

*/

#include <iostream>
#include <cstring>

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {
		char familyName[max_name_length];
		char givenName[max_name_length];
		int sin;

	public:

		CRA_Account();

		void set(const char*, const char*, int);
		bool isEmpty() const;
		void display() const;
	};

}

#endif // !CRA_ACCOUNT_H