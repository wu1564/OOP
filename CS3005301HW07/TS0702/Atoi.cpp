#include "Atoi.h"

Atoi::Atoi() {
	beTrans = "";
}

Atoi::Atoi(string s) {
	beTrans = s;
}

void Atoi::SetString(string s) {
	beTrans = s;
}

const string Atoi::GetString() {
	return beTrans;
}

int Atoi::Length() {
	//processingStr(beTrans);
	return (beTrans[0] == '-') ? beTrans.length() - 1 : beTrans.length();
}

bool Atoi::IsDigital() {
	if (beTrans[0] == '-' || (beTrans[0] >= '0' && beTrans[0] <= '9')) {
		for (int i = 1; i < beTrans.length(); ++i) {
			if (beTrans[i] < '0' || beTrans[i] > '9') {
				return false;
			}
		}
		return true;
	}
	return false;
}

int Atoi::StringToInteger() {
	int number = 0, i;
	
	i = (beTrans[0] == '-') ? 1 : 0;
	for (; i < beTrans.length(); ++i) {
		number += beTrans[i] - '0';
		number *= 10;
	}
	number = (beTrans[0] == '-') ? number / -10 : number / 10;
	
	return number;
}
