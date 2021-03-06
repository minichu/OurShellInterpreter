CC		= gcc
CFLAGS		= -g -O2
TARGET		= oursh
OBJECTS		= execute.o parser.o redirect.o symbol.o util.o command.o
MAIN_SOURCE	= oursh.c

all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -d $@ $(OBJECTS) $(MAIN_SOURCE)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

