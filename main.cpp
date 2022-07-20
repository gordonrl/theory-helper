//
//  main.cpp
//  theory-helper
//
//  Created by Gordon Lewis on 7/12/22.
//

#include <iostream>
#include <utility>
#include <string>
#include "constants.h"

using namespace std;

/*
 The project will work by identifying the type of each chord and the interval between them.
 Ex: Am-D7-Gmaj is a ii-V-I and you can tell becuse Am-D7 is the A is minor, the D is dominant,
 and it's a perfect fourth between them.
 
 It sucks that there's a lot of mundane, dumb hard coding for these intervals but it is what it is.
 But the nice thing is that if you go by half steps it shouldn't be too bad
 */

//EFFECTS: Takes in a chord and determines it's type (major, minor, etc.)
string determineChordType(string chord);

//EFFECTS: Checks that the inputted chords are valid
bool isValid(string chord);

//EFFECTS: Determines the interval between the two chords
string determineInterval(string chord1, string chord2);

int main() {
    cout << "Welcome to Theory Helper!" << endl << endl;
    cout << "Please enter two chords, separated by a space, at a time." << endl << "Write minor chords as 'm', major chords as 'M', and dominant chords as '7'" << endl;
    cout << "This is all that is supported at this time, but expansion will come!" << endl << endl;
    
    string chord1; string chord2;
    cout << "Please enter chords: ";
    cin >> chord1 >> chord2;
    
    //step 1 is to make sure each chord is valid
    if (!isValid(chord1) || !isValid(chord2)) {
        cout << "Please enter valid chords" << endl;
        return 1;
    }
    
    //step 2 is to determine the type of each chord
    string chord1Type = determineChordType(chord1);
    string chord2Type = determineChordType(chord2);
    
    //step 3 is to determine the interval between the chords
    //The interval will always be read as the distance from the first chord to the second
    
    return 0;
}

string determineChordType(string chord) {
    //the position in the string of the chord type depends on the chord
    //ex: c#m is indicated to be minor at chord[2], but cm is at chord[1]
    
    //this is just a series of conditionals, which is good because it should be
    //easily expandable for more chord types in the future
    if (chord[1] == 'm' || chord[2] == 'm') {
        return MINOR;
    }
    else if (chord[1] == 'M' || chord[2] == 'M') {
        return MAJOR;
    }
    else if (chord[1] == '7' || chord[2] == '7') {
        return DOMINANT;
    }
    return "invalid chord type";
}

bool isValid(string chord) {
    //string of 1 or 2 letters that checks chord type
    string checker;
    if (chord[1] == '#' || chord[1] == 'b') {
        checker = tolower(chord[0]);
        checker+= chord[1];
    }
    else {
        checker = tolower(chord[0]);
    }
    
    bool isValidNote = false;
    for (int i = 0; i < VALID_NOTES_SIZE; i++) {
        if (checker == VALID_NOTES[i]) {
            isValidNote = true;
            i = VALID_NOTES_SIZE;
        }
    }
    
    bool isValidChordType = true;
    if (determineChordType(chord) == "invalid chord type") {
        isValidChordType = false;
    }
    
    if (isValidNote && isValidChordType) {
        return true;
    }
    else {
        return false;
    }
}

string determineInterval(string chord1, string chord2) {
    //pretty simple function, just need to loop through the
    //correct interval array until we find a match
    
    return "this will be fixed";
}
