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
string determineInterval(string chord1Key, string chord2Key);

//EFFECTS: Outputs information about the major ii-V progression
//note: only needs chord2Key because that can alone be used
//to determine the key of the progression
void majTwoFiveInfo(string chord2Key);

//EFFECTS: determines progression for chords that move by a perfect fourth
//REQUIRES: The chord arguments are a fourth apart
void perfFourthProgs(string chord1Type, string chord2Key, string chord2Type);

//EFFECTS: Determines the type of chord progression
//will be split into multiple functions so I don't just have one crazy long function
void determineProg(string chord1, string chord2, string tonic);



#endif /* utility_hpp */
