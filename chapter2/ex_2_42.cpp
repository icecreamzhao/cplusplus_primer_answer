#include "chapter2/chapter_2.h"
#include "chapter2/Sales_data.h"

int main()
{
	// practice 1.5.1
	Sales_data book;
	std::cin >> book.isbn >> book.item >> book.price;

	book.CalcRevence();
	book.Print();

	// practice 1.5.2
	Sales_data book2;
	std::cin >> book2.isbn >> book2.item >> book2.price;
	book2.CalcRevence();
	if (book.isbn == book2.isbn)
	{
		book.AddBook(book2);
		book.Print();
	}
	else
	{
		std::cout << "isbn is not equal. " << std::endl;
	}

	return 0;
}
