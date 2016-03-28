CC = g++
#CFLAGS = -Wall -g
CFLAGS = -std=c++0x -Wall -g

SRCS = knn.cpp Naiveexe.cpp Example.cpp NumericAttribute.cpp Attribute.cpp Node.cpp AttributeFactory.cpp Classifier.cpp NominalAttribute.cpp Performance.cpp TrainTestSets.cpp ID3exe.cpp Examples.cpp ID3.cpp KNearest.cpp Attributes.cpp NB.cpp Evaluator.cpp DataSet.cpp 

OBJS = ${SRCS:.cpp=.o}
KOBJS = knn.o
NOBJS = Naiveexe.o 
IOBJS = ID3exe.o
COBJS = Example.o NumericAttribute.o Attribute.o Node.o AttributeFactory.o Classifier.o NominalAttribute.o Performance.o TrainTestSets.o Examples.o ID3.o KNearest.o Attributes.o NB.o Evaluator.o DataSet.o

all:$(OBJS)
	$(CC) -o knn $(CFLAGS) $(KOBJS) $(COBJS)
	$(CC) -o nb $(CFLAGS) $(NOBJS) $(COBJS)
	$(CC) -o id $(CFLAGS) $(IOBJS) $(COBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cpp

depend:
	$(CC) -MM $(SRCS) $(COBJS) > Makefile.dep

docs:
	rm -fr html latex 
	/usr/bin/doxygen doxygen.config *.h *.cc

Makefile.dep:
	touch Makefile.dep

clean:
	rm -f $(OBJS) a.out core 

include Makefile.dep

