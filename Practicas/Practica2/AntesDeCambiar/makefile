#Crea el ejecutable final 
practica : escena.o practica1.o objeto3d.o cubo.o tetra.o octa.o ply.o file_ply_stl.o orevolucion.o
	g++ -o practica escena.o practica1.o objeto3d.o cubo.o tetra.o octa.o ply.o file_ply_stl.o orevolucion.o -L/usr/lib64 -lGL -lGLU -lglut

#Crea los objetos a partir de los fuente
practica1.o : practica1.cc
	g++ -c -o practica1.o practica1.cc -L/usr/lib64 -lGL -lGLU -lglut

escena.o : escena.cc
	g++ -c -o escena.o escena.cc -L/usr/lib64 -lGL -lGLU -lglut

cubo.o : cubo.cpp 
	g++ -c -o cubo.o cubo.cpp -L/usr/lib64 -lGL -lGLU -lglut

tetra.o : tetra.cpp 
	g++ -c -o tetra.o tetra.cpp -L/usr/lib64 -lGL -lGLU -lglut

octa.o : octa.cpp 
	g++ -c -o octa.o octa.cpp -L/usr/lib64 -lGL -lGLU -lglut

ply.o : ply.cpp 
	g++ -c -o ply.o ply.cpp -L/usr/lib64 -lGL -lGLU -lglut

orevolucion.o : orevolucion.cpp 
	g++ -c -o orevolucion.o orevolucion.cpp -L/usr/lib64 -lGL -lGLU -lglut

objeto3d.o : objeto3d.cpp
	g++ -c -o objeto3d.o objeto3d.cpp -L/usr/lib64 -lGL -lGLU -lglut

file_ply_stl.o : file_ply_stl.cc
	g++ -c -o file_ply_stl.o file_ply_stl.cc -L/usr/lib64 -lGL -lGLU -lglut

clean :
	rm -f *.o *~ 