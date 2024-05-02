CC=gcc
CFLAGS=-I.

DEPS = createAccount.h
OBJ = Main.o createAccount.o menu.o login.o seeAccountDetails.o updateBalance.o deleteAccount.o logout.o editAccount.o transfer.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) Main