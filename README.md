==== GASimple ==== <br>
A C++/OpenGL program that uses a genetic algorithm to get from a designated starting point to a designated finish point.<br>
The program runs using FreeGLUT for OpenGL graphics and input management and uses a map loaded from the GASimple<br> 
MapEditor program below. I was too lazy to include any command line arguments to control the mapdata file, so the<br>
mapdata file must be named 'mapdata.gas'.<br><br>
The genetic algorithm uses a fitness score based solely on the distance each 'creature' is from the end point after a set<br>
number of steps. Each generation is made of 100 different creatures, the 50 closest creatures survive and the other 50<br>
are killed. To handle repopulating, each surviving creature makes a duplicate of itself with a small % chance of their <br>
path mutating to form a different path. The values for "mutatePercent" and "MAX_FRAMES" found in globals.h will heavily<br> 
influence how quick or straight the path to the goal eventually found is. <br><br>
This program wasn't a school project, it wasn't graded, and it wasn't for any purpose. I have a small interest in machine
learning and figured a genetic algorithm, no matter how simple or complicated, would be a good starting point to let that
interest grow. To me, this program mixed together two interests of mine, machine learning and pathfinding. I have other
path finders, such as an RRT pathfinder (uses rapidly expanding random movements to find a goal), and this was really
a nice small step into machine learning using something visual (pathfinding in OpenGL) and simple (euclidian distance
formula for genetic fitness).<br><br><br>

--Windows | MSVC--<br>
This program comes with glut.h already, so including it into your MSVC include path won't be necessary, however, you will need
to make sure the working directory has glut32.dll in it otherwise you will receive a run-time error. In your program's properties
page make sure under "Linker >> Input >> Additional Dependancies" You have "opengl32.lib;glu32.lib;glut32.lib;%(AdditionalDependencies)"
as the set value. This will require you to make sure your MSVS library directory contains opengl32.lib, glu32.lib, and glut32.lib,
which if I remember correctly are found at the freeglut homepage, glut32.lib is included with the program, for some reason..<br><br>

--Windows | MinGW--<br>
Same as the MSVC build, only thing to note is to make sure your PATH variable contains your MinGW 'bin' directory (for access
to gcc/g++/etc..), then compiling just requires the following command string<br>
"g++ -o GASimple *.cpp -lopengl32 -lglu32 -lglut32"<br><br>

--Linux--<br>
For Linux OS's, make sure you have FreeGLUT and gcc/g++ installed and compile using the following line<br>
"g++ -o GASimple *.cpp -lopengl32 -lglu32 -lglut32"<br><br><br><br>



==== GASimple MapEditor ====<br>
GASimple MapEditor is a program written in C++ using FreeGLUT for OpenGL support. The program is meant to create 'mapdata'
files that the original program (GASimple) can read and use. The MapEditor is easy to use and doesn't require much to compile.<br><br><br>


--Windows | MSVC--<br>
This program comes with glut.h already, so including it into your MSVC include path won't be necessary, however, you will need
to make sure the working directory has glut32.dll in it otherwise you will receive a run-time error. In your program's properties
page make sure under "Linker >> Input >> Additional Dependancies" You have "opengl32.lib;glu32.lib;glut32.lib;%(AdditionalDependencies)"
as the set value. This will require you to make sure your MSVS library directory contains opengl32.lib, glu32.lib, and glut32.lib,
which if I remember correctly are found at the freeglut homepage, glut32.lib is included with the program, for some reason..<br><br>

--Windows | MinGW--<br>
Same as the MSVC build, only thing to note is to make sure your PATH variable contains your MinGW 'bin' directory (for access
to gcc/g++/etc..), then compiling just requires the following command string<br>
"g++ -o GASimpleMapEditor *.cpp -lopengl32 -lglu32 -lglut32"<br><br>

--Linux--<br>
For Linux OS's, make sure you have FreeGLUT and gcc/g++ installed and compile using the following line<br>
"g++ -o GASimpleMapEditor *.cpp -lopengl32 -lglu32 -lglut32"<br><br><br><br>



- If you have issues, send me an e-mail and i'll try to resolve the issue.<br>
- Fair warning, I've only compiled/ran this on Windows using MinGW and MSVC, so I'm going off of the hope that anyone running this
on linux has the know-how to install FreeGlut, gcc/g++, and make sure libraries/includes are set up properly..<br>
- I'm open to any criticism of the program, I know it's not the most elegant code and it's definately not the most efficient thing
I've written, but it does what it was written to do and it was still a learning experience for me.
