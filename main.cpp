#include <iostream>
#include <vector>
#include <string>
#include "MusicString.cpp"



//enum notes {C,C#,D,D#,E,F,F#,G,G#,A,A#,B};
//std::vector<string>::iterator it;

//class variables
std::vector<std::string> MusicString::notes = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
std::map<std::string, int> MusicString::nameMap;

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
    std::vector<MusicString> musicStrings = {s1,s2,s3,s4,s5,s6};


    std::vector<std::string> melody = {"B3", "C#4", "D4", "E4"};
    
    for(int i=0; i<melody.size(); i++){
        for(int stringNum=0;stringNum<musicStrings.size();stringNum++){ //for each string
            musicStrings[stringNum].printBuffer.append("-");
            int fret = musicStrings[stringNum].getFret(melody[i]);
            if (fret != -1){
                musicStrings[stringNum].printBuffer.append(std::to_string(fret));
                if(fret<10){
                    musicStrings[stringNum].printBuffer.append("-");
                }
            }else{
                musicStrings[stringNum].printBuffer.append("--");
            }
            
        }
    }
    

    for(int stringNum=0;stringNum<musicStrings.size();stringNum++){ //for each string
        std::cout << musicStrings[stringNum].printBuffer << '\n';
        
    }


/*
    for(int i=0;i<musicStrings.size();i++){
        //find a note on each string
        cout << getNoteName(musicStrings[i].getName()) << " on " << musicStrings[i].getFret(getNoteNum("C#4"))<< '\n';
    }
*/

    
}

