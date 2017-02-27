generate:
	g++ -std=c++11 -Wall -c main.cpp -o main.o
	g++ -std=c++11 -Wall -c csv_creator.cpp -o csv_creator.o
	g++ -std=c++11 -Wall main.o csv_creator.o -o generate

clean:
	@rm csv_creator.o main.o
	@echo
	@echo "Cleanup complete"
