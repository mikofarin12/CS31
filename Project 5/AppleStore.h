#pragma once
#ifndef APPLESTORE_h
#define APPLESTORE_h  
#include <string>  
#include "AppleProduct.h"

using namespace std;
namespace cs31 {
	class AppleStore {

	public:
		AppleStore();														//using a constructer to initialize

		AppleProduct buyWatch1(string color);								//public memeber functions to call to get the correct AppleProduct
		AppleProduct buyWatch3(string color);

		AppleProduct buyiPad(string color, int gigabytes);
		AppleProduct buyiPadPro(string color, int gigabytes);

		AppleProduct buyiPhoneX(string color, int gigabytes);
		AppleProduct buyiPhone8(string color, int gigabytes);
		AppleProduct buyiPhone8Plus(string color, int gigabytes);
	};
}
#endif
