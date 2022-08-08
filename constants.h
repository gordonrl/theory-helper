//
//  constants.h
//  theory-helper
//
//  Created by Gordon Lewis on 7/13/22.
//

#ifndef intervals_h
#define intervals_h
#include <utility>
#include <string>
#include <iostream>
#include <map>

using namespace std;

/*
 Here's a key to all of the first parts of the pairs:
 -General:
    A two afterwards means an alternate writing
        Ex: Bb = A# so both need to be considered
    
    Capital "M" means major while lowercase means minor
    The number afterwards is the interval
        Ex: M7 = major seventh while m6 means minor sixth
 
 P =  Unison/Perfect interval = same note
 T = Tritone = sharp 4
 
 P.S. Since it's nothing more than copying, pasting, and changing like two letters
 I'm doing separate maps for the same keys written differently (like C# and Db)
 */

/*
 A map does "mess" up the order of the intervals (ex: M2 won't be right after m2), but that's
 okay because they're all unique values
 */

//Here are a few constants for chord types
const string MINOR = "minor";
const string MAJOR = "major";
const string DOMINANT = "dominant";

//Here are the acceptable chords/notes for checking
const int VALID_NOTES_SIZE = 21;
const string VALID_NOTES[] = {"c", "b#", "db", "c#", "d", "eb", "d#", "e", "fb", "f", "e#", "f#", "gb", "g", "ab", "g#", "a", "bb", "a#", "b", "cb"};


const int INTERVAL_ARR_SIZE = 21;
//intervals for the key of C
const map<string, string> C_NATURAL = {
    {"c", "P1"}, {"b#", "P12"}, {"c#", "m22"}, {"db", "m2"}, {"d", "M"}, {"d#", "m32"}, {"eb", "m3"},
    {"e", "M3"}, {"fb", "M32"}, {"f", "P4"}, {"e#", "P42"}, {"f#", "T"}, {"gb", "T2"}, {"g", "P5"},
    {"ab", "m6"}, {"g#", "m62"}, {"a", "M6"}, {"bb", "m7"}, {"a#", "m72"}, {"b", "M7"}, {"cb", "M72"}
};

//intervals for the key of B#
const map<string, string> B_SHARP = {
    {"c", "P12"}, {"b#", "P1"}, {"c#", "m2"}, {"db", "m22"}, {"d", "M2"}, {"d#", "m3"}, {"eb", "m32"},
    {"e", "M3"}, {"fb", "M32"}, {"e#", "P4"}, {"f", "P422"}, {"f#", "T"}, {"gb", "T2"}, {"g", "P5"},
    {"ab", "m62"}, {"g#", "m6"}, {"a", "M6"}, {"bb", "m72"}, {"a#", "m7"}, {"b", "M7"}, {"cb", "M72"}
};

//intervals for the key of C#
const map<string, string> C_SHARP = {
    {"c#", "P1"}, {"db", "P12"}, {"d", "m2"}, {"d#", "M2"}, {"eb", "M22"}, {"e", "m3"}, {"fb", "m32"},
    {"f", "M32"}, {"e#", "M3"}, {"f#", "P4"}, {"gb", "P42"}, {"g", "T"}, {"g#", "P5"}, {"ab", "P52"},
    {"a", "m6"}, {"a#", "M6"}, {"bb", "M62"}, {"b", "m7"}, {"cb", "m72"}, {"c", "M72"}, {"b#", "M7"}
};

//intervals for the key of Db
const map<string, string> D_FLAT = {
    {"c#", "P12"}, {"db", "P1"}, {"d", "m2"}, {"d#", "M22"}, {"eb", "M2"}, {"e", "m32"}, {"fb", "m3"},
    {"f", "M3"}, {"e#", "M32"}, {"gb", "P4"}, {"f#", "P42"}, {"g", "T"}, {"g#", "P52"}, {"ab", "P5"},
    {"a", "m6"}, {"a#", "M62"}, {"bb", "M6"}, {"b", "m72"}, {"cb", "m7"}, {"c", "M7"}, {"b#", "M72"}
};

//intervals for the key of D
const map<string, string> D_NATURAL = {
    {"d", "P1"}, {"d#", "m22"}, {"eb", "m2"}, {"e", "M2"}, {"fb", "M22"}, {"f", "m3"}, {"e#", "m32"},
    {"f#", "M3"}, {"gb", "M32"}, {"g", "P4"}, {"g#", "T"}, {"ab", "T2"}, {"a", "P5"}, {"a#", "m62"},
    {"bb", "m6"}, {"b", "M6"}, {"cb", "M62"}, {"b#", "m72"}, {"c", "m7"}, {"c#", "M7"}, {"db", "M72"}
};

//intervals for the key of Eb
const map<string, string> E_FLAT = {
    {"eb", "P1"}, {"d#", "P12"}, {"e", "m22"}, {"fb", "m2"}, {"f", "M2"}, {"e#", "M22"}, {"f#", "m32"}, {"gb", "m3"},
    {"g", "M3"}, {"ab", "P4"}, {"g#", "P42"}, {"a", "T"}, {"bb", "P5"}, {"a#", "P52"}, {"b", "m62"},
    {"cb", "m6"}, {"c", "M6"}, {"b#", "M62"}, {"db", "m7"}, {"c#", "m72"}, {"d", "M7"}
};

//intervals for the key of D#
const map<string, string> D_SHARP = {
    {"eb", "P12"}, {"d#", "P1"}, {"e", "m2"}, {"fb", "m22"}, {"f", "M22"}, {"e#", "M2"}, {"f#", "m3"}, {"gb", "m32"},
    {"g", "M3"}, {"g#", "P4"}, {"ab", "P42"}, {"a", "T"}, {"bb", "P52"}, {"a#", "P5"}, {"b", "m6"},
    {"cb", "m62"}, {"c", "M62"}, {"b#", "M6"}, {"db", "m72"}, {"c#", "m7"}, {"d", "M7"}
};

//intervals for the key of E
const map<string, string> E_NATURAL = {
    {"e", "P1"}, {"fb", "P12"}, {"f", "m2"}, {"e#", "m22"}, {"f#", "M2"}, {"gb", "M22"}, {"g", "m3"},
    {"g#", "M3"}, {"ab", "M32"}, {"a", "P4"}, {"a#", "T"}, {"bb", "T2"}, {"b", "P5"}, {"cb", "P52"}, {"c", "m6"},
    {"b#", "m62"}, {"c#", "M6"}, {"db", "M62"}, {"d", "m7"}, {"d#", "M7"}, {"eb", "M72"}
};

//intervals for the key of Fb
const map<string, string> F_FLAT = {
    {"e", "P12"}, {"fb", "P1"}, {"f", "m2"}, {"e#", "m22"}, {"f#", "M22"}, {"gb", "M2"}, {"g", "m3"},
    {"g#", "M32"}, {"ab", "M3"}, {"a", "P4"}, {"a#", "T2"}, {"bb", "T"}, {"b", "P52"}, {"cb", "P5"}, {"c", "m6"},
    {"b#", "m62"}, {"c#", "M62"}, {"db", "M6"}, {"d", "m7"}, {"d#", "M72"}, {"eb", "M7"}
};

//intervals for the key of F
const map<string, string> F_NATURAL = {
    {"f", "P1"}, {"e#", "P12"}, {"f#", "m22"}, {"gb", "m2"}, {"g", "M2"}, {"ab", "m3"}, {"g#", "m32"},
    {"a", "M3"}, {"bb", "P4"}, {"a#", "P42"}, {"b", "T"}, {"cb", "T2"}, {"c", "P5"}, {"b#", "P52"}, {"c#", "m62"},
    {"db", "m6"}, {"d", "M6"}, {"eb", "m7"}, {"d#", "m72"}, {"e", "M7"}, {"fb", "M72"}
};

//intervals for the key of E#
const map<string, string> E_SHARP = {
    {"f", "P12"}, {"e#", "P1"}, {"f#", "m2"}, {"gb", "m22"}, {"g", "M2"}, {"ab", "m32"}, {"g#", "m3"},
    {"a", "M3"}, {"a#", "P4"}, {"bb", "P42"}, {"b", "T"}, {"cb", "T2"}, {"c", "P52"}, {"b#", "P5"}, {"c#", "m6"},
    {"db", "m62"}, {"d", "M6"}, {"eb", "m72"}, {"d#", "m7"}, {"e", "M7"}, {"fb", "M72"}
};

//intervals for the key of F#
const map<string, string> F_SHARP = {
    {"f#", "P1"}, {"gb", "P12"}, {"g", "m2"}, {"ab", "M22"}, {"g#", "M2"}, {"a", "m3"}, {"bb", "M32"},
    {"a#", "M3"}, {"b", "P4"}, {"cb", "P42"}, {"c", "T2"}, {"b#", "T"}, {"c#", "P5"}, {"db", "P52"}, {"d", "m6"},
    {"eb", "M62"}, {"d#", "M6"}, {"e", "m7"}, {"fb", "m72"}, {"f", "M72"}, {"e#", "M7"}
};

//intervals for the key of Gb
const map<string, string> G_FLAT = {
    {"f#", "P12"}, {"gb", "P1"}, {"g", "m2"}, {"ab", "M2"}, {"g#", "M22"}, {"a", "m32"}, {"bb", "M3"},
    {"a#", "M3"}, {"cb", "P4"}, {"b", "P42"}, {"c", "T"}, {"b#", "T2"}, {"c#", "P52"}, {"db", "P5"}, {"d", "m6"},
    {"eb", "M6"}, {"d#", "M62"}, {"e", "m72"}, {"fb", "m7"}, {"f", "M7"}, {"e#", "M72"}
};

//intervals for the key of G
const map<string, string> G_NATURAL = {
    {"g", "P1"}, {"ab", "m2"}, {"g#", "m22"}, {"M2", "a"}, {"bb", "m3"}, {"a#", "m32"}, {"b", "M3"},
    {"cb", "M32"}, {"c", "P4"}, {"b#", "P42"}, {"c#", "T"}, {"db", "T2"}, {"d", "P5"}, {"eb", "m6"}, {"d#", "m62"},
    {"e", "M6"}, {"fb", "M62"}, {"f", "m7"}, {"e#", "m72"}, {"f#", "M7"}, {"gb", "M72"}
};

//intervals for the key of Ab
const map<string, string> A_FLAT = {
    {"ab", "P1"}, {"g#", "P12"}, {"a", "m2"}, {"a#", "M22"}, {"bb", "M2"}, {"b", "m32"}, {"cb", "m3"}, {"c", "M3"},
    {"b#", "M32"}, {"db", "P4"}, {"c#", "P42"}, {"d", "T"}, {"eb", "P5"}, {"d#", "P52"}, {"e", "m62"}, {"fb", "m6"},
    {"e#", "M62"}, {"f", "M6"}, {"f#", "m72"}, {"gb", "m7"}, {"g", "M7"}
};

//intervals for the key of G#
const map<string, string> G_SHARP = {
    {"ab", "P12"}, {"g#", "P1"}, {"a", "m2"}, {"a#", "M2"}, {"bb", "M22"}, {"b", "m3"}, {"cb", "m32"}, {"c", "M32"},
    {"b#", "M3"}, {"c#", "P4"}, {"db", "P42"}, {"d", "T"}, {"eb", "P52"}, {"d#", "P5"}, {"e", "m6"}, {"fb", "m62"},
    {"e#", "M6"}, {"f", "M62"}, {"f#", "m7"}, {"gb", "m72"}, {"g", "M7"}
};

//intervals for the key of A
const map<string, string> A_NATURAL = {
    {"a", "P1"}, {"bb", "m2"}, {"a#", "m22"}, {"b", "M2"}, {"cb", "M22"}, {"c", "m3"}, {"b#", "m32"}, {"c#", "M3"},
    {"db", "M32"}, {"d", "P4"}, {"eb", "T2"}, {"d#", "T"}, {"e", "P5"}, {"fb", "P52"}, {"e#", "m62"}, {"f", "m6"},
    {"f#", "M6"}, {"gb", "M62"}, {"g", "m7"}, {"g#", "M7"}, {"ab", "M72"}
};

//intervals for the key of Bb
const map<string, string> B_FLAT = {
    {"bb", "P1"}, {"a#", "P12"}, {"b", "m22"}, {"cb", "m2"}, {"c", "M2"}, {"b#", "M22"}, {"db", "m3"}, {"c#", "m32"},
    {"d", "M3"}, {"eb", "P4"}, {"d#", "P42"}, {"e", "T"}, {"fb", "T2"}, {"f", "P5"}, {"e#", "P52"}, {"gb", "m6"}, {"f#", "m62"}, {"g", "M6"},
    {"ab", "m7"}, {"g#", "m72"}, {"a", "M7"}
};

//intervals for the key of A#
const map<string, string> A_SHARP = {
    {"bb", "P12"}, {"a#", "P1"}, {"b", "m2"}, {"cb", "m22"}, {"c", "M22"}, {"b#", "M2"}, {"db", "m32"}, {"c#", "m3"},
    {"d", "M3"}, {"d#", "P4"}, {"eb", "P42"}, {"e", "T"}, {"fb", "T2"}, {"f", "P52"}, {"e#", "P5"}, {"gb", "m62"}, {"f#", "m6"},
    {"g", "M6"}, {"ab", "m72"}, {"g#", "m7"}, {"a", "M7"}
};

//intervals for the key of B
const map<string, string> B_NATURAL = {
    {"b", "P1"}, {"cb", "P12"}, {"b#", "m22"}, {"c", "m2"}, {"c#", "M2"}, {"db", "M22"}, {"d", "m3"}, {"d#", "M3"},
    {"eb", "M32"}, {"e", "P4"}, {"fb", "P42"}, {"e#", "T"}, {"f", "T2"}, {"f#", "P5"}, {"gb", "P52"}, {"g", "m6"},
    {"g#", "M6"}, {"ab", "M62"}, {"a", "m7"}, {"a#", "M7"}, {"bb", "M72"}
};

//intervals for the key of Cb
const map<string, string> C_FLAT = {
    {"b", "P12"}, {"cb", "P1"}, {"b#", "m22"}, {"c", "m2"}, {"c#", "M22"}, {"db", "M2"}, {"d", "m3"}, {"d#", "M32"},
    {"eb", "M3"}, {"fb", "P4"}, {"e", "P42"}, {"e#", "T2"}, {"f", "T"}, {"f#", "P52"}, {"gb", "P5"}, {"g", "m6"},
    {"g#", "M62"}, {"ab", "M6"}, {"a", "m7"}, {"a#", "M72"}, {"bb", "M7"}
};


//Array of pairs and pointers so the program can find which array from above to us given a user-inputted string
//P.S. I know that using an unordered_map is ideal for this and I will switch to that, but it's not agreeing with
//the compiler at the given moment
pair<string, map<string, string>> ARRAY_KEY[] = {
    {"c", C_NATURAL}, {"b#", B_SHARP}, {"c#", C_SHARP}, {"db", D_FLAT}, {"d", D_NATURAL}, {"d#", D_SHARP},
    {"eb", E_FLAT}, {"e", E_NATURAL}, {"fb", F_FLAT}, {"f", F_NATURAL}, {"e#", E_SHARP}, {"f#", F_SHARP},
    {"gb", G_FLAT}, {"g", G_NATURAL}, {"g#", G_SHARP}, {"ab", A_FLAT}, {"a", A_NATURAL}, {"a#", A_SHARP},
    {"bb", B_FLAT}, {"b", B_NATURAL}, {"cb", C_FLAT}
};

//hopefully the last set of constants
//here are constants for each interval name so we don't just have random "magic inputs" in the rest of the program
const string UNISON = "P1";
const string ALT_UNISON = "P12";
const string MINOR_SECOND = "m2";
const string ALT_MINOR_SECOND = "m22";
const string MAJOR_SECOND = "M2";
const string ALT_MAJOR_SECOND = "M22";
const string MINOR_THIRD = "m3";
const string ALT_MINOR_THIRD = "m32";
const string MAJOR_THIRD = "M3";
const string ALT_MAJOR_THIRD = "M32";
const string PERFECT_FOURTH = "P4";
const string ALT_PERFECT_FOURTH = "P42";
const string TRITONE = "T";
const string ALT_TRITONE = "T2";
const string PERFECT_FIFTH = "P5";
const string ALT_PERFECT_FIFTH = "P52";
const string MINOR_SIXTH = "m6";
const string ALT_MINOR_SIXTH = "m62";
const string MAJOR_SIXTH = "M6";
const string ALT_MAJOR_SIXTH = "M62";
const string MINOR_SEVENTH = "m7";
const string ALT_MINOR_SEVENTH = "m72";
const string MAJOR_SEVENTH = "M7";
const string ALT_MAJOR_SEVENTH = "M72";

#endif /* intervals_h */
