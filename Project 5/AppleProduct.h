#pragma once
#ifndef APPLEPRODUCT_h
#define APPLEPRODUCT_h  
#include <string>  
using namespace std;
namespace cs31			//creating the correct namespace
{
	class AppleProduct {
	public:
		enum Kind { NOTSPECIFIED, IPHONE, IPAD, WATCH };						//creating a new enumeration
		AppleProduct();															//intializing the variables 
		AppleProduct(Kind kind, string version, string color, double cost);
		Kind getKind();															//public member functions
		string getVersion();
		string getColor();
		double getCost();


	private:
		string mVersion;														//private memeber functions
		string mColor;
		double mCost;
		Kind mKind;
	};
}
#endif