#ifndef __PERSON__
#define __PERSON__

// ----- include -----

#include <string>

using std::string;

struct Person
{
	// ----- constructor -----

	Person(const string &name, const string &address) : name(name), address(address) {}
	Person() : Person("nobody", "nowhere") {}
	Person(const string &name) : Person(name, "nowhere") {}

	// ----- member -----

	string sayToYou(const Person &);
	inline string getName() const { return name; }
	inline string getAddress() const { return address; }
	inline Person &setName(const string name)
	{
		this->name = name; 
		return *this;
	}
	inline Person &setAddress(const string address)
	{
		this->address = address; 
		return *this;
	}

	// ----- friend function -----

	friend string sayHello(Person &);

private:
	string name;
	string address;
};

#endif