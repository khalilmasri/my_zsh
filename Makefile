SRC=src
OBJ=obj
BIN=bin

CFLAGS +=-W  -Wall -Wextra -g3 -Iinclude 
CC=gcc
TARGET=my_zsh
RM=rm -rf

$(shell mkdir -p obj)

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	${CC} ${CFLAGS} -c $< -o $@

# dir don't exit

clean:
	$(RM) $(TARGET) $(BIN)/*.dSYM $(OBJ)
