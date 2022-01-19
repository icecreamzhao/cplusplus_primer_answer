#ifndef CHAPTER_SIX
#define CHAPTER_SIX

#include <string>
#include <vector>
#include <initializer_list>

using std::vector;
using std::string;
using std::initializer_list;

using arrP = string[10];

struct Chapter_six
{
	int fact(int &);
	inline bool isShorter(const string &, const string &);

	void p_6p1_6p3();
	void p_6p1_6p4();
	void p_6p1_6p5(const int &);
	int &p_6p1p1_6p7();
	void p_6p2p1_6p10(int *, int *);
	void p_6p2p1_6p12(int &, int &);
	void p_6p2p3_6p17_1(const string &);
	void p_6p2p3_6p17_2(string &);
	void p_6p2p3_6p17();
	bool p_6p2p3_6p18_compare(const int &, const int &);
	vector<int> &p_6p2p3_6p18_change_val(const int &, vector<int> &);
	void p_6p2p3_6p18();
	int p_6p2p4_6p21(const int *, const int);
	void p_6p2p4_6p22(int *&, int *&);
	void p_6p2p4_6p23(int, int *, int *);
	void p_6p2p6_6p27(initializer_list<int>(&));
	vector<int>::iterator p_6p3p2_6p33(vector<int>(&), vector<int>::iterator);
	string(&p_6p3p3_6p36(string(&)[10]))[10];
	arrP &p_6p3p3_6p37_typedef(arrP &);
	vector<int>::iterator p_6p5p3_6p47(vector<int>(&), vector<int>::iterator);
	int p_6p7_6p54_1(int, int);
	void p_6p7_6p54();
	int p_6p7_6p55_1(int, int);
	int p_6p7_6p55_2(int, int);
	int p_6p7_6p55_3(int, int);
	int p_6p7_6p55_4(int, int);
	void p_6p7_6p55();

	void runAll();
};

inline bool Chapter_six::isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

#endif
