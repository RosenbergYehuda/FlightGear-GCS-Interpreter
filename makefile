CXX = g++
CXXFLAGS = -pthread

output: main.o lexer.o commandMap.o command.o server.o client.o symbolPathMap.o pathValueMap.o toolBox.o
	$(CXX) $(CXXFLAGS) main.o lexer.o commandMap.o command.o server.o client.o symbolPathMap.o pathValueMap.o toolBox.o -o output

main.o: main.cpp lexer.cpp commandMap.cpp
	$(CXX) -c main.cpp

server.o: server.cpp  pathValueMap.cpp 
	$(CXX) -c $(CXXFLAGS) server.cpp 

client.o: client.cpp 
	$(CXX) -c client.cpp

command.o: command.cpp shuntingYard.cpp symbolPathMap.cpp pathValueMap.cpp
	$(CXX) -c $(CXXFLAGS) command.cpp 

commandMap.o: commandMap.cpp command.cpp
	$(CXX) -c commandMap.cpp

lexer.o: lexer.cpp toolBox.cpp
	$(CXX) -c lexer.cpp

pathValueMap.o: pathValueMap.cpp 
	$(CXX) -c pathValueMap.cpp

shuntingYard.o: shuntingYard.cpp
	$(CXX) -c shuntingYard.cpp

symbolPathMap.o: symbolPathMap.cpp
	$(CXX) -c symbolPathMap.cpp

toolBox.o: toolBox.cpp
	$(CXX) -c toolBox.cpp

clean:
	rm *.o output
