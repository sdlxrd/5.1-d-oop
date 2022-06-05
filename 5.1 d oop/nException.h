#pragma once
#include <string>
#include <sstream>

using namespace std;

class nException
{
private:
	string message;
public:
	nException(string msg) : message(msg) {}
	string getMessage() { return message; }
};