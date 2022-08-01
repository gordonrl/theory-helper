//
//  utility.hpp
//  theory-helper
//
//  Created by Gordon Lewis on 8/1/22.
//

#ifndef utility_hpp
#define utility_hpp

#include <stdio.h>
#include <utility>
#include <string>
#include <iostream>
#include <map>

using namespace std;

//EFFECTS: Takes in a chord and returns the key of it
string getKey(string chord);

//EFFECTS: Takes in a chord and determines it's type (major, minor, etc.)
string determineChordType(string chord);

//EFFECTS: Checks that the inputted chords are valid
bool isValid(string chord);

//EFFECTS: Determines the interval between the two chords
string determineInterval(string chord1, string chord2);

//EFFECTS: Determines the type of chord progression
//will be split into multiple functions so I don't just have one crazy long function
string determineProg(string chord1Type, string chord2Type, string interval);

//EFFECTS: Determiens the progression if the first chord is minor
string determineMinorProg(string chord2Type, string interval);

//EFFECTS: Determines the progression if the first chord is major
string determineMajProg(string chord2Type, string interval);

//EFFECTS: Determines the progression if the first chord is dominant
string determineDomProj(string chord2Type, string interval);

#endif /* utility_hpp */
