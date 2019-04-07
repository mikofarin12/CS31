#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Donor Name: " ;	//To take a valid donor name
	string donerName;
	getline(cin, donerName);

	cout << "Gender: " ;	//To know the gender of the donor and to create the correct parameters for the specified gender
	string gender;
	getline(cin, gender);

	cout << "Age: " ;		//To know the age of the donor	
	double personsAge;
	cin >> personsAge;
	cin.ignore(100000, '\n');

	cout << "Weight: ";		// To know the weight of the donor
	double personsWeight;
	cin >> personsWeight;
	cin.ignore(100000, '\n');
	
	cout << "Height: ";		//To get the height of the donor
	double personsHeight;
	cin >> personsHeight;
	cin.ignore(100000, '\n');

	cout << "---";

	if (donerName == "")	//If an empty string is put in, it will tell the user to input a valid string
	{
		cout << "You must enter a valid name." << endl ;
			return 0;
	}		

	if (gender != "Male" && gender != "Female" && gender != "Queer" && gender != "Different" && gender != "Trans Male" && gender != "Trans Female")		// if the gender inputed is not one of the valid gender, it will tell the user to correctly put a gender
	{
		cout << "You must enter a valid gender." << endl;
		return 0;
	}

	if (personsAge < 1)		// if a person enters an age that is less than 1, the user will be told to enter a valid age
	{
		cout << "You must enter a valid age" << endl;
		return 0;
	}

	if (personsWeight < 1)	// if the person enters an weight not valid it will tell the user to enter a valid weight
	{
		cout << "You must enter a valid weight." << endl;
		return 0;
	}

	if (personsHeight < 1)		// if the person enters an height not valid it will tell the user to enter a valid height
	{
		cout << "You must enter a valid height." << endl;
		return 0;
	}
	
	if (personsAge < 16) //if the person is less than 16 years old the person cannot donate

	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (personsWeight < 110)	// if the person weight less than 110 pounds the person cannot donate
	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Male" && personsAge >= 16 && personsAge <= 22 && personsWeight > 110 && personsHeight < 60) //if male is between 16-22 years old and under 5', cannot donate
	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Male" && personsAge >= 16 && personsAge <= 22 && personsWeight > 110 && personsHeight >= 60) //if male is between 16-22 years old and  5' or more, can donate
	{
		cout << "Yes, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Male" && personsAge > 22 && personsWeight > 110) //otherwise can donate
	{
		cout << "Yes, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}
	
	if (gender == "Female" && personsAge >= 16 && personsAge <= 22 && personsWeight > 110 && personsHeight < 58) // if a female is between 16-22 years old and under 4'10, cannot donate
	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Female" && personsAge >= 16 && personsAge <= 22 && personsWeight > 145 && personsHeight == 58) // if a female is between 16-22 years old and is 4'10, she must weigh more that 145, can donate
	{
		cout << "Yes, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}
	if (gender == "Female" && personsAge >= 16 && personsAge <= 22 && personsWeight < 145 && personsHeight == 58)
	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Female" && personsAge >= 16 && personsAge <= 22 && personsWeight >= 142 && personsHeight == 59) // if a female is between 16-22 years old and is 4'11, she must weigh more that 142, can donate
	{
		cout << "Yes, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Female" && personsAge >= 16 && personsAge <= 22 && personsWeight < 142 && personsHeight == 59) // if a female is between 16-22 years old and is 4'11, she must weigh more that 142, can donate
	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Female" && personsAge >= 16 && personsAge <= 22 && personsWeight > 110 && personsHeight >= 60)// if a female is between 16-22 years old and is 5', can donate
	{
		cout << "Yes, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Trans Male" && personsAge < 23 && personsAge > 16 && personsWeight > 110) // if a trans male/female and the person is between 16-22 years of age, they cannot donate.
	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Trans Female" && personsAge < 23 && personsAge > 16 && personsWeight > 110) // if a trans female and the person is between 16-22 years of age, they cannot donate.
	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Queer" && personsAge < 23 && personsAge > 16 && personsWeight > 110) // if a Queer and the person is between 16-22 years of age, they cannot donate.
	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Different" && personsAge < 23 && personsAge > 16 && personsWeight > 110) // if Different and the person is between 16-22 years of age, they cannot donate.
	{
		cout << "No, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Trans Male" && personsAge > 22 && personsWeight > 110) // if a trans male/female and the person is older than 22, they can donate.
	{
		cout << "Yes, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}

	if (gender == "Trans Female"  && personsAge > 22 && personsWeight > 110) // if a trans male/female and the person is older than 22, they can donate.
	{
		cout << "Yes, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}
	
	if (gender == "Queer" && personsAge > 22 && personsWeight > 110) // if a Queer and the person is older than 22, they can donate.
	{
		cout << "Yes, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}
	
	if (gender == "Different" && personsAge > 22 && personsWeight > 110) // if Different and the person is older than 22, they can donate.
	{
		cout << "Yes, " << donerName << " you cannot donate blood." << endl;
		return 0;
	}











}
