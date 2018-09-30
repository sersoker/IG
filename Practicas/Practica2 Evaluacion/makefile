#Crea el ejecutable final 
practica : escena.o practica1.o objeto3d.o cubo.o tetra.o octa.o ply.o file_ply_stl.o orevolucion.o
	g++ -o practica escena.o practica1.o objeto3d.o cubo.o tetra.o octa.o ply.o file_ply_stl.o orevolucion.o -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

#Crea los objetos a partir de los fuente
practica1.o : practica1.cc
	g++ -c -o practica1.o practica1.cc -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

escena.o : escena.cc
	g++ -c -o escena.o escena.cc -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

cubo.o : cubo.cpp 
	g++ -c -o cubo.o cubo.cpp -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

tetra.o : tetra.cpp 
	g++ -c -o tetra.o tetra.cpp -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

octa.o : octa.cpp 
	g++ -c -o octa.o octa.cpp -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

ply.o : ply.cpp 
	g++ -c -o ply.o ply.cpp -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

orevolucion.o : orevolucion.cpp 
	g++ -c -o orevolucion.o orevolucion.cpp -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

objeto3d.o : objeto3d.cpp
	g++ -c -o objeto3d.o objeto3d.cpp -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

file_ply_stl.o : file_ply_stl.cc
	g++ -c -o file_ply_stl.o file_ply_stl.cc -L/usr/lib64 -lGL -lGLU -lglut -std=c++11

clean :
	rm -f *.o *~ 