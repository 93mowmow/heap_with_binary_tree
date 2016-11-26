CC := gcc -g -O0
#CFLAGS = -I. -I /usr/include/modbus -I /usr/include/mysql
CFLAGS = -I. 
# linker flags
#LDFLAGS = -L/usr/lib -L/usr/lib/mysql -lmysqlclient -lmodbus -lm -lz
LDFLAGS = -L/usr/lib -lm -lz
# clear suffix list and set new one
.SUFFIXES:
.SUFFIXES: .cpp .o
#-----
all : heap_with_binary_tree

heap_with_binary_tree: main.o btheap.o node.o
	$(CC) main.o btheap.o node.o $(CFLAGS) $(LDFLAGS) -o heap_with_binary_tree
main.o: main.c
	$(CC) main.c $(CFLAGS) $(LDFLAGS) -c
btheap.o: btheap.c
	$(CC) btheap.c $(CFLAGS) $(LDFLAGS) -c
node.o: node.c
	$(CC) node.c $(CFLAGS) $(LDFLAGS) -c	
	
clean:
	@rm -rf heap_with_binary_tree main.o btheap.o node.o
