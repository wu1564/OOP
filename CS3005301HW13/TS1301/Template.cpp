#include "Template.h"

template<> void ItrBinarySearch(const int a[], int first, int last, int key, bool& found, int& location) {
	int find;
	while (first <= last) {
		find = (first + last) / 2;
		if (a[find] == key) {
			found = true;
			location = find;
			return;
		}
		else if (a[find] < key) {
			first = find + 1;
		}
		else if (a[find] > key) {
			last = find - 1;
		}
	}
	found = false;
}

template<> void ItrBinarySearch(const double a[], int first, int last, double key, bool& found, int& location) {
	int find;
	while (first <= last) {
		find = (first + last) / 2;
		if (a[find] == key) {
			found = true;
			location = find;
			return;
		}
		else if (a[find] < key) {
			first = find + 1;
		}
		else if (a[find] > key) {
			last = find - 1;
		}
	}
	found = false;
}

template<> void ItrBinarySearch(const std::string a[], int first, int last, std::string key, bool& found, int& location) {
	int find = 0, length = 0;

	while (first <= last) {
		find = (first + last) / 2;
		length = (a[find].length() > key.length()) ? a[find].length() : key.length();
		if (a[find] == key) {
			found = true;
			location = find;
			return;
		}
		for (int i = 0; i < length; ++i) {
			int overLength = (i >= key.length()) ? key.length() : i;
			int a_overLength = (i >= a[find].length()) ? a[find].length() : i;
			if ((unsigned int)a[find][a_overLength] > (unsigned int)key[overLength]) {
				last = find - 1;
				break;
			} else if ((unsigned int)a[find][a_overLength] < (unsigned int)key[overLength]) {
				first = find + 1;
				break;
			}
		}
	}
	found = false;
}

template<> void RecBinarySearch(const int a[], int first, int last, int key, bool& found, int& location) {
	int find = (first + last) / 2;

	if (first > last) return;
	if (a[find] == key) {
		location = find;
		found = true;
		return;
	}
	else if (a[find] < key) {
		found = false;
		RecBinarySearch(a, find + 1, last, key, found, location);
	}
	else {
		found = false;
		RecBinarySearch(a, first, find - 1, key, found, location);
	}
}

template<> void RecBinarySearch(const double a[], int first, int last, double key, bool& found, int& location) {
	int find = (first + last) / 2;
	if (first > last) return;
	if (a[find] == key) {
		location = find;
		found = true;
		return;
	}
	else if (a[find] < key) {
		found = false;
		RecBinarySearch(a, find + 1, last, key, found, location);
	}
	else {
		found = false;
		RecBinarySearch(a, first, find - 1, key, found, location);
	}
}

template<> void RecBinarySearch(const std::string a[], int first, int last, std::string key, bool& found, int& location) {
	int find = (first + last) / 2;
	int length = (a[find].length() > key.length()) ? key.length() : a[find].length();

	if (first > last || a[find].length() != key.length()) {
		found = false;
		return; 
	}
	if (a[find] == key) {
		location = find;
		found = true;
		return;
	}
	for (int i = 0; i < length; ++i) {
		if ((unsigned int)a[find][i] < (unsigned int)key[i]) {
			found = false;
			RecBinarySearch(a, find + 1, last, key, found, location);
			break;
		}
		else if ((unsigned int)a[find][i] > (unsigned int)key[i]) {
			found = false;
			RecBinarySearch(a, first, find - 1, key, found, location);
			break;
		}
	}
}
