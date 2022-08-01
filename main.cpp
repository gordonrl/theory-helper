//
//  main.cpp
//  theory-helper
//
//  Created by Gordon Lewis on 7/12/22.
//

#include <iostream>
#include <utility>
#include <string>
#include "utility.hpp"

using namespace std;


/*
 The project will work by identifying the type of each chord and the interval between them.
 Ex: Am-D7-Gmaj is a ii-V-I and you can tell becuse Am-D7 is the A is minor, the D is dominant,
 and it's a perfect fourth between them.
 
 It sucks that there's a lot of mundane, dumb hard coding for these intervals but it is what it is.
 But the nice thing is that if you go by half steps it shouldn't be too bad
 */

int main() {
    cout << "Welcome to Theory Helper!" << endl << endl;
    cout << "Please enter two chords, each serparated by a space." << endl << "Indicate minor chords with '-' or 'm'," << endl
    << "major chords with 'M', or with no symbol after the chord" << endl << "and dominant chords with '7'" << endl << endl;
    cout << "These are all of the chord types supported at this time, but expansion will come!" << endl << endl;
    
    //step 1 is to take read in chords from the user and make sure their valid
    string chord1; string chord2;
    cout << "Please enter chords: ";
    //A while loop allows us to keep prompting user for valid chords rather than fully
    //restarting the program if they enter an invalid chord
    while (chord1 == "" || chord2 == "") {
        cin >> chord1 >> chord2;
        if (!isValid(chord1) || !isValid(chord2)) {
            cout << "Please enter valid chords: ";
            chord1 = "";
            chord2 = "";
        }
    }
    
    //step 2 is to determine the type of each chord
    string chord1Type = determineChordType(chord1);
    string chord2Type = determineChordType(chord2);
    
    cout << chord1 << " is " << chord1Type << endl;
    cout << chord2 << " is " << chord2Type << endl;
    
    //step 3 is to determine the interval between the chords
    //The interval will always be read as the distance from the first chord to the second
    string interval = determineInterval(chord1, chord2);
    
    //finally we can use the interval and chord type to determine the chord progression
    
    return 0;
}
