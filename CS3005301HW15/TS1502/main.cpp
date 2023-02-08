#include <iostream>
#include "Library.h"
#include <string>
#include <sstream>
using namespace std;

enum libraryCommand {
	INSERT = 0,
	DELETE_EDITION,
	DELETE_BOOK,
	FIND_BOOK,
	FIND_AUTHOR,
	SORT_BY_AUTHOR,
	SORT_BY_TITLE
};

void getString(string &inputStr, bool &incomplete) {
	char str, str2;
	string temp;
	int complete = 0;

	if (!incomplete) {
		str2 = getchar();	// ' '
		str = getchar();	//  " 
		if (str == '\"' && str2 == ' ') {
			complete++;
			do {
				str = getchar();
				if (str == '\n') {
					break;
				}
				else if (str != '\"') {
					temp.push_back(str);
				}
			} while (str != '\"');
			if (str != '\n') complete++;
			inputStr = temp;
		}
	}
	if(complete != 2) {
		incomplete = true;
	}
}

void LibraryInterface() {
	Book book;
	Library bookLibrary;
	string command, title, author;
	int edition = 0, commandNum = 0;
	bool unknown = false, incomplete = false;

	while (cin >> command) {
		if (command == "Insert") {
			getString(title, incomplete);
			getString(author, incomplete);
			if(!incomplete) cin >> edition;
			commandNum = INSERT;
		} else if (command == "Delete") {
			cin >> command;
			if (command == "Edition") {
				getString(title, incomplete);
				getString(author, incomplete);
				if (!incomplete) cin >> edition;
				commandNum = DELETE_EDITION;
			} else if(command == "Book") {	// delete book
				getString(title, incomplete);
				getString(author, incomplete);
				commandNum = DELETE_BOOK;
			} else {
				unknown = true;
			}
		} else if (command == "Find") {
			cin >> command;
			if (command == "Book") {
				getString(title, incomplete);
				getString(author, incomplete);
				commandNum = FIND_BOOK;
			} else if(command == "Author") {	//	find author
				getString(author, incomplete);
				commandNum = FIND_AUTHOR;
			} else {
				unknown = true;
			}
		} else if (command == "Sort") {
			cin >> command;
			if (command == "by") {
				cin >> command;
				if (command == "Title") {
					commandNum = SORT_BY_TITLE;
				} else if (command == "Author") {
					commandNum = SORT_BY_AUTHOR;
				} else {
					unknown = true;
				}
			} else {
				unknown = true;
			}
		} else {
			unknown = true;
		}
		if (!incomplete && !unknown) {
			switch (commandNum) {
				case INSERT:			bookLibrary.insert(Book(title, author, edition));		 break;
				case DELETE_EDITION:	bookLibrary.deleteEdition(Book(title, author, edition)); break;
				case DELETE_BOOK:		bookLibrary.deleteBook(title, author);					 break;
				case FIND_BOOK:			bookLibrary.findBook(title, author);					 break;
				case FIND_AUTHOR:		bookLibrary.findAuthor(author);							 break;
				case SORT_BY_AUTHOR:	bookLibrary.sortByAuthor();								 break;
				case SORT_BY_TITLE:		bookLibrary.sortByTitle();								 break;
				default:																         break;
			}
		}
		if (unknown) {
			cout << "Unknown Command." << endl;
		} else if (incomplete) {
			cout << "Incomplete Command." << endl;
		}
		incomplete = false;
		unknown = false;
	}
}

int main(void) {
	LibraryInterface();
}
