#include <cassert>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isValidEbayListingString(string auctionstring);
bool listingSold(string auctionstring);
int howMuch(string auctionstring);
int watchers(string auctionstring);
int number(string s, int& startingposition);


int main()
{
	int i;
	double d;
	float f;
	string s;
	assert(isValidEbayListingString("") == false);
	assert(isValidEbayListingString(" ") == false);
	assert(isValidEbayListingString("a") == false);
	assert(isValidEbayListingString("z") == false);
	assert(isValidEbayListingString("0") == false);
	assert(isValidEbayListingString("l50") == true);
	assert(isValidEbayListingString("L50") == true);
	assert(isValidEbayListingString("L00050") == false);
	assert(isValidEbayListingString("L-1") == false);
	assert(isValidEbayListingString("Lambasdff ") == false);
	assert(isValidEbayListingString("L50L50L50l50") == false);
	assert(isValidEbayListingString("L100B99") == true);
	
	cerr << "All tests succeeded" << endl;

	return 0;
}
	
bool isValidEbayListingString(string auctionstring)
{
	bool result = true;
	size_t length = auctionstring.length();
	bool firsttimeThru = true;

	if (auctionstring.length() == 0)
	{
		result = false;
	}
else
	for (size_t i = 0; i < length; i++)    
	{
	char c = auctionstring[i];				
		switch (c)
		{
		case 'L':
		case 'l': 
			if (firsttimeThru)
		{
			int variable = 1;
			int value = number(auctionstring, variable);
			if (value != 0 && value != -1)
			{
				if (variable == auctionstring.length() - 1)
				{
					result = true;
				}
				else
				{
					for (i = variable + 1; i < length; i++)
					{
						if (firsttimeThru)
						{

							char d = auctionstring[i];
							char e = auctionstring[i + 1];
							char f = auctionstring[i - 1];
							switch (d)
							{
							case 'B':
							case 'b':
								for (i = variable; i < length; i++)
								{
									if (firsttimeThru)
									{
										int value = number(auctionstring, variable);
										if (value != 0 && value != -1)
										{

											if (variable == auctionstring.length() - 1)
											{
												result = true;
											}
											else
												for (i = variable; i < length; i++)
												{
													if (firsttimeThru)
													{
														char o = auctionstring[i];
														char p = auctionstring[i - 1];
														char t = auctionstring[i + 1];
														switch (o)
														{
														case 'B':
														case 'b':
															if (auctionstring[i + 1] != '+')
															{
																result = false;
																break;
															}

															for (i = variable; i < length; i++)
															{
																int variable;
																int value = number(auctionstring, variable);


															}



															break;
														case 'W':
														case 'w':
															for (i = variable; i < length; i++)
															{
																int W = 0;
																int U = 0;
																char m = auctionstring[i];
																switch (m)
																{
																case 'W':
																case 'w':
																	W = W + 1;
																	break;
																case 'U':
																case 'u':
																	U = U + 1;
																	break;
																default:
																	result = false;
																	break;
																}
																if (W > U)
																{
																	result = true;
																}
																if (U > W || U == W)
																{
																	result = false;
																	break;
																}




															}

														default:
															result = false;
															break;
														}

													}
													firsttimeThru = false;
												}



										}

									}
									firsttimeThru = false;
								}

								break;
							case 'W':
							case 'w':
								for (i = variable; i < length; i++)
								{
									int W = 0;
									int U = 0;
									if (W > U || W == U)
									{
										result = true;
									}
									if (U > W)
									{
										result = false;
										break;
									}
									char m = auctionstring[i];
									switch (m)
									{
									case 'W':
									case 'w':
										W = W + 1;
										break;
									case 'U':
									case 'u':
										U = U + 1;
										break;
									default:
										result = false;
										break;
									}

								}
								break;
							default:
								result = false;
								break;
							}
						}
						firsttimeThru = false;
					}
				}

				
			}
			else
			{	
				result = false;
			}
		}
			else
				{
				result = false;
				}
			break;
		default:
			result = false;
			break;
			}
			firsttimeThru = false;
		}
	return(result);
}

bool listingSold(string auctionstring)
{
	bool result = true;
	size_t length = auctionstring.length();
	for (size_t i = 0; i < length; i++)
	{
		int listingPrice = 0;
		int biddingPrice = 0;
		char c = auctionstring[i];
		char d = auctionstring[i - 1];
		char e = auctionstring[i + 1];
		switch (c)
		{
		case 'L':
		case 'l':
			for (size_t i = 1; i < length; i++)
				if (auctionstring[i] >= '1' && auctionstring[i] <= '9')
				{
					int Lcarry = 0;
					while (auctionstring[i] >= '0' && auctionstring[i] <= '9')
					{
						int value = auctionstring[i] - '0';
						Lcarry = (Lcarry * 10) + value;
						i = i + 1;
					}
					listingPrice = Lcarry + listingPrice;
				}
			break;
		case 'B':
		case 'b':
		case '+':
			for (size_t i = 1; i < length; i++)
				if (auctionstring[i] >= '1' && auctionstring[i] <= '9')
				{
					int carry = 0;
					while (auctionstring[i] >= '0' && auctionstring[i] <= '9')
					{
						int value = auctionstring[i] - '0';
						carry = (carry * 10) + value;
						i = i + 1;
					}
					biddingPrice = carry + biddingPrice;
				}
			break;
		default:
			break;

			if (listingPrice > biddingPrice || listingPrice == biddingPrice)
			{
				result = false;
			}
			if (listingPrice < biddingPrice)
			{
				result = true;
			}

		}
	}return (result);



}

int howMuch(string auctionstring)
{
	int result = 0;
	size_t length = auctionstring.length();

		for (size_t i = 0; i < length; i++)
		{
			int biddingPrice = 0;
			char c = auctionstring[i];
			char d = auctionstring[i - 1];
			char e = auctionstring[i + 1];
			switch (c)
			{
			case 'B':
			case 'b':
			case '+':
				for (size_t i = 1; i < length; i++)
					if (auctionstring[i] >= '1' && auctionstring[i] <= '9')
					{
						int carry = 0;
						while (auctionstring[i] >= '0' && auctionstring[i] <= '9')
						{
							int value = auctionstring[i] - '0';
							carry = (carry * 10) + value;
							i = i + 1;
						}
						biddingPrice = carry + biddingPrice;
					}
				break;
			default:
				break;
			}
			result = biddingPrice;
		}
	}
	return (result);
}




int watchers(string auctionstring)
{
	int result = 0;
	size_t length = auctionstring.length();
	int numberofW = 0;
	int numberofU = 0;
	for (size_t i = 0; i < length; i++)
	{
		char c = auctionstring[i];
		char d = auctionstring[i - 1];
		char e = auctionstring[i + 1];
		switch (c)
		{
		case 'W':
		case 'w':
			numberofW = numberofW + 1;
			break;
		case 'U':
		case 'u':
			numberofU = numberofU + 1;
			break;
		default:
			break;
		}
		int result = numberofW - numberofU;
	}
	return (result);
}





int number(string s, int& startingposition)
{
	int result = 0;		
	if (s[startingposition] >= '1' && s[startingposition] <= '9')
		{ 
		while (s[startingposition] >= '0' && s[startingposition] <= '9')
			{
				int value = s[startingposition] - '0';
				result = (result * 10) + value;			
				startingposition = startingposition + 1;
			}
		}
		else
		{ 
		result = -1;
		}
return(result);
}


