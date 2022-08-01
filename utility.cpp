//
//  utility.cpp
//  theory-helper
//
//  Created by Gordon Lewis on 8/1/22.
//

//this file contains all of the implementations
//for the functions in utility.h and used in
//main.cpp

#include <utility>
#include <string>
#include <iostream>
#include <map>
#include "constants.h"

using namespace std;

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
    else if (chord[1] == '7' || chord[2] == '7') {
        return DOMINANT;
    }
    else if (chord[1] == 'M' || chord[2] == 'M' ||chord[1] == 'b' || chord[1] == '#' ||
             chord.length() == 1 || chord.length() == 2) {
        return MAJOR;
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

#include "utility.hpp"
