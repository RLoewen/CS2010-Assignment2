#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

/*
  you will have to write code for these 5 functions. 
*/

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);

/*
  note that these are global variables so that they are already initialized to 0
*/

DICT dictionary;  //your dictionary 
WORD word;        // 
int count[MAX];   //tracks word frequencies
int NEXT = 0;

BOOL InsertWord(DICT dict, WORD word)
{
/* 
  adds word to dictionary , if word can't be added returns 0 else returns 1
*/

  if(!FullDictionary(dict)){
  count[NEXT]++;
  dict[NEXT] = word;

  NEXT++;
  return true;
  }
return false;
}

void DumpDictionary(DICT dict, int count[]) {
/* 
  will sort the dictionary, and display the contents
*/

  for (int i =0; i< (NEXT);i++){

    cout << dict[i] << "    " << count[i] << endl;
  }
}

WORD GetNextWord(void){
/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or 0 if no more words in input stream
*/


   int newLine = 0;
WORD CurrentWord = "";
char ch;

while( cin.good() )
  {
  
  ch = tolower(cin.get());
 if ( isalpha(ch) )  /* function test is ch  is A-Z, a-z */
        {
       CurrentWord += ch;
    newLine = 1;
        }
 else
       if (newLine)
            {
          
          return CurrentWord; 

          }
  }
return CurrentWord;
}

BOOL FullDictionary(DICT dict) {
/* 
   if dictionary is full, return 1 else 0 
 */

    if (!dict[(MAX-1)].empty())return false;  // if the last word in dict is empty then return 0, otherwise return 1 since it's full
  else return true;
}

int LocateWord(DICT dict, WORD word) {
/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/
}

int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( 0 == word.length() )  {
           cout << "Word\t\tFrequency\n-------------------\n";
           DumpDictionary(dictionary,count);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}