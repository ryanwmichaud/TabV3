#include "MusicString.h"




MusicString::MusicString(int openParam, int fretsParam){
    open = openParam;
    frets = fretsParam;
    buildMap(open, frets);
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
    }catch(out_of_range e){
        //cout << "getFret error: " << e.what();
        return -1;
    }
    
}


int MusicString::getFret(int noteNum){
    
    try{
        return stringMap.at(noteNum);
    }catch(out_of_range e){
        //cout << "getFret error: " << e.what();
        return -1;
    }
    
}

int MusicString::getFret(std::string noteName){

    int noteNum = getNoteNum(noteName);
    
    try{
        return stringMap.at(noteNum);
    }catch(out_of_range e){
        //cout << "getFret error: " << e.what();
        return -1;
    }
    
}

int MusicString::getName(){
    return open;
}




string MusicString::getNoteName(int noteNum){
    string name = "";
    int note = noteNum%12;
    int octave = noteNum/12;
    name.append(MusicString::notes[note]);
    name.append(to_string(octave));
    return name;
}


int MusicString::getNoteNum(string noteName){
    try{
        int noteNum = 0;
        int octave = stoi(noteName.substr(noteName.length()-1,noteName.length()));  //
        noteNum += (octave) *12;
        int note = MusicString::nameMap.at(noteName.substr(0,noteName.length()-1));
        noteNum += note;
        return noteNum;
    }catch(out_of_range e ){
        cout << "error, invalid note name: "  << e.what();
        return -1;
    }
}