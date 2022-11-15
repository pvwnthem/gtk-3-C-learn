
all: area-app

area-app: 
	gcc main.c -o main `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`