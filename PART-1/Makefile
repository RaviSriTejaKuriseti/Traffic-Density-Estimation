all:empty.cpp
	g++ empty.cpp -o empty -pthread -std=c++11 `pkg-config --cflags --libs opencv`
run:empty.cpp
	./empty
clean:
	$(RM) empty

