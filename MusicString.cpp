#include "MusicString.h"



//constructors
MusicString::MusicString(int openParam, int fretsParam){
    openNum = openParam;
    openName = getNoteName(openNum);
    frets = fretsParam;
    buildMap(openNum, frets);
    printBuffer = openName;  //makes a copy. not a reference. 
}

MusicString::MusicString(std::string openParam, int fretsParam){
    openName = openParam;
    openNum = getNoteNum(openName);
    frets = fretsParam;
    buildMap(openNum, frets);
    printBuffer = openName;
}

MusicString::~MusicString(){
}

void MusicString::buildMap(int open, int frets){
    for(int i=0;i<=frets;i++){ 
       stringMap[open+i]=i;
    }
}

int MusicString::getFretOctave(int noteNum){
    
    try{
        return stringMap.at(noteNum);
    }catch(std::out_of_range e){
        //cout << "getFret error: " << e.what();
        return -1;
    }
    
}



int MusicString::getFret(std::string noteName){

    int noteNum = getNoteNum(noteName);
    
    try{
        return stringMap.at(noteNum);
    }catch(std::out_of_range e){
        //cout << "getFret error: " << e.what();
        return -1;
    }

}

std::string MusicString::getOpenName(){
    return openName;
}

int MusicString::getOpenNum(){
    return openNum;
}



//static methods 

std::string MusicString::getNoteName(int noteNum){
    std::string name = "";
    int note = noteNum%12;
    int octave = noteNum/12;
    name.append(MusicString::notes[note]);
    name.append(std::to_string(octave));
    return name;
}


int MusicString::getNoteNum(std::string noteName){
    try{
        int noteNum = 0;
        int octave = stoi(noteName.substr(noteName.length()-1,noteName.length()));  //
        noteNum += (octave) *12;
        int note = MusicString::nameMap.at(noteName.substr(0,noteName.length()-1));
        noteNum += note;
        return noteNum;
    }catch(std::out_of_range e ){
        std::cout << "error, invalid note name: "  << e.what();
        return -1;
    }
}