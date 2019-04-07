#include <iostream>
#include <string>
#include <cassert>

#include "AppleProduct.h"
#include "AppleStore.h"

using namespace std;

int main()
{
	// test code 


	cs31::AppleProduct p;
	assert(p.getCost() == 0.0);
	assert(p.getKind() == cs31::AppleProduct::Kind::NOTSPECIFIED);
	assert(p.getColor() == "");
	assert(p.getVersion() == "");

	cs31::AppleProduct p1(cs31::AppleProduct::Kind::IPHONE, "8", "Space Grey", 699.00);
	assert(std::to_string(p1.getCost()) == "699.000000");
	assert(p1.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(p1.getColor() == "Space Grey");
	assert(p1.getVersion() == "8");

	cs31::AppleProduct p2(cs31::AppleProduct::Kind::IPAD, "Pro", "Silver", 649.00);
	assert(std::to_string(p2.getCost()) == "649.000000");
	assert(p2.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(p2.getColor() == "Silver");
	assert(p2.getVersion() == "Pro");

	cs31::AppleProduct p3(cs31::AppleProduct::Kind::WATCH, "1", "BLACK", 249.00);
	assert(std::to_string(p3.getCost()) == "249.000000");
	assert(p3.getKind() == cs31::AppleProduct::Kind::WATCH);
	assert(p3.getColor() == "BLACK");
	assert(p3.getVersion() == "1");

	cs31::AppleProduct p4(cs31::AppleProduct::Kind::IPHONE, "X", "BLACK", 999.00);
	assert(std::to_string(p4.getCost()) == "999.000000");
	assert(p4.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(p4.getColor() == "BLACK");
	assert(p4.getVersion() == "X");

	cs31::AppleStore store;
	cs31::AppleProduct iphone8_64 = store.buyiPhone8("Space Grey", 64);
	assert(std::to_string(iphone8_64.getCost()) == "699.000000");
	assert(iphone8_64.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8_64.getColor() == "Space Grey");
	assert(iphone8_64.getVersion() == "8");

	cs31::AppleStore store1;
	cs31::AppleProduct buywatch_1 = store1.buyWatch1("White");
	assert(std::to_string(buywatch_1.getCost()) == "249.000000");
	assert(buywatch_1.getKind() == cs31::AppleProduct::Kind::WATCH);
	assert(buywatch_1.getColor() == "White");
	assert(buywatch_1.getVersion() == "1");

	cs31::AppleStore store2;
	cs31::AppleProduct buywatch_3 = store2.buyWatch3("BLUE");
	assert(std::to_string(buywatch_3.getCost()) == "329.000000");
	assert(buywatch_3.getKind() == cs31::AppleProduct::Kind::WATCH);
	assert(buywatch_3.getColor() == "BLUE");
	assert(buywatch_3.getVersion() == "3");

	cs31::AppleStore store3;
	cs31::AppleProduct ipad = store.buyiPad("Green", 32);
	assert(std::to_string(ipad.getCost()) == "329.000000");
	assert(ipad.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipad.getColor() == "Green");
	assert(ipad.getVersion() == "");

	cs31::AppleStore store4;
	cs31::AppleProduct ipad_2 = store.buyiPad("Purple", 128);
	assert(std::to_string(ipad_2.getCost()) == "429.000000");
	assert(ipad_2.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipad_2.getColor() == "Purple");
	assert(ipad_2.getVersion() == "");

	cs31::AppleStore store5;
	cs31::AppleProduct ipad_pro = store.buyiPadPro("Gold", 64);
	assert(std::to_string(ipad_pro.getCost()) == "649.000000");
	assert(ipad_pro.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipad_pro.getColor() == "Gold");
	assert(ipad_pro.getVersion() == "Pro");

	cs31::AppleStore store6;
	cs31::AppleProduct ipad_pro_256 = store.buyiPadPro("LOL", 256);
	assert(std::to_string(ipad_pro_256.getCost()) == "799.000000");
	assert(ipad_pro_256.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipad_pro_256.getColor() == "LOL");
	assert(ipad_pro_256.getVersion() == "Pro");

	cs31::AppleStore store7;
	cs31::AppleProduct ipad_pro_512 = store.buyiPadPro("GOLDEN BROWN", 512);
	assert(std::to_string(ipad_pro_512.getCost()) == "999.000000");
	assert(ipad_pro_512.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipad_pro_512.getColor() == "GOLDEN BROWN");
	assert(ipad_pro_512.getVersion() == "Pro");

	cs31::AppleStore store8;
	cs31::AppleProduct iPhone_8 = store.buyiPhone8("Green", 64);
	assert(std::to_string(iPhone_8.getCost()) == "699.000000");
	assert(iPhone_8.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iPhone_8.getColor() == "Green");
	assert(iPhone_8.getVersion() == "8");

	cs31::AppleStore store9;
	cs31::AppleProduct iPhone_8_2 = store.buyiPhone8("Red", 256);
	assert(std::to_string(iPhone_8_2.getCost()) == "849.000000");
	assert(iPhone_8_2.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iPhone_8_2.getColor() == "Red");
	assert(iPhone_8_2.getVersion() == "8");

	cs31::AppleStore store10;
	cs31::AppleProduct iPhone_8_plus = store.buyiPhone8Plus("Purple", 64);
	assert(std::to_string(iPhone_8_plus.getCost()) == "799.000000");
	assert(iPhone_8_plus.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iPhone_8_plus.getColor() == "Purple");
	assert(iPhone_8_plus.getVersion() == "8Plus");

	cs31::AppleStore store11;
	cs31::AppleProduct iPhone_8_plus_256 = store.buyiPhone8Plus("Silver M", 256);
	assert(std::to_string(iPhone_8_plus_256.getCost()) == "949.000000");
	assert(iPhone_8_plus_256.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iPhone_8_plus_256.getColor() == "Silver M");
	assert(iPhone_8_plus_256.getVersion() == "8Plus");

	cs31::AppleStore store12;
	cs31::AppleProduct iPhone_X = store.buyiPhoneX("Grey", 64);
	assert(std::to_string(iPhone_X.getCost()) == "999.000000");
	assert(iPhone_X.getColor() == "Grey");
	assert(iPhone_X.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iPhone_X.getVersion() == "X");

	cs31::AppleStore store13;
	cs31::AppleProduct iPhone_X_256 = store.buyiPhoneX("Space Black", 256);
	assert(std::to_string(iPhone_X_256.getCost()) == "1149.000000");
	assert(iPhone_X_256.getColor() == "Space Black");
	assert(iPhone_X_256.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iPhone_X_256.getVersion() == "X");



	try
	{
		cs31::AppleStore s;
		cs31::AppleProduct iphone8 = s.buyiPhone8("Space Grey", 9999);
		assert(false);
		
		cs31::AppleStore s1;
		cs31::AppleProduct iphone8_64 = s1.buyiPhone8("Space Grey", 10000 );
		assert(false);

		cs31::AppleStore s3;
		cs31::AppleProduct iPad = s3.buyiPad("Space Grey", 64);
		assert(false);

	}
	catch (std::logic_error)
	{
		assert(true);
	}

	cout << "all tests passed!" << endl;

	return 0;

}