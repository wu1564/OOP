#include "Recorder.h"

Student::Student() {
	Id = 0;
}

Student::Student(const Student &student) {
	Id = student.Id;
}

void Student::storeStudent(Student student) {
	store.push_back(student);
}

Student::~Student() {

}

//-----------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------

int Class::getStudentId(Student student) {
	//record.push_back(student);
	return student.Id;
}

Class::Class() {

}

Class::Class(string subject) {

}
