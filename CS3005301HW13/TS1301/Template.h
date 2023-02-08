#pragma once
#include <iostream>
#include <string>
template <class T> void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location);
template <class T> void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location);
