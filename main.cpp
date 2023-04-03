#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Описание класса RecordBook
class RecordBook 
{
public:
    string name;
    string surname;
    string subject;
    int grade;

    // Конструктор класса
    RecordBook() {};
    RecordBook(string n, string s, string subj, int gr)
    {
        name = n;
        surname = s;
        subject = subj;
        grade = gr;
    }
};

// Функция ввода данных о предметах студента
void enterData(RecordBook& rb)
{
    cout << "Enter student's name: ";
    getline(cin, rb.name);
    cout << "Enter student's surname: ";
    getline(cin, rb.surname);
    cout << "Enter subject: ";
    getline(cin, rb.subject);
    cout << "Enter grade: ";
    cin >> rb.grade;
  
    
    
    cin.ignore();
}

// Функция вывода данных о студенте и его предмете
void displayData(const RecordBook& rb)
{
    cout << "Name: " << rb.name << endl;
    cout << "Surname: " << rb.surname << endl;
    cout << "Subject: " << rb.subject << endl;
    cout << "Grade: " << rb.grade << endl;
    cout << endl;
}

// Функция сравнения студентов по фамилии и имени
bool compareStudents(const RecordBook& a, const RecordBook& b)
{
    if (a.surname == b.surname) 
    {
        return a.name < b.name;
    }
    return a.surname < b.surname;
}

// Функция выхода из программы
void exitProgram()
{
    cout << "Exiting program..." << endl;
    exit(0);
}

// Главная функция
int main()
{
    vector<RecordBook> students; // вектор, который будет хранить объекты RecordBook
    int choice;
    RecordBook rb;
     //Проверка оценка не должна быть меньше 1 и больше 5
    try 
    {
        enterData(rb);
        if (rb.grade < 1 || rb.grade > 5) 
        {
            throw std::invalid_argument("Invalid grade: " + std::to_string(rb.grade));
        }
        students.push_back(rb);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    // Бесконечный цикл для отображения меню и выполнения действий по выбору пользователя
    while (true)
    {
        cout << "MENU:" << endl;
        cout << "1 - Enter data" << endl;
        cout << "2 - Show data" << endl;
        cout << "3 - Sort data" << endl;
        cout << "4 - Exit the program" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            // Ввод данных о предметах студента
            enterData(rb);
            students.push_back(rb); // добавляем объект RecordBook в вектор
            break;

        case 2:
            // Вывод данных о студентах и их предметах
            for (RecordBook& rb : students)
            {
                displayData(rb);
            }
            break;

        case 3:
            // Сортировка данных о студентах по фамилии и имени
            sort(students.begin(), students.end(), compareStudents);
            cout << "Data sorted successfully!" << endl;
            break;

        case 4:
            // Выход из программы  
            exitProgram();
            break;

        default:
            cout << "Wrong choice. try again." << endl;
            break;
        }
    }
    return 0;

};
