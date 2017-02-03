#make file: Assignment 4
# Alireza Rahbar
# 301040709
# ara14@sfu.ca

all: EKTApp2

EKTApp2: dictionaryEntry.o EKTApp2.cpp
	g++ -o EKTApp2  dictionaryEntry.o EKTApp2.cpp


dictionaryEntry.o: dictionaryEntry.cpp dictionaryEntry.h
	g++ -c -Wall dictionaryEntry.cpp

clean:
	rm -f bsApp *.o