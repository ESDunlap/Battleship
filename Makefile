CC = gcc
CFLAGS = 

TARGET = Battleship

SRC = game_manager.c battleShipPlacement.c board_prints.c fire_shot.c fire_input.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
		$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(TARGET)