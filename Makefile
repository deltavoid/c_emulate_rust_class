

.PHONY: run build clean

run: build
	./main

build: main

main: main.c hello.h hello.c
	gcc -o $@ $^

clean:
	rm main