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

#include "info-syst.h"

int main(int argc, char** argv) {
    Group groupOne( "Group Number One" ); // object instantiation

    int MainChoice;

    do {
        cout << "\n\n\n";
        cout << " ------------------------------------ " << endl;
        cout << " --- Information System Main Menu --- " << endl;
        cout << " ------------------------------------ " << endl;
        cout << "\n\n";
        cout << " Select \"1\" to Read from File" << endl;
        cout << " Select \"2\" to Read from Console" << endl;
        cout << " Select \"3\" to Write to File" << endl;
        cout << " Select \"4\" to Print to Monitor" << endl;
        cout << " Select \"5\" to Edit" << endl;
        cout << " Select \"6\" to Search by Last Name" << endl;
        cout << " Select \"7\" to Sort by Average Grade" << endl;
        cout << " Select \"8\" to Display the About information" << endl;
        cout << " Select \"9\" to Exit" << endl;
        cout << "\n\n Please, select some number to proceed:" << endl;

        cin >> MainChoice;

        switch ( MainChoice ) {
        case 1:
            cout << " Choice \"1\" is selected. Reading from file." << endl;
            groupOne.readFromFile();
            break;
        case 2:
            cout << " Choice \"2\" is selected. Reading from Console." << endl;
            groupOne.readConsole();
            break;
        case 3:
            cout << " Choice \"3\" is selected. Writing to File." << endl;
            groupOne.writeToFile();
            break;
        case 4:
            cout << " Choice \"4\" is selected. Printing to Monitor." << endl;
            groupOne.printToMonitor();
            break;
        case 5:
            cout << " Choice \"5\" is selected. Editing." << endl;
            groupOne.editList();
            break;
        case 6:
            cout << " Choice \"6\" is selected. Searching by Last Name." << endl;
            groupOne.linearSearch();
            break;
        case 7:
            cout << " Choice \"7\" is selected. Sorting Students by Average Grade."
                 << endl;
            groupOne.sortByAverageGrade();
            break;
        case 8:
            cout << " Choice \"8\" is selected. Information about the developer "
                 << "of this program." << endl;
            groupOne.infoAboutDeveloper();
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
    } while ( MainChoice != 9 );

    cout << " Choice 9 is selected.\n Exiting the Program..." << endl;
    return 0;
}
