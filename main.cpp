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

using namespace std;

int main()

{
    // Declaring base variables
    // User's name
    char username[100];
    // Medication name
    char med_name[100];
    // Tablets in a box.
    float med_box;
    // Daily tablet intake.
    float med_day;
    // Tablets left in box.
    float med_left;
    // Repeats left.
    float med_rpt;
    // Usual repeats given by GP.
    float med_rpt_get;
    // Medication cost.
    float med_cost;
    // Currency symbol
    char dollarsign[10];

    // Asking name for personal touch
    cout << "What is your name?: ";
    cin >> username;
    cout << "What is your currency symbol?: ";
    cin >> dollarsign;
    cout << "Welcome to Medication Tracker, " << username << "!" << endl;
    // Asking questions about medication
    cout << "What is the name of your medication?: ";
    cin >> med_name;
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
    float med_box_days_left;
    // How long the current repeat cycle will last.
    float med_rpt_days_left;
    // How long a repeat cycle lasts.
    float med_rpt_days;
    // How much a repeat cycle costs.
    float med_rpt_get_cost;
    // How much a tablet costs.
    float med_tab_cost;
    // How much the current repeat cycle will cost.
    float med_rpt_cost;
    // How many days a repeat cycle lasts.
    float med_rpt_get_days;
    // How many tablets in a repeat cycle.
    float med_tab_rpt_get;

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

    cout << username << ", Here are the statistics for your medication, " << med_name << "." << endl;
    cout << "You take " << med_day << " tablets daily out of a box of " << med_box << ". This lasts you " << med_box_days << " days." << endl;
    cout << "You have " << med_left << " tablets left, this will last you " << med_box_days_left << " more days." << endl;
    cout << "You have " << med_rpt << " repeats left, the cycle will last you " << med_rpt_days_left << " more days." << endl;
    cout << "This will cost you " << dollarsign << med_rpt_cost << " in total and " << dollarsign << med_cost << " per box." << endl;
    cout << "Please press any key to exit, please see stats.txt for more statistics.";
    ofstream statsfile;
    statsfile.open ("stats.txt");
    statsfile << med_name << " statistics. --------------------" << endl;
    statsfile << "Cost per tablet: " << dollarsign << med_tab_cost << "." << endl;
    statsfile << "Cost per repeat cycle: " << dollarsign << med_rpt_get_cost << "." << endl;
    statsfile << "Days per repeat cycle: " << med_rpt_get_days << "." << endl;
    statsfile << "Tablets per repeat cycle: " << med_tab_rpt_get << "." << endl;
    statsfile << "END STATISTICS FILE --------------------" << endl;
    statsfile.close();
    getch();
    return 0;
}
