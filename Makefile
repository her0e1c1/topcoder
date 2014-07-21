CC = gcc
CPP = g++
#OPT = -g 

HEADERS = -I ./

%: %.cpp
	@$(CPP) $(HEADERS) $(OPT) -o ./a.out $^
