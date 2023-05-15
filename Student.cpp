#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>

#include "Func.h"
#include "Student.h"
#include "Crypto.h"

#define line cout << "+"; for (int _ = 0; _ < 100; _++) { if (_ == 35) {cout << "+";} else {cout << "-";}} cout << "+\n"

using namespace std;

string end_record = "=== END ===";

Student::Student() {
	fio.surname = fio.name = fio.patronymic = faculty.faculty = department.department = group.group = studentbook_number.student_book_number = sex.sex = "";
	birth_date.day = birth_date.month = birth_date.year = admission_year.admission_year = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j <  10; j++) {
			session.subject[i][j] = "";
			session.mark[i][j] = -1;
			session.is_empty[i][j] = true;
		}
	}
}

void Student::getSurname() {
	cout << "������� �������: ";
	string out = getAlpha("������� �������: ");
	system("cls");
	fio.surname = out;
}

void Student::getName() {
	cout << "������� ���: ";
	string out = getAlpha("������� ���: ");
	system("cls");
	fio.name = out;
}

void Student::getPatronymic() {
	cout << "������� ��������: ";
	string out = getAlpha("������� ��������: ");
	system("cls");
	fio.patronymic = out;
}

void Student::getBirthDate() {
	int out_day;
	int out_month;
	int out_year;
	// �������� �� ���� ������ � ���������� ��������
	while (true) {
		cout << "������� ���� �������� (����� �� 1 �� 31): ";
		out_day = getDigit("������� ���� �������� (����� �� 1 �� 31): ");
		cout << "\n";
		// ����� ���� ����� 31 ����
		if (checkForValue(1, out_day, 31)) {
			break;
		}
		system("cls");
	}
	system("cls");

	while (true) {
		cout << "������� ����� �������� (����� �� 1 �� 12): ";
		out_month = getDigit("������� ����� �������� (����� �� 1 �� 12): ");
		cout << "\n";
		if (checkForValue(1, out_month, 12)) {
			break;
		}
		system("cls");
	}
	system("cls");

	while (true) {
		cout << "������� ��� �������� (����� �� 1900 �� 2008): ";
		out_year = getDigit("������� ��� �������� (����� �� 1900 �� 2008): ");
		cout << "\n";
		if (checkForValue(1900, out_year, 2008)) {
			break;
		}
		system("cls");
	}
	system("cls");

	birth_date.day = out_day;
	birth_date.month = out_month;
	birth_date.year = out_year;
}

void Student::getAdmissionYear() {
	int out;
	while (true) {
		cout << "������� ��� ����������� (����� �� 1900 �� 2022): ";
		out = getDigit("������� ��� ����������� (����� �� 1900 �� 2022): ");
		cout << "\n";
		if (checkForValue(1900, out, 2022)) {
			break;
		}
		system("cls");
	}
	system("cls");
	admission_year.admission_year = out;
}

void Student::getFaculty() {
	cout << "������� ���������: ";
	string out = getAlpha("������� ���������: ");
	system("cls");
	faculty.faculty = out;
}

void Student::getDepartment() {
	string out;
	cout << "������� �������: ";
	cin >> out;
	system("cls");
	department.department = out;
}

void Student::getGroup() {
	string out;
	cout << "������� ������: ";
	cin >> out;
	system("cls");
	group.group = out;
}

void Student::getStudentbookNumber() {
	string out;
	cout << "������� ����� �������� ������: ";
	cin >> out;
	system("cls");
	studentbook_number.student_book_number = out;
}

void Student::getSex() {
	int out;
	while (true) {
		cout << "������� ��� (1 � �������, 0 � �������): ";
		out = getDigit("������� ��� (1 � �������, 0 � �������): ");
		cout << "\n";
		if (checkForValue(0, out, 1)) {
			if (out == 1) {
				system("cls");
				sex.sex = "�������";
				break;
			}
			else {
				system("cls");
				sex.sex = "�������";
				break;
			}
		}
		system("cls");
	}
}

void Student::getSession() {
	int session_num, out_mark;
	string out_subject;
	while (true) {
		// ���� ������ ������
		cout << "������� ����� ������ (����� �� 1 �� 9) ��� \"0\" ����� ����������: ";
		while (true) {
			session_num = getDigit("������� ����� ������ (����� �� 1 �� 9) ��� \"0\" ����� ����������: ");
			cout << "\n";
			if (checkForValue(0, session_num, 9)) {
				break;
			}
		}
		// while � �������� �� ��������� :�
		if (session_num == 0) { break; }
		// ������ ��� �������
		session_num--;
		system("cls");
		// ���� �������� ��������
		cout << "������� �������� ��������: ";
		cin >> out_subject;
		system("cls");
		// ���� ������ ��� �����/�������
		while (true) {
			cout << "������ ������� ������ ��� ��������.\n" <<
				"0-�������\n" <<
				"1-�����\n" <<
				"2-�������������������\n" <<
				"3-�����������������\n" <<
				"4-������\n" <<
				"5-�������\n\n" <<
				"��� �����: ";
			out_mark = getDigit("������ ������� ������ ��� ��������.\n0-�������\n1-�����\n2-�������������������\n3-�����������������\n4-������\n5-�������\n\n��� �����: ");
			cout << "\n";
			if (checkForValue(0, out_mark, 5)) {
				break;
			}
		}
		cout << "\n";
		// �������� �� ��, ����� ������� ����� �� ������
		int subject_num = getEmptySessionNumber(session_num);
		if (subject_num == -1) {
			cout << "� ������ " << session_num << " ��� ��� ��������� ���� ��� ����������";
			break;
		}
		else {
			session.subject[session_num][subject_num] = out_subject;
			session.mark[session_num][subject_num] = out_mark;
			session.is_empty[session_num][subject_num] = false;
			cout << "������ ������� ���������!\n��� ����������� ������� ����� �������. . .";
			_getch();
			system("cls");
		}
	}
}


// ������, ������� ��������� �������� � ����� ������
int Student::getEmptySessionNumber(int session_num) {
	for (int i = 0; i < 10; i++) {
		if (session.is_empty[session_num][i]) {
			return i;
		}
	}
	return -1;
}


// ���� ������ � ����������
void Student::addStudent() {
	getSurname();
	getName();
	getPatronymic();
	getBirthDate();
	getAdmissionYear();
	getFaculty();
	getDepartment();
	getGroup();
	getStudentbookNumber();
	getSex();
	getSession();
	writeIntoFile(fio, birth_date, admission_year, faculty, department, group, studentbook_number, sex, session);
	cout << "������ ������� ��������";
	cout << "��� ����������� ������� ����� �������. . .";
	_getch();
	system("cls");
}


// ����� ������ � ���������
void Student::printStudent(int student_num) {
	line;
	cout << left << "| " << student_num + 1;
	cout.width(30);
	cout << ".\t1. ���: ";
	cout << "|\t" << fio.surname << " " << fio.name << " " << fio.patronymic;
	cout.width(63 - fio.surname.length() - fio.name.length() - fio.patronymic.length() - 2);
	cout << right << "|\n";
	cout.width(30);
	cout << left << "|\t2. ���� ��������: ";
	cout << "|\t";
	if (birth_date.day < 10) {
		cout << 0;
	}
	cout << birth_date.day << ".";
	if (birth_date.month < 10) {
		cout << 0;
	}
	cout << birth_date.month << "." << birth_date.year;
	cout.width(63 - 10);
	cout << right << "|\n";
	cout.width(30);
	cout << left << "|\t3. ��� �����������: ";
	cout << "|\t" << admission_year.admission_year;
	cout.width(63 - 4);
	cout << right << "|\n";
	cout.width(30);
	cout << left << "|\t4. ��������� (��������): ";
	cout << "|\t" << faculty.faculty;
	cout.width(63 - faculty.faculty.length());
	cout << right << "|\n";
	cout.width(30);
	cout << left << "|\t5. �������: ";
	cout << "|\t" << department.department;
	cout.width(63 - department.department.length());
	cout << right << "|\n";
	cout.width(30);
	cout << left << "|\t6. ������: ";
	cout << "|\t" << group.group;
	cout.width(63 - group.group.length());
	cout << right << "|\n";
	cout.width(30);
	cout << left << "|\t7. ����� �������� ������: ";
	cout << "|\t" << studentbook_number.student_book_number;
	cout.width(63 - studentbook_number.student_book_number.length());
	cout << right << "|\n";
	cout.width(30);
	cout << left << "|\t8. ���: ";
	cout << "|\t" << sex.sex;
	cout.width(63 - sex.sex.length());
	cout << right << "|\n";
	line;
	cout.width(30);
	cout << left << "|\t9. ���������� ������: ";
	cout << "|\t";
	for (int session_num = 0; session_num < 9; session_num++) {
		if (session_num != 0) { cout.width(36); cout << left << "|"; cout << "|\t"; }

		cout << session_num + 1 << " ������: ";
		// � ������ ���� ���� ���� ��������� ������
		if (getEmptySessionNumber(session_num) != 0) {
			for (int subject_num = 0; subject_num < 10; subject_num++) {
				if (!session.is_empty[session_num][subject_num]) {
					if (subject_num != 0) {
						cout.width(36);
						cout << left << "|";
						cout << "|\t\t  ";
					}
					cout << session.subject[session_num][subject_num] << " � ";

					if (session.mark[session_num][subject_num] == 0) {
						cout << "�������";
						cout.width(63 - 9 - session.subject[session_num][subject_num].length() - 3 - 8);
					}
					else if (session.mark[session_num][subject_num] == 1) {
						cout << "�����";
						cout.width(63 - 9 - session.subject[session_num][subject_num].length() - 3 - 6);
					}
					else {
						cout << session.mark[session_num][subject_num];
						cout.width(63 - 10 - session.subject[session_num][subject_num].length() - 3 - 1);
					}
					cout << right << "|\n";

				}
				// ������ ������ (�����������)
				else { break; }
			}
		}
		// ��� ������ � �������
		else {
			cout << "��� ������";
			cout.width(63 - 20);
			cout << right << "|\n";
		}
	}
	line;
	cout << "\n\n";
}


// ������ ������ (����� ������) � ����
void Student::writeIntoFile(Fio fio_, BirthDate birth_date_, AdmissionYear admission_year_, Faculty faculty_,
	Department department_, Group group_, StudentBookNumber studentbook_number_, Sex sex_, Session session_) {
	Decrypt();
	ofstream file;
	file.open("StudentsData.bin", ios_base::binary | ios_base::in | ios_base::app);
	// TODO: ������������ ��� ������
	if (!file.is_open()) {
		cout << "���� �� ������!" << endl;
		_getch();
		return;
	}
	//file.write((char*)&fio_.surname, sizeof(string));
	//file << endl;
	//file.write((char*)&fio_.name, sizeof(string));
	//file << endl;
	//file.write((char*)&fio_.patronymic, sizeof(string));
	//file << endl;
	//file.write((char*)&birth_date_.day, sizeof(int));
	//file << endl;
	//file.write((char*)&birth_date_.month, sizeof(int));
	//file << endl;
	//file.write((char*)&birth_date_.year, sizeof(int));
	//file << endl;
	//file.write((char*)&admission_year_.admission_year, sizeof(int));
	//file << endl;
	//file.write((char*)&faculty_.faculty, sizeof(string));
	//file << endl;
	//file.write((char*)&department_.department, sizeof(string));
	//file << endl;
	//file.write((char*)&group_.group, sizeof(string));
	//file << endl;
	//file.write((char*)&studentbook_number_.student_book_number, sizeof(string));
	//file << endl;
	//file.write((char*)&sex_.sex, sizeof(string));
	//file << endl;

	file << fio_.surname << "\n" << fio_.name << "\n" << fio_.patronymic << "\n";
	file << birth_date_.day << "\n" << birth_date_.month << "\n" << birth_date_.year << "\n";
	file << admission_year_.admission_year << "\n";
	file << faculty_.faculty << "\n";
	file << department_.department << "\n";
	file << group_.group << "\n";
	file << studentbook_number_.student_book_number << "\n";
	file << sex_.sex << "\n";

	// �������� ������, �� ���� ����-���� �������� �� ���� �������
	for (int session_num = 0; session_num < 9; session_num++) {
		// ��� �����������, ���� �� ������ � ������ ������
		int subject_count;
		for (int i = 0; i < 10; i++) {
			if (session_.is_empty[session_num][i]) {
				subject_count = i;
			}
		}
		if (subject_count) {
			file << session_num << "\n";
			// �� � �������, ���������� � ��������(!) ������ �� ��������(!) ������� � ���������� � ����
			for (int i = 0; i < subject_count; i++) {
				file << session_.subject[session_num][i] << ":" << session_.mark[session_num][i] << "\n";
			}
		}
	}
	file << end_record << "\n";
	file.close();
	Crypt();
}


// ������ ������ (����� ������) �� �����
void Student::readFromFile(int requirement_number) {
	int student_number = 0, session_num = 0;
	string buffer;
	int f_line = 0;
	Decrypt();
	ifstream file("StudentsData.bin", ios_base::in | ios_base::binary);
	if (!file.is_open()) {
		cout << "���� �� ������!\n";
		return;
	}
	else {
		while (getline(file, buffer, '\n')) {
			if (buffer[0] == ':' && buffer[1] == '-') {}
			else if (student_number == requirement_number && buffer != end_record) {
				switch (f_line) {
				case 0:
					fio.surname = buffer;
					break;
				case 1:
					fio.name = buffer;
					break;
				case 2:
					fio.patronymic = buffer;
					break;
				case 3:
					birth_date.day = atoi(buffer.c_str());
					break;
				case 4:
					birth_date.month = atoi(buffer.c_str());
					break;
				case 5:
					birth_date.year = atoi(buffer.c_str());
					break;
				case 6:
					admission_year.admission_year = atoi(buffer.c_str());
					break;
				case 7:
					faculty.faculty = buffer;
					break;
				case 8:
					department.department = buffer;
					break;
				case 9:
					group.group = buffer;
					break;
				case 10:
					studentbook_number.student_book_number = buffer;
					break;
				case 11:
					sex.sex = buffer;
					break;
				default:
					if (buffer.length() == 1) { session_num = atoi(buffer.c_str()); }
					else {
						int subject_num = getEmptySessionNumber(session_num);
						bool was_colon = false;
						for (char letter : buffer) {
							if (letter == ':') { was_colon = true; }
							else if (!was_colon) { session.subject[session_num][subject_num] += letter; }
							else {
								session.mark[session_num][subject_num] = int(letter) - int('0');
								session.is_empty[session_num][subject_num] = false;
							}
						}
					}
					break;
				}
				f_line++;
			}
			else if (buffer == end_record) {
				student_number++;
				f_line = 0;
			}
		}
		file.close();
		Crypt();
	}
}


// �������� ��������
int Student::deleteStudent(Student* student, int student_count) {
	int number;
	if (student_count == 0) {
		cout << "���� �� ���� ��������� :(\n";
	}
	else {
		while (true) {
			cout << "������� ���������� ����� ��������: ";
			cin >> number;
			if (checkForValue(1, number, student_count)) {
				number--;
				break;
			}
		}
		system("cls");

		// ������� ���� ����� ������� ���� "���������" ��������
		Decrypt();
		ofstream file("StudentsData.bin", ios_base::binary | ios_base::trunc);
		file.close();
		Crypt();
		for (int i = 0; i < student_count; i++) {
			if (i != number) {
				writeIntoFile(student[i].fio, student[i].birth_date, student[i].admission_year, student[i].faculty, student[i].department, student[i].group, student[i].studentbook_number, student[i].sex, student[i].session);
			}
		}
		cout << "������ ������� ���������!\n";
	}
	cout << "��� ����������� ������� ����� �������...";
	_getch();
	system("cls");
	return number;
}


// ��������� ������ ��������
void Student::editStudent(Student* student, int student_count) {
	if (student_count == 0) { cout << "��� ���-�� �����. ��� ������, �������� ���������\n"; }
	else {
		int requred_student, parameter;
		while (true) {
			cout << "������� ���������� ����� ��������, ������ �������� ������ ��������: ";
			requred_student = getDigit("������� ���������� ����� ��������, ������ �������� ������ ��������: ");
			cout << "\n";
			if (checkForValue(1, requred_student, student_count)) {
				break;
			}
		}
		// ��������� �� 1, ������ ��� �������� � ���������
		requred_student--;
		system("cls");

		while (true) {
			cout << "������ ������� ����� ���������, ������� ������ ��������.\n���������:\n1-�������\n2-���\n3-��������\n4-���� ��������\n5-��� �����������\n6-���������\n7-�������\n8-������\n9-����� �������� ������\n10-���\n11-������ � ������\n\n��� �����: ";
			parameter = getDigit("������ ������� ����� ���������, ������� ������ ��������.\n���������:\n1-�������\n2-���\n3-��������\n4-���� ��������\n5-��� �����������\n6-���������\n7-�������\n8-������\n9-����� �������� ������\n10-���\n11-������ � ������\n\n��� �����: ");
			cout << "\n";
			if (checkForValue(1, parameter, 11)) {
				break;
			}
		}
		system("cls");

		switch (parameter) {
		case 1:
			student[requred_student].getSurname();
			break;
		case 2:
			student[requred_student].getName();
			break;
		case 3:
			student[requred_student].getBirthDate();
			break;
		case 5:
			student[requred_student].getAdmissionYear();
			break;
		case 6:
			student[requred_student].getFaculty();
			break;
		case 7:
			student[requred_student].getDepartment();
			break;
		case 8:
			student[requred_student].getGroup();
			break;
		case 9:
			student[requred_student].getStudentbookNumber();
			break;
		case 10:
			student[requred_student].getSex();
			break;
		case 11:
			student[requred_student].editStudentSession(requred_student);
			break;
		default:
			cout << "��������� �������������� ������!";
		}

		// ������� ���� ����� ������� ���� "���������" ��������
		Decrypt();
		ofstream file("StudentsData.bin", ios_base::trunc);
		file.close();
		Crypt();
		for (int i = 0; i < student_count; i++) {
			writeIntoFile(student[i].fio, student[i].birth_date, student[i].admission_year, student[i].faculty, student[i].department, student[i].group, student[i].studentbook_number, student[i].sex, student[i].session);
		}
		cout << "������ ������� ���������!\n";
	}
	cout << "��� ����������� ������� ����� �������...";
	_getch();
	system("cls");
}


// ��������� ������ �������� � ��������
void Student::editStudentSession(int required_student) {
	int choose, session_num, subject_num, num_subj_in_session, new_mark;
	string new_subject;
	printStudent(required_student);
	cout << "�������:\n\"1\", ����� �������� ����� ������\n\"2\", ����� �������� ������������ ������\n\"3\", ����� ������� ������������ ������\n\n��� ����� : ";
	while (true) {
		choose = getDigit("�������:\n\"1\", ����� �������� ����� ������\n\"2\", ����� �������� ������������ ������\n\"3\", ����� ������� ������������ ������\n\n��� ����� : ");
		cout << "\n";
		if (checkForValue(1, choose, 3)) {
			break;
		}
	}
	system("cls");

	// �������� ����� ������
	if (choose == 1) {
		getSession();
	}

	else if (choose == 2) {
		// �������� ����� ������
		printStudent(required_student);
		cout << "������� ����� ������, ������ ������� �� ������ ��������: ";
		while (true) {
			session_num = getDigit("������� ����� ������, ������ ������� �� ������ ��������: ");
			cout << "\n";
			if (checkForValue(1, session_num, 9)) {
				num_subj_in_session = getEmptySessionNumber(session_num - 1);
				if (num_subj_in_session == 0) { cout << "� ���� ������ ��� ��������� ��� ���������. �������������� �������� ���������� ����� ������!"; }
				else { break; }
			}
		}
		system("cls");

		// �������� ������ ��������
		printStudent(required_student);
		cout << "������ ������� ����� ��������, ������ �������� ������ ��������: ";
		while (true) {
			subject_num = getDigit("������ ������� ����� ��������, ������ �������� ������ ��������: ");
			cout << "\n";
			if (checkForValue(1, subject_num, num_subj_in_session)) {
				break;
			}
		}
		system("cls");

		// �������� ����� �������� ��������
		cout << "������� �������� ��������: ";
		cin >> new_subject;

		// ��������  ����� ������
		cout << "������ ������� ������ ��� ��������.\n0 - �������\n1 - �����\n2 - �������������������\n3 - �����������������\n4 - ������\n5 - �������\n\n��� ����� : ";
		while (true) {
			new_mark = getDigit("������ ������� ������ ��� ��������.\n0-�������\n1-�����\n2-�������������������\n3-�����������������\n4-������\n5-�������\n\n��� �����: ");
			cout << "\n";
			if (checkForValue(0, new_mark, 5)) {
				break;
			}
		}

		// �������� �������� � �������� ������
		session.subject[session_num - 1][subject_num - 1] = new_subject;
		session.mark[session_num - 1][subject_num - 1] = new_mark;
	}

	// ������� ������������ ������
	else {
		deleteSession(required_student);
	}
}

void Student::deleteSession(int required_student) {
	int session_num, subject_num, num_subj_in_session;
	printStudent(required_student);
	cout << "������� ����� ������, ������ ������� �� ������ �������: ";
	while (true) {
		session_num = getDigit("������� ����� ������, ������ ������� �� ������ �������: ");
		cout << "\n";
		if (checkForValue(1, session_num, 9)) {
			num_subj_in_session = getEmptySessionNumber(session_num - 1);
			if (num_subj_in_session == 0) { cout << "� ���� ������ ��� ��������� ��� ��������. �������������� �������� ���������� ����� ������!"; }
			else { break; }
		}
	}
	system("cls");

	printStudent(required_student);
	cout << "������ ������� ����� ��������, ������ �������� ������ �������: ";
	while (true) {
		subject_num = getDigit("������ ������� ����� ��������, ������ �������� ������ �������: ");
		cout << "\n";
		if (checkForValue(1, subject_num, num_subj_in_session)) {
			break;
		}
	}
	system("cls");


	if (!session.is_empty[session_num - 1][subject_num]) {
		while (!session.is_empty[session_num - 1][subject_num]) {
			session.subject[session_num - 1][subject_num - 1] = session.subject[session_num - 1][subject_num];
			session.mark[session_num - 1][subject_num - 1] = session.mark[session_num - 1][subject_num];
			session.is_empty[session_num - 1][subject_num - 1] = session.is_empty[session_num - 1][subject_num];
			subject_num++;
		}
	}
	session.subject[session_num - 1][subject_num - 1] = "";
	session.mark[session_num - 1][subject_num - 1] = -1;
	session.is_empty[session_num - 1][subject_num - 1] = true;
}

