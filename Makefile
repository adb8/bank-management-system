CC=gcc
CFLAGS=-I.

DEPS = globals.h
OBJ = main.o create_account.o menu.o login.o account_details.o update_balance.o delete_account.o logout.o edit_account.o transfer.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) main