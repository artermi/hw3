target = hw3_1 hw3_2
FLAG = -O2 -Wall
CPPFLAGS = -O2 -std=c++11 -Wall

all:$(target)

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@
	
hw3_1: main.cpp caculator.cpp caculator.h postfix.cpp postfix.h 
		g++ $(CPPFLAGS) main.cpp caculator.cpp caculator.h postfix.cpp postfix.h -o $@
hw3_2: main2.cpp caculator2.cpp caculator2.h postfix2.cpp postfix2.h 
		g++ $(CPPFLAGS) main2.cpp caculator2.cpp caculator2.h postfix2.cpp postfix2.h -o $@

clean:
		rm -rf $(target)
			
run:
		./demo