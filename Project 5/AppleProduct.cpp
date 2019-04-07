#include <iostream>
#include <string>
#include <cassert>
#include "AppleProduct.h"
using namespace std;
namespace cs31 {

	AppleProduct::AppleProduct()														//creating the accessor functions
	{
		mCost = 0.0;
		mKind = NOTSPECIFIED;
		mColor = "";
		mVersion = "";
	}

	AppleProduct::AppleProduct(Kind kind, string version, string color, double cost)
	{
		mKind = kind;
		mColor = color;
		mCost = cost;
		mVersion = version;
	}

	AppleProduct::Kind AppleProduct::getKind()
	{

		return mKind;
	}

	string AppleProduct::getVersion()

	{
		return mVersion;
	}

	string AppleProduct::getColor()
	{
		return mColor;
	}

	double AppleProduct::getCost()
	{
		return mCost;

	}

}