all:altframes.cpp
	g++ altframes.cpp -o altframes -pthread -std=c++11 `pkg-config --cflags --libs opencv4`
run:altframes.cpp
	./altframes
clean:
	$(RM) altframes

