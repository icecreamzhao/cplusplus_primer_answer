#include "Person.h"

/*
======================================
����һ�����ʺ�

>> person: �ʺõ���
======================================
*/
string Person::sayToYou(const Person &person)
{
	string result = "hello, " + person.getName();
	return result;
}

string sayHello(Person &person)
{
	string hello = "���, �ҽ�" + person.name + ", ��ס��" + person.address;
	return hello;
}