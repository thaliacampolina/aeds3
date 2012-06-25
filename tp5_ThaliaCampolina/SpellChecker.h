#ifndef _SpellChecker_h_ 
#define _SpellChecker_h_ 
int countWordCharacter(char* count_word) ;

int LengthStr(char* word);

int EqualWords(char* word, char* word_dic);

int CalculatesDistance(char* word, char* word_dic) ;

void FindMinorDistance(List* list ,FILE* dictionary, FILE* stopwords, int word_counter);

void* CreateOutput(FILE* output, int word_counter, int char_counter, List* words);

void ReadFromFile(FILE* input, FILE* output, List* words, FILE* dictionary, FILE* stopwords);
#endif
