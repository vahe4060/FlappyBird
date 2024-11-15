# Makefile colors
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

# Compiler and Flags
CXX := g++
CXX_FLAGS := -std=c++17 -Wall -Wextra
CXX_FLAGS_DBG := -g -std=c++17 -Wall -Wextra

# SDL2 and SDL2_image Flags and Libraries
SDL2_FLAGS := -I/usr/local/include -I/usr/local/include/SDL2 -D_REENTRANT
SDL2_LIBS := -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2 

SDL2IMAGE_FLAGS := -I/usr/include/SDL2 -I/usr/local/include -I/usr/local/include/SDL2 -D_REENTRANT -I/usr/include/libpng16 -I/usr/include/x86_64-linux-gnu -I/usr/include/webp
SDL2IMAGE_LIBS := -lSDL2_image -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2_image

TARGET = FlappyBird
SRC_DIR = ./sources
INCLUDES_DIR = ./includes
BUILD_DIR = ./build
BUILD_DBG_DIR = ./build_dbg
TARGET_EXE := $(BUILD_DIR)/$(TARGET)
TARGET_DBG_EXE := $(BUILD_DBG_DIR)/$(TARGET)

INCLUDES = $(INCLUDES_DIR)/ClickButton.h \
           $(INCLUDES_DIR)/Game.h \
           $(INCLUDES_DIR)/GameObject.h \
           $(INCLUDES_DIR)/GameStateMachine.h \
           $(INCLUDES_DIR)/GameStates.h \
           $(INCLUDES_DIR)/InputHandler.h \
           $(INCLUDES_DIR)/Obstacle.h \
           $(INCLUDES_DIR)/Player.h \
           $(INCLUDES_DIR)/TextureManager.h   

SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/ClickButton.cpp \
      $(SRC_DIR)/Game.cpp \
      $(SRC_DIR)/GameStates.cpp \
      $(SRC_DIR)/GameOverState.cpp \
      $(SRC_DIR)/GameStateMachine.cpp \
      $(SRC_DIR)/InputHandler.cpp \
      $(SRC_DIR)/MenuState.cpp \
      $(SRC_DIR)/Obstacle.cpp \
      $(SRC_DIR)/Player.cpp \
      $(SRC_DIR)/PlayState.cpp \
      $(SRC_DIR)/TextureManager.cpp
      
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
OBJ_DBG = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DBG_DIR)/%.o)


all: $(TARGET_EXE)
	@ln -sf $(TARGET_EXE) $(TARGET)

$(TARGET_EXE): $(OBJ)
	@echo "$(GREEN)Compiling $@$(RESET)"
	@$(CXX) $(CXX_FLAGS) -o $@ $^ $(SDL2_LIBS) $(SDL2IMAGE_LIBS)

debug: $(TARGET_DBG_EXE)
	@ln -sf $(TARGET_DBG_EXE) $(TARGET)

$(TARGET_DBG_EXE): $(OBJ_DBG)
	@echo "$(GREEN)Compiling $@$(RESET)"
	$(CXX) $(CXX_FLAGS_DBG) -o $(TARGET_DBG_EXE) $^ $(SDL2_LIBS) $(SDL2IMAGE_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDES)
	@echo "$(GREEN)Compiling $@$(RESET)"
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXX_FLAGS) $(SDL2_FLAGS) $(SDL2IMAGE_FLAGS) -I$(INCLUDES_DIR) -o $@ -c $<

$(BUILD_DBG_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDES)
	@echo "$(GREEN)Compiling $@$(RESET)"
	@mkdir -p $(BUILD_DBG_DIR)
	$(CXX) $(CXX_FLAGS_DBG) $(SDL2_FLAGS) $(SDL2IMAGE_FLAGS) -I$(INCLUDES_DIR) -o $@ -c $<

clean:
	@rm -rf $(BUILD_DIR) $(BUILD_DBG_DIR) $(TARGET_EXE) $(TARGET_DBG_EXE) $(TARGET)

re: clean all


.PHONY: all clean debug re
