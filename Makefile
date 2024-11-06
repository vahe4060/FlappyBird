CXX := g++
CXX_Flags = -std=c++17 -Wall -Wextra

SDL2 := -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2 
SDL2_Flags := -I/usr/local/include -I/usr/local/include/SDL2 -D_REENTRANT 

SDL2Image := -lSDL2_image -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2 
SDL2Image_Flags := -I/usr/include/SDL2 -I/usr/local/include -I/usr/local/include/SDL2 -D_REENTRANT -I/usr/include/libpng16 -I/usr/include/x86_64-linux-gnu -I/usr/include/webp 
	
TARGET := FlappyBird
INCLUDES_DIR = ./includes
INCLUDES = includes/ClickButton.h \
	   includes/game.h \
	   includes/GameObject.h \
	   includes/gameOverState.h \
	   includes/gameStateMachine.h \
	   includes/gameStates.h \
	   includes/inputHandler.h \
	   includes/LoaderParams.h \
	   includes/Obstacle.h \
	   includes/Player.h \
	   includes/textureManager.h
SRC = sources/ClickButton.cpp \
      sources/flappyBird.cpp  \
      sources/game.cpp  \
      sources/gameOverState.cpp \
      sources/gameStateMachine.cpp \
      sources/inputHandler.cpp \
      sources/menuState.cpp \
      sources/Obstacle.cpp \
      sources/Player.cpp \
      sources/playState.cpp \
      sources/textureManager.cpp
OBJ = $(SOURCES:.cpp=.o)



all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXX_Flags) -o $@ $^ $(SDL2) $(SDL2Image)

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXX_Flags) $(SDL2_Flags) $(SDL2Image_Flags) -I$(INCLUDES_DIR) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

re: clean all

debug: clean
	@make -s $(TARGET) CXX_FLAGS="$(CXX_Flags) -g"


.PHONY: all clean re debug
