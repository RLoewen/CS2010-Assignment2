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
void SortInsert(DICT);

/*
  note that these are global variables so that they are already initialized to 0
*/

DICT dictionary;  //your dictionary 
WORD word;        // 
int freq[MAX];   //tracks word frequencies
int numWords = 0;


// Sort the dictionary with an Insertion Sort

void SortInsert(DICT dict){
WORD temp;
int tempFreq;
int k;
  for(int i=1; i<(numWords); ++i) 
  {
    for(int j=0; j<i;++j)
        if(dict[j]>dict[i])
// sorting in ascending order
        {
          // backup the current word to be sorted and it's corresponding frequency
          temp = dict[i];   
          tempFreq = freq[i];
          k=i;  
          while(k!=j)
          {

            dict[k]=dict[k-1];
            freq[k]=freq[k-1];
            --k;

          }
          // insert current word and it's frequency into the new location
          dict[j]=temp;
          freq[j]=tempFreq;
        }          
    
  }

}


BOOL InsertWord(DICT dict, WORD word)
{
/* 
  adds word to dictionary , if word can't be added returns 0 else returns 1
*/

  if(!FullDictionary(dict)){
  freq[numWords]++;      //increment the occurence count for the new word
  dict[numWords] = word;  // add the word to the next available spot in the dictionary

  numWords++;             // increment numWords
  return true;
  }
return false;
}



void DumpDictionary(DICT dict, int freq[]) {
/* 
  will sort the dictionary, and display the contents

*/
 

 // run an InsertionSort on dictionary
SortInsert(dict);

  // once sorting is complete print out the dictionary of words along with their occurences



  for (int i =0; i< (numWords);i++){

    cout << dict[i] << "\t\t\t\t" << freq[i] << endl;
  }
}




WORD GetNextWord(void){
/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or empty line if no more words in input stream
*/


   int newLine = 0;
WORD CurrentWord = "";
char ch;

while( cin.good() )
  {
  
  ch = tolower(cin.get());  // get a character and convert it to lower case
 if ( isalpha(ch) )  /* function test if ch  is A-Z, a-z */
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
   if dictionary is full, return true, else false
 */

    if (dict[(MAX-1)].empty())return false;  // if the last word in dict is empty then return 0, otherwise return 1 since it's full
  else return true;

}

int LocateWord(DICT dict, WORD word) {
/*
   will determine if dictionary contains word. if found, returns position else returns value -1
*/

   for (int i = 0; i < numWords; i++) // searches through current numWords for the current word
  {
    if( dict[i] == word)return i; // returns the location of the word if it's found
  }
return -1;
}
