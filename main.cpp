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
    // Yes/No for saving graph.
    char savegraph;

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
        cout << "How many repeats do you have left (Current one inclusive)?: ";
        cin >> med_rpt;
        if (med_rpt == 0)
        {
            cout << "You cannot enter zero, if you are on your last repeat, please type 1." << endl;
            cout << "How many repeats do you have left?: ";
            cin >> med_rpt;
        }
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
        // How many tablets have beem taken.
        float med_taken;
        // Needed for graphing
        int med_cost_year_round;
        // Needed for graphing
        int med_taken_round;
        // Needed for graphing
        int med_cost_round;
        // Needed for graphing
        int med_left_round;

        // Various calculations.
        med_box_days = med_box / med_day;
        med_box_days_left = med_left / med_day;
        if (med_rpt != 1)
        {
            med_rpt_days_left = med_box_days_left + (med_box_days * med_rpt);
        }
        else
        {
            med_rpt_days_left = med_box_days_left;
        }
        med_rpt_get_cost = med_rpt_get * med_cost;
        med_tab_cost = med_cost / med_box;
        med_rpt_cost = med_rpt * med_cost;
        med_rpt_get_days = med_rpt_get * med_box_days;
        med_tab_rpt_get = med_box * med_rpt_get;
        med_tab_year = med_day * 365;
        med_box_year = med_tab_year / med_box;
        med_cost_year = med_cost * med_box_year;
        med_taken = med_box - med_left;

        // Declaring graph variables.
        int med_cost_year_graph;
        int med_cost_graph;
        int med_box_graph;
        int med_left_graph;
        int med_taken_graph;

        // Graphing variable setting.
        med_cost_year_graph = 0;
        med_box_graph = 0;
        med_left_graph = 0;
        med_taken_graph = 0;
        med_cost_graph = 0;
        med_cost_round = med_cost;
        med_taken_round = med_taken;
        med_left_round = med_left;
        med_cost_year_round = med_cost_year;


        cout << "--------------------" << endl;
        cout << med_name << " cost per year in dollars." << endl;
        while (med_cost_year_graph != med_cost_year_round)
        {
            cout << dollarsign;
            ++med_cost_year_graph;
        }

        cout << endl  << "--------------------" << endl;
        cout << med_name << " cost per box in dollars." << endl;
        while (med_cost_graph != med_cost_round)
        {
            cout << dollarsign;
            ++med_cost_graph;
        }

        cout << endl  << "--------------------" << endl;
        cout << "An average box of "<< med_name << "." << endl;
        while (med_box_graph != med_box)
        {
            cout << "O";
            ++med_box_graph;
        }

        cout << endl  << "--------------------" << endl;
        cout << "Your current box of "<< med_name << "." << endl;
        while (med_taken_graph != med_taken_round)
        {
            cout << "-";
            ++med_taken_graph;
        }
        while (med_left_graph != med_left_round)
        {
            cout << "O";
            ++med_left_graph;
        }

        cout << endl;

        cout << "Would you like to save this information to graph.txt? [Y/N]: ";
        cin >> savegraph;

        // Graphing variable resetting.
        med_cost_year_graph = 0;
        med_box_graph = 0;
        med_left_graph = 0;
        med_taken_graph = 0;
        med_cost_graph = 0;
        med_cost_round = med_cost;
        med_taken_round = med_taken;
        med_left_round = med_left;
        med_cost_year_round = med_cost_year;

        if (toupper(savegraph) == 'Y')
        {

            // Printing graphs to file.
            ofstream graphfile;
            graphfile.open ("graph.txt");
            graphfile << "--------------------" << endl;
            graphfile << med_name << " cost per year in dollars." << endl;
            while (med_cost_year_graph != med_cost_year_round)
            {
                graphfile << dollarsign;
                ++med_cost_year_graph;
            }

            graphfile << endl  << "--------------------" << endl;
            graphfile << med_name << " cost per box in dollars." << endl;
            while (med_cost_graph != med_cost_round)
            {
                graphfile << dollarsign;
                ++med_cost_graph;
            }

            graphfile << endl  << "--------------------" << endl;
            graphfile << "An average box of "<< med_name << "." << endl;
            while (med_box_graph != med_box)
            {
                graphfile << "O";
                ++med_box_graph;
            }

            graphfile << endl  << "--------------------" << endl;
            graphfile << "Your current box of "<< med_name << "." << endl;
            while (med_taken_graph != med_taken_round)
            {
                graphfile << "-";
                ++med_taken_graph;
            }
            while (med_left_graph != med_left_round)
            {
                graphfile << "O";
                ++med_left_graph;
            }

            graphfile << endl;
        }

        // Printing relevant stats on screen.
        cout << username << ", Here are the statistics for your medication, " << med_name << "." << endl;
        cout << "You take " << med_day << " tablets daily out of a box of " << med_box << ". This lasts you " << med_box_days << " days." << endl;
        cout << "You have " << med_left << " tablets left, this will last you " << med_box_days_left << " more days." << endl;
        cout << "You have " << med_rpt << " repeats left, the cycle will last you " << med_rpt_days_left << " more days." << endl;
        cout << "This will cost you " << dollarsign << med_rpt_cost << " in total and " << dollarsign << med_cost << " per box." << endl;
        cout << "The next cycle will have " << med_rpt_get << " repeats and will cost " << dollarsign << med_rpt_get_cost << "." << endl;
        cout << "Would you like to save this information to log.txt? [Y/N]: ";
        cin >> savelog;

        // Saving log.
        if (toupper(savelog) == 'Y')
        {
            ofstream logfile;
            logfile.open ("log.txt");
            logfile << "START LOG ENTRY --------------------" << endl;
            logfile << username << ", Here are the statistics for your medication, " << med_name << "." << endl;
            logfile << "You take " << med_day << " tablets daily out of a box of " << med_box << ". This lasts you " << med_box_days << " days." << endl;
            logfile << "You have " << med_left << " tablets left, this will last you " << med_box_days_left << " more days." << endl;
            logfile << "You have " << med_rpt << " repeats left, the cycle will last you " << med_rpt_days_left << " more days." << endl;
            logfile << "This will cost you " << dollarsign << med_rpt_cost << " in total and " << dollarsign << med_cost << " per box." << endl;
            logfile << "The next cycle will have " << med_rpt_get << " repeats and will cost " << dollarsign << med_rpt_get_cost << "." << endl;
            logfile << "END LOG ENTRY --------------------" << endl;
            logfile.close();
        }

        // Saving secondary stats.
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

        // Asking to enter another medication.
        cout << "Would you like to enter another medication? [Y/N]";
        cin >> runprogram;

        cout << "Please see stats.txt for more statistics." << endl;
    }
    cout << "Please press enter to exit.";
    cin.ignore(1);
    cin.ignore(1);
    return 0;
}
