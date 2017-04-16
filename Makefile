parkSimulation: project4.o AttractionClass.o EventClass.o random.o RiderClass.o TrainClass.o
	g++ project4.o AttractionClass.o EventClass.o random.o RiderClass.o TrainClass.o -o parkSimulation

project4.o: project4.cpp AttractionClass.h random.h
	g++ -c project4.cpp -o project4.o

AttractionClass.o: AttractionClass.h AttractionClass.cpp FIFOQueueClass.h FIFOQueueClass.inl SortedListClass.h SortedListClass.inl LinkedNodeClass.h LinkedNodeClass.inl RiderClass.h TrainClass.h EventClass.h constants.h random.h
	g++ -c AttractionClass.cpp -o AttractionClass.o

EventClass.o: EventClass.cpp EventClass.h RiderClass.h TrainClass.h constants.h
	g++ -c EventClass.cpp -o EventClass.o

random.o: random.cpp random.h
	g++ -c random.cpp -o random.o

RiderClass.o: RiderClass.cpp constants.h
	g++ -c RiderClass.cpp -o RiderClass.o

TrainClass.o: TrainClass.cpp TrainClass.h
	g++ -c TrainClass.cpp -o TrainClass.o

clean:
	rm -f parkSimulation project4.o AttractionClass.o EventClass.o random.o RiderClass.o TrainClass.o
