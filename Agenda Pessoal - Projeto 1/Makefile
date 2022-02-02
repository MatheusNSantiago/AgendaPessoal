CFLAGS = -Wall
CC = gcc
# LDFLAGS = -lm (poderia ser necess´aria em outro projeto que utilizasse a math.h)

OBJDIR = objects
BINDIR = bin

SRC := $(shell find . -name '*.c')
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

abrir-agenda:
	@./bin/main

compilar-programa: binfolder objfolder bin/main

bin/main: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

binfolder:
	@mkdir -p $(BINDIR)

objfolder:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%main.o: main.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: %.c %.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -Rf bin objects