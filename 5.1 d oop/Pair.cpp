#include "Pair.h"

using namespace std;

void Pair::setGrn(long value)
{
	if (value < 0)
		throw Exception("\nGrn must be > 0\n");
	else
		grn = value;
}
void Pair::setKop(unsigned long value)
{
	if (value < 0)
		throw Exception("\nKop must be > 0\n");

	else
		kop = value;
}
Pair::Pair(const long x, const unsigned long y) : grn(x), kop(y)
{ }

Pair::Pair(const Pair& x)
{
	grn = x.grn;
	kop = x.kop;
}

Pair::~Pair(void)
{}

Pair::operator string() const
{
	stringstream ss;
	
	ss << grn << ", " << kop;
	
	return ss.str();
}
ostream& operator <<(ostream& out, const Pair& x)
{
	out << (string)x;
	return out;
}
istream& operator >>(istream& in, Pair& x)
{
	long grns;
	unsigned long kops;

	cout << "Grn = ";cin >> grns;
	cout << "Kop = ";cin >> kops;
	
	if(grns < 0 || kops < 0)
		throw nException("\nGrn and Kop must be > 0\n");
	
	else
	{
		x.setGrn(grns);
		x.setKop(kops);
	}
	return in;
}