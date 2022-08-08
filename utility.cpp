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
#include <cassert>
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

string determineKey(string chord2Key, string interval, bool isMajor) {
    //first we need to find the right array to use
    map<string, string> keyMap;
    for (int i = 0; i < INTERVAL_ARR_SIZE; i++) {
        if (chord2Key == ARRAY_KEY[i].first) {
            keyMap = ARRAY_KEY[i].second;
            i = INTERVAL_ARR_SIZE;
        }
    }
    
    //then we can find rhe right key using the given interval
    string key = "";
    //for a ii-V the tonic will just be a P4 from the second chord
    //and we can find that using the valid notes array and another for loop
    for (int i = 0; i < VALID_NOTES_SIZE; i++) {
        //I don't include the Alternate perfect fourth because then the output could look
        //weird because it could say something like d- G7 is a ii-V in b#, which is technically true,
        //but no one would write it this way
        if (keyMap[VALID_NOTES[i]] == interval) {
            key = VALID_NOTES[i];
            i = VALID_NOTES_SIZE;
        }
    }
    
    //lastly we may need to make the key uppcase if it's major
    if (isMajor) {
        if (key.length() == 1) {
            key = toupper(key[0]);
        }
        else {
            char temp = key[1];
            key = toupper(key[0]);
            key += temp;
        }
    }
    
    return key;
}

void majTwoFive(string chord2Key) {
    string intervalToKey = PERFECT_FOURTH;
    string key = determineKey(chord2Key, intervalToKey, true);
    //cout cool stuff about a ii-V
    cout << "It looks like you have a major ii-V progression in the key of " << key << "!" << endl << endl;
    cout << "A Dorian scale is typically used over the ii chord and a Mixolydian scale is typically used for the V chord!"
    << " This would be the same as playing the Ionian (major) scale in the key of " << key << " for the whole progression." << endl << endl;
   
    return;
}

void majFiveOne(string chord2Key) {
    string intervalToKey = UNISON;
    string key = determineKey(chord2Key, intervalToKey, true);
    //cout cool stuff about a V-i
    cout << "It looks like you have a major V-I progression in the key of " << key << "!" << endl << endl;
    cout << "A Mixolydian scale is typically used over the V chord and an Ionion (major) scale is typically used for the I chord!"
    << " You can also use the " << key << " Ionian scale over the V as well." << endl << endl;
}

void perfFourthProgs(string chord1Type, string chord2Key, string chord2Type) {
    //a minor chord to a dominant chord separated by a perfect fourth is
    //ALWAYS a major ii-V
    if (chord1Type == MINOR && chord2Type == DOMINANT) {
        majTwoFive(chord2Key);
    }
    //a dominant chord to a major chord separated by a perfect fourth is
    //ALWAYS a major V-I
    else if (chord1Type == DOMINANT && chord2Type == MAJOR) {
        majFiveOne(chord2Key);
    }
    return;
}

void determineProg(string chord1, string chord2) {
    //We need to get the key of the key of the chords,
    //the type of the chords (minor, major, etc.), and the interval
    //between the chords
    
    string chord1Type = determineChordType(chord1);
    string chord1Key = getKey(chord1);
    
    string chord2Type = determineChordType(chord2);
    string chord2Key = getKey(chord2);
    
    string interval = determineInterval(chord1Key, chord2Key);
    
    if (interval == PERFECT_FOURTH || interval == ALT_PERFECT_FOURTH) {
        return perfFourthProgs(chord1Type, chord2Key, chord2Type);
    }
    
    return;
}

#include "utility.hpp"
