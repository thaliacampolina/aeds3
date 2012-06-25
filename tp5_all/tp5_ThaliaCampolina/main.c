#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include "SpellChecker.h"


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
            ReadFromFile(input, output, words, dictionary, stopwords);
        }
        return 0;
    }
}

