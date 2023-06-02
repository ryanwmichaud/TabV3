#include <iostream>
#include <vector>
#include <string>
#include "MusicString.cpp"



//enum notes {C,C#,D,D#,E,F,F#,G,G#,A,A#,B};
//std::vector<string>::iterator it;

//class variables
vector<string> MusicString::notes = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
map<string, int> MusicString::nameMap;

int main(){

    //populate name map class variable
    for (int i=0;i<12;i++){
        MusicString::nameMap[MusicString::notes[i]] = i;
    }

    //create music strings
    MusicString s1 = MusicString(MusicString::getNoteNum("E4"),12);
    MusicString s2 = MusicString(MusicString::getNoteNum("B3"),12);
    MusicString s3 = MusicString(MusicString::getNoteNum("G3"),12);
    MusicString s4 = MusicString(MusicString::getNoteNum("D3"),12);
    MusicString s5 = MusicString(MusicString::getNoteNum("A2"),12);
    MusicString s6 = MusicString(MusicString::getNoteNum("E2"),12);
    vector<MusicString> musicStrings = {s1,s2,s3,s4,s5,s6};


    vector<std::string> chord = {"C", "E", "G"};
    std::cout << musicStrings[0].getFret(64);
    std::cout << MusicString::getNoteName(64);
    std::cout << MusicString::getNoteNum("E5");
/*
    for(int i=0;i<musicStrings.size();i++){
        //find a note on each string
        cout << getNoteName(musicStrings[i].getName()) << " on " << musicStrings[i].getFret(getNoteNum("C#4"))<< '\n';
    }
*/

    
}

