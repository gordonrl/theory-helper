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
#include <cctype>
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

string determineInterval(string chord1Key, string chord2Key) {
    
    //step 2 is to find the right array to navigate through
    map<string, string> intervalMap;
    for (int i = 0; i < INTERVAL_ARR_SIZE; i++) {
        if (chord1Key == ARRAY_KEY[i].first) {
            intervalMap = ARRAY_KEY[i].second;
            i = INTERVAL_ARR_SIZE;
        }
    }
    
    //step 3 is to use the key of chord2 to find
    //the right interval in the map
    string interval = intervalMap[chord2Key];
    
    return interval;
}

void majTwoFiveInfo(string chord2Key) {
    //first we need to find the key of the ii-V
    //loop puts us in the right array
    map<string, string> keyMap;
    for (int i = 0; i < INTERVAL_ARR_SIZE; i++) {
        if (chord2Key == ARRAY_KEY[i].first) {
            keyMap = ARRAY_KEY[i].second;
            i = INTERVAL_ARR_SIZE;
        }
    }
    string key = "";
    //for a ii-V the tonic will just be a P4 from the second chord
    //and we can find that using the valid notes array and another for loop
    for (int i = 0; i < VALID_NOTES_SIZE; i++) {
        if (keyMap[VALID_NOTES[i]] == "P4") {
            key = VALID_NOTES[i];
            i = VALID_NOTES_SIZE;
        }
    }
    
    //now we can cout cool stuff about a ii-V
    cout << "It looks like you have a major ii-V progression in the key of " << key << "!" << endl << endl;
    cout << "A Dorian scale is typically used over the ii chord and a Mixolydian scale is typically used for the V chord!"
    << " This would be the same as playing the Ionian (major) scale in the key of " << key << " for the whole progression." << endl << endl;
   
    return;
}

void perfFourthProgs(string chord1Type, string chord2Key, string chord2Type) {
    if (chord1Type == MINOR && chord2Type == DOMINANT) {
        majTwoFiveInfo(chord2Key);
    }
    return;
}

void determineProg(string chord1, string chord2, string tonic) {
    //We need to get the key of the tonic, the key of the chords,
    //the type of the chords (minor, major, etc.), and the interval
    //between the chords
    string key = getKey(tonic);
    
    string chord1Type = determineChordType(chord1);
    string chord1Key = getKey(chord1);
    
    string chord2Type = determineChordType(chord2);
    string chord2Key = getKey(chord2);
    
    string interval = determineInterval(chord1Key, chord2Key);
    
    if (interval == "P4") {
        return perfFourthProgs(chord1Type, chord2Key, chord2Type);
    }
    
    return;
}

#include "utility.hpp"
