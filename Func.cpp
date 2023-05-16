#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>

#include "Func.h"
#include "MainMenu.h"
#include "Crypto.h"

using namespace std;

//возвращает кол-во студентов в базе данных
int getAmountOfStudents() {
    string buffer;
    int count = 0;
	Decrypt();
    ifstream file("StudentsData.bin",ios_base::binary|ios_base::out);
    if (!file.is_open()) {
        cout << "Файл не открыт!\n";
        return 404;
    }
    while (getline(file, buffer, '\n')) {
        if (buffer == "=== END ===") {
            count++;
        }
    }
	file.close();
	Crypt();
    return count;
}

//проверка, находится ли значение в интервале min < value <max
bool checkForValue(int min, int value, int max) {
	if (min <= value && value <= max) {
		return true;
	}
	else {
		cout << "\a";
		cout << "Введено неверное значение (" << value << ")! Введите число от " << min << " до " << max << "\n";
		cout << "Для продолжения нажмите любую клавишу...";
		_getch();
		system("cls");
		return false;
	}
}

//введение только букв с клавиатуры
string getAlpha(string whatToEnter) {
	string output = "";
	char letter = 0;
	while (letter != 13) {
		letter = _getch();
		// проверка на соответствие введённого символа большим или маленькими буквами английского, а затем русского алфавита
		if ((65 <= letter && letter <= 90) || (97 <= letter && letter <= 122) || (-200 <= letter && letter <= -1)) {
			output += letter;
			system("cls");
		}
		// удаление при нажатии backspace
		else if (letter == 8 && output.length() != 0) {
			output.pop_back();
			system("cls");
		}
		else {
			system("cls");
		}
		cout << whatToEnter << output;
	}
	return output;
}

//перенос курсора. Не использование я избежал, но показал знание
void gotoxy(short x, short y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

//геттер для получения оценок из локальных данных
int Student::getMark(int i, int j) {
	return session.mark[i][j];
}

//геттер для получения номера зачетной книги из локальных данных
string Student::getStudentBook() {
	return studentbook_number.student_book_number;
}

//введение только чисел с клавиатуры
int getDigit(string whatToEnter) {
	string output = "";
	char letter = 0;
	while (letter != 13) {
		letter = _getch();
		if (48 <= letter && letter <= 57) {
			output += letter;
			system("cls");
		}
		else if (letter == 8 && output.length() != 0) {
			output.pop_back();
			system("cls");
		}
		else {
			system("cls");
		}
		cout << whatToEnter << output;
	}
	return atoi(output.c_str());
}
//функция, выполняющая сортировку по варианту
void task(Student* student) {
	bool filtr_check = false;
	int sc = getAmountOfStudents();
	int amoutn = sc;
	float u[1000];
	Student* students = new Student[sc];
	for (int t = 0; t < sc; t++) {
		students[t].readFromFile(t);
	}

	//сортрую всех студентов по номеру студака
	for (int i = 0; i < sc; i++) {
		bool flag = true;
		for (int j = 0;  j < sc - (i+1); j++) {
			if (stoi(students[j].getStudentBook()) > stoi(students[j+1].getStudentBook())) {
				flag = false;
				swap(students[j], students[j + 1]);
			}
		}
	}
	
	//вывожу табличку с отличниками
	cout << "Отличники и хорошисты:\n";
	for (int o = 0; o < sc; o++) {
		bool brk = false;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				int mark = students[o].getMark(i, j);
				if (mark != 2 and mark != 3 and mark != 0) {
					filtr_check = true;
				}
				else {
					filtr_check = false;
					brk = true;
				}
				if (brk) { break; }
			}
			if (brk) { break; }
		}
		if (filtr_check) {
			students[o].printStudent(o);
		}
	}

	//вывожу таблицу с троечниками
	cout << "\n\n\nТроечники и двоечники:\n";
	for (int o = 0; o < sc; o++) {
		bool brk = false;
		int n = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				int mark = students[o].getMark(i, j);
				if (mark == 2 or mark == 3 or mark == 0) {
					n++;
				}
			}
		}
		if (n > 0) {
			students[o].printStudent(o);
		}
	}
	delete[] students;
}
/*Вариант 15. Разбить группу на 2 части:
− хорошисты и отличники;
− троечники.
Каждую часть отсортировать по номерам зачетных книжек.*/