CC = gcc

CFLAGS = -Wall -g -lpthread

RM = rm -f

OBJS = list.o main.o marriage.o person.o

MAIN = tp6

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
	./$(MAIN) -i input.txt -o output.txt -t 4

