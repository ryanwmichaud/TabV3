
notes = ["C","C#","D","D#","E","F","F#","G","G#","A","A#","B"]
noteMap = dict()

for i in range(12):
    noteMap[notes[i]]=i

print(noteMap)

class MusicString:
    
    open = ""
    frets = 0

    def __innit__(self, openArg, fretsArg):
        self.open = openArg
        self.frets = fretsArg
    
    def getFret(num):
        return 


def main():
    print('hello')

main()