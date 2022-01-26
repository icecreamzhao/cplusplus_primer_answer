#include "Chapter_8.h"

// ----- include -----

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "../chapter2/Sales_data.h"
#include "Person.h"

// ----- using -----

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::vector;
using std::flush;
using std::string;
using std::to_string;
using std::istringstream;
using std::ostringstream;

/*
=====================================
改变cin状态
=====================================
*/
void Chapter_eight::process_input(istream &is)
{
	int i = 0;
	is >> i;
}

/*
=====================================
设置cin标志位
=====================================
*/
void Chapter_eight::setCinState()
{
	// 获取当前cin的状态
	auto cin_state = cin.rdstate();

	// 清除cin的状态
	cin.clear();

	// 改变cin的状态
	process_input(cin);

	// 重新设置cin的状态
	cin.setstate(cin_state);
}

/*
=====================================
将函数的返回值和参数都设为istream的引用
从给定的流中读取数据并从标准输出中输出
在返回该引用之前将流复位

参数

>> is: 输入流

=====================================
*/
istream &Chapter_eight::p_8p1p2_8p1_f(istream &is)
{
	auto old_state = is.rdstate();
	int i;
	while (is >> i)
	{
		cout << i << endl;
	}
	cin.setstate(old_state);
	return cin;
}

void Chapter_eight::p_8p1p2_8p1()
{
	p_8p1p2_8p1_f(cin);
}

/*
=====================================
以读模式打开一个文件, 将其中的内容读入一个string的
vector中, 将每一行作为一个独立的元素存入到vector中
=====================================
*/
void Chapter_eight::p_8p2p1_8p4()
{
	vector<string> result;
	ifstream read_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\Chapter_8.h");
	if (read_file_obj.is_open())
	{
		while (!read_file_obj.eof())
		{
			string input = "";
			getline(read_file_obj, input);
			result.push_back(input);
		}
	}
	else
	{
		cerr << "not open file" << endl;
		exit(-1);
	}

	for (string s : result)
		cout << s << flush << endl;
}

/*
=====================================
改写程序, 改为将每个单词都放入单独的元素中
=====================================
*/
void Chapter_eight::p_8p2p1_8p5()
{
	vector<string> result;
	ifstream read_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\Chapter_8.h");
	if (read_file_obj.is_open())
	{
		while (!read_file_obj.eof())
		{
			string input = "";
			if (read_file_obj >> input)
			{
				result.push_back(input);
			}
		}
	}
	else
	{
		cerr << "not open file" << endl;
		exit(-1);
	}

	for (string s : result)
		cout << s << flush << endl;
}

/*
=====================================
从一个文件中读入交易记录, 并重写书店程序
=====================================
*/
void Chapter_eight::p_8p2p1_8p6()
{
	Sales_data data_1;
	ifstream read_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\Sales_data.txt");

	if (read_file_obj.is_open())
	{
		if (read_file_obj >> data_1.isbn >> data_1.item >> data_1.price)
		{
			data_1.revenue = data_1.item * data_1.price;

			Sales_data data_2;

			while (read_file_obj >> data_2.isbn >> data_2.item >> data_2.price)
			{
				data_2.revenue = data_2.item * data_2.price;
				if (data_1.isbn == data_2.isbn)
				{
					data_1.item += data_2.item;
					data_1.revenue += data_2.revenue;
				}
				else
				{
					cout << data_1.isbn << " isbn, item is " << data_1.item << ", and revenue is " << data_1.revenue << endl;

					data_1.isbn = data_2.isbn;
					data_1.item = data_2.item;
					data_1.revenue = data_2.revenue;
				}
			}
		}

		cout << data_1.isbn << " isbn, item is " << data_1.item << ", and revenue is " << data_1.revenue << endl;
	}
}

/*
=====================================
本函数演示了out模式会丢弃已有数据的现象
=====================================
*/
void Chapter_eight::overwrite_file()
{
	// 首先写入一些数据
	ofstream write_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\test.txt");
	// 此时file中已经被写入了字符串"123"和一个回车符
	write_file_obj << "123" << endl;
	write_file_obj.close();

	// 再写入一些数据
	ofstream write_file_obj2("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\test.txt");
	write_file_obj2 << "456" << endl;
	write_file_obj2.close();

	// 读出该文件
	ifstream read_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\test.txt");
	if (read_file_obj.is_open())
	{
		while (!read_file_obj.eof())
		{
			string s = "";
			read_file_obj >> s;
			cout << s << endl;
		}
	}
}

/*
=====================================
修改书店程序, 将结果保留至文件中
=====================================
*/
void Chapter_eight::p_8p2p2_8p7()
{
	ifstream read_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\Sales_data.txt");
	Sales_data data1;
	vector<string> result;

	if (read_file_obj.is_open())
	{
		if (read_file_obj >> data1.isbn >> data1.item >> data1.price)
		{
			data1.revenue = data1.item * data1.price;
			Sales_data data2;
			while (read_file_obj >> data1.isbn >> data1.item >> data1.price)
			{
				data2.revenue = data2.item * data2.price;
				if (data2.isbn == data1.isbn)
				{
					data1.item += data2.item;
					data1.price += data2.price;
					data1.revenue += data2.revenue;
				}
				else
				{
					string res = data1.isbn + " isbn, item is " + to_string(data1.item) + ", and revenue is " + to_string(data1.revenue);
					result.push_back(res);
				}
			}
		}
		string res = data1.isbn + " isbn, item is " + to_string(data1.item) + ", and revenue is " + to_string(data1.revenue);
		result.push_back(res);

		ofstream write_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\test.txt");
		if (write_file_obj.is_open())
		{
			for (string s : result)
				write_file_obj << s << endl;
		}
	}
}

/*
=====================================
修改书店程序, 将结果追加至文件中
=====================================
*/
void Chapter_eight::p_8p2p2_8p8()
{
	ifstream read_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\Sales_data.txt");
	Sales_data data1;
	vector<string> result;

	if (read_file_obj.is_open())
	{
		if (read_file_obj >> data1.isbn >> data1.item >> data1.price)
		{
			data1.revenue = data1.item * data1.price;
			Sales_data data2;
			while (read_file_obj >> data1.isbn >> data1.item >> data1.price)
			{
				data2.revenue = data2.item * data2.price;
				if (data2.isbn == data1.isbn)
				{
					data1.item += data2.item;
					data1.price += data2.price;
					data1.revenue += data2.revenue;
				}
				else
				{
					string res = data1.isbn + " isbn, item is " + to_string(data1.item) + ", and revenue is " + to_string(data1.revenue);
					result.push_back(res);
				}
			}
		}
		string res = data1.isbn + " isbn, item is " + to_string(data1.item) + ", and revenue is " + to_string(data1.revenue);
		result.push_back(res);

		ofstream write_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\test.txt", ofstream::app);
		if (write_file_obj.is_open())
		{
			for (string s : result)
				write_file_obj << s << endl;
		}
	}
}

void Chapter_eight::isstream()
{
	vector<PersonInfo> persons;
	ifstream read_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\person.txt");
	string line, word;
	if (read_file_obj.is_open())
	{
		istringstream iss;
		while (getline(read_file_obj, line))
		{
			iss.clear();
			iss.str(line);
			PersonInfo person;
			iss >> person.getName();

			vector<string> phones;
			while (!iss.eof())
			{
				iss >> word;
				person.getPhone().push_back(word);
			}
			
			persons.push_back(person);
		}
	}

	for (PersonInfo person : persons)
	{
		cout << person.getName() << ": ";
		for (string phone : person.getPhone())
			cout << phone << ", ";
		cout << endl;
	}
}

/*
=====================================
使用isstringstream作为输入流来调用8.1.2节中的函数
=====================================
*/
void Chapter_eight::p_8p3p1_8p9()
{
	string s = "1";
	istringstream iss(s);
	p_8p1p2_8p1_f(iss);
}

void Chapter_eight::p_8p3p1_8p10()
{
	ifstream read_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\test.txt");
	vector<string> vec;
	string line;

	if (read_file_obj.is_open())
	{
		while (getline(read_file_obj, line))
		{
			vec.push_back(line);
		}
	}

	string word;
	for (string s : vec)
	{
		istringstream iss(s);
		while (iss >> word)
			cout << word;
		cout << endl;
	}
}

/*
=====================================
使用ostringstream, 将string存入内存中
=====================================
*/
void Chapter_eight::p_8p3p2_8p13()
{
	// 从文件中读入电话号
	ifstream read_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\person.txt");
	
	string line;
	if (read_file_obj.is_open())
	{
		while (getline(read_file_obj, line))
		{
			ostringstream formatted, badNums;
			string name;
			read_file_obj >> name;

			string word;
			while (read_file_obj >> word)
			{
				if (word.size() > 7)
					badNums << word << " ";
				else
				{
					formatted << word << " ";
				}
			}

			if (badNums.str().empty())
				cout << formatted.str() << endl;
			else
			{
				cout << "err: " << endl;
				cout << badNums.str() << endl;
			}
		}
	}
}

void Chapter_eight::runAll()
{
	//setCinState();
	//p_8p1p2_8p1();
	//p_8p2p1_8p4();
	//p_8p2p1_8p5();
	//p_8p2p1_8p6();
	//overwrite_file();
	//p_8p2p2_8p7();
	//p_8p2p2_8p8();
	//isstream();
	//p_8p3p1_8p9();
	//p_8p3p1_8p10();
	p_8p3p2_8p13();
}