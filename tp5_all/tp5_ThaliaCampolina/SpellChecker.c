#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"


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
    if (strcmp(word,word_dic)==0){
        return 1;
    } else {
        return 0;
    }
}

int CalculatesDistance(char* word, char* word_dic) {
    int i=0;
    int dif=0;
    while( i < LengthStr(word) && word_dic[i]!='\0'){
        if(word[i]!=word_dic[i]){
            dif++;
        }
        i++;
    }
   return dif; 
}

void FindMinorDistance(List* list ,FILE* dictionary, FILE* stopwords, int word_counter){
    char* dic = (char*)calloc(100,sizeof(char));
    char* stopw = (char*)calloc(100,sizeof(char));
    char* word = (char*)calloc(100,sizeof(char));
    char c;
    Node* node;
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    for (node = frontList(list); node != backList(list); node = node->next_){

        strcpy(word,node->info_);
        //converting to lowercase 
        while(i < LengthStr(word)){
            c=word[i];
            word[i]=putchar(tolower(c));
            i++;
        }
         /////////////////////////////////////////
        //searching the words on the dictionary//
        ////////////////////////////////////////
        while(fscanf(dictionary,"%s", dic) >0) {
        
        //converting to lowercase 
            while(dic[j] < LengthStr(dic)){
                char c=dic[j];
                dic[j]=putchar(tolower(c));
                j++;
            }

            //if the words are equal, problem solved
            //if(EqualWords(node->info_,dic)==1){
            if(EqualWords(word,dic)==1){
                strcpy(node->suggest_,dic);
                //node->dif_= CalculatesDistance(node->info_, dic);
                node->dif_= CalculatesDistance(word, dic);

            //else, find the minor distance
            //} else if(CalculatesDistance(node->info_, dic) < node->dif_){
            } else if(CalculatesDistance(word, dic) < node->dif_){
                strcpy(node->suggest_,dic);
                //node->dif_= CalculatesDistance(node->info_, dic);
                node->dif_= CalculatesDistance(word, dic);
            }
        }

         ///////////////////////////////////////
        //searching the words on the stopwords//
        ///////////////////////////////////////
        while(fscanf(stopwords,"%s", stopw) >0) {


        //converting to lowercase 
            while(stopw[k] < LengthStr(stopw)){
                char c=stopw[k];
                stopw[k]=putchar(tolower(c));
                i++;
            }


            //if the words are equal, problem solved
            //if(EqualWords(node->info_,stopw)==1){
            if(EqualWords(word,stopw)==1){
                strcpy(node->suggest_,stopw);
             //   node->dif_= CalculatesDistance(node->info_, stopw);
                node->dif_= CalculatesDistance(word, stopw);

            //else, find the minor distance
           // } else if(CalculatesDistance(node->info_, stopw) < node->dif_){
            } else if(CalculatesDistance(word, stopw) < node->dif_){
                strcpy(node->suggest_,stopw);
                //node->dif_= CalculatesDistance(node->info_, stopw);
                node->dif_= CalculatesDistance(word, stopw);
            }
        }


        rewind(dictionary);
        rewind(stopwords);
        l++;
        if(l==word_counter) break;
    }
}


void* CreateOutput(FILE* output, int word_counter, int char_counter, List* words){
    int l = 0;
    Node* node;
    fprintf(output,"%d\n%d\n",char_counter, word_counter);
    for (node = frontList(words); node != backList(words); node = node->next_){
        l++;
        fprintf(output,"%s ", node->suggest_ );
        if(l==word_counter) break;
    }
}




void ReadFromFile(FILE* input, FILE* output, List* words, FILE* dictionary, FILE* stopwords){
    char* word=calloc(100,sizeof(char));
    char* empty;
    int word_counter=0;
    int char_counter=0;


//CREATE WORDS LIST    
    while(fscanf(input,"%s",word)>0){ 
        Node* node = NewNode(word, words->end_, words->end_);
        InsertBack(words, word);  
        word_counter++;
        char_counter = countWordCharacter(word) + char_counter;
    }


    FindMinorDistance(words, dictionary, stopwords, word_counter);

    CreateOutput(output, word_counter, char_counter, words);


}






