CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g 
CXXFLAGS += -Wall -pedantic
CXXFLAGS += -pedantic-errors
CXXFLAGS +=-D_GLIBCXX_DEBUG

OBJS = Space.o Jupiter.o Mars.o ship.o black_hole.o Saturn.o Enceladus.o Titan.o menu.o main.o
SRCS = Space.cpp Jupiter.cpp Mars.cpp ship.cpp black_hole.cpp Saturn.cpp Enceladus.cpp Titan.cpp menu.cpp main.cpp
HEADERS = Space.hpp Jupiter.hpp Mars.hpp ship.hpp black_hole.hpp Saturn.hpp Enceladus.hpp Titan.hpp menu.hpp

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main  

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean: 
	${RM} ${OBJS} main 
