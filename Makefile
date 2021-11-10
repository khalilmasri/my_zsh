CC = gcc
CFLAGS += -Wall -Wextra -Werror -g3 
DEPS += include/include.h
OBJFILES = src/main.o src/my_readline.o\
		   src/string.o src/parse.o\
		   src/my_zsh.o src/echo.o\
		   src/cd.o src/which.o

TARGET = my_zsh
all: $(TARGET)

$(TARGET): $(OBJFILES) $(DEPS)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

.PHONY: clean
clean:
	rm -f src/*.o $(TARGET)
