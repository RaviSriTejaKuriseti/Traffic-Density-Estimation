all:subsample.cpp
	g++ subsample.cpp -o subsample -pthread -std=c++11 `pkg-config --cflags --libs opencv4`
run:subsample.cpp
	./subsample
clean:
	$(RM) subsample

