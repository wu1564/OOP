#include "School.h"

//------------------------------------------------------------------------------
// School
//------------------------------------------------------------------------------
School::School(string schoolName, float studentNum) {
	this->name = schoolName;
	this->studentAmount = studentNum;
	this->studentAmountNextYear = studentAmount;
}

School::~School() {

}

void School::admissions(float amount) {
	this->studentAmount += (amount >= 0) ? amount : 0;
}

void School::dropouts(float amount) {
	this->studentAmount -= (amount >= 0 && amount <= this->studentAmount) ? amount : 0;
}

void School::transfer(float amount, School& toSchool) {
	if (amount > 0 && amount <= this->studentAmount) {
		dropouts(amount);
		toSchool.admissions(amount);
	}
}

ostream& operator<<(ostream& out, const School &school) {
	out << school.name << "\t" << school.studentAmount << "\t" << school.studentAmountNextYear;
	return out;
}

//------------------------------------------------------------------------------
// Private School
//------------------------------------------------------------------------------
int PrivateSchool::droptimes = 0;

PrivateSchool::~PrivateSchool() {

}

void PrivateSchool::dropouts(float amount) {
	this->studentAmount -= (amount >= 0 && amount <= this->studentAmount) ? amount : 0;
	if (droptimes != 0) this->studentAmountNextYear -= 100;
	this->droptimes += 1;
}


//------------------------------------------------------------------------------
// Public School
//------------------------------------------------------------------------------
float PublicSchool::growing_rate = 0.05;

void PublicSchool::dropouts(float amount) {
	this->studentAmount -= (amount >= 0 && amount <= this->studentAmount) ? amount : 0;
	if (amount > 100) {
		this->studentAmountNextYear -= (this->studentAmountNextYear * growing_rate);
	}
}

void PublicSchool::apply_growth() {
	this->studentAmountNextYear += (this->growing_rate * this->studentAmountNextYear);
}

PublicSchool::~PublicSchool() {

}




