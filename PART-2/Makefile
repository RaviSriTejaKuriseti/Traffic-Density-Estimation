all:videoprocess.cpp
	g++ videoprocess.cpp -o videoprocess -pthread -std=c++11 `pkg-config --cflags --libs opencv4`
run:videoprocess.cpp
	./videoprocess
clean:
	$(RM) videoprocess

