list: linklistfxn.c linklistfxn.h mytunes.c mytunes.h main.c
	gcc linklistfxn.c linklistfxn.h mytunes.c mytunes.h main.c

clean:
	rm *~

run: a.out
	./a.out
