#ifndef __PERSON_PHONE__
#define __PERSON_PHONE__

#include <vector>
#include <string>

using std::vector;
using std::string;

struct PersonInfo
{
	PersonInfo(string n) : name(n) {}
	PersonInfo() : PersonInfo("") {}

	string &getName() { return name; }
	vector<string> &getPhone() { return phone; }
	void setName(string name) { this->name = name; }
	void setPhone(vector<string> phone) { this->phone = phone; }

private:
	string name;
	vector<string> phone;
};
#endif
