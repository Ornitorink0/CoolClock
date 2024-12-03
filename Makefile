# Variables for the compiler
CXX = g++
CXXFLAGS = -Wall -g -std=c++17

# Libraries path
NCURSES_LIBS = -lncurses

# Source and object directories
SRC_DIR = src
SRC_FONTS = src/fonts
OBJ_DIR = obj
OBJ_FONTS_DIR = obj/fonts

# Source files
SOURCES = \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/clockfont.cpp \
	$(SRC_DIR)/fonts/hashtag.cpp \
	$(SRC_DIR)/fonts/asterisk.cpp \
	$(SRC_DIR)/fonts/lines.cpp \
	$(SRC_DIR)/fonts/doublelines.cpp

# Object files
OBJECTS = \
	$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/clockfont.o \
	$(OBJ_FONTS_DIR)/hashtag.o \
	$(OBJ_FONTS_DIR)/asterisk.o \
	$(OBJ_FONTS_DIR)/lines.o \
	$(OBJ_FONTS_DIR)/doublelines.o

# Executable name
EXEC = coolclock

# Installation directory
DESTDIR = /usr/local
BIN_DIR = $(DESTDIR)/bin

# Default rule to compile
all: $(EXEC)

# How to compile the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) $(NCURSES_LIBS)

# How to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_FONTS_DIR)/%.o: $(SRC_FONTS)/%.cpp
	@mkdir -p $(OBJ_FONTS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and executables
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Recompile everything
rebuild: clean all

# Installation
install: $(EXEC)
	install -D $(EXEC) $(BIN_DIR)/$(EXEC)
	@echo "Installed in $(BIN_DIR)/$(EXEC)"

# Uninstallation
uninstall:
	rm -f $(BIN_DIR)/$(EXEC)
	@echo "Uninstalled from $(BIN_DIR)/$(EXEC)"
