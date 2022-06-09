#include "Money.h"
#include <string>
#include <sstream>

using namespace std;

Money::Money(const long grn, const unsigned long kop)
{
	if (grn < 0 || kop < 0)
		throw invalid_argument("this values cannot be negative");
	else
	{
		long a = grn;
		unsigned long b = kop;
		while (b > 99)
		{
			b -= 100;
			a++;
		}
		setGrn(a);
		setKop(b);
	}
}
Money::Money(double x)
{
	if (x < 0)
		throw invalid_argument("this value cannot be negative");
	else
	{
		long a = (long)x;
		x -= a;
		x *= 100;
		unsigned long b = (unsigned long)x;
		while (b > 99)
		{
			b-=100;
			a++;
		}
		setGrn(a);
		setKop(b);
	}
}
Money::Money(const Money& x)
{
	int grn = x.getGrn();
	int kop = x.getKop();

	while (kop > 99)
	{
		kop -= 100;
		grn++;
	}
	while (kop < -99)
	{
		kop += 100;
		grn--;
	}
	setGrn(grn);
	setKop(kop);
}
Money::~Money(void)
{}

Money operator -(const Money& first, const Money& second)
{
	Money t;
	
	
	if ((first.getGrn() > second.getGrn()) && ((first.getKop() > second.getKop())))
	{
		long grns  = first.getGrn() - second.getGrn();
		unsigned long kops = first.getKop() - second.getKop();
		t.setGrn(grns);
		t.setKop(kops);
	}
	else
		if (first.getGrn() < second.getGrn())
		{
			long grns = 0;
			unsigned long kops = 0;
			t.setGrn(grns);
			t.setKop(kops);
		}
		else
			if ((first.getGrn() > second.getGrn()) && (first.getKop() < second.getKop()))
			{
				long grns = (first.getGrn() - 1) - second.getGrn();
				long unsigned kops = 100 - (second.getKop() - first.getKop());
				t.setGrn(grns);
				t.setKop(kops);
			}
	return t;

}
Money operator *(const Money& sum, const double n)
{
	Money t;
	long grn;
	unsigned long kop;
	grn = (sum.getGrn() * n);
	kop = (sum.getKop() * n);
	while (kop > 99)
	{
		kop -= 100;
		grn++;
	}
	t.setGrn(grn);
	t.setKop(kop);
	
	return t;
}

bool Money::Init(int x, int y)
{
	if (x >= 0 && y >= 0)
	{
		setGrn(x);
		setKop(y);
		return true;
	}
	else
		return false;
}

bool Money::operator ==(const Money& x) const
{
	if ((this->getGrn() == x.getGrn()) && (this->getKop() == x.getKop()))
		return true;
	else
		return false;
}
bool Money::operator >(const Money& x) const
{
	if ((this->getGrn() > x.getGrn()) || (this->getGrn() == x.getGrn() && this->getKop() > x.getKop()))
		return true;
	else
		return false;
}
bool Money::operator < (const Money& x)const
{
	if ((this->getGrn() < x.getGrn()) || (this->getGrn() == x.getGrn() && this->getKop() < x.getKop()))
		return true;
	else
		return false;
}
Money& Money::operator ++()
{
	int grn = this->getGrn();
	int kop = this->getKop();
	
	grn++;
	kop++;
	
	this->setGrn(grn);
	this->setKop(kop);
	
	return *this;
}
Money& Money::operator --()
{
	int grn = this->getGrn();
	int kop = this->getKop();

	grn--;
	kop--;

	this->setGrn(grn);
	this->setKop(kop);

	return *this;
}
Money Money::operator ++(int)
{
	Money t(*this);
	int grn = this->getGrn();
	int kop = this->getKop();
	
	grn++;
	kop++;
	
	this->setGrn(grn);
	this->setKop(kop);
	
	return t;
}
Money Money::operator --(int)
{
	Money t(*this);
	int grn = this->getGrn();
	int kop = this->getKop();

	grn--;
	kop--;

	this->setGrn(grn);
	this->setKop(kop);

	return t;
}