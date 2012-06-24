#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include "list.c"


void ReadFromFile(FILE* input, List* words, FILE* dictionary, FILE* stopwords){
    char* word=calloc(100,sizeof(char));
    char* empty;
    int word_counter=0;
    int char_counter=0;


//CREATE WORDS LIST    
    while(fscanf(input,"%s",word)>0){ 
        Node* node = NewNode(word, words->end_, words->end_);
printf("NODE: %s ",node->info_);
        InsertBack(words, word);  
        word_counter++;
        char_counter = countWordCharacter(word) + char_counter;
printf("LIST:%s ",node->info_);
    }
printf("\n \n number of char: %d \n number of words %d\n \n",char_counter,word_counter);


FindMinorDistance(words, dictionary, stopwords);

printf("\n \n waka waka eh eh \n");

}



int countWordCharacter(char* count_word) {
    int i = 0;
    while(count_word[i]!= '\0'){
        i++;
    }
    return i;
}

int LengthStr(char* word){
    int i=0;
    while(word[i]!='\0'){
        i++;
    }
    return i;
}



int EqualWords(char* word, char* word_dic){
    int i=0;
    int sub=CalculatesDistance(word,word_dic);
    if(LengthStr(word)==LengthStr(word_dic)){
        if (sub==0) return 1;
    }
    return 0;
}


int CalculatesDistance(char* word, char* word_dic) {
    int i=0;
    int dif=0;
    while( i != LengthStr(word) && word_dic[i]!='\0'){
        if(word[i]!=word_dic[i]){
            dif++;
        }
        i++;
    }
   return dif; 
}

void FindMinorDistance(List* list ,FILE* dictionary, FILE* stopwords){
    char* dic = (char*)calloc(100,sizeof(char));
    char* stopw = (char*)calloc(100,sizeof(char));
    Node* node;
    int i=0;
    for (node = frontList(list); node != backList(list); node = node->next_){
        //searching the words on the dictionary
        while(fscanf(dictionary,"%s", dic) >0) {
            //if the words are equal, problem solved
            if(EqualWords(node->info_,dic)==1){
                strcpy(node->suggest_,stopw);
                node->dif_= CalculatesDistance(node->info_, stopw);
            //else, find the minor distance
            } else if(CalculatesDistance(node->info_, dic) < node->dif_){
                strcpy(node->suggest_,dic);
                node->dif_= CalculatesDistance(node->info_, dic);
            }
        }

        //searching the words on the stopwords
        while(fscanf(stopwords,"%s", stopw) >0) {
            //if the words are equal, problem solved
            if(EqualWords(node->info_,dic)==1){
                strcpy(node->suggest_,stopw);
                node->dif_= CalculatesDistance(node->info_, stopw);
            //else, find the minor distance
            } else if(CalculatesDistance(node->info_, stopw) < node->dif_){
                strcpy(node->suggest_,stopw);
                node->dif_= CalculatesDistance(node->info_, stopw);
            }
        }


        rewind(dictionary);
        rewind(stopwords);
        i++;
        if(i==12) break;
printf("\n \n \n suggest: %s \n",node->suggest_);
    }
}



int main (int argc, char* argv[]) {
    FILE *dictionary,*stopwords,*input,*output;
    char option;
    char *s_dictionary, *s_stopwords, *s_input, *s_output;
    List* words;
    words = NewList(); 
    if (argc<8){
        puts("ARGUMENT MISSING");
        return 0;
    } else {
        while((option = getopt(argc,argv,"i:d:s:o:")) != -1){
		switch(option){
			case 'i':
				s_input = optarg;
				break;
			case 'd':
				s_dictionary = optarg;
				break;
			case 's':
				s_stopwords = optarg;
				break;
			case 'o':
				s_output = optarg;
				break;
			default :
				exit(0);
		}
	}

    dictionary = fopen(s_dictionary, "r");
    stopwords = fopen(s_stopwords, "r") ;
    input = fopen(s_input, "r");
    output = fopen(s_output, "w");

        if (input == NULL){
            puts("O ARQUIVO NAO FOI ABERTO");
            return 0;
        } else {
            ReadFromFile(input, words, dictionary, stopwords);
        }
        return 0;
    }
}

