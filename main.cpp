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
 Ex: Am-D7-Gmaj is a ii-V-I and you can tell because with the Am-D7 the A is minor, the D is dominant,
 and it's a perfect fourth between them, then its another perfect fourth between the D7 and Gmaj
 
 It sucks that there's a lot of mundane, dumb hard coding for these intervals but it is what it is.
 But the nice thing is that if you go by half steps it shouldn't be too bad
 */

int main() {
    cout << "Welcome to Theory Helper!" << endl << endl;
    
    cout << "Please enter two chords, each serparated by a space." << endl << "Indicate minor chords with '-' or 'm'," << endl
    << "major chords with 'M', or with no symbol after the chord" << endl << "and dominant chords with '7'" << endl << endl;
    
    cout << "These are all of the chord types supported at this time, but expansion will come!" << endl << endl;
    
    //Read in chords and tonic from the user and make sure their valid
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
    cout << endl;
    
    //now we can input these chords into our helper function to
    //determine the progression
    determineProg(chord1, chord2);
    
    cout << "Thank you for using Theory Helper!" << endl << endl;
    
    return 0;
}
