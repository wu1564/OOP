#include "Library.h"
#include <algorithm>
//-------------------------------------------------------------------------------
// Book
//-------------------------------------------------------------------------------
Book::Book() {
	title = "";
	author = "";
	edition = 0;
}

Book::Book(const Book& book) {
	this->author = book.author;
	this->edition = book.edition;
	this->title = book.title;
}

Book::Book(std::string title, std::string author, int edition) {
	this->title = title;
	this->author = author;
	this->edition = edition;
}

void Book::buildBook(std::string title, std::string author, int edition) {
	this->title = title;
	this->author = author;
	this->edition = edition;
}

bool Book::operator==(const Book& book) {
	return (book.author == author && book.edition == edition && book.title == title) ? true : false;
}

//-------------------------------------------------------------------------------
// Library
//-------------------------------------------------------------------------------
std::vector<Book> Library::recordBook;

void Library::insert(Book book) {
	//Insert author's title, Edition: edition.\n
	for (int i = 0; i < recordBook.size(); ++i) {
		if (recordBook[i] == book) {
			std::cout << "Datum already exist." << std::endl;
			return;
		}
	}
	recordBook.push_back(book);
	std::cout << "Insert " << book.author << "\'s " << book.title << ", Edition: " << book.edition << "." << std::endl;
}

void Library::deleteEdition(Book book) {
	for (std::vector<Book>::iterator it = recordBook.begin(); it != recordBook.end(); ++it) {
		if (*it == book) {
			std::cout << "Delete " << book.author << "\'s " << book.title << ", Edition: " << book.edition << "." << std::endl;
			recordBook.erase(it);
			return;
		}
	}
	std::cout << "Datum doesn't exist." << std::endl;
}

void Library::deleteBook(std::string title, std::string author) {
	int tempSize = recordBook.size();

	for (std::vector<Book>::iterator it = recordBook.begin(); it != recordBook.end();) {
		if (it->title == title && it->author == author) {
			std::cout << "Delete " << author << "\'s " << title << "." << std::endl;// << ", Edition: " << it->edition << "." << std::endl;
			it = recordBook.erase(it);
		} else {
			++it;
		}
	}
	if (tempSize == recordBook.size()) {
		std::cout << "Book doesn't exist." << std::endl;
	}
}

void Library::findBook(std::string title, std::string author) {
	bool found = false;
	std::vector<int> editionRecord;
	for (int i = 0; i < recordBook.size(); ++i) {
		if (recordBook[i].title == title && recordBook[i].author == author) {
			editionRecord.push_back(recordBook[i].edition);
			found = true;
		}
	}
	if (!found) {
		std::cout << "Book doesn't exist.";
	} else {
		std::cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: ";
		std::sort(editionRecord.begin(), editionRecord.end());
		for (int i = 0; i < editionRecord.size(); ++i) {
			std::cout << editionRecord[i];
			if (i != editionRecord.size() - 1) std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void Library::findAuthor(std::string author) {
	std::vector<std::string> temp;
	//author's Books: titles <T1, T2, ¡K>\n
	for (int i = 0; i < recordBook.size(); ++i) {
		if (recordBook[i].author == author) {
			temp.push_back(recordBook[i].title);
		}
	}
	std::sort(temp.begin(), temp.end());
	if (temp.size() != 0) {
		std::cout << author << "\'s Books: ";
		for (int i = 0; i < temp.size(); ++i) {
			std::cout << temp[i];
			if (i != temp.size() - 1) std::cout << ", ";
		}
	} else {
		std::cout << "No book found.";
	}
	std::cout << std::endl;
	//std::map<std::string, std::vector<int>> table;
	//std::map<std::string, std::vector<int>>::iterator it;
	/*
	for (int i = 0; i < recordBook.size(); ++i) {
		if (recordBook[i].author == author) {
			it = table.find(author);
			if (it != table.end()) {
				table[recordBook[i].title].push_back(recordBook[i].edition);
			} else {
				temp.push_back(recordBook[i].edition);
				table[recordBook[i].title] = temp;
				temp.clear();
			}
		}
	}
	/*if (table.size() != 0) {
		for (it = table.begin(); it != table.end(); ++it) {
			std::cout << "Title: " << it->first << "\tAuthor: " << author << "\tEdition: ";
			std::sort(it->second.begin(), it->second.end());
			for (int i = 0; i < it->second.size(); ++i) {
				std::cout << it->second[i];
				if (i != it->second.size() - 1) std::cout << ", ";
			}
			std::cout << std::endl;
		}
	} else {
		std::cout << "No Book Found." << std::endl;
	}*/
}

void swap(std::vector<Book> &array, int index1, int index2) {
	Book temp = array[index2];
	array[index2] = array[index1];
	array[index1] = temp;
}

void Library::sortByTitle() {
	std::string tempTitle, tempAuthor;

	for (int i = 0; i < recordBook.size() - 1; ++i) {
		for (int j = 0; j < recordBook.size() - 1 - i; ++j) {
			if ((recordBook[j].title > recordBook[j + 1].title) || 
				(recordBook[j].title == recordBook[j + 1].title && recordBook[j].author > recordBook[j + 1].author) ||
				(recordBook[j].title == recordBook[j + 1].title && recordBook[j].author == recordBook[j + 1].author && recordBook[j].edition > recordBook[j+1].edition)) {
				swap(recordBook, j, j+1);
			}
		}
	}
	for (int i = 0; i < recordBook.size(); ++i) {
		if (tempTitle == recordBook[i].title && tempAuthor == recordBook[i].author) {
			std::cout  << ", "  << recordBook[i].edition;
		} else {
			if(i != 0) std::cout << std::endl;
			std::cout << "Title: " << recordBook[i].title << "\tAuthor: " << recordBook[i].author << "\tEdition: " << recordBook[i].edition;
		}
		tempTitle = recordBook[i].title;
		tempAuthor = recordBook[i].author;	
		if (i == recordBook.size() - 1) std::cout << std::endl;
	}
}

void Library::sortByAuthor() {
	std::string tempTitle, tempAuthor;

	for (int i = 0; i < recordBook.size() - 1; ++i) {
		for (int j = 0; j < recordBook.size() - 1 - i; ++j) {
			if ((recordBook[j].author > recordBook[j + 1].author) ||
				(recordBook[j].author == recordBook[j + 1].author && recordBook[j].title> recordBook[j + 1].title) ||
				(recordBook[j].title == recordBook[j + 1].title && recordBook[j].author == recordBook[j + 1].author && recordBook[j].edition > recordBook[j + 1].edition)) {
				swap(recordBook, j, j + 1);
			}
		}
	}
	for (int i = 0; i < recordBook.size(); ++i) {
		if (tempTitle == recordBook[i].title && tempAuthor == recordBook[i].author) {
			std::cout << ", " << recordBook[i].edition;
		}
		else {
			if (i != 0) std::cout << std::endl;
			std::cout << "Title: " << recordBook[i].title << "\tAuthor: " << recordBook[i].author << "\tEdition: " << recordBook[i].edition;
		}
		tempTitle = recordBook[i].title;
		tempAuthor = recordBook[i].author;
		if (i == recordBook.size() - 1) std::cout << std::endl;
	}
}
