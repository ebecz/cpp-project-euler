PROBLEMS=$(shell ls *.cpp | sed 's/.cpp//g')

all: $(PROBLEMS)

clean:
	rm -f *.o $(PROBLEMS)

%: %.o

