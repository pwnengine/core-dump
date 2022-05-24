CFLAGS=-m32 -std=c99 -pedantic
OBJECTS=mem.o main.o entity.o bhop.o
CFILES=main.c mem/mem.c entity/entity.c hacks/bhop.c
BUILD=build/build.dll

all: cheat

cheat: mem.o main.o entity.o bhop.o  
	gcc --shared $(CFLAGS) mem.o main.o entity.o bhop.o -o $(BUILD)

main.o: main.c
	gcc -c $(CFLAGS) main.c

mem.o: mem/mem.c
	gcc -c $(CFLAGS) mem/mem.c

entity.o: entity/entity.c
	gcc -c $(CFLAGS) entity/entity.c

bhop.o: hacks/bhop.c
	gcc -c $(CFLAGS) hacks/bhop.c


clean:
	rm $(OBJECTS) $(BUILD)
