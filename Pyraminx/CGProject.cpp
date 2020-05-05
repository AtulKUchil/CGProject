#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
#include<string.h>
#include"rubixcube.h"   //calls rubix's cube code.
#include"pyraminx.h"    //calls pyraminx code.

using namespace std;

// used for drawing text.
void draw_text_frontWindow(int x, int y, const char* text, int font){
    const char *c;
    glRasterPos2i(x,y);
    for(c=text;*c!='\0';c++)
        if(font == 1)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
        else
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
}

// Draws the choose text.
void choose_text_frontWindow(){
    string front1 = "Choose by entering 1, 2, or 3:";
    string front2 = "1. Pyraminx";
    string front3 = "2. Rubix's Cube";
    string front4 = "3. Exit";
    draw_text_frontWindow(20, 70, front1.data(),1);
    draw_text_frontWindow(20, 65, front2.data(),1);
    draw_text_frontWindow(20, 60, front3.data(),1);
    draw_text_frontWindow(20, 55, front4.data(),1);
}

// calls all the funtions needed for proper functioning.
void display_frontWindow(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    choose_text_frontWindow();
    string a = "Project By:";
    string b = "Anirudh Sureshram - 1PE16CS020";
    string c = "Aravindhan Venkataramanan - 1PE17CS026";
    string d = "Atul K Uchil - 1PE17CS029";
    draw_text_frontWindow(70, 15, a.data(),2);
    draw_text_frontWindow(75, 12, b.data(),2);
    draw_text_frontWindow(75, 9, c.data(),2);
    draw_text_frontWindow(75, 6, d.data(),2);
	glFlush();
	glutSwapBuffers();
}

//Choosing which operation - pyraminx, rubix's cube or exit.
void keys_frontWindow(unsigned char key, int x,int y){
    if(key == '1'){
        // Calling Pyraminx Code by creating new window.
        glutCreateWindow("Pyraminx");
	    glutFullScreen();
        glutReshapeFunc(myReshape_pyraminx);
        glutDisplayFunc(display_pyraminx);
	    glutPassiveMotionFunc(hover_pyraminx);
	    glutKeyboardFunc(keys_pyraminx);
	    glutMouseFunc(mouse_pyraminx);
        glEnable(GL_DEPTH_TEST);
    }
    else if(key == '2'){
        // Calling Rubix's Cube Code by creating new window.
        glutCreateWindow("Rubix's Code");
	    glutFullScreen();
        glutReshapeFunc(myReshape_cube);
        glutDisplayFunc(display_cube);
        glutMouseFunc(mouse_cube);
        glutKeyboardFunc(keys_cube);
        glEnable(GL_DEPTH_TEST);
    }
    else if(key == '3'){
        exit(0);
    }
}

// To define the width and height of the draw-space.
void myReshape_frontWindow(int w, int h){
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
    glutCreateWindow("Front Window");
    glutFullScreen();
	glutReshapeFunc(myReshape_frontWindow);
	glutDisplayFunc(display_frontWindow);
	glutKeyboardFunc(keys_frontWindow);
	glutMainLoop();
	return 0;
}
