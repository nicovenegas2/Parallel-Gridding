
program.exe: Griding.cc Lecture.o GridTaskV1.o GridTaskV2.o Matrix.o
	u++ -o program.exe Lecture.o GridTaskV1.o GridTaskV2.o Matrix.o Griding.cc 

Lecture.o: Lecture.cc Lecture.h Matrix.o
	u++ -c Lecture.cc Matrix.o

GridTaskV1.o: GridTaskV1.cc GridTaskV1.h Lecture.o Matrix.o
	u++ -c GridTaskV1.cc Lecture.o Matrix.o

GridTaskV2.o: GridTaskV2.cc GridTaskV2.h Lecture.o Matrix.o
	u++ -c GridTaskV2.cc Lecture.o Matrix.o

Matrix.o: Matrix.cc Matrix.h
	u++ -c Matrix.cc

test: program.exe
	make
	clear
	./program.exe -i ese.csv -o grid -d 0.5 -N 8 -c 3 -t 4


clean:
	rm -f *.o *.exe