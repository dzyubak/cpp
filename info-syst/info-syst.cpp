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
    using std::ios;
    using std::left;
    using std::right;

#include <list>
using namespace std;

#include <string>
    using std::string;

#include <fstream>
    using std::ifstream;
    using std::ofstream;

#include <iomanip>
    using std::setw;

#include "info-syst.h"

// "put-to" or "stream insertion" operator overloading
ostream &operator<<( ostream &output, const Student &number ) {
    output
        << "   | " << left << setw( 21 ) << number.LastName << " |"
        << right << setw( 11 ) << number.BirthYear << " |" << setw( 14 )
        << number.AverageGrade << " |";
    return output;
}

bool operator<(const Student &o1, const Student &o2) {
    return o1.AverageGrade < o2.AverageGrade;
}

bool operator>(const Student &o1, const Student &o2) {
    return o1.AverageGrade > o2.AverageGrade;
}

bool operator==(const Student &o1, const Student &o2) {
    return o1.AverageGrade == o2.AverageGrade;
}

bool operator!=(const Student &o1, const Student &o2) {
    return o1.AverageGrade != o2.AverageGrade;
}

// constructor
Student::Student( string i, int j, int k ) {
    LastName = i; // save LastName in an object
    BirthYear = j;
    AverageGrade = k;
};

Student::~Student() { }

int Student::getGrade() {
    return AverageGrade;
};

string Student::getName() {
    return LastName;
};

// constructor
Group::Group( string gName ) {
    groupName = gName;
}

Group::~Group() { }

void Group::backToMainMenu() {
    char backToMainMenuChoice;

    do {
        cout << "\n Type <m> to get back to the Main Menu."
        << endl;
        cin >> backToMainMenuChoice;
    }
    while ( backToMainMenuChoice != 'm');
}

int Group::printToMonitor() {
    // check, if the list is not empty
    if ( group.empty() ) {
        cout << "\n The list is currently empty. Please, enter some records "
             << "to the list first." << endl;
        backToMainMenu();
        return 0;
    }

    cout << "\n The list content is:\n"
         << "   +-----------------------+------------+---------------+\n"
         << "   |       Last Name       | Birth Year | Average Grade |\n"
         << "   +-----------------------+------------+---------------+\n";
    list<Student>::iterator p = group.begin();
    while( p != group.end() ) {
        cout << *p << endl;
        p++;
    }
    cout << "   +-----------------------+------------+---------------+\n\n";

    cout << " We currently have " << group.size() << " students in the group."
         << endl;

    backToMainMenu();
    return 0;
}

void Group::linearSearch() {
    /*
    // alternative: search for average grade
    int key = 123;

    list<Student>::iterator p = group.begin();
    while( p != group.end() )
    {
        cout << p->getGrade() << endl; // cout << p->getName() << endl;
        if ( p->getGrade() == key )
            cout << *p << endl;
        p++;
    }
    */

    string key;            // search key
    int SearchResults = 0; // search results counter

    cout << "Please type the Last Name below:" << endl;
    cin >> key;

    list<Student>::iterator p = group.begin();
    while( p != group.end() ) {
        if ( p->getName() == key ) {
            cout << *p << endl;
            SearchResults++;
        }
        p++;
    }

    if ( SearchResults == 0 ) {
        cout << "No students with last name that matched your search query "
        << "were found."
        << "\nYou have typed \"" << key << "\" for Your search string."
        << "Please check Your spelling and try again."
        << endl;
    } else if ( SearchResults == 1 ) {
        cout << " " << SearchResults << " student with \"" << key
        << "\" last name was found."
        << endl;
    } else {
        cout << " " << SearchResults << " students with \"" << key
        << "\" last name were found."
        << endl;
    }

    backToMainMenu();

    cout << " Done searching. Entering the Main Menu." << endl;
}

void Group::readConsole() {
    string TheLastName;
    int YearOfBirth;
    int GradeAverage;

    char ReadConsoleChoice;

    do {
        cout << " Please, enter the required details." << endl;
        cout << " Input Last Name: ";
        cin >> TheLastName;
        cout << " Input Birth Year: ";
        cin >> YearOfBirth;
        cout << " Input Average Grade: ";
        cin >> GradeAverage;
        group.push_back( Student(TheLastName, YearOfBirth, GradeAverage) );

        cout << " New record has been added successfully." << endl;
        cout << right << setw( 21 ) << TheLastName << setw( 7 ) << YearOfBirth
             << setw( 5 ) << GradeAverage << endl;
        cout << "\n Whould You like to add another record?"
             << "\n Type \"y\" for Yes or \"n\" for No" << endl;
        cin >> ReadConsoleChoice;
    }
    while ( ReadConsoleChoice != 'n');

    printToMonitor();

    cout << " Done Reading from Console. Entering the Main Menu." << endl;
}

void Group::sortByAverageGrade() {
    cout << "\n --- Unsorted group of students. ---" << endl;

    cout << "\n The list content is:\n"
         << "   +-----------------------+------------+---------------+\n"
         << "   |       Last Name       | Birth Year | Average Grade |\n"
         << "   +-----------------------+------------+---------------+\n";
    list<Student>::iterator p = group.begin();
    while( p != group.end() ) {
        cout << *p << endl;
        p++;
    }
    cout << "   +-----------------------+------------+---------------+\n\n";

    group.sort();    // 0...100
    group.reverse(); // 100...0

    cout << "\n --- The sorted group of students. ---" << endl;
    printToMonitor();

    cout << " Done sorting by average grade. Entering the Main Menu." << endl;
}

int Group::eraseRecord() {
    int i = 1; // record counter
    int eraseRecord;
    // specific record is deleted by using the iterator
    list<Student>::iterator ittr;

    cout << " Deleting specific record by its number." << endl;

    list<Student>::iterator p = group.begin();
    while( p != group.end() ) {
        cout << setw( 5 ) << i++ << *p << endl;
        p++;
    }
    cout << "\n\n";

    // check, if the list is not empty
    if ( group.empty() ) {
        cout << " The list is currently empty." << endl;
        return 0;
    }

    cout << " Type the number of the record you want to delete." << endl;
    cin >> eraseRecord;

    if ( eraseRecord > i - 1 ) {
        cout << " The number you typed is greater, "
             << "then there are records available."
             << "\n Please, try again.\n\n";
        return 0;
    }

    if ( eraseRecord == 1 ) {
        ittr = group.begin();
    } else {
        ittr = group.begin();
        for ( int k = 1 ; k < eraseRecord; k++ ) {
            ittr++;
        }
    }

    char eraseRecordChoice;
    cout << "\n Do you really want to delete this record from the list?\n"
         << *ittr << "\n\n Type \"y\" to delete the record from the list,"
         << "\n otherwise type any letter to enter the Edit Menu." << endl;
    cin >> eraseRecordChoice;

    if ( eraseRecordChoice == 'y' ) {
        group.erase(ittr);

        // output updated list to screen
        i = 1;
        list<Student>::iterator q = group.begin();
        while( q != group.end() ) {
            cout << i++ << " " << *q << endl;
            q++;
        }
        cout << "\n\n";
    }
    return 0;
}

int Group::clearList() {
    // check, if the list is not empty
    if ( group.empty() ) {
        cout << " The list is currently empty. Nothing to delete." << endl;
        return 0;
    }

    char ClearListChoice;
    cout << "\n\n CAUTION!!! Do you really want to delete "
         << "ALL elements from the list?"
         << "\n\n Type \"y\" to delete all elements from the list,"
         << "\n otherwise type any letter to enter the Edit Menu." << endl;
    cin >> ClearListChoice;

    if ( ClearListChoice == 'y' ) {
        group.clear();

        // check, if the list is really empty now
        if ( group.empty() ) {
            cout << " All elements from the list were deleted. "
                 << "The list is empty now." << endl;
        }
    }
    return 0;
}

int Group::editList() {
    int EditChoice;

    do {
        cout << "\n\n ------------ Edit Menu ------------ " << endl;
        cout << " Select \"1\" to Read from Console" << endl;
        cout << " Select \"2\" to Delete specific record by number" << endl;
        cout << " Select \"3\" to Delete ALL the Records from the List" << endl;
        cout << " Select \"4\" to Enter the Main Menu" << endl;
        cout << " Please, select some number to proceed:" << endl;
        cin >> EditChoice;

        switch ( EditChoice ) {
        case 1:
            cout << " Choice \"1\" is selected. Reading from Console." << endl;
            readConsole();
            break;
        case 2:
            cout << " Choice \"2\" is selected. Erasing Records." << endl;
            eraseRecord();
            break;
        case 3:
            cout << " Choice \"3\" is selected. "
                 << "Deleting ALL Records from the List." << endl;
            clearList();
            break;
        // ignore whitespaces input
        case '\n':
        case '\t':
        case ' ':
            break;
        // catch all other symbols
        default:
            cout << "Incorrect digit is entered. Please enter another number."
                 << endl;
            break;
        }
    } while ( EditChoice != 4 );

    cout << " Choice 4 is selected.\n Entering the Main Menu..." << endl;
    return 0;
}

int Group::writeToFile() {
    // open file
    ofstream listFile( "students.txt", ios::out );

    // if ofstream could not open the file, exit this function
    if ( !listFile ) {
        cerr << "File could not be opened." << endl;
        return 0;
    }

    // write every single record to file
    list<Student>::iterator p = group.begin();
    while( p != group.end() ) {
        listFile << *p << endl;
        p++;
    }
    cout << "\n\n";

    cout << " Data has been written to file successfully." << endl;

    return 0;
}

int Group::readFromFile() {
    // open file
    ifstream listFile( "students.txt", ios::in );

    // if ofstream could not open the file, exit this function
    if ( !listFile ) {
        cerr << "File could not be opened." << endl;
        return 0;
    }

    string TheLastName;
    int YearOfBirth;
    int GradeAverage;
    string tc1 = "   | "; // vertical pipe to draw a table 1
    string tc2 = " |";    // vertical pipe to draw a table 2

    while ( listFile >> tc1 >> setw( 21 ) >> TheLastName >> tc2 >> setw( 11 )
        >> YearOfBirth >> tc2 >> setw( 14 ) >> GradeAverage >> tc2 )
        group.push_back( Student(TheLastName, YearOfBirth, GradeAverage) );

    return 0;
}

void Group::infoAboutDeveloper() {
    cout << "\n\n     --- Information about the Developer of this Program. ---"
         << "\n\n   This program is developed by Dmytro Dzyubak."
         << "\n   If You have any questions, comments or bug reports, "
         << "don't hesitate\n to contact me."
         << "\n\n\n   Special thanks to"
         << "\n\n - Domnin F. A. for educating through my first steps "
         << "in programming and\n   motivation"
         << "\n - Harvey M. Deitel, Paul J. Dietel and Herbert Schildt for their"
         << "\n   excellent books"
         << "\n - http://www.cplusplus.com/ for their outstanding resources network"
         << "\n - and of course my Mum and Granny for their loving care."
         << "\n\n   Without the help of these people, this program would "
         << "just not exist."
         << "\n\n" << endl;
    backToMainMenu();
}
