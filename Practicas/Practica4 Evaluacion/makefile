# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=   -g -w
CXXFLAGS= -w -g 

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut -ljpeg

# definicion del compilador
#
CC = g++

# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : escena.o practica1.o objeto3d.o cubo.o tetra.o octa.o ply.o file_ply_stl.o orevolucion.o objetoCompuesto.o base.o esfera.o ssolar.o planeta.o escenap4.o luz.o luzDireccional.o luzPosicional.o jpg_imagen.o jpg_memsrc.o jpg_readwrite.o examen.o luzRoja.o
	$(CC) -g -o $@ $(CXXFLAGS) escena.o practica1.o objeto3d.o cubo.o tetra.o octa.o ply.o file_ply_stl.o orevolucion.o objetoCompuesto.o base.o esfera.o ssolar.o planeta.o escenap4.o luz.o luzDireccional.o luzPosicional.o jpg_imagen.o jpg_memsrc.o jpg_readwrite.o examen.o luzRoja.o $(LDFLAGS)

#
#
clean:
	rm -f *.o
	rm -f $(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *
