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

//EFFECTS: Takes in a chord and returns the key of it
string getKey(string chord);

//EFFECTS: Takes in a chord and determines it's type (major, minor, etc.)
string determineChordType(string chord);

//EFFECTS: Checks that the inputted chords are valid
bool isValid(string chord);

//EFFECTS: Determines the interval between the two chords
string determineInterval(string chord1, string chord2);

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
    
    //step 3 is to determine the interval between the chords
    //The interval will always be read as the distance from the first chord to the second
    cout << determineInterval(chord1, chord2) << endl << endl;
    
    return 0;
}

string getKey(string chord) {
    string key;
    if (chord[1] == '#' || chord[1] == 'b') {
        key = tolower(chord[0]);
        key+= chord[1];
    }
    else {
        key = tolower(chord[0]);
    }
    
    return key;
}

string determineChordType(string chord) {
    //the position in the string of the chord type depends on the chord
    //ex: c#m is indicated to be minor at chord[2], but cm is at chord[1]
    
    //this is just a series of conditionals, which is good because it should be
    //easily expandable for more chord types in the future
    if (chord[1] == '-' || chord[2] == '-' || chord[1] == 'm' || chord[2] == 'm') {
        return MINOR;
    }
    else if (chord[1] == 'M' || chord[2] == 'M' || chord.length() == 1
             || (chord.length() == 2 && (chord[1] == '#' || chord[2] == 'b'))) {
        return MAJOR;
    }
    else if (chord[1] == '7' || chord[2] == '7') {
        return DOMINANT;
    }
    return "invalid chord type";
}

bool isValid(string chord) {
    //string of 1 or 2 letters that checks chord type
    string checker = getKey(chord);
    
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
    //step 1 is to get the key of our chords
    string chord1Key = getKey(chord1);
    string chord2Key = getKey(chord2);
    
    
    //step 2 is to find the right array to navigate through
    map<string, string> intervalMap;
    for (int i = 0; i < INTERVAL_ARR_SIZE; i++) {
        if (chord1Key == ARRAY_KEY[i].first) {
            intervalMap = ARRAY_KEY[i].second;
            i = INTERVAL_ARR_SIZE;
        }
    }
    
    //step 3 is to use the key of chord2 to find
    // the right interval in the map
    string interval = intervalMap[chord2Key];
    
    return interval;
}

