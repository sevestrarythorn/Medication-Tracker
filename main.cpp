//  Medication Tracker, A tool to help people who take medication keep track of it.
//  Copyright (C) 2012 James Knight <jamesknight313 AT gmail.com>

//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

int main()

{
    // Declaring base variables
    // User's name
    string username;
    // Medication name
    string med_name;
    // Tablets in a box.
    int med_box;
    // Daily tablet intake.
    float med_day;
    // Tablets left in box.
    float med_left;
    // Repeats left.
    int med_rpt;
    // Usual repeats given by GP.
    int med_rpt_get;
    // Medication cost.
    float med_cost;
    // Currency symbol
    string dollarsign;
    // Yes/No for running program
    char runprogram;
    // Yes/No for saving log.
    char savelog;

    // Asking to run program.
    cout << "Would you like to run Medication Tracker? [Y/N]: ";
    cin >> runprogram;

    while (toupper(runprogram) == 'Y')
    {
        // Needed to fix text skip bug.
        cin.ignore(1);
        // Asking name for personal touch
        cout << "What is your name?: ";
        getline (cin,username);
        // Asking currency symbol for cost variables.
        cout << "What is your currency symbol?: ";
        getline (cin,dollarsign);
        cout << "Welcome to Medication Tracker, " << username << "!" << endl;
        // Asking questions about medication
        cout << "What is the name of your medication?: ";
        getline (cin,med_name);
        cout << "How many tablets are in a box?: ";
        cin >> med_box;
        cout << "How many tablets do you take daily?: ";
        cin >> med_day;
        cout << "How many tablets do you have left?: ";
        cin >> med_left;
        cout << "How many repeats do you have left?: ";
        cin >> med_rpt;
        cout << "How many repeats do you usually get?: ";
        cin >> med_rpt_get;
        // The dollar sign below is for currency display.
        cout << "How much does your medication cost?: " << dollarsign;
        cin >> med_cost;
        // Declaring calc variables

        // How long a box lasts
        float med_box_days;
        // How long the current box(es) will last.
        int med_box_days_left;
        // How long the current repeat cycle will last.
        int med_rpt_days_left;
        // How long a repeat cycle lasts.
        int med_rpt_days;
        // How much a repeat cycle costs.
        float med_rpt_get_cost;
        // How much a tablet costs.
        float med_tab_cost;
        // How much the current repeat cycle will cost.
        float med_rpt_cost;
        // How many days a repeat cycle lasts.
        float med_rpt_get_days;
        // How many tablets in a repeat cycle.
        int med_tab_rpt_get;
        // How many tablets you take a year.
        float med_tab_year;
        // How many boxes you use in a year.
        float med_box_year;
        // How much your medication costs per year.
        float med_cost_year;


        // Various calculations.
        med_box_days = med_box / med_day;
        med_box_days_left = med_left / med_day;
        med_rpt_days_left = med_box_days_left + (med_box_days * med_rpt);
        med_rpt_days = med_box * med_rpt_get;
        med_rpt_get_cost = med_rpt_get * med_cost;
        med_tab_cost = med_cost / med_box;
        med_rpt_cost = med_rpt * med_cost;
        med_rpt_get_days = med_rpt_get * med_box_days;
        med_tab_rpt_get = med_box * med_rpt_get;
        med_tab_year = med_day * 365;
        med_box_year = med_tab_year / med_box;
        med_cost_year = med_cost * med_box_year;

        cout << username << ", Here are the statistics for your medication, " << med_name << "." << endl;
        cout << "You take " << med_day << " tablets daily out of a box of " << med_box << ". This lasts you " << med_box_days << " days." << endl;
        cout << "You have " << med_left << " tablets left, this will last you " << med_box_days_left << " more days." << endl;
        cout << "You have " << med_rpt << " repeats left, the cycle will last you " << med_rpt_days_left << " more days." << endl;
        cout << "This will cost you " << dollarsign << med_rpt_cost << " in total and " << dollarsign << med_cost << " per box." << endl;
        cout << "Would you like to save this information to log.txt? [Y/N]: ";
        cin >> savelog;
        while (toupper( savelog ) == 'Y')
        {
            ofstream logfile;
            logfile.open ("log.txt");
            logfile << "START LOG ENTRY --------------------" << endl;
            logfile << username << ", Here are the statistics for your medication, " << med_name << "." << endl;
            logfile << "You take " << med_day << " tablets daily out of a box of " << med_box << ". This lasts you " << med_box_days << " days." << endl;
            logfile << "You have " << med_left << " tablets left, this will last you " << med_box_days_left << " more days." << endl;
            logfile << "You have " << med_rpt << " repeats left, the cycle will last you " << med_rpt_days_left << " more days." << endl;
            logfile << "This will cost you " << dollarsign << med_rpt_cost << " in total and " << dollarsign << med_cost << " per box." << endl;
            logfile << "END LOG ENTRY --------------------" << endl;
            logfile.close();
        }
        ofstream statsfile;
        statsfile.open ("stats.txt");
        statsfile << med_name << " statistics. --------------------" << endl;
        statsfile << "Cost per tablet: " << dollarsign << med_tab_cost << "." << endl;
        statsfile << "Cost per repeat cycle: " << dollarsign << med_rpt_get_cost << "." << endl;
        statsfile << "Days per repeat cycle: " << med_rpt_get_days << "." << endl;
        statsfile << "Tablets per repeat cycle: " << med_tab_rpt_get << "." << endl;
        statsfile << "Tablets per year: " << med_tab_year << "." << endl;
        statsfile << "Boxes per year: " << med_box_year << "." << endl;
        statsfile << "Cost per year: " << dollarsign << med_cost_year << "." << endl;
        statsfile << "END STATISTICS ENTRY --------------------" << endl;
        statsfile.close();
        cout << "Would you like to enter another medication? [Y/N]";
        cin >> runprogram;
    }
    cout << "Please press any key to exit, please see stats.txt for more statistics.";
    getch();
    return 0;
}
