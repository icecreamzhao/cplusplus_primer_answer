#include <iostream>
#include "Chapter_7.h"
#include "../chapter2/Sales_data.h"
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"
#include "Class_X.h"
#include "No_default.h"
#include "Debug.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

/*
======================================
使用Sales_data来处理书店数据
======================================
*/
void Chapter_seven::p_7p1p1_7p1()
{
	Sales_data total;
	if (cin >> total.isbn >> total.item >> total.price)
	{
		Sales_data item;
		while (cin >> item.isbn >> item.item >> item.price)
		{
			if (total.isbn == item.isbn)
			{
				total.item += item.item;
				total.revenue = total.price * total.item;
				item.revenue = item.price * item.item;
				total.revenue += item.revenue;
			}
			else
			{
				cout << "isbn is " << total.isbn << ", price is " << total.price << endl;
				total.isbn = item.isbn;
				total.item = item.item;
				total.price = item.price;
				total.revenue = item.revenue;
			}
		}
	}
	else
	{
		cerr << "please input currect data!" << endl;
	}
}

/*
======================================
使用Sales_data(改写后)来处理书店数据
======================================
*/
void Chapter_seven::p_7p1p2_7p2()
{
	Sales_data_better total;
	if (read(cin, total))
	{
		Sales_data_better item;
		while (read(cin, item))
		{
			if (total.isbn() == item.isbn())
			{
				total.combine(item);
			}
			else
			{
				printSales(total);
				total = item;
			}
		}
	}
	else
	{
		cerr << "please input currect data!" << endl;
	}
}

/*
======================================
使用person类
======================================
*/
void Chapter_seven::p_7p1p2_7p5()
{
	Person john;
	john.setAddress("中国-北京").setName("john");
	cout << sayHello(john) << endl;
}

/*
======================================
在Sales_data_better中添加构造函数并使用
======================================
*/
void Chapter_seven::p_7p1p4_7p11()
{
	Sales_data_better data1;
	Sales_data_better data2 = Sales_data_better("12345", 4, 12.1);
	printSales(data1);
}

/*
======================================
添加person构造函数
======================================
*/
void Chapter_seven::p_7p1p4_7p15()
{
	Person john = Person("john", "中国-北京");
	cout << sayHello(john) << endl;
}

/*
======================================
使用screen的构造函数初始化
======================================
*/
void Chapter_seven::p_7p3p1_7p24()
{
	Screen screen = Screen();
	Screen screen2 = Screen(24, 80, 'a');
	cout << screen2.get() << endl;

	Screen screen3 = Screen(24, 80);
	cout << screen3.get() << endl;
}

/*
======================================
使用screen类做一些操作
======================================
*/
void Chapter_seven::p_7p3p2_7p27()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display();
	cout << endl;
	myScreen.display();
	cout << endl;
}

/*
======================================
创建X类和Y类, 令X类包含Y类的指针, Y类包含X类的对象
======================================
*/
void Chapter_seven::p_7p3p3_7p31()
{
	X x;
	Y y;
}

/*
======================================
使用委托构造函数
======================================
*/
void Chapter_seven::p_7p5p2_7p41()
{
	Person person = Person();
	cout << sayHello(person) << endl;
}

/*
======================================
设计一个类, 只有一个接受一个整数的构造函数,
在设计一个类, 该类包含上一个类的一个对象
======================================
*/
void Chapter_seven::p_7p5p3_7p43()
{
	C c = C();
	cout << c.getD().getI() << endl;

	C c2 = C(No_default(2));
	cout << c2.getD().getI() << endl;
}

/*
======================================
实验类类型隐式转换
======================================
*/
void Chapter_seven::personTest()
{
	string bob = "bob";
	Person person = Person();
	cout << person.sayToYou(bob)<< endl;
}

/*
======================================
使用constexpr
======================================
*/
void Chapter_seven::p_7p5p6_7p53()
{
	Debug debug(false, true, false);
	if (debug.any())
		cout << "print appropriate error messages" << endl;

	Debug prod(false);
	if (prod.any())
		cout << "print an error messages" << endl;
}

void Chapter_seven::runAll()
{
	//p_7p1p1_7p1();
	//p_7p1p2_7p2();
	//p_7p1p2_7p5();
	//p_7p1p4_7p11();
	//p_7p1p4_7p15();
	//p_7p3p1_7p24();
	//p_7p3p2_7p27();
	//p_7p5p2_7p41();
	//p_7p5p3_7p43();
	//personTest();
	p_7p5p6_7p53();
}