BINNAME	:= "peor-ajuste"
CC_WIN	:= x86_64-w64-mingw32-gcc 
CC := gcc
BINDIR	:= bin
SRCDIR	:= src
SRCTESTDIR := tests
# INCLUDE := 
# LIB	:= -L LIB
CFLAGS	:= -Wextra -g -Og
CFLGAS-DEBUG := -fsanitize=address 


all: clean build run

build_win:
	$(CC_WIN) $(CFLAGS) $(INCLUDE) $(SRCDIR)/*.c -o $(BINDIR)/$(BINNAME).exe

build: 
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCDIR)/*.c -o $(BINDIR)/$(BINNAME)

test: 
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCTESTDIR)/*.c -o $(BINDIR)/$(BINNAME)-test

clean:
	rm -rf $(BINDIR)
	mkdir $(BINDIR)

run:
	./$(BINDIR)/$(BINNAME)

runtest: test
	./$(BINDIR)/$(BINNAME)-test
