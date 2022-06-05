#pragma once
#include <string>
#include <sstream>

using namespace std;

class Exception : public exception
{
private:
	string message;
public:
	Exception(string msg) : message(msg) {}
	string getMessage() { return message; }
};