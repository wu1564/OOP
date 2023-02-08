#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

class Student;
class Class;

class Student {
public:
	friend class Class;
	Student();
	Student(std::string name);
	Student(const Student &student);
	void addGrade(std::string subject, int point);
	void deleteGrade(std::string subject);
	void deleteGrade();
	void printGrade();
	~Student();
private:
	int Id;
	std::string studentName;
	//std::map<std::string ,int> gradeRecord;
	std::vector<std::pair<std::string, int>> gradeRecord;
	static int studentNum;
	static int defaultStudentNum;
	static std::vector<std::string>studentNameRecord;
};

class Class {
public:
	Class();
	void addStudent(Student student);
	void deleteStudent(Student student);
	void deleteStudent(std::string studentName);
	void printNumOfStudent(std::string subjectName);
	void printNumOfStudent();
	void printAvgScore(std::string subjectName);
	void printAvgScore();
	void printSubjectInformation(std::string subjectName);
	void printSubjectInformation();
	~Class();
private:
	static std::vector<std::pair<std::string, std::vector<std::pair<std::string, int>>>> subjectRecord;
	static std::vector<Student> studentRecord;
};
