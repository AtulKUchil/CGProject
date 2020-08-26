# PyraminxAndRubiksCubeSimulation
This openGL project simulates the working of a Pyaminx and a Rubik's Cube. One can control the cubes using mouse and keyboard.

## Prerequisites
* C++ installed in your System
* OpenGL - GL, GLU, glut


To install openGL in linux use the commands:
```bash
sudo apt-get install freeglut3-dev
sudo apt-get install mesa-utils
```

## Usage
In the first page you can select either Pyraminx or Rubik's Cube.  
If the Pyraminx was selected, use the w,a,s,d keys to move the Pyraminx around and use the mouse to move the layers of the Pyraminx.  
If the Rubik's Cube was selected, use the w,a,s,d keys to move the Rubik's Cube around and use the mouse to move the layers of the Rubik's Cube.  

To compile the Code:  
```bash
g++ pyraminx.cpp rubixcube.cpp CGProject.cpp -lGL -lGLU -lglut
```

To run the program:  
```bash
./a.out
```

## ScreenShots
![FirstPage](https://github.com/AtulKUchil/PyraminxAndRubiksCubeSimulation/blob/master/images/firstpage.png)
![Pyraminx1](https://github.com/AtulKUchil/PyraminxAndRubiksCubeSimulation/blob/master/images/pyraminx1.png)
![Pyraminx2](https://github.com/AtulKUchil/PyraminxAndRubiksCubeSimulation/blob/master/images/pyraminx2.png)
![Pyraminx3](https://github.com/AtulKUchil/PyraminxAndRubiksCubeSimulation/blob/master/images/pyraminx3.png)
![rubik1](https://github.com/AtulKUchil/PyraminxAndRubiksCubeSimulation/blob/master/images/rubicks1.png)
![rubik2](https://github.com/AtulKUchil/PyraminxAndRubiksCubeSimulation/blob/master/images/rubicks2.png)
![rubik3](https://github.com/AtulKUchil/PyraminxAndRubiksCubeSimulation/blob/master/images/rubicks3.png)
