# Variabili per il compilatore
CXX = g++
CXXFLAGS = -Wall -g -std=c++17

# Percorso delle librerie
NCURSES_LIBS = -lncurses

# Directory dei sorgenti e degli oggetti
SRC_DIR = src
SRC_FONTS = src/fonts
OBJ_DIR = obj
OBJ_FONTS_DIR = obj/fonts

# File sorgenti
SOURCES = \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/clockfont.cpp \
	$(SRC_DIR)/fonts/hashtag.cpp \
	$(SRC_DIR)/fonts/asterisk.cpp \
	$(SRC_DIR)/fonts/lines.cpp \
	$(SRC_DIR)/fonts/doublelines.cpp

# File oggetti
OBJECTS = \
	$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/clockfont.o \
	$(OBJ_FONTS_DIR)/hashtag.o \
	$(OBJ_FONTS_DIR)/asterisk.o \
	$(OBJ_FONTS_DIR)/lines.o \
	$(OBJ_FONTS_DIR)/doublelines.o

# Nome dell'eseguibile
EXEC = CoolClock

# Regola di default per compilare
all: $(EXEC)

# Come compilare l'eseguibile
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) $(NCURSES_LIBS)

# Come compilare i file oggetto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_FONTS_DIR)/%.o: $(SRC_FONTS)/%.cpp
	@mkdir -p $(OBJ_FONTS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pulizia dei file oggetto ed eseguibili
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Regola per ricompilare tutto
rebuild: clean all
