CFLAGS= -I .

all:myShell

myShell: shellMain.o sysCommand.o pipeCommand.o redirection.o
	gcc -o $@ $^

clean:
	-rm myShell *.o
