#pragma once
using namespace std;

// �������, ��� � ��������
struct Fio {
	string surname, name, patronymic;
};

// ���� ��������
struct BirthDate {
	int day, month, year;
};

// ��� �����������
struct AdmissionYear {
	int admission_year;
};

// ���������
struct Faculty {
	string faculty;
};

// �������
struct Department {
	string department;
};

// ����� ������
struct Group {
	string group;
};

// ����� �������� ������
struct StudentBookNumber {
	string student_book_number;
};

// ���
struct Sex {
	string sex;
};

// ������
struct Session {
	// �������� �������� (9 ������ �� 10 ��������� � ������)
	string subject[9][10];
	// ������ (9 ������ �� 10 ��������� � ������)
	int mark[9][10];
	// ��������, ������ �� �������� (9 ������ �� 10 ��������� � ������)
	// true � �����, false � ���
	bool is_empty[9][10];
};


//Student* student[], int i, int j
class Student {
private:
	Fio fio;
	BirthDate birth_date;
	AdmissionYear admission_year;
	Faculty faculty;
	Department department;
	Group group;
	StudentBookNumber studentbook_number;
	Sex sex;
	Session session;
public:
	Student();
	void getSurname();
	void getName();
	int getMark(int i, int j);
	string getStudentBook();
	void getPatronymic();
	void getBirthDate();
	void getAdmissionYear();
	void getFaculty();
	void getDepartment();
	void getGroup();
	void getStudentbookNumber();
	void getSex();
	int getEmptySessionNumber(int session_num);
	void getSession();

	void addStudent();
	void printStudent(int student_num);
	void writeIntoFile(Fio fio_, BirthDate birth_date_, AdmissionYear admission_year_, Faculty faculty_,
		Department department_, Group group_, StudentBookNumber studentbook_number_,
		Sex sex_, Session session_);
	void readFromFile(int required_number);
	void editStudent(Student* student, int student_count);
	void editStudentSession(int required_student);
	int deleteStudent(Student* student, int student_count);
	void deleteSession(int required_student);
};