#ifndef __SCREEN__
#define __SCREEN__

// ----- include -----

#include <string>
#include <iostream>
#include <vector>

// ----- using -----

using std::string;
using std::ostream;
using std::vector;

// ----- 窗口管理器 ----

class Screen;

class Window_mgr
{
public:
	using screenIndex = vector<Screen>::size_type;
	void clear(screenIndex);
};

class Screen
{
public:
	using pos = string::size_type;

	// ----- friend member -----

	//friend class Window_mgr;
	friend void Window_mgr::clear(Window_mgr::screenIndex);

	// ----- constructor -----

	Screen() = default;
	Screen(const pos ht, pos wd, char c) : height(ht), width(wd), content(ht * wd, c) {}
	Screen(const pos ht, pos wd) : height(ht), width(wd), content(ht * wd, ' ') {}

	// ----- member function -----

	/*
	=====================================
	获取光标所在字符
	=====================================
	*/
	char get() const { return content[cursor]; }
	char get(pos ht, pos wd) const;
	Screen &move(const pos r, const pos c);
	Screen &set(const char &);
	Screen &set(const pos &ht, const pos &wd, const char &c);
	const Screen &display() const;
	Screen &display();

private:
	pos width = 0, height = 0, cursor = 0;
	string content = "";
	void do_display(ostream &) const;
};


#endif
