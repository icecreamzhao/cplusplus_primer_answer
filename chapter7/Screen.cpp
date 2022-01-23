#include "Screen.h"
#include <iostream>

using std::cout;
using std::endl;

/*
=====================================
获取指定位置的字符

>> ht: 行数
>> wd: 宽度
=====================================
*/
inline char Screen::get(Screen::pos ht, Screen::pos wd) const
{
	auto row = ht * width;
	return content[row + wd];
}

/*
=====================================
移动光标

>> r: 行数
>> c: 宽度
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
设置光标所在位置的字符

>> c:  设置的字符
=====================================
*/
Screen &Screen::set(const char &c)
{
	content[cursor] = c;
	return *this;
}

/*
=====================================
设置指定位置的字符

>> ht: 行数
>> wd: 宽度
>> c:  设置的字符
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
打印光标所在位置的字符(返回常量引用)
=====================================
*/
const Screen &Screen::display() const
{
	do_display(cout);
	return *this;
}

/*
=====================================
打印光标所在位置的字符(返回普通引用)
=====================================
*/
Screen &Screen::display()
{
	do_display(cout);
	return *this;
}
