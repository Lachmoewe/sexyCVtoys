CC='g++'
CC_FLAGS='pkg-config –cflags opencv'
CC_LIBS='pkg-config --libs opencv'
SOURCES = $(wildcard *.cpp)

%: %.cpp
    $(CC) $(CC_FLAGS) $< -o $(CC_LIBS) $@


#final: final.cpp
#	g++ `pkg-config –cflags opencv` final.cpp `pkg-config --libs opencv` -o final
#greyscale: greyscale.cpp
#	g++ `pkg-config –cflags opencv` greyscale.cpp `pkg-config --libs opencv` -o greyscale
#bw: bw.cpp
#	g++ `pkg-config –cflags opencv` bw.cpp `pkg-config --libs opencv` -o bw
#amplify: amplify.cpp
#	g++ `pkg-config –cflags opencv` amplify.cpp `pkg-config --libs opencv` -o amplify
#small: small.cpp
#	g++ `pkg-config –cflags opencv` small.cpp `pkg-config --libs opencv` -o small
#2windowblur: 2windowblur.cpp
#	g++ `pkg-config –cflags opencv` 2windowblur.cpp `pkg-config --libs opencv` -o 2windowblur
