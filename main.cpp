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

    while (choice != 4)
    {
        choice = main_menu();
        switch (choice)
        {
        case 1:
            add_goat(trip, names, colors);
            break;
        case 2:
            delete_goat(trip);
            break;
        case 3:
            display_trip(trip);
            break;
        default:
            break;
        }
    }


    return 0;
}

int main_menu()
{
    int choice;

    do
    {
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice -->";
        cin >> choice;
    } while (choice > 4 || choice < 1);
    return choice;
}

void add_goat(list<Goat> &trip, string names[], string colors[])
{
    int randName = rand() % SZ_COLORS+1;
    int randColor = rand() % SZ_COLORS+1;
    int randAge = rand() % MAX_AGE;

    trip.push_back(Goat(names[randName], randAge, colors[randColor]));
}

void delete_goat(list<Goat> &trip)
{
    int count = 1;
    int goatIndex;
    list<Goat>::iterator it = trip.begin();

    cout << "Select the goat you wish to delete from the list:" << endl;
    for (Goat theGoat : trip)
    {
        cout << "[" << count << "] " << theGoat.get_name() << " (" << theGoat.get_age() << ", " << theGoat.get_color() << ")" << endl;
        count++;
    }
    cout << "Choice -->";
    cin >> goatIndex;

    if (trip.empty())
    {
        cout << "List is empty unable to delete goat" << endl;
    }
    else if (goatIndex > count-1 || goatIndex < 1)
    {
        cout << "Choice was not in the List unable to delete goat" << endl;
    }
    else
    {
        advance(it, goatIndex);
        trip.erase(it);
        cout << "Successfully deleted goat";
    }
}

void display_trip(list<Goat> trip)
{
    cout << "Printing List:" << endl;
    for (Goat theGoat : trip)
    {
        cout << "   " << theGoat.get_name() << " (" << theGoat.get_age() << ", " << theGoat.get_color() << ")" << endl;
    }
}