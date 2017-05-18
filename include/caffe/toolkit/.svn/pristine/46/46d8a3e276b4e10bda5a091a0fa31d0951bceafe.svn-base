GXX=g++
GCC=gcc
CXXFLAG=-fopenmp -march=core2 -O3 -fomit-frame-pointer -pipe -fPIC -msse4
CFLAG=$(CXXFLAG)
DIR_INC=./
DIR_SRC=./
DIR_OBJ=./obj
DIR_BIN=./
DIR_LIB=./
LDFLAG=-Wl,--rpath=$(DIR_LIB)/lib,-O3 -fopenmp -msse4
SOFLAG=-fPIC -shared 
INCLUDE=-I$(DIR_INC) -I $(DIR_LIB)/include -I/usr/local/include -Ilib/include -I/usr/local/cuda-7.5/include -I/usr/local/include/opencv
LIBS=-L$(DIR_LIB)/lib -Llib -L/usr/local/lib -L/usr/lib -L/usr/lib64 -lglog -lgflags -lopencv_highgui -lopencv_core -lopencv_imgproc -lopencv_features2d -lopencv_objdetect -lboost_system -lboost_filesystem -lboost_thread-mt -lboost_regex -lssl -lcrypto
TARGET=cmd
DEF= -DLINUX #-DPATH #-DDEBUG 
SRC=$(wildcard ${DIR_SRC}/*.cpp)
OBJS=$(SRC:$(DIR_SRC)/%.cpp=$(DIR_OBJ)/%.o)

$(TARGET):$(OBJS) 
		$(GXX) $(GXXFLAG)$(LDFLAG) -o $@ $(OBJS) $(LIBS)

$(DIR_OBJ)/%.o:$(DIR_SRC)/%.cpp
		$(GXX) -o $@ -c $< $(CXXFLAG) $(INCLUDE) $(DEF)
clean:
		rm -fr $(OBJS) $(TARGET);
