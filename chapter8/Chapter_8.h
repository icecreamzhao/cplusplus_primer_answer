#ifndef __CHAPTER_EIGHT__
#define __CHAPTER_EIGHT__

// ----- include -----

#include <iostream>

// ----- using -----

using std::cin;
using std::istream;
using std::endl;

class Chapter_eight
{
public:
	// ----- example -----

	void setCinState();
	void process_input(istream &);
	void overwrite_file();
	void isstream();

	// ----- practice -----

	istream &p_8p1p2_8p1_f(istream &);
	void p_8p1p2_8p1();
	void p_8p2p1_8p4();
	void p_8p2p1_8p5();
	void p_8p2p1_8p6();
	void p_8p2p2_8p7();
	void p_8p2p2_8p8();
	void p_8p3p1_8p9();
	void p_8p3p1_8p10();
	void p_8p3p2_8p13();

	void runAll();
};
#endif
