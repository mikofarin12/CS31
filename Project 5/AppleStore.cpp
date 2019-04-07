#include <iostream>
#include <string>
#include <cassert>
#include "AppleProduct.h"
#include "AppleStore.h"
using namespace std;


namespace cs31 {
	AppleStore::AppleStore()														// creating the modifiers to get the correct Version, Kind, Color and Price of the AppleProduct
	{
	}

	AppleProduct AppleStore::buyWatch1(string color)
	{
		AppleProduct buywatch_1(AppleProduct::Kind::WATCH, "1", color, 249.00);
		return buywatch_1;
	}

	AppleProduct AppleStore::buyWatch3(string color)
	{
		AppleProduct buywatch_3(AppleProduct::Kind::WATCH, "3", color, 329.00);
		return buywatch_3;
	}

	AppleProduct AppleStore::buyiPad(string color, int gigabytes)
	{
		double cost;
		if (gigabytes == 32)
		{
			cost = 329.00;
		}
		else if (gigabytes == 128)
		{
			cost = 429.00;
		}
		else
		{
			throw logic_error("error");
		}

		AppleProduct ipad(AppleProduct::Kind::IPAD, "", color, cost);
		return ipad;
	}

	AppleProduct AppleStore::buyiPadPro(string color, int gigabytes)
	{
		double cost;
		if (gigabytes == 64)
		{
			cost = 649.00;
		}
		else if (gigabytes == 256)
		{
			cost = 799.00;
		}
		else if (gigabytes == 512)
		{
			cost = 999.00;
		}
		else
		{
			throw logic_error("error");
		}

		AppleProduct ipadpro(AppleProduct::Kind::IPAD, "Pro", color, cost);
		return ipadpro;

	}

	AppleProduct AppleStore::buyiPhoneX(string color, int gigabytes)
	{
		double cost;
		if (gigabytes == 64)
		{
			cost = 999.00;
		}
		else if (gigabytes == 256)
		{
			cost = 1149.00;
		}
		else
		{
			throw logic_error("error");
		}

		AppleProduct iphone_X(AppleProduct::Kind::IPHONE, "X", color, cost);
		return iphone_X;
	}

	AppleProduct AppleStore::buyiPhone8(string color, int gigabytes)
	{
		double cost;
		if (gigabytes == 64)
		{
			cost = 699.00;
		}
		else if (gigabytes == 256)
		{
			cost = 849.00;
		}
		else
		{
			throw logic_error("error");
		}

		AppleProduct iphone_8(AppleProduct::Kind::IPHONE, "8", color, cost);
		return iphone_8;
	}

	AppleProduct AppleStore::buyiPhone8Plus(string color, int gigabytes)
	{
		double cost;
		if (gigabytes == 64)
		{
			cost = 799.00;
		}
		else if (gigabytes == 256)
		{
			cost = 949.00;
		}
		else
		{
			logic_error("error");
		}

		AppleProduct iphone_8_plus(AppleProduct::Kind::IPHONE, "8Plus", color, cost);
		return iphone_8_plus;
	}



}