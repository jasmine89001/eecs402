project3.exe: project3.o promptMainMenu.o isValidInt.o isValidFileStream.o setColor.o ColorClass.o ColorImageClass.o PatternClass.o PixelLocationClass.o RectangleClass.o
	g++ project3.o promptMainMenu.o isValidInt.o isValidFileStream.o setColor.o ColorClass.o ColorImageClass.o PatternClass.o PixelLocationClass.o RectangleClass.o -o project3.exe

project3.o: project3.cpp constants.h RectangleClass.h PatternClass.h ColorClass.h ColorImageClass.h PixelLocationClass.h
	g++ -c project3.cpp -o project3.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h
	g++ -c ColorClass.cpp -o ColorClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h PixelLocationClass.h RectangleClass.h PatternClass.h ColorClass.h constants.h
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

PatternClass.o: PatternClass.cpp PixelLocationClass.h PatternClass.h
	g++ -c PatternClass.cpp -o PatternClass.o

PixelLocationClass.o: PixelLocationClass.cpp PixelLocationClass.h
	g++ -c PixelLocationClass.cpp -o PixelLocationClass.o

RectangleClass.o: RectangleClass.cpp constants.h RectangleClass.h PixelLocationClass.h
	g++ -c RectangleClass.cpp -o RectangleClass.o

promptMainMenu.o: promptMainMenu.cpp promptMainMenu.h constants.h
	g++ -c promptMainMenu.cpp -o promptMainMenu.o

isValidInt.o: isValidInt.cpp isValidInt.h constants.h
	g++ -c isValidInt.cpp -o isValidInt.o

isValidFileStream.o: isValidFileStream.cpp isValidFileStream.h constants.h
	g++ -c isValidFileStream.cpp -o isValidFileStream.o

setColor.o: setColor.cpp setColor.h ColorClass.h constants.h
	g++ -c setColor.cpp -o setColor.o

clean:
	rm -f project3.exe project3.o ColorClass.o ColorImageClass.o PatternClass.o PixelLocationClass.o RectangleClass.o promptMainMenu.o isValidInt.o isValidFileStream.o setColor.o
