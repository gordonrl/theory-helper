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
 I'm doing separate arrays for the same keys written differently (like C# and Db)
 */

/*
 There also needs to be a pointer to each array because we need to be able to read in
 the name of a chord and determine which array to use.
 
 This can be done by having an array of pairs whose first value is a chord name and whose
 second value is a pointer to the correct array
 */

//Here are a few constants for chord types
const string MINOR = "minor";
const string MAJOR = "major";
const string DOMINANT = "dominant";

//Here are the acceptable chords/notes for checking
const int VALID_NOTES_SIZE = 21;
const string VALID_NOTES[] = {"c", "b#", "c#", "db", "d", "d#", "eb", "e", "fb", "f", "e#", "f#", "gb", "g", "g#", "ab", "a", "bb", "a#", "b", "cb"};


const int INTERVAL_ARR_SIZE = 21;
//intervals for the key of C
const pair<string, string> C_NATURAL[] = {
    {"P1", "c"}, {"P12", "b#"}, {"m2", "c#"}, {"m22", "db"}, {"M2", "d"}, {"m3", "d#"}, {"m32", "eb"},
    {"M3", "e"}, {"M32", "fb"}, {"P4", "f"}, {"P42", "e#"}, {"T", "f#"}, {"T2", "Gb"}, {"P5", "g"},
    {"m6", "ab"}, {"m62", "g#"}, {"M6", "a"}, {"m7", "bb"}, {"m72", "a#"}, {"M7", "b"}, {"M72", "cb"}
};
const pair<string, string> *C_NAT_PTR = C_NATURAL;

//intervals for the key of B#
const pair<string, string> B_SHARP[] = {
    {"P1", "c"}, {"P12", "b#"}, {"m2", "c#"}, {"m22", "db"}, {"M2", "d"}, {"m3", "d#"}, {"m32", "eb"},
    {"M3", "e"}, {"M32", "fb"}, {"P4", "f"}, {"P42", "e#"}, {"T", "f#"}, {"T2", "Gb"}, {"P5", "g"},
    {"m6", "ab"}, {"m62", "g#"}, {"M6", "a"}, {"m7", "bb"}, {"m72", "a#"}, {"M7", "b"}, {"M72", "cb"}
};
const pair<string, string> *B_SHARP_PTR = B_SHARP;

//intervals for the key of C#
const pair<string, string> C_SHARP[] = {
    {"P1", "c#"}, {"P12", "db"}, {"m2", "d"}, {"M2", "d#"}, {"M22", "eb"}, {"m3", "e"}, {"m32", "fb"},
    {"M3", "f"}, {"M32", "e#"}, {"P4", "f#"}, {"P42", "gb"}, {"T", "g"}, {"P5", "g#"}, {"P52", "ab"},
    {"m6", "a"}, {"M6", "a#"}, {"M62", "bb"}, {"m7", "b"}, {"m72", "cb"}, {"M7", "c"}, {"M72", "b#"}
};
const pair<string, string> *C_SHARP_PTR = C_SHARP;

//intervals for the key of Db
const pair<string, string> D_FLAT[] = {
    {"P1", "c#"}, {"P12", "db"}, {"m2", "d"}, {"M2", "d#"}, {"M22", "eb"}, {"m3", "e"}, {"m32", "fb"},
    {"M3", "f"}, {"M32", "e#"}, {"P4", "f#"}, {"P42", "gb"}, {"T", "g"}, {"P5", "g#"}, {"P52", "ab"},
    {"m6", "a"}, {"M6", "a#"}, {"M62", "bb"}, {"m7", "b"}, {"m72", "cb"}, {"M7", "c"}, {"M72", "b#"}
};
const pair<string, string> *D_FLAT_PTR = D_FLAT;

//intervals for the key of D
const pair<string, string> D_NATURAL[] = {
    {"P1", "d"}, {"m2", "d#"}, {"m22", "eb"}, {"M2", "e"}, {"M22", "fb"}, {"m3", "f"}, {"m32", "e#"},
    {"M3", "f#"}, {"M32", "gb"}, {"P4", "g"}, {"T", "g#"}, {"T2", "ab"}, {"P5", "a"}, {"m6", "a#"},
    {"m62", "bb"}, {"M6", "b"}, {"M62", "cb"}, {"m7", "b#"}, {"m72", "c"}, {"M7", "c#"}, {"M72", "db"}
};
const pair<string, string> *D_NAT_PTR = D_NATURAL;

//intervals for the key of Eb
const pair<string, string> E_FLAT[] = {
    {"P1", "eb"}, {"P12", "d#"}, {"m2", "e"}, {"m22", "fb"}, {"M2", "f"}, {"M22", "e#"}, {"m3", "f#"}, {"m32", "gb"},
    {"M3", "g"}, {"P4", "ab"}, {"P42", "g#"}, {"T", "a"}, {"P5", "bb"}, {"P52", "a#"}, {"m6", "b"},
    {"m62", "cb"}, {"M6", "c"}, {"M62", "b#"}, {"m7", "db"}, {"m72", "c#"}, {"M7", "d"}
};
const pair<string, string> *E_FLAT_PTR = E_FLAT;

//intervals for the key of D#
const pair<string, string> D_SHARP[] = {
    {"P1", "eb"}, {"P12", "d#"}, {"m2", "e"}, {"m22", "fb"}, {"M2", "f"}, {"M22", "e#"}, {"m3", "f#"}, {"m32", "gb"},
    {"M3", "g"}, {"P4", "ab"}, {"P42", "g#"}, {"T", "a"}, {"P5", "bb"}, {"P52", "a#"}, {"m6", "b"},
    {"m62", "cb"}, {"M6", "c"}, {"M62", "b#"}, {"m7", "db"}, {"m72", "c#"}, {"M7", "d"}
};
const pair<string, string> *D_SHARP_PTR = D_SHARP;

//intervals for the key of E
const pair<string, string> E_NATURAL[] = {
    {"P1", "e"}, {"P12", "fb"}, {"m2", "f"}, {"m22", "e#"}, {"M2", "f#"}, {"M22", "gb"}, {"m3", "g"},
    {"M3", "g#"}, {"M32", "ab"}, {"P4", "a"}, {"T", "a#"}, {"T2", "bb"}, {"P5", "b"}, {"P52", "cb"}, {"m6", "c"},
    {"m62", "b#"}, {"M6", "c#"}, {"M62", "db"}, {"m7", "d"}, {"M7", "d#"}, {"M72", "eb"}
};
const pair<string, string> *E_NAT_PTR = E_NATURAL;

//intervals for the key of Fb
const pair<string, string> F_FLAT[] = {
    {"P1", "e"}, {"P12", "fb"}, {"m2", "f"}, {"m22", "e#"}, {"M2", "f#"}, {"M22", "gb"}, {"m3", "g"},
    {"M3", "g#"}, {"M32", "ab"}, {"P4", "a"}, {"T", "a#"}, {"T2", "bb"}, {"P5", "b"}, {"P52", "cb"}, {"m6", "c"},
    {"m62", "b#"}, {"M6", "c#"}, {"M62", "db"}, {"m7", "d"}, {"M7", "d#"}, {"M72", "eb"}
};
const pair<string, string> *F_FLAT_PTR = F_FLAT;

//intervals for the key of F
const pair<string, string> F_NATURAL[] = {
    {"P1", "f"}, {"P12", "e#"}, {"m2", "f#"}, {"m22", "gb"}, {"M2", "g"}, {"m3", "ab"}, {"m32", "g#"},
    {"M3", "a"}, {"P4", "bb"}, {"P42", "a#"}, {"T", "b"}, {"T2", "cb"}, {"P5", "c"}, {"P52", "b#"}, {"m6", "c#"},
    {"m62", "db"}, {"M6", "d"}, {"m7", "eb"}, {"m72", "d#"}, {"M7", "e"}, {"M72", "fb"}
};
const pair<string, string> *F_NAT_PTR = F_NATURAL;

//intervals for the key of E#
const pair<string, string> E_SHARP[] = {
    {"P1", "f"}, {"P12", "e#"}, {"m2", "f#"}, {"m22", "gb"}, {"M2", "g"}, {"m3", "ab"}, {"m32", "g#"},
    {"M3", "a"}, {"P4", "bb"}, {"P42", "a#"}, {"T", "b"}, {"T2", "cb"}, {"P5", "c"}, {"P52", "b#"}, {"m6", "c#"},
    {"m62", "db"}, {"M6", "d"}, {"m7", "eb"}, {"m72", "d#"}, {"M7", "e"}, {"M72", "fb"}
};
const pair<string, string> *E_SHARP_PTR = E_SHARP;

//intervals for the key of F#
const pair<string, string> F_SHARP[] = {
    {"P1", "f#"}, {"P12", "gb"}, {"m2", "g"}, {"M2", "ab"}, {"M22", "g#"}, {"m3", "a"}, {"M3", "bb"},
    {"M32", "a#"}, {"P4", "b"}, {"P42", "cb"}, {"T", "c"}, {"T2", "b#"}, {"P5", "c#"}, {"P52", "db"}, {"m6", "d"},
    {"M6", "eb"}, {"M62", "d#"}, {"m7", "e"}, {"m72", "fb"}, {"M7", "f"}, {"M72", "e#"}
};
const pair<string, string> *F_SHARP_PTR = F_SHARP;

//intervals for the key of Gb
const pair<string, string> G_FLAT[] = {
    {"P1", "f#"}, {"P12", "gb"}, {"m2", "g"}, {"M2", "ab"}, {"M22", "g#"}, {"m3", "a"}, {"M3", "bb"},
    {"M32", "a#"}, {"P4", "b"}, {"P42", "cb"}, {"T", "c"}, {"T2", "b#"}, {"P5", "c#"}, {"P52", "db"}, {"m6", "d"},
    {"M6", "eb"}, {"M62", "d#"}, {"m7", "e"}, {"m72", "fb"}, {"M7", "f"}, {"M72", "e#"}
};
const pair<string, string> *G_FLAT_PTR = G_FLAT;

//intervals for the key of G
const pair<string, string> G_NATURAL[] = {
    {"P1", "g"}, {"m2", "ab"}, {"m22", "g#"}, {"M2", "a"}, {"m3", "bb"}, {"m32", "a#"}, {"M3", "b"},
    {"M32", "cb"}, {"P4", "c"}, {"P42", "b#"}, {"T", "c#"}, {"T2", "db"}, {"P5", "d"}, {"m6", "eb"}, {"m62", "d#"},
    {"M6", "e"}, {"M62", "fb"}, {"m7", "f"}, {"m72", "e#"}, {"M7", "f#"}, {"M72", "gb"}
};
const pair<string, string> *G_NAT_PTR = G_NATURAL;

//intervals for the key of Ab
const pair<string, string> A_FLAT[] = {
    {"P1", "ab"}, {"P12", "g#"}, {"m2", "a"}, {"M2", "a#"}, {"M22", "bb"}, {"m3", "b"}, {"m32", "cb"}, {"M3", "c"},
    {"M32", "b#"}, {"P4", "c#"}, {"P42", "db"}, {"T", "d"}, {"P5", "eb"}, {"P52", "d#"}, {"m6", "e"}, {"m62", "fb"},
    {"M6", "e#"}, {"M62", "f"}, {"m7", "f#"}, {"m72", "gb"}, {"M7", "g"}
};
const pair<string, string> *A_FLAT_PTR = A_FLAT;

//intervals for the key of G#
const pair<string, string> G_SHARP[] = {
    {"P1", "ab"}, {"P12", "g#"}, {"m2", "a"}, {"M2", "a#"}, {"M22", "bb"}, {"m3", "b"}, {"m32", "cb"}, {"M3", "c"},
    {"M32", "b#"}, {"P4", "c#"}, {"P42", "db"}, {"T", "d"}, {"P5", "eb"}, {"P52", "d#"}, {"m6", "e"}, {"m62", "fb"},
    {"M6", "e#"}, {"M62", "f"}, {"m7", "f#"}, {"m72", "gb"}, {"M7", "g"}
};
const pair<string, string> *G_SHARP_PTR = G_SHARP;

//intervals for the key of A
const pair<string, string> A_NATURAL[] = {
    {"P1", "a"}, {"m2", "bb"}, {"m22", "a#"}, {"M2", "b"}, {"M22", "cb"}, {"m3", "c"}, {"m32", "b#"}, {"M3", "c#"},
    {"M32", "db"}, {"P4", "d"}, {"T", "eb"}, {"T2", "d#"}, {"P5", "e"}, {"P52", "fb"}, {"m6", "e#"}, {"m62", "f"},
    {"M6", "f#"}, {"M62", "gb"}, {"m7", "g"}, {"M7", "g#"}, {"M72", "ab"}
};
const pair<string, string> *A_NAT_PTR = A_NATURAL;

//intervals for the key of Bb
const pair<string, string> B_FLAT[] = {
    {"P1", "bb"}, {"P12", "a#"}, {"m2", "b"}, {"m22", "cb"}, {"M2", "c"}, {"M22", "b#"}, {"m3", "db"}, {"m32", "c#"},
    {"M3", "d"}, {"P4", "eb"}, {"P42", "d#"}, {"T", "e"}, {"T2", "fb"}, {"P5", "f"}, {"m6", "gb"}, {"m62", "f#"}, {"M6", "g"},
    {"m7", "ab"}, {"m72", "g#"}, {"M7", "a"}
};
const pair<string, string> *B_FLAT_PTR = B_FLAT;

//intervals for the key of A#
const pair<string, string> A_SHARP[] = {
    {"P1", "bb"}, {"P12", "a#"}, {"m2", "b"}, {"m22", "cb"}, {"M2", "c"}, {"M22", "b#"}, {"m3", "db"}, {"m32", "c#"},
    {"M3", "d"}, {"P4", "eb"}, {"P42", "d#"}, {"T", "e"}, {"T2", "fb"}, {"P5", "f"}, {"m6", "gb"}, {"m62", "f#"}, {"M6", "g"},
    {"m7", "ab"}, {"m72", "g#"}, {"M7", "a"}
};
const pair<string, string> *A_SHARP_PTR = A_SHARP;

//intervals for the key of B
const pair<string, string> B_NATURAL[] = {
    {"P1", "b"}, {"P12", "cb"}, {"m2", "b#"}, {"m22", "c"}, {"M2", "c#"}, {"M22", "db"}, {"m3", "d"}, {"M3", "d#"},
    {"M32", "eb"}, {"P4", "e"}, {"P42", "fb"}, {"T", "e#"}, {"T2", "f"}, {"P5", "f#"}, {"P52", "gb"}, {"m6", "g"},
    {"M6", "g#"}, {"M62", "ab"}, {"m7", "a"}, {"M7", "a#"}, {"M72", "bb"}
};
const pair<string, string> *B_NAT_PTR = B_NATURAL;

//MAKE ARRAY OF PAIRS OR WHATEVER

#endif /* intervals_h */
