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
�ı�cin״̬
=====================================
*/
void Chapter_eight::process_input(istream &is)
{
	int i = 0;
	is >> i;
}

/*
=====================================
����cin��־λ
=====================================
*/
void Chapter_eight::setCinState()
{
	// ��ȡ��ǰcin��״̬
	auto cin_state = cin.rdstate();

	// ���cin��״̬
	cin.clear();

	// �ı�cin��״̬
	process_input(cin);

	// ��������cin��״̬
	cin.setstate(cin_state);
}

/*
=====================================
�������ķ���ֵ�Ͳ�������Ϊistream������
�Ӹ��������ж�ȡ���ݲ��ӱ�׼��������
�ڷ��ظ�����֮ǰ������λ

����

>> is: ������

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
�Զ�ģʽ��һ���ļ�, �����е����ݶ���һ��string��
vector��, ��ÿһ����Ϊһ��������Ԫ�ش��뵽vector��
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
��д����, ��Ϊ��ÿ�����ʶ����뵥����Ԫ����
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
��һ���ļ��ж��뽻�׼�¼, ����д������
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
��������ʾ��outģʽ�ᶪ���������ݵ�����
=====================================
*/
void Chapter_eight::overwrite_file()
{
	// ����д��һЩ����
	ofstream write_file_obj("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\test.txt");
	// ��ʱfile���Ѿ���д�����ַ���"123"��һ���س���
	write_file_obj << "123" << endl;
	write_file_obj.close();

	// ��д��һЩ����
	ofstream write_file_obj2("C:\\Users\\littleboy\\source\\repos\\primerFifth\\chapter8\\test.txt");
	write_file_obj2 << "456" << endl;
	write_file_obj2.close();

	// �������ļ�
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
�޸�������, ������������ļ���
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
�޸�������, �����׷�����ļ���
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
ʹ��isstringstream��Ϊ������������8.1.2���еĺ���
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
ʹ��ostringstream, ��string�����ڴ���
=====================================
*/
void Chapter_eight::p_8p3p2_8p13()
{
	// ���ļ��ж���绰��
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