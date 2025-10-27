#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"

using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

// function prototypes
int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

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

    list<Goat> trip; // linked list to hold all goats
    int choice; // user's menu choice

    do {
        choice = main_menu(); // display the menu and get choices

        if (choice == 1) 
            add_goat(trip, names, colors);
        
        else if (choice == 2) 
            delete_goat(trip);
        
        else if (choice == 3) 
            display_trip(trip);

        else cout << "Goodbye!" << endl;
        
    } while (choice != 4);


    return 0;
}

int main_menu() {
    cout << "\n*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] Display all goats" << endl;
    cout << "[4] Exit" << endl;
    cout << "Enter choice: ";

    int c;
    cin >> c;

    // basic input validation -- check later
    while (c < 1 || c > 4) {
        cout << "Invalid choice. Enter choice: ";
        cin >> c;
    }
    return c;

    void add_goat(list<Goat> &trip, string names[], string colors[]) { // function to add a goat
        int rand_name = rand() % SZ_NAMES;
        int rand_age = rand() % (MAX_AGE + 1);
        int rand_color = rand() % SZ_COLORS;

         // 3-arg goat constructor
        Goat g(names[rand_name], rand_age, colors[rand_color]);
        trip.push_back(g);

        cout << "Added goat: " << names[rand_name]
        << " (" << rand_age << " , " << colors[rand_color] << ")" << endl;

    void display_trip(list<Goat> trip) { // function to display all goats
        if (trip.empty()) {
            cout << "No goats in the trip yet" << endl;
            return;
        }

        cout << "\nCurrent Goats: " << endl;
        int i = 1;
        for (auto g : trip) 
            cout << "[" << ++i << "] "
                 << g.get_name() << " ("
                 << g.get_age() << ", "
                 << g.get_color() << ")" << endl;
    }

    int select_goat(list<Goat> trip) { // function to select a goat
        int i = 1;
        for (auto g : trip)
            cout << "[" << i++ << "] "
                 << g.get_name() << " ("
                 << g.get_age() << ", "
                 << g.get_color() << ")" << endl;

        cout << "Select goat number: ";
        int n;
        cin >> n;
        return n;
    }

    void delete_goat(list<Goat> &trip) { // function to delete a goat
        if (trip.empty()) {
            cout << "No goats to delete." << endl;
            return;
        }

        int pick = select_goat(trip);
        if (pick < 1 || pick > trip.size()) {
            cout << "Invalid selection." << endl;
            return;
    }
        auto it = trip.begin(); // iterator to the beginning
        advance(it, pick-1);
        cout << "Deleting goat: " << it->get_name() << endl;
        trip.erase(it);
    }

 }

};


