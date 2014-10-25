#include "dictionary.cpp"
int main (void) {
    int pos;      // will hold the position of a word if it is found by LocateWord function
    //extern DICT dictionary;  //your dictionary 
    //extern WORD word;        // 
    //extern int freq[MAX];   //tracks word frequencies
    while (1) {
       word = GetNextWord();
       if ( 0 == word.length() )  {
           cout << "Word\t\t\t\tFrequency\n-----------------------------------------\n";
           DumpDictionary(dictionary,freq);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           freq[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}