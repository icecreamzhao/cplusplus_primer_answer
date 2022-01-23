#ifndef __WINDOW_MGR__
#define __WINDOW_MGR__

// ----- include -----

#include <vector>
//#include "Screen.h"

// ----- using -----

using std::vector;

// ----- class define -----

class Screen;

class Window_mgr
{
public:
	using screenIndex = vector<Screen>::size_type;
	void clear(screenIndex);

private:
	vector<Screen> screens{ Screen(5, 5, 'X') };
};

#endif
