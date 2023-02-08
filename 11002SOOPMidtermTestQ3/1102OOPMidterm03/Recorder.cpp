#include "Recorder.h"

//--------------------------------------------------------------------------------------
// Student
//--------------------------------------------------------------------------------------
//static data member
int Student::defaultStudentNum = 0;
int Student::studentNum = 0;
std::vector<std::string> Student::studentNameRecord;

Student::Student() {
	Id = studentNum++;
	studentName = "Student" + std::to_string(defaultStudentNum++);
	studentNameRecord.push_back(studentName);
}

Student::Student(const Student& student) {
	Id = student.Id;
	studentName = student.studentName;
	gradeRecord = student.gradeRecord;
}

Student::Student(std::string name) {
	int findIndex = name.find("Student", 0);

	// if the name exist;
	for (int i = 0; i < studentNameRecord.size(); ++i) {
		if (studentNameRecord[i] == name) {
			Id = studentNum++;
			studentName = "Student" + std::to_string(defaultStudentNum);
			studentNameRecord.push_back(studentName);
			std::cout << "Error: The name " << name << " exists. Use default name: Student" << defaultStudentNum++ << "." << std::endl;
			return;
		}
	}

	// find if the name has prefix "Student"
	if (!findIndex) {
		Id = studentNum++;
		studentName = "Student" + std::to_string(defaultStudentNum);
		studentNameRecord.push_back(studentName);
		std::cout << "Error: The name Student is reserved word. Use default name: Student" << defaultStudentNum++ << "." << std::endl;
		return;
	}

	// normal case
	Id = studentNum++;
	studentName = name;
	studentNameRecord.push_back(studentName);
}

void Student::addGrade(std::string subject, int point) {
	std::pair<std::string, int> temp(subject, point);
	
	for (int i = 0; i < gradeRecord.size(); ++i) {
		if (gradeRecord[i].first == subject) {
			gradeRecord[i].second = point;
			return;
		}
	}
	gradeRecord.push_back(temp);
}

void Student::deleteGrade(std::string subject) {
	std::vector<std::pair<std::string, int>>::iterator it;
	
	for (it = gradeRecord.begin(); it != gradeRecord.end(); ++it) {
		if (it->first == subject) {
			it = gradeRecord.erase(it);
			return;
		}
	}
	std::cout << "Error: Subject " << subject << " could not be found." << std::endl;
}

void Student::deleteGrade() {
	gradeRecord.clear();
}

void Student::printGrade() {
	// no grade exist
	if (!gradeRecord.size()) {
		std::cout << "Error: Grade could not be found." << std::endl;
	} else {	// exist
		std::cout << "ID:" << Id << " Name: " << studentName << std::endl;
		for (std::vector<std::pair<std::string,int>>::iterator it = gradeRecord.begin(); it != gradeRecord.end(); ++it) {
			std::cout << it->first << " " << it->second << std::endl;
		}
	}
}

Student::~Student() {

}

//--------------------------------------------------------------------------------------
// Class
//--------------------------------------------------------------------------------------
std::vector<std::pair<std::string, std::vector<std::pair<std::string, int>>>> Class::subjectRecord;
std::vector<Student> Class::studentRecord;
Class::Class() {

}

void Class::addStudent(Student student) {
	// student grade
	std::pair<std::string, int> studentGrade;
	// array
	std::vector<std::pair<std::string, int>> temp;
	// subject <student grade>
	std::pair<std::string, std::vector<std::pair<std::string, int>>> subjectStudentGrade;
	bool exist = false;

	// student already in class
	for (int i = 0; i < studentRecord.size(); ++i) {
		if (studentRecord[i].studentName == student.studentName) {
			std::cout << "Error: The student " << student.studentName << " is already in the class." << std::endl;
			return;
		}
	}

	// normal case
	studentRecord.push_back(student);
	for (int i = 0; i < student.gradeRecord.size(); ++i) {
		studentGrade = std::make_pair(student.studentName, student.gradeRecord[i].second);
		exist = false;
		for (int j = 0; j < subjectRecord.size(); ++j) {
			if (student.gradeRecord[i].first == subjectRecord[j].first) {// subject already in the list
				subjectRecord[j].second.push_back(studentGrade);
				exist = true;
				break;
			}
		}
		if (!exist) {
			temp.push_back(studentGrade);
			subjectStudentGrade = std::make_pair(student.gradeRecord[i].first, temp);
			subjectRecord.push_back(subjectStudentGrade);
			temp.clear();
		}
	}
}

void Class::deleteStudent(Student student) {
	for (std::vector<Student>::iterator i = studentRecord.begin(); i != studentRecord.end(); ++i) {
		if (i->studentName == student.studentName) {
			// delete the student in student name record 
			studentRecord.erase(i);
			// delete all subject of this student in the record list
			for (int j = 0; j < subjectRecord.size(); ++j) {
				for (std::vector<std::pair<std::string, int>>::iterator it = subjectRecord[j].second.begin(); it != subjectRecord[j].second.end();) {
					if (it->first == student.studentName) {
						it = subjectRecord[j].second.erase(it);
					} else {
						it++;
					}
				}
			}
			return;
		}
	}
	std::cout << "Error: Student " << student.studentName << " could not be found." << std::endl;
}

void Class::deleteStudent(std::string studentName) {
	for (std::vector<Student>::iterator i = studentRecord.begin(); i != studentRecord.end(); ++i) {
		if (i->studentName == studentName) {
			// delete the student in student name record 
			studentRecord.erase(i);
			// delete all subject of this student in the record list
			for (int j = 0; j < subjectRecord.size(); ++j) {
				for (std::vector<std::pair<std::string, int>>::iterator it = subjectRecord[j].second.begin(); it != subjectRecord[j].second.end();) {
					if (it->first == studentName) {
						it = subjectRecord[j].second.erase(it);
					} else {
						it++;
					}
				}
			}
			return;
		}
	}
	std::cout << "Error: Student " << studentName << " could not be found." << std::endl;
}

void Class::printNumOfStudent(std::string subjectName) {
	for (int i = 0; i < subjectRecord.size(); ++i) {
		if (subjectRecord[i].first == subjectName) {
			std::cout << subjectName << " " << subjectRecord[i].second.size() << std::endl;
			return;
		}
	}
	std::cout << "Error: Subject " << subjectName << " could not be found." << std::endl;
}

void Class::printNumOfStudent() {
	std::vector<std::string> subject;
	bool found = false;

	for (int i = 0; i < studentRecord.size(); ++i) {
		for (int j = 0; j < studentRecord[i].gradeRecord.size(); ++j) {
			found = false;
			for (int k = 0; k < subject.size(); ++k) {
				if (subject[k] == studentRecord[i].gradeRecord[j].first) {
					found = true;
					break;
				}
			}
			if (!found) subject.push_back(studentRecord[i].gradeRecord[j].first);
		}
	}
	for (int i = 0; i < subject.size(); ++i) {
		for (int j = 0; j < subjectRecord.size(); ++j) {
			if (subject[i] == subjectRecord[j].first) {
				std::cout << subject[i] << " " << subjectRecord[j].second.size() << std::endl;
				break;
			}
		}
	}
}

void Class::printAvgScore(std::string subjectName) {
	int avg = 0;

	for (int i = 0; i < subjectRecord.size(); ++i) {
		if (subjectRecord[i].first == subjectName) {
			for (int j = 0; j < subjectRecord[i].second.size(); ++j) {
				avg += subjectRecord[i].second[j].second;
			}
			avg /= subjectRecord[i].second.size();
			std::cout << subjectName << " " << avg << std::endl;
			return;
		}
	}
	std::cout << "Error: Subject " << subjectName << " could not be found." << std::endl;
}

void Class::printAvgScore() {
	std::vector<std::string> subject;
	bool found = false;
	int avg = 0;

	for (int i = 0; i < studentRecord.size(); ++i) {
		for (int j = 0; j < studentRecord[i].gradeRecord.size(); ++j) {
			found = false;
			for (int k = 0; k < subject.size(); ++k) {
				if (subject[k] == studentRecord[i].gradeRecord[j].first) {
					found = true;
					break;
				}
			}
			if (!found) subject.push_back(studentRecord[i].gradeRecord[j].first);
		}
	}
	for (int i = 0; i < subject.size(); ++i) {
		avg = 0;
		for (int j = 0; j < subjectRecord.size(); ++j) {
			if (subject[i] == subjectRecord[j].first) {
				std::cout << subject[i] << " ";
				for (int k = 0; k < subjectRecord[j].second.size(); ++k) {
					avg += subjectRecord[j].second[k].second;
				}
				avg /= subjectRecord[j].second.size();
				std::cout << avg << std::endl;
				break;
			}
		}
	}
}

void Class::printSubjectInformation(std::string subjectName) {
	for (int i = 0; i < subjectRecord.size(); ++i) {
		if (subjectRecord[i].first == subjectName) {
			std::cout << "Subject name: " << subjectName << std::endl;
			std::cout << "Num of students: " << subjectRecord[i].second.size() << std::endl;
			for (int j = 0; j < subjectRecord[i].second.size(); ++j) {
				std::cout << subjectRecord[i].second[j].first << " " << subjectRecord[i].second[j].second << std::endl;
			}
			return;
		}
	}
	std::cout << "Error: Subject " << subjectName << " could not be found." << std::endl;
}

void Class::printSubjectInformation() {
	std::vector<std::string> subject;
	bool found = false;
	int avg = 0;

	for (int i = 0; i < studentRecord.size(); ++i) {
		for (int j = 0; j < studentRecord[i].gradeRecord.size(); ++j) {
			found = false;
			for (int k = 0; k < subject.size(); ++k) {
				if (subject[k] == studentRecord[i].gradeRecord[j].first) {
					found = true;
					break;
				}
			}
			if (!found) subject.push_back(studentRecord[i].gradeRecord[j].first);
		}
	}
	for (int i = 0; i < subject.size(); ++i) {
		std::cout << "Subject name: " << subject[i] << std::endl;
		for (int j = 0; j < subjectRecord.size(); ++j) {
			if (subject[i] == subjectRecord[j].first) {
				std::cout << "Num of students: " << subjectRecord[j].second.size() << std::endl;
				for (int k = 0; k < subjectRecord[j].second.size(); ++k) {
					std::cout << subjectRecord[j].second[k].first << " " << subjectRecord[j].second[k].second << std::endl;
				}
			}
		}
	}
}

Class::~Class() {

}
