# Directories
SRCDIR := src
INCDIR := include
OBJDIR := obj

# Source files
SRC := $(wildcard $(SRCDIR)/*.c)

# Object files
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -I$(INCDIR)

# Final executable
TARGET := fdf

# Library directories
LIBMLX := lib/minilibx
LIBFT := lib/libft

# Default target
.PHONY: all
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $^ -L$(LIBMLX) -lmlx -L$(LIBFT) -lft -lXext -lX11 -o $@

# Ensure the obj directory exists and compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Run the program
.PHONY: run
run: all
	./$(TARGET) something.txt

# Clean up
.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(TARGET)
