build:
	g++ -w -std=c++14 \
	./*.cpp \
	-o bin/particle \
	-lSDL2 \

clean:
	rm ./bin/particle;

run:
	./bin/particle;
