

.PHONY: run build clean

run: build
	./main

build: main

main: main.c hello.h hello.c hello_ext.h hello_ext.c
	gcc -o $@ $^

clean:
	rm main