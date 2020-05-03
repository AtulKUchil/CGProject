#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include"rubixcube.h"

using namespace std;

//Defines vertices for the innermost cube which helps in drawing the Rubix's cube.
GLfloat vertices[][3] = {{-2,-2,-2},{2,-2,-2},{2,2,-2}, {-2,2,-2}, {-2,-2,2}, {2,-2,2}, {2,2,2}, {-2,2,2}};
// Defines the colors used in the coloring the cube.
GLfloat colors1[][3] = {{1.0,1.0,1.0},{1.0,0.5,0.0},{1.0,1.0,1.0},{0.0,0.7,0.0},{1.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,1.0},{0.7,0.0,0.0}};

// Stores the vertices of all the 27 cubes.
class cubicle{
	public:
	GLfloat cube_vertices[8][3] = {0};
};
cubicle cube[27];

// angles in which the whole cube rotates.
float angle_cube_x = 0, angle_cube_y = 0;

//drawing the first rubix's cube.
// draws the face of a cube and also stores all the coordinates of all the cubes.
void polygon(int a, int b, int c , int d, int x, int y, int z){
    GLfloat sum[8][3] = {0};
    int cube_no = 9*(x+1) + 3*(y+1) + (z+1);
	glBegin(GL_POLYGON);
	glColor3fv(colors1[d]);		
	sum[a][0] = vertices[a][0] + 4.0*x;
	sum[a][1] = vertices[a][1] + 4.0*y;
	sum[a][2] = vertices[a][2] + 4.0*z; 
	glVertex3fv(sum[a]);
    cube[cube_no].cube_vertices[a][0] = sum[a][0];
    cube[cube_no].cube_vertices[a][1] = sum[a][1];
    cube[cube_no].cube_vertices[a][2] = sum[a][2];
	
    sum[b][0] = vertices[b][0] + 4.0*x;
	sum[b][1] = vertices[b][1] + 4.0*y;
	sum[b][2] = vertices[b][2] + 4.0*z;
	glVertex3fv(sum[b]);
    cube[cube_no].cube_vertices[b][0] = sum[b][0];
    cube[cube_no].cube_vertices[b][1] = sum[b][1];
    cube[cube_no].cube_vertices[b][2] = sum[b][2];
	
    sum[c][0] = vertices[c][0] + 4.0*x;
	sum[c][1] = vertices[c][1] + 4.0*y;
	sum[c][2] = vertices[c][2] + 4.0*z;
	glVertex3fv(sum[c]);
    cube[cube_no].cube_vertices[c][0] = sum[c][0];
    cube[cube_no].cube_vertices[c][1] = sum[c][1];
    cube[cube_no].cube_vertices[c][2] = sum[c][2];
	
    sum[d][0] = vertices[d][0] + 4.0*x;
	sum[d][1] = vertices[d][1] + 4.0*y;
	sum[d][2] = vertices[d][2] + 4.0*z;
	glVertex3fv(sum[d]);
    cube[cube_no].cube_vertices[d][0] = sum[d][0];
    cube[cube_no].cube_vertices[d][1] = sum[d][1];
    cube[cube_no].cube_vertices[d][2] = sum[d][2];
	glEnd();

    // lines to separate the cubes.
    glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3fv(sum[a]);
	glVertex3fv(sum[b]);
	glVertex3fv(sum[c]);
	glVertex3fv(sum[d]);
	glEnd();
}

//temporary array variable to store the coordinates while swaping.
GLfloat temp[27][8][3] = {0};

// storing the updated value of the cube after rotation about X-axis in temp variable.
void updateXRotation(int count, int a, int b, int c, int d){
    int tempa = cube[count].cube_vertices[a][1];
    int tempb = cube[count].cube_vertices[b][1];
    int tempc = cube[count].cube_vertices[c][1];
    int tempd = cube[count].cube_vertices[d][1];

    temp[count][a][0] = cube[count].cube_vertices[a][0];
    temp[count][a][1] = cube[count].cube_vertices[a][1]*cos(90*3.14159265/180) - cube[count].cube_vertices[a][2]*sin(90*3.14159265/180);
    temp[count][a][2] = cube[count].cube_vertices[a][2]*cos(90*3.14159265/180) + tempa*sin(90*3.14159265/180);
    temp[count][b][0] = cube[count].cube_vertices[b][0];
    temp[count][b][1] = cube[count].cube_vertices[b][1]*cos(90*3.14159265/180) - cube[count].cube_vertices[b][2]*sin(90*3.14159265/180);
    temp[count][b][2] = cube[count].cube_vertices[b][2]*cos(90*3.14159265/180) + tempb*sin(90*3.14159265/180);
    temp[count][c][0] = cube[count].cube_vertices[c][0];
    temp[count][c][1] = cube[count].cube_vertices[c][1]*cos(90*3.14159265/180) - cube[count].cube_vertices[c][2]*sin(90*3.14159265/180);
    temp[count][c][2] = cube[count].cube_vertices[c][2]*cos(90*3.14159265/180) + tempc*sin(90*3.14159265/180);
    temp[count][d][0] = cube[count].cube_vertices[d][0];
    temp[count][d][1] = cube[count].cube_vertices[d][1]*cos(90*3.14159265/180) - cube[count].cube_vertices[d][2]*sin(90*3.14159265/180);
    temp[count][d][2] = cube[count].cube_vertices[d][2]*cos(90*3.14159265/180) + tempd*sin(90*3.14159265/180);
}

// storing the updated value of the cube after rotation about Y-axis in temp variable.
void updateYRotation(int count, int a, int b, int c, int d){
    int tempa = cube[count].cube_vertices[a][0];
    int tempb = cube[count].cube_vertices[b][0];
    int tempc = cube[count].cube_vertices[c][0];
    int tempd = cube[count].cube_vertices[d][0];

    temp[count][a][1] = cube[count].cube_vertices[a][1];
    temp[count][a][0] = cube[count].cube_vertices[a][0]*cos(90*3.14159265/180) + cube[count].cube_vertices[a][2]*sin(90*3.14159265/180);
    temp[count][a][2] = cube[count].cube_vertices[a][2]*cos(90*3.14159265/180) - tempa*sin(90*3.14159265/180);
    temp[count][b][1] = cube[count].cube_vertices[b][1];
    temp[count][b][0] = cube[count].cube_vertices[b][0]*cos(90*3.14159265/180) + cube[count].cube_vertices[b][2]*sin(90*3.14159265/180);
    temp[count][b][2] = cube[count].cube_vertices[b][2]*cos(90*3.14159265/180) - tempb*sin(90*3.14159265/180);
    temp[count][c][1] = cube[count].cube_vertices[c][1];
    temp[count][c][0] = cube[count].cube_vertices[c][0]*cos(90*3.14159265/180) + cube[count].cube_vertices[c][2]*sin(90*3.14159265/180);
    temp[count][c][2] = cube[count].cube_vertices[c][2]*cos(90*3.14159265/180) - tempc*sin(90*3.14159265/180);
    temp[count][d][1] = cube[count].cube_vertices[d][1];
    temp[count][d][0] = cube[count].cube_vertices[d][0]*cos(90*3.14159265/180) + cube[count].cube_vertices[d][2]*sin(90*3.14159265/180);
    temp[count][d][2] = cube[count].cube_vertices[d][2]*cos(90*3.14159265/180) - tempd*sin(90*3.14159265/180);
}

// storing the updated value of the cube after rotation about Z-axis in temp variable.
void updateZRotation(int count, int a, int b, int c, int d){
    int tempa = cube[count].cube_vertices[a][0];
    int tempb = cube[count].cube_vertices[b][0];
    int tempc = cube[count].cube_vertices[c][0];
    int tempd = cube[count].cube_vertices[d][0];

    temp[count][a][2] = cube[count].cube_vertices[a][2];
    temp[count][a][0] = cube[count].cube_vertices[a][0]*cos(90*3.14159265/180) - cube[count].cube_vertices[a][1]*sin(90*3.14159265/180);
    temp[count][a][1] = cube[count].cube_vertices[a][1]*cos(90*3.14159265/180) + tempa*sin(90*3.14159265/180);
    temp[count][b][2] = cube[count].cube_vertices[b][2];
    temp[count][b][0] = cube[count].cube_vertices[b][0]*cos(90*3.14159265/180) - cube[count].cube_vertices[b][1]*sin(90*3.14159265/180);
    temp[count][b][1] = cube[count].cube_vertices[b][1]*cos(90*3.14159265/180) + tempb*sin(90*3.14159265/180);
    temp[count][c][2] = cube[count].cube_vertices[c][2];
    temp[count][c][0] = cube[count].cube_vertices[c][0]*cos(90*3.14159265/180) - cube[count].cube_vertices[c][1]*sin(90*3.14159265/180);
    temp[count][c][1] = cube[count].cube_vertices[c][1]*cos(90*3.14159265/180) + tempc*sin(90*3.14159265/180);
    temp[count][d][2] = cube[count].cube_vertices[d][2];
    temp[count][d][0] = cube[count].cube_vertices[d][0]*cos(90*3.14159265/180) - cube[count].cube_vertices[d][1]*sin(90*3.14159265/180);
    temp[count][d][1] = cube[count].cube_vertices[d][1]*cos(90*3.14159265/180) + tempd*sin(90*3.14159265/180);
}

// Drawing the rubix's cube and also does the operation of rotating on keypress.
void polygon1(int a,int b, int c, int d,int x, int y, int z, int keypressedx, int keypressedy, int keypressedz){
    int count = 9*(x+1) + 3*(y+1) + (z+1);
    
    //storing all the previous values of cube.
    temp[count][a][0] = cube[count].cube_vertices[a][0];
    temp[count][a][1] = cube[count].cube_vertices[a][1];
    temp[count][a][2] = cube[count].cube_vertices[a][2];
    temp[count][b][0] = cube[count].cube_vertices[b][0];
    temp[count][b][1] = cube[count].cube_vertices[b][1];
    temp[count][b][2] = cube[count].cube_vertices[b][2];
    temp[count][c][0] = cube[count].cube_vertices[c][0];
    temp[count][c][1] = cube[count].cube_vertices[c][1];
    temp[count][c][2] = cube[count].cube_vertices[c][2];
    temp[count][d][0] = cube[count].cube_vertices[d][0];
    temp[count][d][1] = cube[count].cube_vertices[d][1];
    temp[count][d][2] = cube[count].cube_vertices[d][2];
    
    // Updating cube coordinates for x-axis rotation
    if(x == keypressedx){
        updateXRotation(count, a, b, c, d);
    }

    // Updating cube coordinates for y-axis rotation
    if(y == keypressedy){
        updateYRotation(count, a, b, c, d);
    }

    // Updating cube coordinates for z-axis rotation
    if(z == keypressedz){
        updateZRotation(count, a, b, c, d);
    }

    // Drawing cube after operation.
    glBegin(GL_POLYGON);
    glColor3fv(colors1[d]);
	glVertex3fv(temp[count][a]);
	glVertex3fv(temp[count][b]);
	glVertex3fv(temp[count][c]);
	glVertex3fv(temp[count][d]);
	glEnd();

    // Drawing lines separating the cubes.
	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3fv(temp[count][a]);
	glVertex3fv(temp[count][b]);
	glVertex3fv(temp[count][c]);
	glVertex3fv(temp[count][d]);
	glEnd();
}

// Drawing the rubix's cube and updates the coorinates into the object cube from the temp cube.
void colorcube1(int keypressedx = 3, int keypressedy = 3, int keypressedz = 3){
    for(int x=-1;x<2;x++){
        for(int y=-1;y<2;y++){
            for(int z=-1;z<2;z++){
                int count = 9*(x+1) + 3*(y+1) + (z+1);
                polygon1(0,3,2,1,x,y,z,keypressedx,keypressedy,keypressedz);
                polygon1(2,3,7,6,x,y,z,keypressedx,keypressedy,keypressedz);
                polygon1(0,4,7,3,x,y,z,keypressedx,keypressedy,keypressedz);
                polygon1(1,2,6,5,x,y,z,keypressedx,keypressedy,keypressedz);
                polygon1(4,5,6,7,x,y,z,keypressedx,keypressedy,keypressedz);
                polygon1(0,1,5,4,x,y,z,keypressedx,keypressedy,keypressedz);
                
                //updates all the cubes with new vertices.
                for(int i=0;i<8;i++){
                    for(int j=0;j<3;j++)
                        cube[count].cube_vertices[i][j] = temp[count][i][j];
                }
            }
        }
    }

    // updating the cube value to store in the right order.
    // Incase of X-axis rotation. 
    for(int x=-1;x<2;x++){
        if(keypressedx == x){
            for(int count = 0;count <9; count++){
                int temp_count;
                if((count+(x+1)*9) < (x+1)*9 + 3)
                    temp_count =(x+1)*9 + (count+(count+1)*2);
                else if((count+(x+1)*9) < (x+1)*9 + 6)
                    temp_count = (x+1)*9 + (count+(count+1)*2 - 10);
                else if((count+(x+1)*9) < (x+1)*9 + 9)
                    temp_count =(x+1)*9 + (count+(count+1)*2 - 20);

                // updating the cube value for the rotated cubes since others are alright.
                for(int i=0;i<8;i++){
                    for(int j=0;j<3;j++)
                        cube[count+(x+1)*9].cube_vertices[i][j] = temp[temp_count][i][j];
                }
            }
        }
    }

    // Incase of Y-axis rotation.
    int addY[9] = {18,8,-2,10,0,-10,2,-8,-18};
    int Ypath[9] = {0,1,2,9,10,11,18,19,20};
    for(int y=-1;y<2;y++){
        if(keypressedy == y){
            for(int count = 0;count <9; count++){
                int temp_count = Ypath[count]+(y+1)*3 + addY[count];

                // updating the cube value for the rotated cubes since others are alright.
                for(int i=0;i<8;i++){
                    for(int j=0;j<3;j++)
                        cube[Ypath[count]+(y+1)*3].cube_vertices[i][j] = temp[temp_count][i][j];
                }
            }
        }
    }

    //Incase of Z-axis rotation.
    int addZ[9] = {6,-6,-18,12,0,-12,18,6,-6};
    int Zpath[9] = {0,9,18,3,12,21,6,15,24};
    for(int z=-1;z<2;z++){
        if(keypressedz == z){
            for(int count = 0;count <9; count++){
                int temp_count = Zpath[count]+(z+1) + addZ[count];

                // updating the cube value for the rotated cubes since others are alright.
                for(int i=0;i<8;i++){
                    for(int j=0;j<3;j++){
                        cube[Zpath[count]+(z+1)].cube_vertices[i][j] = temp[temp_count][i][j];
                    }
                }
            }
        }
    }
}

//Drawing the first rubix's cube.
void colorcube(){
    for(int x=-1;x<2;x++){
        for(int y=-1;y<2;y++){
            for(int z=-1;z<2;z++){
                polygon(0,3,2,1,x,y,z);
                polygon(2,3,7,6,x,y,z);
                polygon(0,4,7,3,x,y,z);
                polygon(1,2,6,5,x,y,z);
                polygon(4,5,6,7,x,y,z);
                polygon(0,1,5,4,x,y,z);
            }
        }
    }
}

// Drawing Characters in screen.
void draw_character(GLfloat x, GLfloat y, GLfloat z, const char* text, int font){
    const char *c;
    glRasterPos3f(x,y,z);
    for(c=text;*c!='\0';c++)
        if(font == 1)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c); // Larger font. 
        else
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c); // smaller font.
}

// Drawing the squares for the button-like feature in the output.
void draw_square(){
    // to prevent any rotate operation to act on the squares.
    glPushMatrix(); 
    glLoadIdentity();

    //Draw red polygon.
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.0,0.0);
    glVertex3f(20.0, 4.0,0.0);
    glVertex3f(24.0, 4.0,0.0);
    glVertex3f(24.0,-4.0,0.0);
    glVertex3f(20.0,-4.0,0.0);
    glEnd();
    //Draw blue polygon.
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(24.0, 4.0,0.0);
    glVertex3f(28.0, 4.0,0.0);
    glVertex3f(28.0,-4.0,0.0);
    glVertex3f(24.0,-4.0,0.0);
    glEnd();
    //Draw orange polygon.
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,0.0);
    glVertex3f(28.0, 4.0,0.0);
    glVertex3f(32.0, 4.0,0.0);
    glVertex3f(32.0,-4.0,0.0);
    glVertex3f(28.0,-4.0,0.0);
    glEnd();
    //Draw Green polygon.
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.7,0.0);
    glVertex3f(32.0, 4.0,0.0);
    glVertex3f(36.0, 4.0,0.0);
    glVertex3f(36.0,-4.0,0.0);
    glVertex3f(32.0,-4.0,0.0);
    glEnd();
    //Draw white polygon.
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(36.0, 4.0,0.0);
    glVertex3f(40.0, 4.0,0.0);
    glVertex3f(40.0,-4.0,0.0);
    glVertex3f(36.0,-4.0,0.0);
    glEnd();
    // Draw Yellow polygon.
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(40.0, 4.0,0.0);
    glVertex3f(44.0, 4.0,0.0);
    glVertex3f(44.0,-4.0,0.0);
    glVertex3f(40.0,-4.0,0.0);
    glEnd();
    //Draw lines separating the squares.
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(20.0, 4.0,0.1);
    glVertex3f(24.0, 4.0,0.1);
    glVertex3f(24.0,-4.0,0.1);
    glVertex3f(20.0,-4.0,0.1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(24.0, 4.0,0.1);
    glVertex3f(28.0, 4.0,0.1);
    glVertex3f(28.0,-4.0,0.1);
    glVertex3f(24.0,-4.0,0.1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(32.0, 4.0,0.1);
    glVertex3f(28.0, 4.0,0.1);
    glVertex3f(28.0,-4.0,0.1);
    glVertex3f(32.0,-4.0,0.1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(36.0, 4.0,0.1);
    glVertex3f(32.0, 4.0,0.1);
    glVertex3f(32.0,-4.0,0.1);
    glVertex3f(36.0,-4.0,0.1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(40.0, 4.0,0.1);
    glVertex3f(36.0, 4.0,0.1);
    glVertex3f(36.0,-4.0,0.1);
    glVertex3f(40.0,-4.0,0.1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(44.0, 4.0,0.1);
    glVertex3f(40.0, 4.0,0.1);
    glVertex3f(40.0,-4.0,0.1);
    glVertex3f(44.0,-4.0,0.1);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(20.0, 0.0,0.1);
    glVertex3f(44.0, 0.0,0.1);
    glEnd();

    // Drawing the characters on the squares.
    string f = "F";
    draw_character(21.8,1.5,0.1,f.data(),1);
    string r = "R";
    draw_character(25.8,1.5,0.1,r.data(),1);
    string b = "B";
    draw_character(29.8,1.5,0.1,b.data(),1);
    string l = "L";
    draw_character(33.8,1.5,0.1,l.data(),1);
    string u = "U";
    draw_character(37.8,1.5,0.1,u.data(),1);
    string d = "D";
    draw_character(41.8,1.5,0.1,d.data(),1);
    string f_inverse = "F'";
    draw_character(21.8,-2.5,0.1,f_inverse.data(),1);
    string r_inverse = "R'";
    draw_character(25.8,-2.5,0.1,r_inverse.data(),1);
    string b_inverse = "B'";
    draw_character(29.8,-2.5,0.1,b_inverse.data(),1);
    string l_inverse = "L'";
    draw_character(33.8,-2.5,0.1,l_inverse.data(),1);
    string u_inverse = "U'";
    draw_character(37.8,-2.5,0.1,u_inverse.data(),1);
    string d_inverse = "D'";
    draw_character(41.8,-2.5,0.1,d_inverse.data(),1);
    glPopMatrix();
}

//Display for whenever an operation is done.
void mydisplay1(int keypressedx, int keypressedy, int keypressedz){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angle_cube_x,1.0,0.0,0.0);    // rotation of whole cube about x-axis.
    glRotatef(angle_cube_y,0.0,1.0,0.0);    // rotation of whole cube about y-axis.
    colorcube1(keypressedx,keypressedy,keypressedz);    //rotation of layes on keypress.
    draw_square();                          // Drawing the squares with characters on them.
    string quit = "Press q to quit";        
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    draw_character(-5, 20, 0, quit.data(), 1);      // Print "Press q to quit" on screen.
    glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

// To prevent recall of display1 function.
int flag_display1 = 0;

//Called only once unless fullScreen is removed.
void display1(void){
    if(flag_display1 == 1){
        // Call this whenever display is called except for the first time.
        mydisplay1(3,3,3);
    }
    else{
    // Call this only the first time.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angle_cube_x,1.0,0.0,0.0);
    glRotatef(angle_cube_y,0.0,1.0,0.0);
    flag_display1 = 1;
    colorcube();
    draw_square();
    string quit = "Press q to quit";
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    draw_character(-5, 20, 0, quit.data(), 1);
    glPopMatrix();
	glFlush();
	glutSwapBuffers();
    }
}

// For mouse Input.
void mouse1(int btn, int state, int x, int y){
    int keypressedx=3, keypressedy=3, keypressedz=3;
    if(btn==GLUT_LEFT_BUTTON){
		if(state == GLUT_DOWN){
			if(x>=681 && x<=751 && y<=539 && y>=470){  // F
				keypressedz = 1;
                mydisplay1(keypressedx, keypressedy, keypressedz);
                mydisplay1(keypressedx, keypressedy, keypressedz);
			}
			else if(x>=751 && x<=821 && y<=539 && y>=470){  // R
			    keypressedx = 1;
                mydisplay1(keypressedx, keypressedy, keypressedz);
                mydisplay1(keypressedx, keypressedy, keypressedz);
			}
			else if(x>=821 && x<=891 && y<=539 && y>=470){  // B
			    keypressedz = -1;
			}
			else if(x>=891 && x<=961 && y<=539 && y>=470){  // L
			    keypressedx = -1;
			}
			else if(x>=961 && x<=1031 && y<=539 && y>=470){  // U
			    keypressedy = 1;
                mydisplay1(keypressedx, keypressedy, keypressedz);
                mydisplay1(keypressedx, keypressedy, keypressedz);
			}
			else if(x>=1031 && x<=1101 && y<=539 && y>=470){  // D
			    keypressedy = -1;
			}
			else if(x>=681 && x<=751 && y<=608 && y>=539){  // F'
				keypressedz = 1;
			}
			else if(x>=751 && x<=821 && y<=608 && y>=539){  // R'
			    keypressedx = 1;
			}
			else if(x>=821 && x<=891 && y<=608 && y>=539){  // B'
			    keypressedz = -1;
                mydisplay1(keypressedx, keypressedy, keypressedz);
                mydisplay1(keypressedx, keypressedy, keypressedz);
			}
			else if(x>=891 && x<=961 && y<=608 && y>=539){  // L'
			    keypressedx = -1;
                mydisplay1(keypressedx, keypressedy, keypressedz);
                mydisplay1(keypressedx, keypressedy, keypressedz);
			}
			else if(x>=961 && x<=1031 && y<=608 && y>=539){  // U'
			    keypressedy = 1;
			}
			else if(x>=1031 && x<=1101 && y<=608 && y>=539){  // D'
			    keypressedy = -1;
                mydisplay1(keypressedx, keypressedy, keypressedz);
                mydisplay1(keypressedx, keypressedy, keypressedz);
			}
			else{
                keypressedx = 3;
                keypressedy = 3;
                keypressedz = 3;
            }
		}
    }
	mydisplay1(keypressedx,keypressedy,keypressedz);
}

// For keyboard Input.
void keys1(unsigned char key, int x, int y){
    int keypressedx = 3, keypressedy = 3,keypressedz = 3;
    switch(key){
	case 'A':
	case 'a':
		angle_cube_y += 2;
		if(angle_cube_x <= 0){
			angle_cube_x += 360;
		}
		break;

	case 'd':
	case 'D':
		angle_cube_y -= 2;
		if(angle_cube_x >=360){
			angle_cube_x -= 360;
		}
		break;

	case 'w':
	case 'W':
		angle_cube_x += 3;
		if(angle_cube_y >= 360){
			angle_cube_y -= 360;
		}
		break;

	case 's':
	case 'S':
		angle_cube_x -= 3;
		if(angle_cube_y <= 0){
			angle_cube_y += 360;
		}
		break;
	}

    // Quit code when pressed.
    if(key == 'q'){
        exit(0);
    }
    
    mydisplay1(keypressedx, keypressedy, keypressedz);
}

// Whenever the window is reshaped.
void myReshape1(int w, int h){
	int window_height = h;
	int window_width = w;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	if(w<=h)
		glOrtho(-10.0,50.0*(GLfloat)h/(GLfloat)w,-30.0*(GLfloat)h/(GLfloat)w, 30.0,-50.0,50.0);
	else
		glOrtho(-10.0*(GLfloat)w/(GLfloat)h, 50.0*(GLfloat)w/(GLfloat)h,-30.0,30.0,-50.0,50.0);
	glMatrixMode(GL_MODELVIEW);
}