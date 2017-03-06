OBJECT_FILES := boys/boy.o girls/girl.o gifts/gift.o couples/couple.o utils/logger/logger.o

q1:
	cd tinder;        make q1
	cd boys;          make
	cd girls;         make
	cd couples;       make
	cd gifts;         make
	cd utils/logger;  make
	g++ -Wall -std=c++11 $(OBJECT_FILES) tinder/q1.o -o result
	@echo
	@echo "Everything went find. Run ./result to check the result"

q2:
	cd tinder;        make q2
	cd boys;          make
	cd girls;         make
	cd couples;       make
	cd utils/logger;  make
	g++ -Wall -std=c++11 $(OBJECT_FILES) tinder/q2.o -o result
	@echo
	@echo "Everything went fine. Run ./result to check the result"

csv:
	cd tests-generator; make
	mv tests-generator/generate .
	@echo "Run ./generate to make csv files"

clean:
	cd tinder;        make clean
	cd boys;          make clean
	cd girls;         make clean
	cd couples;       make clean
	cd gifts;         make clean
	cd utils/logger;  make clean
	@echo "Cleanup done!"
