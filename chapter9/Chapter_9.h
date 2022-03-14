#ifndef __CHAPTER_NINE__
#define __CHAPTER_NINE__

#include <vector>
#include <forward_list>
#include <string>

using std::vector;
using std::string;
using std::forward_list;

class Chapter_nine
{
public:
	// ----- example -----

	void containerTest();
	void assignTest();
	void swapTest();
	void insertTest();
	void frontAndBackTest();
	void forward_list_earse();
	void insert_and_earse();
	void capacityAndShrink();
	void stackAdapter();
	
	// ----- practice -----

	void p_9p2_9p2();
	bool p_9p2p1_9p4(vector<int>::iterator beg, vector<int>::const_iterator last, const int i );
	vector<int>::iterator p_9p2p1_9p5(vector<int>::iterator beg, vector<int>::const_iterator last, const int i );
	void p_9p2p4_p9p11();
	void p_9p2p4_p9p13();
	void p_9p2p5_p9p14();
	void p_9p2p7_p9p15();
	void p_9p2p7_p9p16(); 
	void p_9p3p1_p9p18();
	void p_9p3p1_p9p19();
	void p_9p3p1_p9p20();
	void p_9p3p2_p9p23();
	void p_9p3p2_p9p24();
	void p_9p3p3_p9p25();
	void p_9p3p3_p9p26();
	void p_9p3p4_p9p28(forward_list<string>, const string, const string);
	void p_9p3p6_p9p31();
	void p_9p3p6_p9p34();
	void p_9p4_p9p35();
	void p_9p4_p9p36();
	void p_9p4_p9p37();
	void p_9p4_p9p38();
	void p_9p6_p9p52();

	void runAll();
};

#endif
