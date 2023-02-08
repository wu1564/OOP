#pragma once
#include <iostream>
#include <string>
using namespace std;

class School {
public:
	 School(string, float);
	~School();
	void admissions(float amount); // adds the amount (passed as a parameter) to	 the total student amount this year (if the amount is nonnegative), 
	virtual void dropouts(float amount);   //subtracts the amount from the number of students this year (if the amount is nonnegative and less than or equal to the student amount) 
	void transfer(float amount, School& toSchool);
	friend ostream& operator<<(ostream& out, const School &school);
protected:
	string name;
	int studentAmount;
	int studentAmountNextYear;
};

class PrivateSchool: public School {
public:
	//PrivateSchool(string name, float amount);
	using School::School;
	~PrivateSchool();
	void dropouts(float amount);
private:
	static int droptimes;
};

class PublicSchool:public School {
public:
	using School::School;
	~PublicSchool();
	void dropouts(float amount);
	void apply_growth();
private:
	static int droptimes;
	static float growing_rate;
};
