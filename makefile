# Please rewrite me better.
all : bin/test001 bin/test002

.PHONY : all

bin :
	mkdir bin

bin/test001 : bin src/test001/main.cpp src/nn/network.cpp
	g++ -o bin/test001 -g -Wall src/test001/main.cpp src/nn/network.cpp

bin/test002 : bin src/test002/main.cpp src/nn/pool.cpp src/nn/genome.cpp src/nn/network.cpp
	g++ -o bin/test002 -g -Wall src/test002/main.cpp src/nn/pool.cpp src/nn/genome.cpp src/nn/network.cpp
