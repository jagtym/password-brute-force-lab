LIBS=-lcrypto -lssl
CXX=g++

SRCS=$(wildcard *.cc)
PROGS=$(patsubst %.cc,%,$(SRCS))

all: $(PROGS)

%: %.cc
	$(CXX) -o $@ $< $(LIBS)

.PHONY: clean
clean:
	rm -f $(PROGS)
