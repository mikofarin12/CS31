//
//  Cell.h
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef CELL_H
#define CELL_H

#include "NumberSet.h"

#include <string>

namespace cs31
{

	class Cell
	{
	public:
		Cell();

		void setValue(int value);       /* change this cell's value */
		std::string stringify() const;  /* stringify this cell      */
		int  getValue() const;         /* return this cell's value */


									  // called before the Board attempts to change a cell's value
									  // when true, the Board will change the cell's value to thisvalue
		bool isOKToSetValue(int thisvalue, NumberSet box, NumberSet row, NumberSet column) const;

		bool isValueOK(int thisvalue, NumberSet box, NumberSet row, NumberSet column) const; //function to check if a value entered is okay

		/* TODO: CS31 Students must implement this operation */
		bool isImmutable() const;      /* can this cell be changed? */
									   /* TODO: CS31 Students must implement this operation */
		void setImmutable(bool i);   /* update this cell's immutability */
	private:
		int mValue;      /* cell's value 1-9 or 0 if not yet set */
		bool mImmutable; /* if true, this cell's value cannot be changed */
	};
}

#endif
