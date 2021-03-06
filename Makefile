CC=clang++
CFLAGS=--std=c++11

objects = Event.o Simulation.o # .. etc .. put a list of your .o files here  

# this rule will build A2 as the executable from the object files
all: A2main.o $(objects)
	$(CC) $(CFLAGS) -o A2 $< $(objects)
#
#         # this rule will build a .o file from a .cpp file. 
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
