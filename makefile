all: fork4 
fork4: fork4.c

run: fork4 
	./fork4

clean: 
	rm -f *~ fork[12345]
