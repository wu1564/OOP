#include <iostream>
#include <vector>
#include <map>

class Library;

class Book {
public:
	friend class Library;
	Book();
	Book(const Book& book);
	Book(std::string title, std::string author, int edition);
	void buildBook(std::string title, std::string author, int edition);
	bool operator==(const Book& book);
	~Book() {}
private:
	std::string title;
	std::string author;
	int edition;
};

class Library {
public:
	Library() {}
	void insert(Book book);
	void deleteEdition(Book book);
	void deleteBook(std::string title, std::string author);
	void findBook(std::string title, std::string author);
	void findAuthor(std::string author);
	void sortByTitle();
	void sortByAuthor();
private:
	static std::vector<Book> recordBook;
};
