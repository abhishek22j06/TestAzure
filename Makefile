#this is test Makefile

CXXFLAGS=
LDFLAGS=

SOURCES = readConfigFile.cc

OBJS = $(patsubst %.cc, %.o,$(SOURCES))

all: obj bin

obj: $(OBJS)

bin: obj
	$(CXX) -o readConfig $(OBJS)
