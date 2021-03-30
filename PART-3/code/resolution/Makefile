all:resolu.cpp
	g++ resolu.cpp -o resolu -pthread -std=c++11 `pkg-config --cflags --libs opencv4`
run:resolu.cpp
	./resolu
clean:
	$(RM) resolu

