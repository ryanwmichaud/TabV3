
#include <map>
using namespace std;

class MusicString{

    public:
        //class variables - table for note name to note number conversion
        static  vector<string> notes;
        static map<string, int> nameMap;
        //static methods
        static std::string getNoteName(int noteNum);
        static int getNoteNum(string noteName);

        //instance variables for this string
        int open;
        int frets;

        //methods
        MusicString(int openParam, int fretsParam);
        ~MusicString();

        int getFretOctave(int noteNum);
        int getFret(int noteNum);
        int getFret(std::string note);
        int getName();

        

      
    
    private:
        std::map<int, int> stringMap;
        void buildMap(int open, int frets);


};