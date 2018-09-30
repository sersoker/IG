#Crea el ejecutable final 
examen : escena.o practica1.o
	g++ -o p1 escena.o practica1.o -L/usr/lib64 -lGL -lGLU -lglut

#Crea los objetos a partir de los fuente
escena.o : escena.cc
	g++ -c -o escena.o escena.cc -L/usr/lib64 -lGL -lGLU -lglut 
practica1.o : practica1.cc
	g++ -c -o practica1.o practica1.cc -L/usr/lib64 -lGL -lGLU -lglut 

