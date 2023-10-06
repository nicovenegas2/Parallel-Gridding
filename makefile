
program.exe: Lecture.o Griding.cc
	u++ -o program.exe Lecture.o Griding.cc

Lecture.o: Lecture.cc Lecture.h
	u++ -c Lecture.cc


test: program.exe
	./program.exe