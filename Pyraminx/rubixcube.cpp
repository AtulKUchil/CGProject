#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include"rubixcube.h"

using namespace std;

GLfloat vertices[][3] = {{-2,-2,-2},{2,-2,-2},{2,2,-2}, {-2,2,-2}, {-2,-2,2}, {2,-2,2}, {2,2,2}, {-2,2,2}};

GLfloat colors1[][3] = {{1.0,1.0,1.0},{1.0,0.5,0.0},{1.0,1.0,1.0},{0.0,0.7,0.0},{1.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,1.0},{0.7,0.0,0.0}};

class cubicle{
	public:
	GLfloat cube_vertices[8][3] = {0};
};

cubicle cube[27];

float angle_cube_x = 0, angle_cube_y = 0;

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

    glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3fv(sum[a]);
	glVertex3fv(sum[b]);
	glVertex3fv(sum[c]);
	glVertex3fv(sum[d]);
	glEnd();
}

GLfloat temp[27][8][3] = {0};

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

void polygon1(int a,int b, int c, int d,int x, int y, int z, int keypressedx, int keypressedy, int keypressedz){
    int count = 9*(x+1) + 3*(y+1) + (z+1);
    
    
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
    
    if(x == keypressedx){
        // printf("Count: %d\n",count);
        updateXRotation(count, a, b, c, d);
    }

    if(y == keypressedy){
        // printf("Count: %d\n",count);
        updateYRotation(count, a, b, c, d);
    }

    if(z == keypressedz){
        // printf("Count: %d\n",count);
        updateZRotation(count, a, b, c, d);
    }
    glBegin(GL_POLYGON);
    glColor3fv(colors1[d]);
	glVertex3fv(temp[count][a]);
	glVertex3fv(temp[count][b]);
	glVertex3fv(temp[count][c]);
	glVertex3fv(temp[count][d]);
	glEnd();

	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3fv(temp[count][a]);
	glVertex3fv(temp[count][b]);
	glVertex3fv(temp[count][c]);
	glVertex3fv(temp[count][d]);
	glEnd();
}

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;
int colorflag = 0;

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
                // printf("___________________________________________________________________________\n");
                cube[count].cube_vertices[0][0] = temp[count][0][0];
                cube[count].cube_vertices[0][1] = temp[count][0][1];
                cube[count].cube_vertices[0][2] = temp[count][0][2];
                cube[count].cube_vertices[1][0] = temp[count][1][0];
                cube[count].cube_vertices[1][1] = temp[count][1][1];
                cube[count].cube_vertices[1][2] = temp[count][1][2];
                cube[count].cube_vertices[2][0] = temp[count][2][0];
                cube[count].cube_vertices[2][1] = temp[count][2][1];
                cube[count].cube_vertices[2][2] = temp[count][2][2];
                cube[count].cube_vertices[3][0] = temp[count][3][0];
                cube[count].cube_vertices[3][1] = temp[count][3][1];
                cube[count].cube_vertices[3][2] = temp[count][3][2];
                cube[count].cube_vertices[4][0] = temp[count][4][0];
                cube[count].cube_vertices[4][1] = temp[count][4][1];
                cube[count].cube_vertices[4][2] = temp[count][4][2];
                cube[count].cube_vertices[5][0] = temp[count][5][0];
                cube[count].cube_vertices[5][1] = temp[count][5][1];
                cube[count].cube_vertices[5][2] = temp[count][5][2];
                cube[count].cube_vertices[6][0] = temp[count][6][0];
                cube[count].cube_vertices[6][1] = temp[count][6][1];
                cube[count].cube_vertices[6][2] = temp[count][6][2];
                cube[count].cube_vertices[7][0] = temp[count][7][0];
                cube[count].cube_vertices[7][1] = temp[count][7][1];
                cube[count].cube_vertices[7][2] = temp[count][7][2];
                // temp[count][8][3] = {0};
            }
        }
    }
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

        cube[count+(x+1)*9].cube_vertices[0][0] = temp[temp_count][0][0];
        cube[count+(x+1)*9].cube_vertices[0][1] = temp[temp_count][0][1];
        cube[count+(x+1)*9].cube_vertices[0][2] = temp[temp_count][0][2];
        cube[count+(x+1)*9].cube_vertices[1][0] = temp[temp_count][1][0];
        cube[count+(x+1)*9].cube_vertices[1][1] = temp[temp_count][1][1];
        cube[count+(x+1)*9].cube_vertices[1][2] = temp[temp_count][1][2];
        cube[count+(x+1)*9].cube_vertices[2][0] = temp[temp_count][2][0];
        cube[count+(x+1)*9].cube_vertices[2][1] = temp[temp_count][2][1];
        cube[count+(x+1)*9].cube_vertices[2][2] = temp[temp_count][2][2];
        cube[count+(x+1)*9].cube_vertices[3][0] = temp[temp_count][3][0];
        cube[count+(x+1)*9].cube_vertices[3][1] = temp[temp_count][3][1];
        cube[count+(x+1)*9].cube_vertices[3][2] = temp[temp_count][3][2];
        cube[count+(x+1)*9].cube_vertices[4][0] = temp[temp_count][4][0];
        cube[count+(x+1)*9].cube_vertices[4][1] = temp[temp_count][4][1];
        cube[count+(x+1)*9].cube_vertices[4][2] = temp[temp_count][4][2];
        cube[count+(x+1)*9].cube_vertices[5][0] = temp[temp_count][5][0];
        cube[count+(x+1)*9].cube_vertices[5][1] = temp[temp_count][5][1];
        cube[count+(x+1)*9].cube_vertices[5][2] = temp[temp_count][5][2];
        cube[count+(x+1)*9].cube_vertices[6][0] = temp[temp_count][6][0];
        cube[count+(x+1)*9].cube_vertices[6][1] = temp[temp_count][6][1];
        cube[count+(x+1)*9].cube_vertices[6][2] = temp[temp_count][6][2];
        cube[count+(x+1)*9].cube_vertices[7][0] = temp[temp_count][7][0];
        cube[count+(x+1)*9].cube_vertices[7][1] = temp[temp_count][7][1];
        cube[count+(x+1)*9].cube_vertices[7][2] = temp[temp_count][7][2];
        }
    }
    }

    int addY[9] = {18,8,-2,10,0,-10,2,-8,-18};
    int Ypath[9] = {0,1,2,9,10,11,18,19,20};

    for(int y=-1;y<2;y++){
    if(keypressedy == y){
        for(int count = 0;count <9; count++){
            int temp_count = Ypath[count]+(y+1)*3 + addY[count];

        cube[Ypath[count]+(y+1)*3].cube_vertices[0][0] = temp[temp_count][0][0];
        cube[Ypath[count]+(y+1)*3].cube_vertices[0][1] = temp[temp_count][0][1];
        cube[Ypath[count]+(y+1)*3].cube_vertices[0][2] = temp[temp_count][0][2];
        cube[Ypath[count]+(y+1)*3].cube_vertices[1][0] = temp[temp_count][1][0];
        cube[Ypath[count]+(y+1)*3].cube_vertices[1][1] = temp[temp_count][1][1];
        cube[Ypath[count]+(y+1)*3].cube_vertices[1][2] = temp[temp_count][1][2];
        cube[Ypath[count]+(y+1)*3].cube_vertices[2][0] = temp[temp_count][2][0];
        cube[Ypath[count]+(y+1)*3].cube_vertices[2][1] = temp[temp_count][2][1];
        cube[Ypath[count]+(y+1)*3].cube_vertices[2][2] = temp[temp_count][2][2];
        cube[Ypath[count]+(y+1)*3].cube_vertices[3][0] = temp[temp_count][3][0];
        cube[Ypath[count]+(y+1)*3].cube_vertices[3][1] = temp[temp_count][3][1];
        cube[Ypath[count]+(y+1)*3].cube_vertices[3][2] = temp[temp_count][3][2];
        cube[Ypath[count]+(y+1)*3].cube_vertices[4][0] = temp[temp_count][4][0];
        cube[Ypath[count]+(y+1)*3].cube_vertices[4][1] = temp[temp_count][4][1];
        cube[Ypath[count]+(y+1)*3].cube_vertices[4][2] = temp[temp_count][4][2];
        cube[Ypath[count]+(y+1)*3].cube_vertices[5][0] = temp[temp_count][5][0];
        cube[Ypath[count]+(y+1)*3].cube_vertices[5][1] = temp[temp_count][5][1];
        cube[Ypath[count]+(y+1)*3].cube_vertices[5][2] = temp[temp_count][5][2];
        cube[Ypath[count]+(y+1)*3].cube_vertices[6][0] = temp[temp_count][6][0];
        cube[Ypath[count]+(y+1)*3].cube_vertices[6][1] = temp[temp_count][6][1];
        cube[Ypath[count]+(y+1)*3].cube_vertices[6][2] = temp[temp_count][6][2];
        cube[Ypath[count]+(y+1)*3].cube_vertices[7][0] = temp[temp_count][7][0];
        cube[Ypath[count]+(y+1)*3].cube_vertices[7][1] = temp[temp_count][7][1];
        cube[Ypath[count]+(y+1)*3].cube_vertices[7][2] = temp[temp_count][7][2];
        }
    }
    }

    int addZ[9] = {6,-6,-18,12,0,-12,18,6,-6};
    int Zpath[9] = {0,9,18,3,12,21,6,15,24};

    for(int z=-1;z<2;z++){
    if(keypressedz == z){
        for(int count = 0;count <9; count++){
            int temp_count = Zpath[count]+(z+1) + addZ[count];

        cube[Zpath[count]+(z+1)].cube_vertices[0][0] = temp[temp_count][0][0];
        cube[Zpath[count]+(z+1)].cube_vertices[0][1] = temp[temp_count][0][1];
        cube[Zpath[count]+(z+1)].cube_vertices[0][2] = temp[temp_count][0][2];
        cube[Zpath[count]+(z+1)].cube_vertices[1][0] = temp[temp_count][1][0];
        cube[Zpath[count]+(z+1)].cube_vertices[1][1] = temp[temp_count][1][1];
        cube[Zpath[count]+(z+1)].cube_vertices[1][2] = temp[temp_count][1][2];
        cube[Zpath[count]+(z+1)].cube_vertices[2][0] = temp[temp_count][2][0];
        cube[Zpath[count]+(z+1)].cube_vertices[2][1] = temp[temp_count][2][1];
        cube[Zpath[count]+(z+1)].cube_vertices[2][2] = temp[temp_count][2][2];
        cube[Zpath[count]+(z+1)].cube_vertices[3][0] = temp[temp_count][3][0];
        cube[Zpath[count]+(z+1)].cube_vertices[3][1] = temp[temp_count][3][1];
        cube[Zpath[count]+(z+1)].cube_vertices[3][2] = temp[temp_count][3][2];
        cube[Zpath[count]+(z+1)].cube_vertices[4][0] = temp[temp_count][4][0];
        cube[Zpath[count]+(z+1)].cube_vertices[4][1] = temp[temp_count][4][1];
        cube[Zpath[count]+(z+1)].cube_vertices[4][2] = temp[temp_count][4][2];
        cube[Zpath[count]+(z+1)].cube_vertices[5][0] = temp[temp_count][5][0];
        cube[Zpath[count]+(z+1)].cube_vertices[5][1] = temp[temp_count][5][1];
        cube[Zpath[count]+(z+1)].cube_vertices[5][2] = temp[temp_count][5][2];
        cube[Zpath[count]+(z+1)].cube_vertices[6][0] = temp[temp_count][6][0];
        cube[Zpath[count]+(z+1)].cube_vertices[6][1] = temp[temp_count][6][1];
        cube[Zpath[count]+(z+1)].cube_vertices[6][2] = temp[temp_count][6][2];
        cube[Zpath[count]+(z+1)].cube_vertices[7][0] = temp[temp_count][7][0];
        cube[Zpath[count]+(z+1)].cube_vertices[7][1] = temp[temp_count][7][1];
        cube[Zpath[count]+(z+1)].cube_vertices[7][2] = temp[temp_count][7][2];
        }
    }
    }
}

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

void draw_character(GLfloat x, GLfloat y, GLfloat z, const char* text, int font){
    const char *c;
    glRasterPos3f(x,y,z);
    for(c=text;*c!='\0';c++)
        if(font == 1)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
        else
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
}

void draw_square(){
    glPushMatrix();
    glLoadIdentity();
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.0,0.0);
    glVertex3f(20.0, 4.0,0.0);
    glVertex3f(24.0, 4.0,0.0);
    glVertex3f(24.0,-4.0,0.0);
    glVertex3f(20.0,-4.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(24.0, 4.0,0.0);
    glVertex3f(28.0, 4.0,0.0);
    glVertex3f(28.0,-4.0,0.0);
    glVertex3f(24.0,-4.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,0.0);
    glVertex3f(28.0, 4.0,0.0);
    glVertex3f(32.0, 4.0,0.0);
    glVertex3f(32.0,-4.0,0.0);
    glVertex3f(28.0,-4.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.7,0.0);
    glVertex3f(32.0, 4.0,0.0);
    glVertex3f(36.0, 4.0,0.0);
    glVertex3f(36.0,-4.0,0.0);
    glVertex3f(32.0,-4.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(36.0, 4.0,0.0);
    glVertex3f(40.0, 4.0,0.0);
    glVertex3f(40.0,-4.0,0.0);
    glVertex3f(36.0,-4.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(40.0, 4.0,0.0);
    glVertex3f(44.0, 4.0,0.0);
    glVertex3f(44.0,-4.0,0.0);
    glVertex3f(40.0,-4.0,0.0);
    glEnd();
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

void mydisplay1(int keypressedx, int keypressedy, int keypressedz){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // printf("mydisplay\n");
	// printf("theta[0]: %f, theta[1]: %f, theta[2]: %f\n",thetaz[0],thetaz[1],thetaz[2]);
    glRotatef(angle_cube_x,1.0,0.0,0.0);
    glRotatef(angle_cube_y,0.0,1.0,0.0);
    // printf("%f %f\n", cos(90*3.14159265/180), sin(90*3.14159265/180));
    colorcube1(keypressedx,keypressedy,keypressedz);
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

int flag_display1 = 0;

void display1(void){
    if(flag_display1 == 1){
        mydisplay1(3,3,3);
    }
    else{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // printf("Display\n");
	// printf("theta[0]: %f, theta[1]: %f, theta[2]: %f\n",thetaz[0],thetaz[1],thetaz[2]);
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

void mouse1(int btn, int state, int x, int y){
    // printf("x: %d, y: %d\n", x,y);
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

    if(key == 'g')
        keypressedx = 0;
    else if(key == 't')
        keypressedx = -1;
    else if(key == 'b')
        keypressedx = 1;
    // else
    //     keypressedx = 3;

    else if(key == 'r')
        keypressedy = 1;
    else if(key == 'f')
        keypressedy = 0;
    else if(key == 'v')
        keypressedy = -1;
    // else
    //     keypressedy = 3;

    else if(key == 'y')
        keypressedz = -1;
    else if(key == 'h')
        keypressedz = 0;
    else if(key == 'n')
        keypressedz = 1;
    // else
    //     keypressedz = 3;

    else if(key == 'G'){
        keypressedx = 0;
        mydisplay1(keypressedx, keypressedy, keypressedz);
        mydisplay1(keypressedx, keypressedy, keypressedz);
    }
    else if(key == 'T'){
        keypressedx = -1;
        mydisplay1(keypressedx, keypressedy, keypressedz);
        mydisplay1(keypressedx, keypressedy, keypressedz);
    }
    else if(key == 'B'){
        keypressedx = 1;
        mydisplay1(keypressedx, keypressedy, keypressedz);
        mydisplay1(keypressedx, keypressedy, keypressedz);
    }
    // else
    //     keypressedx = 3;

    else if(key == 'R'){
        keypressedy = 1;
        mydisplay1(keypressedx, keypressedy, keypressedz);
        mydisplay1(keypressedx, keypressedy, keypressedz);
    }
    else if(key == 'F'){
        keypressedy = 0;
        mydisplay1(keypressedx, keypressedy, keypressedz);
        mydisplay1(keypressedx, keypressedy, keypressedz);
    }
    else if(key == 'V'){
        keypressedy = -1;
        mydisplay1(keypressedx, keypressedy, keypressedz);
        mydisplay1(keypressedx, keypressedy, keypressedz);
    }
    // else
    //     keypressedy = 3;

    else if(key == 'Y'){
        keypressedz = -1;
        mydisplay1(keypressedx, keypressedy, keypressedz);
        mydisplay1(keypressedx, keypressedy, keypressedz);
    }
    else if(key == 'H'){
        keypressedz = 0;
        mydisplay1(keypressedx, keypressedy, keypressedz);
        mydisplay1(keypressedx, keypressedy, keypressedz);
    }
    else if(key == 'N'){
        keypressedz = 1;
        mydisplay1(keypressedx, keypressedy, keypressedz);
        mydisplay1(keypressedx, keypressedy, keypressedz);
    }
    else{
        keypressedx = 3;
        keypressedy = 3;
        keypressedz = 3;
    }

    if(key == 'q')
        glutDestroyWindow(win2);
    
    
    // printf("Key: %c\n",key);
    // printf("keypressedx: %d keypressedy: %d keypressedz: %d\n", keypressedx, keypressedy, keypressedz);
    mydisplay1(keypressedx, keypressedy, keypressedz);
}

void myReshape1(int w, int h){
	int window_height = h;
	int window_width = w;
    // printf("Reshape\n");
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	if(w<=h)
		glOrtho(-10.0,50.0*(GLfloat)h/(GLfloat)w,-30.0*(GLfloat)h/(GLfloat)w, 30.0,-50.0,50.0);
	else
		glOrtho(-10.0*(GLfloat)w/(GLfloat)h, 50.0*(GLfloat)w/(GLfloat)h,-30.0,30.0,-50.0,50.0);
	glMatrixMode(GL_MODELVIEW);
}

// int main(int argc, char **argv){
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//     // glutInitWindowSize(500, 500);
//     glutCreateWindow("colorcube");
//     glutFullScreen();
//     glutReshapeFunc(myReshape1);
//     glutDisplayFunc(display1);
//     glutMouseFunc(mouse1);
//     glutKeyboardFunc(keys1);
//     glEnable(GL_DEPTH_TEST);
//     glutMainLoop();
//     return 0;
// }