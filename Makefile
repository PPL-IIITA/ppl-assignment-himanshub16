OBJECT_FILES := gifts/gift.o \
								couples/couple.o \
								utils/logger/logger.o

BOY_OBJECT_FILES := boys/boy.o \
										boys/generousboy.o \
										boys/geekboy.o \
										boys/miserboy.o

GIRL_OBJECT_FILES := girls/girl.o \
										 girls/choosygirl.o \
										 girls/desperategirl.o \
									 	 girls/normalgirl.o


makelibs:
	cd boys;					make all
	cd girls;					make all
	cd gifts;					make
	cd couples;				make
	cd utils/logger;	make

q3: makelibs
		cd tinder;				make q3
	g++ -Wall -std=c++11 $(OBJECT_FILES) $(BOY_OBJECT_FILES) $(GIRL_OBJECT_FILES) tinder/q3.o -o result
	@echo
	@echo "Everything went fine. Run ./result to check the result"

q1:
	@echo
	@echo "Question 1 and 2 are not available due to new classes."
	@echo "Please checkout 'first-submission' branch for them."

q2: q1

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
