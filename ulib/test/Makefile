QUIET		?= @

INCPATH		= ../include
LIBPATH		= ../lib

EXTRALIB	?= -L ../../gperftools/lib/

CXXFLAGS	?= -g3 -O0 -W -Wall -fpermissive
LDFLAGS		?= -lulib $(EXTRALIB) -lpthread -lglpk -lgsl -lcblas -lrt -Wl,-eh-frame-hdr
DEBUG		?= 

TARGET		= $(patsubst %.cpp, %.test, $(wildcard *.cpp))

%.test: %.cpp $(LIBPATH)/libulib.a
	$(QUIET)echo "GEN "$@;
	$(QUIET)$(CXX) -I $(INCPATH) $(CXXFLAGS) $(DEBUG) $< -o $@ -L $(LIBPATH) $(LDFLAGS);

all: $(TARGET)

clean:
	$(QUIET)rm -rf $(TARGET) *~

test:
	$(QUIET)./run_all_test.sh

.PHONY: all clean test
