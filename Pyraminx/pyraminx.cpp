#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>

GLfloat v[4][3] = {{0.0,45.0,0.0},{-12.245,25.0,7.07},{12.245,25.0,7.07},{0.0,25.0,-14.14}};
int count =0;
class pyraminx{
	public:
		GLfloat vertices[4][3] = {0.0};
};

class inner_triangle{
	public:
	GLfloat vertices[4][3][3] = {0};
};

inner_triangle inner_pyramid[4];

pyraminx pyramid[10];

void triangle(GLfloat *a, GLfloat *b,GLfloat*c){
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
	
	
	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}

void tetrahedron(){
	if(count == 0){
		int i = count;
		pyramid[0].vertices[0][0] = v[0][0];
		pyramid[0].vertices[0][1] = v[0][1];
		pyramid[0].vertices[0][2] = v[0][2];
		pyramid[0].vertices[1][0] = v[1][0];
		pyramid[0].vertices[1][1] = v[1][1];
		pyramid[0].vertices[1][2] = v[1][2];
		pyramid[0].vertices[2][0] = v[2][0];
		pyramid[0].vertices[2][1] = v[2][1];
		pyramid[0].vertices[2][2] = v[2][2];
		pyramid[0].vertices[3][0] = v[3][0];
		pyramid[0].vertices[3][1] = v[3][1];
		pyramid[0].vertices[3][2] = v[3][2];

		glColor3f(1.0,0.0,0.0);
		triangle(v[0],v[1],v[2]);
		glColor3f(0.0,1.0,0.0);
		triangle(v[3],v[1],v[2]);
		glColor3f(1.0,1.0,0.0);
		triangle(v[0],v[1],v[3]);
		glColor3f(0.0,0.0,1.0);
		triangle(v[0],v[3],v[2]);

		inner_pyramid[i].vertices[0][0][0] = pyramid[i].vertices[1][0];
		inner_pyramid[i].vertices[0][0][1] = pyramid[i].vertices[1][1];
		inner_pyramid[i].vertices[0][0][2] = pyramid[i].vertices[1][2];
		inner_pyramid[i].vertices[0][1][0] = pyramid[i].vertices[1][0] + 24.49;
		inner_pyramid[i].vertices[0][1][1] = pyramid[i].vertices[1][1];
		inner_pyramid[i].vertices[0][1][2] = pyramid[i].vertices[1][2];
		inner_pyramid[i].vertices[0][2][0] = pyramid[i].vertices[1][0] + 12.245;
		inner_pyramid[i].vertices[0][2][1] = pyramid[i].vertices[1][1] - 20.0;
		inner_pyramid[i].vertices[0][2][2] = pyramid[i].vertices[1][2] + 7.07;

		inner_pyramid[i].vertices[1][0][0] = pyramid[i].vertices[2][0];
		inner_pyramid[i].vertices[1][0][1] = pyramid[i].vertices[2][1];
		inner_pyramid[i].vertices[1][0][2] = pyramid[i].vertices[2][2];
		inner_pyramid[i].vertices[1][1][0] = pyramid[i].vertices[2][0] - 12.245;
		inner_pyramid[i].vertices[1][1][1] = pyramid[i].vertices[2][1];
		inner_pyramid[i].vertices[1][1][2] = pyramid[i].vertices[2][2] - 21.21;
		inner_pyramid[i].vertices[1][2][0] = pyramid[i].vertices[2][0];
		inner_pyramid[i].vertices[1][2][1] = pyramid[i].vertices[2][1] - 20.0;
		inner_pyramid[i].vertices[1][2][2] = pyramid[i].vertices[2][2] - 14.14;

		inner_pyramid[i].vertices[2][0][0] = pyramid[i].vertices[3][0];
		inner_pyramid[i].vertices[2][0][1] = pyramid[i].vertices[3][1];
		inner_pyramid[i].vertices[2][0][2] = pyramid[i].vertices[3][2];
		inner_pyramid[i].vertices[2][1][0] = pyramid[i].vertices[3][0] - 12.245;
		inner_pyramid[i].vertices[2][1][1] = pyramid[i].vertices[3][1];
		inner_pyramid[i].vertices[2][1][2] = pyramid[i].vertices[3][2] + 21.21;
		inner_pyramid[i].vertices[2][2][0] = pyramid[i].vertices[3][0] - 12.245;
		inner_pyramid[i].vertices[2][2][1] = pyramid[i].vertices[3][1] - 20.0;
		inner_pyramid[i].vertices[2][2][2] = pyramid[i].vertices[3][2] + 7.07;

		inner_pyramid[i].vertices[3][0][0] = inner_pyramid[i].vertices[0][2][0];
		inner_pyramid[i].vertices[3][0][1] = inner_pyramid[i].vertices[0][2][1];
		inner_pyramid[i].vertices[3][0][2] = inner_pyramid[i].vertices[0][2][2];
		inner_pyramid[i].vertices[3][1][0] = inner_pyramid[i].vertices[1][2][0];
		inner_pyramid[i].vertices[3][1][1] = inner_pyramid[i].vertices[1][2][1];
		inner_pyramid[i].vertices[3][1][2] = inner_pyramid[i].vertices[1][2][2];
		inner_pyramid[i].vertices[3][2][0] = inner_pyramid[i].vertices[2][2][0];
		inner_pyramid[i].vertices[3][2][1] = inner_pyramid[i].vertices[2][2][1];
		inner_pyramid[i].vertices[3][2][2] = inner_pyramid[i].vertices[2][2][2];

		glColor3f(1.0,0.0,0.0);
		triangle(inner_pyramid[i].vertices[0][0],inner_pyramid[i].vertices[0][1],inner_pyramid[i].vertices[0][2]);
		glColor3f(0.0,0.0,1.0);
		triangle(inner_pyramid[i].vertices[1][0],inner_pyramid[i].vertices[1][1],inner_pyramid[i].vertices[1][2]);
		glColor3f(1.0,1.0,0.0);
		triangle(inner_pyramid[i].vertices[2][0],inner_pyramid[i].vertices[2][1],inner_pyramid[i].vertices[2][2]);
		glColor3f(0.0,1.0,0.0);
		triangle(inner_pyramid[i].vertices[3][0],inner_pyramid[i].vertices[3][1],inner_pyramid[i].vertices[3][2]);
	}

	for(int i=1;i<4;i++){
		count = i;
		pyramid[i].vertices[0][0] = v[i][0];
		pyramid[i].vertices[0][1] = v[i][1];
		pyramid[i].vertices[0][2] = v[i][2];

		pyramid[i].vertices[1][0] = v[i][0] - 12.245;
		pyramid[i].vertices[1][1] = v[i][1] - 20;
		pyramid[i].vertices[1][2] = v[i][2] + 7.07;

		pyramid[i].vertices[2][0] = v[i][0] + 12.245;
		pyramid[i].vertices[2][1] = v[i][1] - 20;
		pyramid[i].vertices[2][2] = v[i][2] + 7.07;

		pyramid[i].vertices[3][0] = v[i][0];
		pyramid[i].vertices[3][1] = v[i][1] - 20;
		pyramid[i].vertices[3][2] = v[i][2] - 14.14;

		glColor3f(1.0,0.0,0.0);
		triangle(pyramid[i].vertices[0],pyramid[i].vertices[1],pyramid[i].vertices[2]);
		glColor3f(0.0,1.0,0.0);
		triangle(pyramid[i].vertices[3],pyramid[i].vertices[1],pyramid[i].vertices[2]);
		glColor3f(1.0,1.0,0.0);
		triangle(pyramid[i].vertices[0],pyramid[i].vertices[1],pyramid[i].vertices[3]);
		glColor3f(0.0,0.0,1.0);
		triangle(pyramid[i].vertices[0],pyramid[i].vertices[3],pyramid[i].vertices[2]);

		inner_pyramid[i].vertices[0][0][0] = pyramid[i].vertices[1][0];
		inner_pyramid[i].vertices[0][0][1] = pyramid[i].vertices[1][1];
		inner_pyramid[i].vertices[0][0][2] = pyramid[i].vertices[1][2];
		inner_pyramid[i].vertices[0][1][0] = pyramid[i].vertices[1][0] + 24.49;
		inner_pyramid[i].vertices[0][1][1] = pyramid[i].vertices[1][1];
		inner_pyramid[i].vertices[0][1][2] = pyramid[i].vertices[1][2];
		inner_pyramid[i].vertices[0][2][0] = pyramid[i].vertices[1][0] + 12.245;
		inner_pyramid[i].vertices[0][2][1] = pyramid[i].vertices[1][1] - 20.0;
		inner_pyramid[i].vertices[0][2][2] = pyramid[i].vertices[1][2] + 7.07;

		inner_pyramid[i].vertices[1][0][0] = pyramid[i].vertices[2][0];
		inner_pyramid[i].vertices[1][0][1] = pyramid[i].vertices[2][1];
		inner_pyramid[i].vertices[1][0][2] = pyramid[i].vertices[2][2];
		inner_pyramid[i].vertices[1][1][0] = pyramid[i].vertices[2][0] - 12.245;
		inner_pyramid[i].vertices[1][1][1] = pyramid[i].vertices[2][1];
		inner_pyramid[i].vertices[1][1][2] = pyramid[i].vertices[2][2] - 21.21;
		inner_pyramid[i].vertices[1][2][0] = pyramid[i].vertices[2][0];
		inner_pyramid[i].vertices[1][2][1] = pyramid[i].vertices[2][1] - 20.0;
		inner_pyramid[i].vertices[1][2][2] = pyramid[i].vertices[2][2] - 14.14;

		inner_pyramid[i].vertices[2][0][0] = pyramid[i].vertices[3][0];
		inner_pyramid[i].vertices[2][0][1] = pyramid[i].vertices[3][1];
		inner_pyramid[i].vertices[2][0][2] = pyramid[i].vertices[3][2];
		inner_pyramid[i].vertices[2][1][0] = pyramid[i].vertices[3][0] - 12.245;
		inner_pyramid[i].vertices[2][1][1] = pyramid[i].vertices[3][1];
		inner_pyramid[i].vertices[2][1][2] = pyramid[i].vertices[3][2] + 21.21;
		inner_pyramid[i].vertices[2][2][0] = pyramid[i].vertices[3][0] - 12.245;
		inner_pyramid[i].vertices[2][2][1] = pyramid[i].vertices[3][1] - 20.0;
		inner_pyramid[i].vertices[2][2][2] = pyramid[i].vertices[3][2] + 7.07;

		inner_pyramid[i].vertices[3][0][0] = inner_pyramid[i].vertices[0][2][0];
		inner_pyramid[i].vertices[3][0][1] = inner_pyramid[i].vertices[0][2][1];
		inner_pyramid[i].vertices[3][0][2] = inner_pyramid[i].vertices[0][2][2];
		inner_pyramid[i].vertices[3][1][0] = inner_pyramid[i].vertices[1][2][0];
		inner_pyramid[i].vertices[3][1][1] = inner_pyramid[i].vertices[1][2][1];
		inner_pyramid[i].vertices[3][1][2] = inner_pyramid[i].vertices[1][2][2];
		inner_pyramid[i].vertices[3][2][0] = inner_pyramid[i].vertices[2][2][0];
		inner_pyramid[i].vertices[3][2][1] = inner_pyramid[i].vertices[2][2][1];
		inner_pyramid[i].vertices[3][2][2] = inner_pyramid[i].vertices[2][2][2];

		glColor3f(1.0,0.0,0.0);
		triangle(inner_pyramid[i].vertices[0][0],inner_pyramid[i].vertices[0][1],inner_pyramid[i].vertices[0][2]);
		glColor3f(0.0,0.0,1.0);
		triangle(inner_pyramid[i].vertices[1][0],inner_pyramid[i].vertices[1][1],inner_pyramid[i].vertices[1][2]);
		glColor3f(1.0,1.0,0.0);
		triangle(inner_pyramid[i].vertices[2][0],inner_pyramid[i].vertices[2][1],inner_pyramid[i].vertices[2][2]);
		glColor3f(0.0,1.0,0.0);
		triangle(inner_pyramid[i].vertices[3][0],inner_pyramid[i].vertices[3][1],inner_pyramid[i].vertices[3][2]);
	}

	for(int i=1;i<4;i++){
		count = i;
		pyramid[i*2+2].vertices[0][0] = pyramid[i].vertices[i][0];
		pyramid[i*2+2].vertices[0][1] = pyramid[i].vertices[i][1];
		pyramid[i*2+2].vertices[0][2] = pyramid[i].vertices[i][2];
		pyramid[i*2+2].vertices[1][0] = pyramid[i].vertices[i][0] - 12.245;
		pyramid[i*2+2].vertices[1][1] = pyramid[i].vertices[i][1] - 20;
		pyramid[i*2+2].vertices[1][2] = pyramid[i].vertices[i][2] + 7.07;
		pyramid[i*2+2].vertices[2][0] = pyramid[i].vertices[i][0] + 12.245;
		pyramid[i*2+2].vertices[2][1] = pyramid[i].vertices[i][1] - 20;
		pyramid[i*2+2].vertices[2][2] = pyramid[i].vertices[i][2] + 7.07;
		pyramid[i*2+2].vertices[3][0] = pyramid[i].vertices[i][0];
		pyramid[i*2+2].vertices[3][1] = pyramid[i].vertices[i][1] - 20;
		pyramid[i*2+2].vertices[3][2] = pyramid[i].vertices[i][2] - 14.14;

		glColor3f(1.0,0.0,0.0);
		triangle(pyramid[i*2+2].vertices[0],pyramid[i*2+2].vertices[1],pyramid[i*2+2].vertices[2]);
		glColor3f(0.0,1.0,0.0);
		triangle(pyramid[i*2+2].vertices[3],pyramid[i*2+2].vertices[1],pyramid[i*2+2].vertices[2]);
		glColor3f(1.0,1.0,0.0);
		triangle(pyramid[i*2+2].vertices[0],pyramid[i*2+2].vertices[1],pyramid[i*2+2].vertices[3]);
		glColor3f(0.0,0.0,1.0);
		triangle(pyramid[i*2+2].vertices[0],pyramid[i*2+2].vertices[3],pyramid[i*2+2].vertices[2]);

		int j = i+1;
		if(i == 3){
			j = 1;
		}

		pyramid[i*2+3].vertices[0][0] = pyramid[i].vertices[j][0];
		pyramid[i*2+3].vertices[0][1] = pyramid[i].vertices[j][1];
		pyramid[i*2+3].vertices[0][2] = pyramid[i].vertices[j][2];
		pyramid[i*2+3].vertices[1][0] = pyramid[i].vertices[j][0] - 12.245;
		pyramid[i*2+3].vertices[1][1] = pyramid[i].vertices[j][1] - 20;
		pyramid[i*2+3].vertices[1][2] = pyramid[i].vertices[j][2] + 7.07;
		pyramid[i*2+3].vertices[2][0] = pyramid[i].vertices[j][0] + 12.245;
		pyramid[i*2+3].vertices[2][1] = pyramid[i].vertices[j][1] - 20;
		pyramid[i*2+3].vertices[2][2] = pyramid[i].vertices[j][2] + 7.07;
		pyramid[i*2+3].vertices[3][0] = pyramid[i].vertices[j][0];
		pyramid[i*2+3].vertices[3][1] = pyramid[i].vertices[j][1] - 20;
		pyramid[i*2+3].vertices[3][2] = pyramid[i].vertices[j][2] - 14.14;

		glColor3f(1.0,0.0,0.0);
		triangle(pyramid[i*2+3].vertices[0],pyramid[i*2+3].vertices[1],pyramid[i*2+3].vertices[2]);
		glColor3f(0.0,1.0,0.0);
		triangle(pyramid[i*2+3].vertices[3],pyramid[i*2+3].vertices[1],pyramid[i*2+3].vertices[2]);
		glColor3f(1.0,1.0,0.0);
		triangle(pyramid[i*2+3].vertices[0],pyramid[i*2+3].vertices[1],pyramid[i*2+3].vertices[3]);
		glColor3f(0.0,0.0,1.0);
		triangle(pyramid[i*2+3].vertices[0],pyramid[i*2+3].vertices[3],pyramid[i*2+3].vertices[2]);
	}
	count = 0;
}

// void draw_inner_pyramid(){
// 	for(int i=0;i<4;i++){
// 		inner_pyramid[i].vertices[0][0][0] = pyramid[i].vertices[1][0];
// 		inner_pyramid[i].vertices[0][0][1] = pyramid[i].vertices[1][1];
// 		inner_pyramid[i].vertices[0][0][2] = pyramid[i].vertices[1][2];
// 		inner_pyramid[i].vertices[0][1][0] = pyramid[i].vertices[1][0] + 24.49;
// 		inner_pyramid[i].vertices[0][1][1] = pyramid[i].vertices[1][1];
// 		inner_pyramid[i].vertices[0][1][2] = pyramid[i].vertices[1][2];
// 		inner_pyramid[i].vertices[0][2][0] = pyramid[i].vertices[1][0] + 12.245;
// 		inner_pyramid[i].vertices[0][2][1] = pyramid[i].vertices[1][1] - 20.0;
// 		inner_pyramid[i].vertices[0][2][2] = pyramid[i].vertices[1][2] + 7.07;

// 		inner_pyramid[i].vertices[1][0][0] = pyramid[i].vertices[2][0];
// 		inner_pyramid[i].vertices[1][0][1] = pyramid[i].vertices[2][1];
// 		inner_pyramid[i].vertices[1][0][2] = pyramid[i].vertices[2][2];
// 		inner_pyramid[i].vertices[1][1][0] = pyramid[i].vertices[2][0] - 12.245;
// 		inner_pyramid[i].vertices[1][1][1] = pyramid[i].vertices[2][1];
// 		inner_pyramid[i].vertices[1][1][2] = pyramid[i].vertices[2][2] - 21.21;
// 		inner_pyramid[i].vertices[1][2][0] = pyramid[i].vertices[2][0];
// 		inner_pyramid[i].vertices[1][2][1] = pyramid[i].vertices[2][1] - 20.0;
// 		inner_pyramid[i].vertices[1][2][2] = pyramid[i].vertices[2][2] - 14.14;

// 		inner_pyramid[i].vertices[2][0][0] = pyramid[i].vertices[3][0];
// 		inner_pyramid[i].vertices[2][0][1] = pyramid[i].vertices[3][1];
// 		inner_pyramid[i].vertices[2][0][2] = pyramid[i].vertices[3][2];
// 		inner_pyramid[i].vertices[2][1][0] = pyramid[i].vertices[3][0] - 12.245;
// 		inner_pyramid[i].vertices[2][1][1] = pyramid[i].vertices[3][1];
// 		inner_pyramid[i].vertices[2][1][2] = pyramid[i].vertices[3][2] + 21.21;
// 		inner_pyramid[i].vertices[2][2][0] = pyramid[i].vertices[3][0] - 12.245;
// 		inner_pyramid[i].vertices[2][2][1] = pyramid[i].vertices[3][1] - 20.0;
// 		inner_pyramid[i].vertices[2][2][2] = pyramid[i].vertices[3][2] + 7.07;

// 		inner_pyramid[i].vertices[3][0][0] = inner_pyramid[i].vertices[0][2][0];
// 		inner_pyramid[i].vertices[3][0][1] = inner_pyramid[i].vertices[0][2][1];
// 		inner_pyramid[i].vertices[3][0][2] = inner_pyramid[i].vertices[0][2][2];
// 		inner_pyramid[i].vertices[3][1][0] = inner_pyramid[i].vertices[1][2][0];
// 		inner_pyramid[i].vertices[3][1][1] = inner_pyramid[i].vertices[1][2][1];
// 		inner_pyramid[i].vertices[3][1][2] = inner_pyramid[i].vertices[1][2][2];
// 		inner_pyramid[i].vertices[3][2][0] = inner_pyramid[i].vertices[2][2][0];
// 		inner_pyramid[i].vertices[3][2][1] = inner_pyramid[i].vertices[2][2][1];
// 		inner_pyramid[i].vertices[3][2][2] = inner_pyramid[i].vertices[2][2][2];

// 		glColor3f(1.0,0.0,0.0);
// 		triangle(inner_pyramid[i].vertices[0][0],inner_pyramid[i].vertices[0][1],inner_pyramid[i].vertices[0][2]);
// 		glColor3f(0.0,0.0,1.0);
// 		triangle(inner_pyramid[i].vertices[1][0],inner_pyramid[i].vertices[1][1],inner_pyramid[i].vertices[1][2]);
// 		glColor3f(1.0,1.0,0.0);
// 		triangle(inner_pyramid[i].vertices[2][0],inner_pyramid[i].vertices[2][1],inner_pyramid[i].vertices[2][2]);
// 		glColor3f(0.0,1.0,0.0);
// 		triangle(inner_pyramid[i].vertices[3][0],inner_pyramid[i].vertices[3][1],inner_pyramid[i].vertices[3][2]);
// 	}
// }

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;


static GLdouble viewer[]= {0.0, 0.0, 5.0}; /* initial viewer location */

void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	// printf("theta[0]: %f, theta[1]: %f, theta[2]: %f\n",thetaz[0],thetaz[1],thetaz[2]);
    glRotatef(theta[0],1.0,0.0,0.0);
    glRotatef(theta[1],0.0,1.0,0.0);
    glRotatef(theta[2],0.0,0.0,1.0);
    tetrahedron();
	// draw_inner_pyramid();
	glFlush();
	glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y){
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        axis = 0;
    if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        axis = 2;
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        axis = 1;
    theta[axis] += 22.5;
    printf("Axis: %d\n",axis);

	if( theta[axis] > 360.0 )
        theta[axis] -= 360.0;
    printf("theta[axis]: %f\n",theta[axis]);
	display();
}

// void keys(unsigned char key, int x, int y)
// {
// /* Use x, X, y, Y, z, and Z keys to move viewer */
//     if(key == 'x') viewer[0]-= 1.0;
//     if(key == 'X') viewer[0]+= 1.0;
//     if(key == 'y') viewer[1]-= 1.0;
//     if(key == 'Y') viewer[1]+= 1.0;
//     if(key == 'z') viewer[2]-= 1.0;
//     if(key == 'Z') viewer[2]+= 1.0;
//     display();
// }

void myReshape(int w, int h){
	int window_height = h;
	int window_width = w;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	if(w<=h)
		glOrtho(-50.0,50.0*(GLfloat)h/(GLfloat)w,-50.0*(GLfloat)h/(GLfloat)w, 50.0,-50.0,50.0);
	else
		glOrtho(-50.0*(GLfloat)w/(GLfloat)h, 50.0*(GLfloat)w/(GLfloat)h,-50.0,50.0,-50.0,50.0);
	glMatrixMode(GL_MODELVIEW);
}

int  main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    // glutKeyboardFunc(keys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
