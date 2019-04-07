#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int findMinimum(const string array[], int n);
int countAllPunctuation(const string array[], int n);
int countFloatingPointValues(const string array[], int n);
int removeDuplicatedValues(string array[], int  n);
int replaceAll(string array[], int n, char letterToReplace, char letterToFill);
int shiftRight(string array[], int n, int amount, string   placeholder);




int main()
{


}

int findMinimum(const string array[], int n)

{
	int result = 0; // sets the first element as minimum
	if (n <= 0)
	{
		result = -1;
	}
	for (int i = 0; i < n; i++) // checks the rest of the array
	{

		if (array[i] < array[result])	//if the array is less than the current minimum, it become the new minimum
		{
			result = i;
		}
	}
	return(result);
}

	
int countAllPunctuation(const string array[], int n)
{
	int totalofPuntuation = 0;				// declares the amount of punctuation
	if (n <= 0)
	{
		return (-1);
	}
	else
	{
		for (int i = 0; i < n; i++)				//checks every element in the array
		{
			string s = array[i];				//allows us to use the string within the element
			for (int k = 0; k < s.length(); k++)		// looks through every single character 
			{
				string s = array[i];
				char c = s[k];						// check if it is a punctuation or not and then adds 1 to the counter
				switch (c)
				{
				case '.':
				case ',':
				case '!':
				case ';':
				case '-':
				case '/':
				case ':':
				case '?':
				case '"':
				case '\'':
					totalofPuntuation = totalofPuntuation + 1;
					break;
				default:
					break;
				}
			}

		}

		
	}return(totalofPuntuation);
}

int countFloatingPointValues(const string array[], int n)
{
	int numberfloatingpointValues = 0;
	if (n <= 0)
	{
		return (-1);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			string s = array[i];
			int numberofDecimals = 0;					//only allowed to have 0 or 1 decimal 
			int numberofBad = 0;						//counter for character other than a number or decimal
			for (int k = 0; k < s.length(); k++)
			{
				string s = array[i];
				char c = s[k];
				switch (c)
				{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					break;
				case '.':
					numberofDecimals = numberofDecimals + 1;
					break;
				default:
					numberofBad = numberofBad + 1;
					break;
				}
			}
			if (numberofDecimals <= 1 && numberofBad == 0)      //only allowed to have 0 or 1 decimal; no other character other than a number or decimal
			{
				numberfloatingpointValues = numberfloatingpointValues + 1;
			}
		}
	}
	return (numberfloatingpointValues);
}

int removeDuplicatedValues(string array[], int  n)
{
	int result = 0;
	if (n <= 0)
	{
		result = -1;
	}
	else
	{
		for (int i = 0; i < n; i++)								//this line of code counts the amount of doubles and the amount we need to replace a string
		{
			for (int j = i + 1; j < n; j++)
			{
				if (array[i] == array[j] && array[j] != "")
				{
					result = result + 1;
					array[j] = "";
				}
			}
		}
	}

	for (int i = 0; i < n; i++)								//allows us to move the string forward to the front
	{
		for (int j = i + 1; j < n; j++)
			if (array[i] == "" && array[j] != "")
			{
				array[i] = array[j];
				array[j] = "";
			}
	}

	
	return (result);
}

int replaceAll(string array[], int n, char letterToReplace, char letterToFill)
{
	int result = 0;
	if (n <= 0)
	{
		result = -1;
	}
	else
	{
		for (int i = 0; i < n; i++)							//check every element in the array
		{
			string s = array[i];							// allows us to use the string within the element and check if we need to change the letter
			for (int k = 0; k < s.length(); k++)
			{
				if (s[k] == letterToReplace)
				{
					s[k] = letterToFill;
					array[i] = s;
					result = result + 1;
				}
			}
		}
	}

	
	return(result);
}

int shiftRight(string array[], int n, int amount, string   placeholder)
{	
	if (n < 0)
	{
		return (-1);
	}
	if ((amount < 0) || (amount > n)) 
	{
		return(-1);
	}
	if ((n == 0) && (amount == 0)) 
	{
		return(-1);
	}
	for (int i = 0; i < n - 1; i++)					// checking array
	{ 
		array[n - 1 - i] = array[n - 1 - amount - i];
		if (n - 1 - amount - i == 0)					// if finished looping through the array we get out of the loop
			break;
	}
	for (int i = 0; i < amount; i++) {				// change  the elements with the desired text
		array[i] = placeholder;
	}
	for (int i = 0; i < n; ++i) {
		cerr << array[i] << " ";
	}
	return(n - amount);
}
