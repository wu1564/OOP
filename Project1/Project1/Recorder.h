#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Class;
class Student;

class Class {
public:
	Class();
	Class(string subject);
	int getStudentId(Student student);
private:
	string subject;
	static vector<Student> record;
};

class Student {
public:
	Student();
	Student(const Student &student);
	~Student();
	friend int Class::getStudentId(Student student);
	void storeStudent(Student student);
private:
	int Id;
	static vector<Student> store;
};
