

BOOL InsertWord(DICT dict, WORD word)
{
/* 
  adds word to dictionary , if word can't be added returns 0 else returns 1
*/

if(!FullDictionary(dict)){
	count [NEXT]++;
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

  	cout << dict[i] << "		" << count[i] << endl;
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


/* 
   if dictionary is full, return 1 else 0 
 */
BOOL FullDictionary(DICT dict) {
if (!dict[(MAX-1)].empty())return false;	// if the last word in dict is empty then return 0, otherwise return 1 since it's full
	else return true;
}


/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/
int LocateWord(DICT dict, WORD word) {
	for (int i = 0; i < word; i++)
	{
		if( !strcmp(dict[i],word))return i; // returns the location of the word if it's found
	}
return -1;

}