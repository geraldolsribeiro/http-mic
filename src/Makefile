# apt install libssl-dev libcrypto++-dev

CXXFLAGS+=-std=c++1z
CXXFLAGS+=-Wall -Wextra -Wtype-limits
CXXFLAGS+=-I../include
LDFLAGS+=-lssl -lcrypto -lpthread

all: http-mic
	./http-mic
