rm -rf *.o
gcc -c *.c ../$1.c
gcc -o testing *.o && ./testing
rm -rf *.o testing