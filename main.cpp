#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();
//the main function
int main() {
    srand(time(0));
    bool again;
    int choice = 0;
    list<Goat> trip;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    //A while loop that goes in till choice == 4
    while (choice != 4)
    {
        //Sets choice to the return value of the main_menu() function
        choice = main_menu();
        //switch case for each option
        switch (choice)
        {
        case 1:
            //calls the add_goat() function
            add_goat(trip, names, colors);
            break;
        case 2:
            //calls the delete_goat() function
            delete_goat(trip);
            break;
        case 3:
            //calls the display_trip() function
            display_trip(trip);
            break;
        default:
            break;
        }
    }
    return 0;
}
//the main_menu function
int main_menu()
{
    //Declares and initilizes variables
    int choice;
    //do while loop in till choice is a number between 1 and 4
    do
    {
        //Print Menu
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice -->";
        //user input
        cin >> choice;
    } while (choice > 4 || choice < 1);
    //returns choice
    return choice;
}
//the add_goat function
void add_goat(list<Goat> &trip, string names[], string colors[])
{
    //Declares and initilizes variables
    int randName = rand() % SZ_COLORS+1;
    int randColor = rand() % SZ_COLORS+1;
    int randAge = rand() % MAX_AGE;
    //pushs the new goat to the end of the list
    trip.push_back(Goat(names[randName], randAge, colors[randColor]));
    cout << endl;
}
//the delete_goat function
void delete_goat(list<Goat> &trip)
{
    //Declares and initilizes variables
    int count = 1;
    int goatIndex;
    list<Goat>::iterator it = trip.begin();
    //Prints list with count for each goat
    cout << "Select the goat you wish to delete from the list:" << endl;
    for (Goat theGoat : trip)
    {
        cout << "[" << count << "] " << theGoat.get_name() << " (" << theGoat.get_age() << ", " << theGoat.get_color() << ")" << endl;
        count++;
    }
    //user input
    cout << "Choice -->";
    cin >> goatIndex;
    //checks if list is empty or if user's choice was actually in the list
    if (trip.empty())
    {
        cout << "List is empty unable to delete goat" << endl;
    }
    else if (goatIndex > count || goatIndex < 1)
    {
        cout << "Choice was not in the List unable to delete goat" << endl;
    }
    else
    {
        //advances it to goatIndex
        advance(it, goatIndex);
        //erases goat
        trip.erase(it);
        cout << "Successfully deleted goat" << endl;
    }
    cout << endl;
}
//the display_trip function
void display_trip(list<Goat> trip)
{
    //Prints list
    cout << "Printing List:" << endl;
    for (Goat theGoat : trip)
    {
        cout << "   " << theGoat.get_name() << " (" << theGoat.get_age() << ", " << theGoat.get_color() << ")" << endl;
    }
    cout << endl;
}