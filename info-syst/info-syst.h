/*
 * Copyright (C) 2012, 2015 Dmytro Dzyubak
 * 
 * This file is part of InformationSystem.
 * 
 * InformationSystem is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * InformationSystem is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with InformationSystem. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    using std::ostream;
    using std::istream;

#include <list>
    using namespace std;

class Student
{
    // "<<", ">>", "<", ">", "==", "!=" operators overloading
    friend ostream &operator<<( ostream &, const Student & );
    friend istream &operator>>( istream &, Student & );
    friend bool operator<(const Student &o1, const Student &o2);
    friend bool operator>(const Student &o1, const Student &o2);
    friend bool operator==(const Student &o1, const Student &o2);
    friend bool operator!=(const Student &o1, const Student &o2);

public:
    Student( string i, int j, int k );
    int getGrade();     // get the average grade
    string getName();   // get the last name
    ~Student();

private:
    string LastName;
    int BirthYear;
    int AverageGrade;
};

class Group
{
public:
    Group( string );
    void backToMainMenu();
    int printToMonitor(); // output to monitor screen
    void linearSearch();
    void readConsole();   // read from keyboard
    void sortByAverageGrade();
    int eraseRecord();    // delete record
    int clearList();      // delete all records
    int editList();       // edit list menu
    int writeToFile();
    int readFromFile();
    void infoAboutDeveloper();
    ~Group();

private:
    string groupName;
    list<Student> group; // doubly-linked list of "Student" type
};
