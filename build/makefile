OBJS = opengl.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -lglut$(DEBUG)
LFLAGS = -Wall -lglut$(DEBUG)            

main.o : main.cpp model.h model.cpp bitmap.h bitmap.cpp
    $(CC) $(CFLAGS) main.cpp
    

main : $(OBJS)
    $(CC) $(LFLAGS) $(OBJS) -o opengl
    
clean :
    \rm *.o *~ p1

tar :
   main.cpp model.h model.cpp bitmap.h bitmap.cpp
