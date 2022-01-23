#include "Screen.h"
#include <iostream>

using std::cout;
using std::endl;

/*
=====================================
��ȡָ��λ�õ��ַ�

>> ht: ����
>> wd: ���
=====================================
*/
inline char Screen::get(Screen::pos ht, Screen::pos wd) const
{
	auto row = ht * width;
	return content[row + wd];
}

/*
=====================================
�ƶ����

>> r: ����
>> c: ���
=====================================
*/
Screen &Screen::move(const Screen::pos r, const Screen::pos c)
{
	auto row = r * width;
	cursor = row + c;
	return *this;
}

/*
=====================================
���ù������λ�õ��ַ�

>> c:  ���õ��ַ�
=====================================
*/
Screen &Screen::set(const char &c)
{
	content[cursor] = c;
	return *this;
}

/*
=====================================
����ָ��λ�õ��ַ�

>> ht: ����
>> wd: ���
>> c:  ���õ��ַ�
=====================================
*/
inline Screen &Screen::set(const pos &ht, const pos &wd, const char &c)
{
	cursor = ht * width + wd;
	content[cursor] = c;
	return *this;
}

inline void Screen::do_display(ostream &os) const { os << content; }

/*
=====================================
��ӡ�������λ�õ��ַ�(���س�������)
=====================================
*/
const Screen &Screen::display() const
{
	do_display(cout);
	return *this;
}

/*
=====================================
��ӡ�������λ�õ��ַ�(������ͨ����)
=====================================
*/
Screen &Screen::display()
{
	do_display(cout);
	return *this;
}
