clog.o: clog.c

test.o: test.c

test: clog.o test.o
	$(CC) -o $@ $^

clean:
	rm -f *.o

realclean: clean
	rm -f test
