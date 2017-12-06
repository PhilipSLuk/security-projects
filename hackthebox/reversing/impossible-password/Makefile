mylib.so: mylibrary.c
	gcc -o mylib.so -shared mylibrary.c -ldl

run: mylib.so impossible_password.bin
	LD_PRELOAD=./mylib.so ./impossible_password.bin

clean:
	rm *.so
