CC = gcc

CFLAGS = -Wall -g

RM = rm -f

OBJS = main.o list.o SpellChecker.o

MAIN = tp5 

$(MAIN): $(OBJS)
	@echo ""
	@echo " --- COMPILANDO PROGRAMA ---"
	@$(CC) $(CFLAGS) $(OBJS) -lm -o $(MAIN)
	@echo ""

%.o: %.c %.h
	@echo " --- COMPILANDO OBJETO \"$@\""
	@$(CC) $(CFLAGS) $< -c 

clean:
	$(RM) $(MAIN) *.o
	clear

run: $(MAIN)
	./$(MAIN) -i input.txt -d dictionary.txt -s stopwords.txt -o output.txt


