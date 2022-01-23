#include "Person.h"

/*
======================================
对另一个人问好

>> person: 问好的人
======================================
*/
string Person::sayToYou(const Person &person)
{
	string result = "hello, " + person.getName();
	return result;
}

string sayHello(Person &person)
{
	string hello = "你好, 我叫" + person.name + ", 我住在" + person.address;
	return hello;
}