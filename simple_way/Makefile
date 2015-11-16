GLEW = `pkg-config --cflags glew` `pkg-config --libs glew`
LIB = -framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa -framework GLUT

TARGET = fake_splitScreen

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	clang++ $(TARGET).cpp -o $(TARGET) $(GLFW) $(LIB)
clear:
	rm *.o
