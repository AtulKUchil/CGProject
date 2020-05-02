#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
#include<string.h>
#include"rubixcube.h"   //calls rubix's cube code.
#include"pyraminx.h"    //calls pyraminx code.

using namespace std;

// used for drawing text.
void draw_text(int x, int y, const char* text, int font){
    const char *c;
    glRasterPos2i(x,y);
    for(c=text;*c!='\0';c++)
        if(font == 1)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
        else
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
}

// Draws the choose text.
void choose_text(){
    string front1 = "Choose by entering 1, 2, or 3:";
    string front2 = "1. Pyraminx";
    string front3 = "2. Rubix's Cube";
    string front4 = "3. Exit";
    draw_text(20, 70, front1.data(),1);
    draw_text(20, 65, front2.data(),1);
    draw_text(20, 60, front3.data(),1);
    draw_text(20, 55, front4.data(),1);
}

// calls all the funtions needed for proper functioning.
void display2(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    choose_text();
    string a = "Project By:";
    string b = "Anirudh Sureshram - 1PE16CS020";
    string c = "Aravindhan Venkataramanan - 1PE17CS026";
    string d = "Atul K Uchil - 1PE17CS029";
    draw_text(70, 15, a.data(),2);
    draw_text(75, 12, b.data(),2);
    draw_text(75, 9, c.data(),2);
    draw_text(75, 6, d.data(),2);
	glFlush();
	glutSwapBuffers();
}

// Used for deciding which window needs to be called.
GLint win1, win2, win3;

//Choosing which operation - pyraminx, rubix's cube or exit.
void keys2(unsigned char key, int x,int y){
    if(key == '1'){
        win1 = glutCreateWindow("Pyraminx");
	    glutFullScreen();
        glutReshapeFunc(myReshape);
        glutDisplayFunc(display);
	    glutPassiveMotionFunc(hover);
	    glutKeyboardFunc(keys);
	    glutMouseFunc(mouse);
        glEnable(GL_DEPTH_TEST);
    }
    else if(key == '2'){
        win2 = glutCreateWindow("colorcube");
	    glutFullScreen();
        glutReshapeFunc(myReshape1);
        glutDisplayFunc(display1);
        glutMouseFunc(mouse1);
        glutKeyboardFunc(keys1);
        glEnable(GL_DEPTH_TEST);
    }
    else if(key == '3')
        glutDestroyWindow(win3);
}

// To define the width and height of the draw-space.
void myReshape2(int w, int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0.0,100.0,0.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}

//Main function.
int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    win3 = glutCreateWindow("Front Window");
    glutFullScreen();
	glutReshapeFunc(myReshape2);
	glutDisplayFunc(display2);
	glutKeyboardFunc(keys2);
	glutMainLoop();
	return 0;
}
