#pragma once

#include "Pair.h"

class Money :
	public Pair
{
public:
	Money(const long grn = 0, const unsigned long kop = 0);
	Money(const Money&);
	Money(double x);
	~Money(void);

	friend Money operator -(const Money&, const Money&);
	friend Money operator *(const Money&, const double);

	bool operator ==(const Money&) const;
	bool operator >(const Money&) const;
	bool operator <(const Money&) const;
	bool Init(int, int);
	Money& operator ++();
	Money operator ++(int);
	Money& operator --();
	Money operator --(int);
	
};