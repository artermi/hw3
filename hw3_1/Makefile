target = hw3_1 hw3_2
FLAG = -O2 -Wall
CPPFLAGS = -O2 -std=c++11 -Wall

all:$(target)

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@
	
hw3_1: main.cpp caculator.cpp caculator.h postfix.cpp postfix.h 
		g++ $(CPPFLAGS) main.cpp caculator.cpp caculator.h postfix.cpp postfix.h -o $@

clean:
		rm -rf $(target)
			
run:
		./demo