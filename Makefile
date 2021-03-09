CC=clang++
CFLAGS= --std=c++11 -Wall 
objects = Event.o Simulation.o Burst.o ListItem.o Node.o ParentQueue.o PriorityQueue.o Process.o Queue.o FileReader.o StartCPU.o ProcessArrival.o Timeout.o CompleteCPU.o StartIO.o CompleteIO.o Exit.o# .. etc .. put a list of your .o files here  

# this rule will build A2 as the executable from the object files
all: A2main.o $(objects)
	$(CC) $(CFLAGS) -Wall -o A2 $< $(objects)  
#all: CatchTests.o $(objects) 
#	$(CC) $(CFLAGS) -Wall -o CatchTests $< $(objects) 


#         # this rule will build a .o file from a .cpp file. 
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

