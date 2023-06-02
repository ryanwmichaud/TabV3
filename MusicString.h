
#include <map>

class MusicString{

    public:
        //class variables - table for note name to note number conversion
        static  std::vector<std::string> notes;
        static std::map<std::string, int> nameMap;
        //static methods
        static std::string getNoteName(int noteNum);
        static int getNoteNum(std::string noteName);

        //instance variables for this string
        int openNum;
        std::string openName;
        int frets;
        std::string printBuffer;

        //methods
        MusicString(int openParam, int fretsParam);
        MusicString(std::string openParam, int fretsParam);
        ~MusicString();

        int getFretOctave(int noteNum);
        int getFret(std::string note);
        
        std::string getOpenName();
        int getOpenNum();

        

      
    
    private:
        std::map<int, int> stringMap;
        void buildMap(int open, int frets);


};