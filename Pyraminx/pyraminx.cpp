#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include"pyraminx.h"

GLfloat v[4][3] = {{0.0,45.0,0.0},{-12.245,25.0,7.07},{12.245,25.0,7.07},{0.0,25.0,-14.14}};
GLfloat colors[4][3] = {{1.0,0.0,0.0}, {0.0,0.0,1.0}, {0.0,1.0,0.0}, {1.0,1.0,0.0}};
int count = 0;
float anglex = 0, angley = 0;


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

int color[10][4]={{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3}};
int inner_pyramid_color[4][4] = {{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3}};

int highlight_pyramid[6] = {-1};
int highlight_inner_pyramid[3] = {-1};
GLfloat highlight_color = 0.0;
int highlight_pyramid_count = 0;
GLfloat linewidth = 2.0;

void triangle(GLfloat *a, GLfloat *b,GLfloat*c){
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
	
	
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}

void triangle1(GLfloat *a, GLfloat *b,GLfloat*c, int color_value){
	glBegin(GL_POLYGON);
	glColor3fv(colors[color_value]);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
	
	
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(highlight_color,highlight_color,highlight_color);
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

		glColor3fv(colors[0]);
		triangle(v[0],v[1],v[2]);
		glColor3fv(colors[1]);
		triangle(v[0],v[2],v[3]);
		glColor3fv(colors[2]);
		triangle(v[0],v[1],v[3]);
		glColor3fv(colors[3]);
		triangle(v[1],v[3],v[2]);

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

		glColor3fv(colors[0]);
		triangle(inner_pyramid[i].vertices[0][0],inner_pyramid[i].vertices[0][1],inner_pyramid[i].vertices[0][2]);
		glColor3fv(colors[1]);
		triangle(inner_pyramid[i].vertices[1][0],inner_pyramid[i].vertices[1][1],inner_pyramid[i].vertices[1][2]);
		glColor3fv(colors[2]);
		triangle(inner_pyramid[i].vertices[2][0],inner_pyramid[i].vertices[2][1],inner_pyramid[i].vertices[2][2]);
		glColor3fv(colors[3]);
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

		glColor3fv(colors[0]);
		triangle(pyramid[i].vertices[0],pyramid[i].vertices[1],pyramid[i].vertices[2]);
		glColor3fv(colors[1]);
		triangle(pyramid[i].vertices[0],pyramid[i].vertices[3],pyramid[i].vertices[2]);
		glColor3fv(colors[2]);
		triangle(pyramid[i].vertices[0],pyramid[i].vertices[1],pyramid[i].vertices[3]);
		glColor3fv(colors[3]);
		triangle(pyramid[i].vertices[3],pyramid[i].vertices[1],pyramid[i].vertices[2]);

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

		glColor3fv(colors[0]);
		triangle(inner_pyramid[i].vertices[0][0],inner_pyramid[i].vertices[0][1],inner_pyramid[i].vertices[0][2]);
		glColor3fv(colors[1]);
		triangle(inner_pyramid[i].vertices[1][0],inner_pyramid[i].vertices[1][1],inner_pyramid[i].vertices[1][2]);
		glColor3fv(colors[2]);
		triangle(inner_pyramid[i].vertices[2][0],inner_pyramid[i].vertices[2][1],inner_pyramid[i].vertices[2][2]);
		glColor3fv(colors[3]);
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

		glColor3fv(colors[0]);
		triangle(pyramid[i*2+2].vertices[0],pyramid[i*2+2].vertices[1],pyramid[i*2+2].vertices[2]);
		glColor3fv(colors[1]);
		triangle(pyramid[i*2+2].vertices[0],pyramid[i*2+2].vertices[3],pyramid[i*2+2].vertices[2]);
		glColor3fv(colors[2]);
		triangle(pyramid[i*2+2].vertices[0],pyramid[i*2+2].vertices[1],pyramid[i*2+2].vertices[3]);
		glColor3fv(colors[3]);
		triangle(pyramid[i*2+2].vertices[3],pyramid[i*2+2].vertices[1],pyramid[i*2+2].vertices[2]);

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

		glColor3fv(colors[0]);
		triangle(pyramid[i*2+3].vertices[0],pyramid[i*2+3].vertices[1],pyramid[i*2+3].vertices[2]);
		glColor3fv(colors[1]);
		triangle(pyramid[i*2+3].vertices[0],pyramid[i*2+3].vertices[3],pyramid[i*2+3].vertices[2]);
		glColor3fv(colors[2]);
		triangle(pyramid[i*2+3].vertices[0],pyramid[i*2+3].vertices[1],pyramid[i*2+3].vertices[3]);
		glColor3fv(colors[3]);
		triangle(pyramid[i*2+3].vertices[3],pyramid[i*2+3].vertices[1],pyramid[i*2+3].vertices[2]);
	}
	count = 0;
}

void pyraminx_operation(char keypressed, int value){
	if(value == 1){
		if(keypressed == 'r'){
			highlight_pyramid[0] = 0;
			int temp_color = color[0][0];
			color[0][0] = color[0][2];
			color[0][2] = color[0][1];
			color[0][1] = temp_color;
		}
		if(keypressed == 't'){
			highlight_pyramid[0] = 4;
			int temp_color = color[4][0];
			color[4][0] = color[4][2];
			color[4][2] = color[4][3];
			color[4][3] = temp_color;
		}
		if(keypressed == 'y'){
			highlight_pyramid[0] = 6;
			int temp_color = color[6][0];
			color[6][0] = color[6][3];
			color[6][3] = color[6][1];
			color[6][1] = temp_color;
		}
		if(keypressed == 'u'){
			highlight_pyramid[0] = 8;
			int temp_color = color[8][1];
			color[8][1] = color[8][3];
			color[8][3] = color[8][2];
			color[8][2] = temp_color;
		}
	}
	if(value == 2){
		int pyramid_path[3] = {0};
		if(keypressed == 'f'){
			highlight_pyramid[0] = 1;
			highlight_pyramid[1] = 2;
			highlight_pyramid[2] = 3;
			highlight_inner_pyramid[0] = 0;
			pyramid_path[0] = 1;
			pyramid_path[1] = 2;
			pyramid_path[2] = 3;

			for(int i=0;i<=value;i++){
				int temp_color = color[pyramid_path[i]][0];
				color[pyramid_path[i]][0] = color[pyramid_path[i]][2];
				color[pyramid_path[i]][2] = color[pyramid_path[i]][1];
				color[pyramid_path[i]][1] = temp_color;
			}

			int temp_color_update[3];
			temp_color_update[0] = color[pyramid_path[0]][0];
			temp_color_update[1] = color[pyramid_path[0]][1];
			temp_color_update[2] = color[pyramid_path[0]][2];
			color[pyramid_path[0]][0] = color[pyramid_path[2]][0];
			color[pyramid_path[0]][1] = color[pyramid_path[2]][1];
			color[pyramid_path[0]][2] = color[pyramid_path[2]][2];
			color[pyramid_path[2]][0] = color[pyramid_path[1]][0];
			color[pyramid_path[2]][1] = color[pyramid_path[1]][1];
			color[pyramid_path[2]][2] = color[pyramid_path[1]][2];
			color[pyramid_path[1]][0] = temp_color_update[0];
			color[pyramid_path[1]][1] = temp_color_update[1];
			color[pyramid_path[1]][2] = temp_color_update[2];
			
			int temp_inner_pyramid_color = inner_pyramid_color[0][0];
			inner_pyramid_color[0][0] = inner_pyramid_color[0][2];
			inner_pyramid_color[0][2] = inner_pyramid_color[0][1];
			inner_pyramid_color[0][1] = temp_inner_pyramid_color;
		}
		if(keypressed == 'g'){
			highlight_pyramid[0] = 1;
			highlight_pyramid[1] = 5;
			highlight_pyramid[2] = 9;
			pyramid_path[0] = 1;
			pyramid_path[1] = 5;
			pyramid_path[2] = 9;

			for(int i=0;i<=value;i++){
				int temp_color = color[pyramid_path[i]][0];
				color[pyramid_path[i]][0] = color[pyramid_path[i]][2];
				color[pyramid_path[i]][2] = color[pyramid_path[i]][3];
				color[pyramid_path[i]][3] = temp_color;
			}

			int temp_color_update[3];
			temp_color_update[0] = color[pyramid_path[0]][0];
			temp_color_update[1] = color[pyramid_path[0]][2];
			temp_color_update[2] = color[pyramid_path[0]][3];
			color[pyramid_path[0]][0] = color[pyramid_path[2]][0];
			color[pyramid_path[0]][2] = color[pyramid_path[2]][2];
			color[pyramid_path[0]][3] = color[pyramid_path[2]][3];
			color[pyramid_path[2]][0] = color[pyramid_path[1]][0];
			color[pyramid_path[2]][2] = color[pyramid_path[1]][2];
			color[pyramid_path[2]][3] = color[pyramid_path[1]][3];
			color[pyramid_path[1]][0] = temp_color_update[0];
			color[pyramid_path[1]][2] = temp_color_update[1];
			color[pyramid_path[1]][3] = temp_color_update[2];

			highlight_inner_pyramid[0] = 1;
			int temp_inner_pyramid_color = inner_pyramid_color[1][0];
			inner_pyramid_color[1][0] = inner_pyramid_color[1][2];
			inner_pyramid_color[1][2] = inner_pyramid_color[1][3];
			inner_pyramid_color[1][3] = temp_inner_pyramid_color;
		}
		if(keypressed == 'h'){
			highlight_pyramid[0] = 2;
			highlight_pyramid[1] = 5;
			highlight_pyramid[2] = 7;
			pyramid_path[0] = 2;
			pyramid_path[1] = 7;
			pyramid_path[2] = 5;

			for(int i=0;i<=value;i++){
				int temp_color = color[pyramid_path[i]][0];
				color[pyramid_path[i]][0] = color[pyramid_path[i]][3];
				color[pyramid_path[i]][3] = color[pyramid_path[i]][1];
				color[pyramid_path[i]][1] = temp_color;
			}

			int temp_color_update[3];
			temp_color_update[0] = color[pyramid_path[0]][0];
			temp_color_update[1] = color[pyramid_path[0]][1];
			temp_color_update[2] = color[pyramid_path[0]][3];
			color[pyramid_path[0]][0] = color[pyramid_path[2]][0];
			color[pyramid_path[0]][1] = color[pyramid_path[2]][1];
			color[pyramid_path[0]][3] = color[pyramid_path[2]][3];
			color[pyramid_path[2]][0] = color[pyramid_path[1]][0];
			color[pyramid_path[2]][1] = color[pyramid_path[1]][1];
			color[pyramid_path[2]][3] = color[pyramid_path[1]][3];
			color[pyramid_path[1]][0] = temp_color_update[0];
			color[pyramid_path[1]][1] = temp_color_update[1];
			color[pyramid_path[1]][3] = temp_color_update[2];

			highlight_inner_pyramid[0] = 2;
			int temp_inner_pyramid_color = inner_pyramid_color[2][0];
			inner_pyramid_color[2][0] = inner_pyramid_color[2][3];
			inner_pyramid_color[2][3] = inner_pyramid_color[2][1];
			inner_pyramid_color[2][1] = temp_inner_pyramid_color;
		}
		if(keypressed == 'j'){
			highlight_pyramid[0] = 3;
			highlight_pyramid[1] = 7;
			highlight_pyramid[2] = 9;
			highlight_inner_pyramid[0] = 3;
			pyramid_path[0] = 3;
			pyramid_path[1] = 9;
			pyramid_path[2] = 7;

			for(int i=0;i<=value;i++){
				int temp_color = color[pyramid_path[i]][1];
				color[pyramid_path[i]][1] = color[pyramid_path[i]][3];
				color[pyramid_path[i]][3] = color[pyramid_path[i]][2];
				color[pyramid_path[i]][2] = temp_color;
			}

			int temp_color_update[3];
			temp_color_update[0] = color[pyramid_path[0]][2];
			temp_color_update[1] = color[pyramid_path[0]][1];
			temp_color_update[2] = color[pyramid_path[0]][3];
			color[pyramid_path[0]][2] = color[pyramid_path[2]][2];
			color[pyramid_path[0]][1] = color[pyramid_path[2]][1];
			color[pyramid_path[0]][3] = color[pyramid_path[2]][3];
			color[pyramid_path[2]][2] = color[pyramid_path[1]][2];
			color[pyramid_path[2]][1] = color[pyramid_path[1]][1];
			color[pyramid_path[2]][3] = color[pyramid_path[1]][3];
			color[pyramid_path[1]][2] = temp_color_update[0];
			color[pyramid_path[1]][1] = temp_color_update[1];
			color[pyramid_path[1]][3] = temp_color_update[2];

			int temp_inner_pyramid_color = inner_pyramid_color[3][1];
			inner_pyramid_color[3][1] = inner_pyramid_color[3][3];
			inner_pyramid_color[3][3] = inner_pyramid_color[3][2];
			inner_pyramid_color[3][2] = temp_inner_pyramid_color;
		}
	}
	if(value == 5){
		int pyramid_path[6] = {0};
		int inner_pyramid_path[3] = {0};
		if(keypressed == 'v'){
			highlight_pyramid[0] = 4;
			highlight_pyramid[1] = 5;
			highlight_pyramid[2] = 6;
			highlight_pyramid[3] = 7;
			highlight_pyramid[4] = 8;
			highlight_pyramid[5] = 9;
			highlight_inner_pyramid[0] = 1;
			highlight_inner_pyramid[1] = 2;
			highlight_inner_pyramid[2] = 3;
			pyramid_path[0] = 4;
			pyramid_path[1] = 5;
			pyramid_path[2] = 6;
			pyramid_path[3] = 7;
			pyramid_path[4] = 8;
			pyramid_path[5] = 9;
			
			for(int i=0;i<=value;i++){
				int temp_color = color[pyramid_path[i]][0];
				color[pyramid_path[i]][0] = color[pyramid_path[i]][2];
				color[pyramid_path[i]][2] = color[pyramid_path[i]][1];
				color[pyramid_path[i]][1] = temp_color;
			}

			int temp_color_update[3];
			temp_color_update[0] = color[pyramid_path[0]][0];
			temp_color_update[1] = color[pyramid_path[0]][1];
			temp_color_update[2] = color[pyramid_path[0]][2];
			int temp_color_botface = color[pyramid_path[0]][3];
			color[pyramid_path[0]][0] = color[pyramid_path[4]][0];
			color[pyramid_path[0]][1] = color[pyramid_path[4]][1];
			color[pyramid_path[0]][2] = color[pyramid_path[4]][2];
			color[pyramid_path[0]][3] = color[pyramid_path[4]][3];
			color[pyramid_path[4]][0] = color[pyramid_path[2]][0];
			color[pyramid_path[4]][1] = color[pyramid_path[2]][1];
			color[pyramid_path[4]][2] = color[pyramid_path[2]][2];
			color[pyramid_path[4]][3] = color[pyramid_path[2]][3];
			color[pyramid_path[2]][0] = temp_color_update[0];
			color[pyramid_path[2]][1] = temp_color_update[1];
			color[pyramid_path[2]][2] = temp_color_update[2];
			color[pyramid_path[2]][3] = temp_color_botface;
			temp_color_update[0] = color[pyramid_path[1]][0];
			temp_color_update[1] = color[pyramid_path[1]][1];
			temp_color_update[2] = color[pyramid_path[1]][2];
			temp_color_botface = color[pyramid_path[1]][3];
			color[pyramid_path[1]][0] = color[pyramid_path[5]][0];
			color[pyramid_path[1]][1] = color[pyramid_path[5]][1];
			color[pyramid_path[1]][2] = color[pyramid_path[5]][2];
			color[pyramid_path[1]][3] = color[pyramid_path[5]][3];
			color[pyramid_path[5]][0] = color[pyramid_path[3]][0];
			color[pyramid_path[5]][1] = color[pyramid_path[3]][1];
			color[pyramid_path[5]][2] = color[pyramid_path[3]][2];
			color[pyramid_path[5]][3] = color[pyramid_path[3]][3];
			color[pyramid_path[3]][0] = temp_color_update[0];
			color[pyramid_path[3]][1] = temp_color_update[1];
			color[pyramid_path[3]][2] = temp_color_update[2];
			color[pyramid_path[3]][3] = temp_color_botface;

			inner_pyramid_path[0] = 1;
			inner_pyramid_path[1] = 2;
			inner_pyramid_path[2] = 3;

			for(int i=0;i<3;i++){
				int temp_color = inner_pyramid_color[inner_pyramid_path[i]][0];
				inner_pyramid_color[inner_pyramid_path[i]][0] = inner_pyramid_color[inner_pyramid_path[i]][2];
				inner_pyramid_color[inner_pyramid_path[i]][2] = inner_pyramid_color[inner_pyramid_path[i]][1];
				inner_pyramid_color[inner_pyramid_path[i]][1] = temp_color;
			}

			temp_color_update[0] = inner_pyramid_color[inner_pyramid_path[0]][0];
			temp_color_update[1] = inner_pyramid_color[inner_pyramid_path[0]][1];
			temp_color_update[2] = inner_pyramid_color[inner_pyramid_path[0]][2];
			temp_color_botface = inner_pyramid_color[inner_pyramid_path[0]][3];
			inner_pyramid_color[inner_pyramid_path[0]][0] = inner_pyramid_color[inner_pyramid_path[2]][0];
			inner_pyramid_color[inner_pyramid_path[0]][1] = inner_pyramid_color[inner_pyramid_path[2]][1];
			inner_pyramid_color[inner_pyramid_path[0]][2] = inner_pyramid_color[inner_pyramid_path[2]][2];
			inner_pyramid_color[inner_pyramid_path[0]][3] = inner_pyramid_color[inner_pyramid_path[2]][3];
			inner_pyramid_color[inner_pyramid_path[2]][0] = inner_pyramid_color[inner_pyramid_path[1]][0];
			inner_pyramid_color[inner_pyramid_path[2]][1] = inner_pyramid_color[inner_pyramid_path[1]][1];
			inner_pyramid_color[inner_pyramid_path[2]][2] = inner_pyramid_color[inner_pyramid_path[1]][2];
			inner_pyramid_color[inner_pyramid_path[2]][3] = inner_pyramid_color[inner_pyramid_path[1]][3];
			inner_pyramid_color[inner_pyramid_path[1]][0] = temp_color_update[0];
			inner_pyramid_color[inner_pyramid_path[1]][1] = temp_color_update[1];
			inner_pyramid_color[inner_pyramid_path[1]][2] = temp_color_update[2];
			inner_pyramid_color[inner_pyramid_path[1]][3] = temp_color_botface;
		}
		if(keypressed == 'b'){
			highlight_pyramid[0] = 0;
			highlight_pyramid[1] = 2;
			highlight_pyramid[2] = 3;
			highlight_pyramid[3] = 6;
			highlight_pyramid[4] = 7;
			highlight_pyramid[5] = 8;
			pyramid_path[0] = 0;
			pyramid_path[1] = 2;
			pyramid_path[2] = 6;
			pyramid_path[3] = 7;
			pyramid_path[4] = 8;
			pyramid_path[5] = 3;
			
			for(int i=0;i<=value;i++){
				int temp_color = color[pyramid_path[i]][0];
				color[pyramid_path[i]][0] = color[pyramid_path[i]][2];
				color[pyramid_path[i]][2] = color[pyramid_path[i]][3];
				color[pyramid_path[i]][3] = temp_color;
			}

			int temp_color_update[3];
			temp_color_update[0] = color[pyramid_path[0]][0];
			temp_color_update[1] = color[pyramid_path[0]][2];
			temp_color_update[2] = color[pyramid_path[0]][3];
			int temp_color_botface = color[pyramid_path[0]][1];
			color[pyramid_path[0]][0] = color[pyramid_path[4]][0];
			color[pyramid_path[0]][2] = color[pyramid_path[4]][2];
			color[pyramid_path[0]][3] = color[pyramid_path[4]][3];
			color[pyramid_path[0]][1] = color[pyramid_path[4]][1];
			color[pyramid_path[4]][0] = color[pyramid_path[2]][0];
			color[pyramid_path[4]][2] = color[pyramid_path[2]][2];
			color[pyramid_path[4]][3] = color[pyramid_path[2]][3];
			color[pyramid_path[4]][1] = color[pyramid_path[2]][1];
			color[pyramid_path[2]][0] = temp_color_update[0];
			color[pyramid_path[2]][2] = temp_color_update[1];
			color[pyramid_path[2]][3] = temp_color_update[2];
			color[pyramid_path[2]][1] = temp_color_botface;
			temp_color_update[0] = color[pyramid_path[1]][0];
			temp_color_update[1] = color[pyramid_path[1]][2];
			temp_color_update[2] = color[pyramid_path[1]][3];
			temp_color_botface = color[pyramid_path[1]][1];
			color[pyramid_path[1]][0] = color[pyramid_path[5]][0];
			color[pyramid_path[1]][2] = color[pyramid_path[5]][2];
			color[pyramid_path[1]][3] = color[pyramid_path[5]][3];
			color[pyramid_path[1]][1] = color[pyramid_path[5]][1];
			color[pyramid_path[5]][0] = color[pyramid_path[3]][0];
			color[pyramid_path[5]][2] = color[pyramid_path[3]][2];
			color[pyramid_path[5]][3] = color[pyramid_path[3]][3];
			color[pyramid_path[5]][1] = color[pyramid_path[3]][1];
			color[pyramid_path[3]][0] = temp_color_update[0];
			color[pyramid_path[3]][2] = temp_color_update[1];
			color[pyramid_path[3]][3] = temp_color_update[2];
			color[pyramid_path[3]][1] = temp_color_botface;

			highlight_inner_pyramid[0] = 0;
			highlight_inner_pyramid[1] = 2;
			highlight_inner_pyramid[2] = 3;
			inner_pyramid_path[0] = 0;
			inner_pyramid_path[1] = 2;
			inner_pyramid_path[2] = 3;

			for(int i=0;i<3;i++){
				int temp_color = inner_pyramid_color[inner_pyramid_path[i]][0];
				inner_pyramid_color[inner_pyramid_path[i]][0] = inner_pyramid_color[inner_pyramid_path[i]][2];
				inner_pyramid_color[inner_pyramid_path[i]][2] = inner_pyramid_color[inner_pyramid_path[i]][3];
				inner_pyramid_color[inner_pyramid_path[i]][3] = temp_color;
			}

			temp_color_update[0] = inner_pyramid_color[inner_pyramid_path[0]][0];
			temp_color_update[1] = inner_pyramid_color[inner_pyramid_path[0]][2];
			temp_color_update[2] = inner_pyramid_color[inner_pyramid_path[0]][3];
			temp_color_botface = inner_pyramid_color[inner_pyramid_path[0]][1];
			inner_pyramid_color[inner_pyramid_path[0]][0] = inner_pyramid_color[inner_pyramid_path[2]][0];
			inner_pyramid_color[inner_pyramid_path[0]][2] = inner_pyramid_color[inner_pyramid_path[2]][2];
			inner_pyramid_color[inner_pyramid_path[0]][3] = inner_pyramid_color[inner_pyramid_path[2]][3];
			inner_pyramid_color[inner_pyramid_path[0]][1] = inner_pyramid_color[inner_pyramid_path[2]][1];
			inner_pyramid_color[inner_pyramid_path[2]][0] = inner_pyramid_color[inner_pyramid_path[1]][0];
			inner_pyramid_color[inner_pyramid_path[2]][2] = inner_pyramid_color[inner_pyramid_path[1]][2];
			inner_pyramid_color[inner_pyramid_path[2]][3] = inner_pyramid_color[inner_pyramid_path[1]][3];
			inner_pyramid_color[inner_pyramid_path[2]][1] = inner_pyramid_color[inner_pyramid_path[1]][1];
			inner_pyramid_color[inner_pyramid_path[1]][0] = temp_color_update[0];
			inner_pyramid_color[inner_pyramid_path[1]][2] = temp_color_update[1];
			inner_pyramid_color[inner_pyramid_path[1]][3] = temp_color_update[2];
			inner_pyramid_color[inner_pyramid_path[1]][1] = temp_color_botface;
		}
		if(keypressed == 'n'){
			highlight_pyramid[0] = 0;
			highlight_pyramid[1] = 1;
			highlight_pyramid[2] = 3;
			highlight_pyramid[3] = 4;
			highlight_pyramid[4] = 8;
			highlight_pyramid[5] = 9;
			pyramid_path[0] = 0;
			pyramid_path[1] = 3;
			pyramid_path[2] = 8;
			pyramid_path[3] = 9;
			pyramid_path[4] = 4;
			pyramid_path[5] = 1;
			
			for(int i=0;i<=value;i++){
				int temp_color = color[pyramid_path[i]][0];
				color[pyramid_path[i]][0] = color[pyramid_path[i]][3];
				color[pyramid_path[i]][3] = color[pyramid_path[i]][1];
				color[pyramid_path[i]][1] = temp_color;
			}

			int temp_color_update[3];
			temp_color_update[0] = color[pyramid_path[0]][0];
			temp_color_update[1] = color[pyramid_path[0]][1];
			temp_color_update[2] = color[pyramid_path[0]][3];
			int temp_color_botface = color[pyramid_path[0]][2];
			color[pyramid_path[0]][0] = color[pyramid_path[4]][0];
			color[pyramid_path[0]][1] = color[pyramid_path[4]][1];
			color[pyramid_path[0]][3] = color[pyramid_path[4]][3];
			color[pyramid_path[0]][2] = color[pyramid_path[4]][2];
			color[pyramid_path[4]][0] = color[pyramid_path[2]][0];
			color[pyramid_path[4]][1] = color[pyramid_path[2]][1];
			color[pyramid_path[4]][3] = color[pyramid_path[2]][3];
			color[pyramid_path[4]][2] = color[pyramid_path[2]][2];
			color[pyramid_path[2]][0] = temp_color_update[0];
			color[pyramid_path[2]][1] = temp_color_update[1];
			color[pyramid_path[2]][3] = temp_color_update[2];
			color[pyramid_path[2]][2] = temp_color_botface;
			temp_color_update[0] = color[pyramid_path[1]][0];
			temp_color_update[1] = color[pyramid_path[1]][1];
			temp_color_update[2] = color[pyramid_path[1]][3];
			temp_color_botface = color[pyramid_path[1]][2];
			color[pyramid_path[1]][0] = color[pyramid_path[5]][0];
			color[pyramid_path[1]][1] = color[pyramid_path[5]][1];
			color[pyramid_path[1]][3] = color[pyramid_path[5]][3];
			color[pyramid_path[1]][2] = color[pyramid_path[5]][2];
			color[pyramid_path[5]][0] = color[pyramid_path[3]][0];
			color[pyramid_path[5]][1] = color[pyramid_path[3]][1];
			color[pyramid_path[5]][3] = color[pyramid_path[3]][3];
			color[pyramid_path[5]][2] = color[pyramid_path[3]][2];
			color[pyramid_path[3]][0] = temp_color_update[0];
			color[pyramid_path[3]][1] = temp_color_update[1];
			color[pyramid_path[3]][3] = temp_color_update[2];
			color[pyramid_path[3]][2] = temp_color_botface;

			highlight_inner_pyramid[0] = 0;
			highlight_inner_pyramid[1] = 1;
			highlight_inner_pyramid[2] = 3;
			inner_pyramid_path[0] = 0;
			inner_pyramid_path[1] = 3;
			inner_pyramid_path[2] = 1;

			for(int i=0;i<3;i++){
				int temp_color = inner_pyramid_color[inner_pyramid_path[i]][0];
				inner_pyramid_color[inner_pyramid_path[i]][0] = inner_pyramid_color[inner_pyramid_path[i]][3];
				inner_pyramid_color[inner_pyramid_path[i]][3] = inner_pyramid_color[inner_pyramid_path[i]][1];
				inner_pyramid_color[inner_pyramid_path[i]][1] = temp_color;
			}

			temp_color_update[0] = inner_pyramid_color[inner_pyramid_path[0]][0];
			temp_color_update[1] = inner_pyramid_color[inner_pyramid_path[0]][1];
			temp_color_update[2] = inner_pyramid_color[inner_pyramid_path[0]][3];
			temp_color_botface = inner_pyramid_color[inner_pyramid_path[0]][2];
			inner_pyramid_color[inner_pyramid_path[0]][0] = inner_pyramid_color[inner_pyramid_path[2]][0];
			inner_pyramid_color[inner_pyramid_path[0]][1] = inner_pyramid_color[inner_pyramid_path[2]][1];
			inner_pyramid_color[inner_pyramid_path[0]][3] = inner_pyramid_color[inner_pyramid_path[2]][3];
			inner_pyramid_color[inner_pyramid_path[0]][2] = inner_pyramid_color[inner_pyramid_path[2]][2];
			inner_pyramid_color[inner_pyramid_path[2]][0] = inner_pyramid_color[inner_pyramid_path[1]][0];
			inner_pyramid_color[inner_pyramid_path[2]][1] = inner_pyramid_color[inner_pyramid_path[1]][1];
			inner_pyramid_color[inner_pyramid_path[2]][3] = inner_pyramid_color[inner_pyramid_path[1]][3];
			inner_pyramid_color[inner_pyramid_path[2]][2] = inner_pyramid_color[inner_pyramid_path[1]][2];
			inner_pyramid_color[inner_pyramid_path[1]][0] = temp_color_update[0];
			inner_pyramid_color[inner_pyramid_path[1]][1] = temp_color_update[1];
			inner_pyramid_color[inner_pyramid_path[1]][3] = temp_color_update[2];
			inner_pyramid_color[inner_pyramid_path[1]][2] = temp_color_botface;
		}
		if(keypressed == 'm'){
			highlight_pyramid[0] = 0;
			highlight_pyramid[1] = 1;
			highlight_pyramid[2] = 2;
			highlight_pyramid[3] = 4;
			highlight_pyramid[4] = 5;
			highlight_pyramid[5] = 6;
			highlight_inner_pyramid[0] = 0;
			highlight_inner_pyramid[1] = 1;
			highlight_inner_pyramid[2] = 2;
			pyramid_path[0] = 0;
			pyramid_path[1] = 1;
			pyramid_path[2] = 4;
			pyramid_path[3] = 5;
			pyramid_path[4] = 6;
			pyramid_path[5] = 2;
			
			for(int i=0;i<=value;i++){
				int temp_color = color[pyramid_path[i]][1];
				color[pyramid_path[i]][1] = color[pyramid_path[i]][3];
				color[pyramid_path[i]][3] = color[pyramid_path[i]][2];
				color[pyramid_path[i]][2] = temp_color;
			}

			int temp_color_update[3];
			temp_color_update[0] = color[pyramid_path[0]][1];
			temp_color_update[1] = color[pyramid_path[0]][2];
			temp_color_update[2] = color[pyramid_path[0]][3];
			int temp_color_botface = color[pyramid_path[0]][0];
			color[pyramid_path[0]][1] = color[pyramid_path[4]][1];
			color[pyramid_path[0]][2] = color[pyramid_path[4]][2];
			color[pyramid_path[0]][3] = color[pyramid_path[4]][3];
			color[pyramid_path[0]][0] = color[pyramid_path[4]][0];
			color[pyramid_path[4]][1] = color[pyramid_path[2]][1];
			color[pyramid_path[4]][2] = color[pyramid_path[2]][2];
			color[pyramid_path[4]][3] = color[pyramid_path[2]][3];
			color[pyramid_path[4]][0] = color[pyramid_path[2]][0];
			color[pyramid_path[2]][1] = temp_color_update[0];
			color[pyramid_path[2]][2] = temp_color_update[1];
			color[pyramid_path[2]][3] = temp_color_update[2];
			color[pyramid_path[2]][0] = temp_color_botface;
			temp_color_update[0] = color[pyramid_path[1]][1];
			temp_color_update[1] = color[pyramid_path[1]][2];
			temp_color_update[2] = color[pyramid_path[1]][3];
			temp_color_botface = color[pyramid_path[1]][0];
			color[pyramid_path[1]][1] = color[pyramid_path[5]][1];
			color[pyramid_path[1]][2] = color[pyramid_path[5]][2];
			color[pyramid_path[1]][3] = color[pyramid_path[5]][3];
			color[pyramid_path[1]][0] = color[pyramid_path[5]][0];
			color[pyramid_path[5]][1] = color[pyramid_path[3]][1];
			color[pyramid_path[5]][2] = color[pyramid_path[3]][2];
			color[pyramid_path[5]][3] = color[pyramid_path[3]][3];
			color[pyramid_path[5]][0] = color[pyramid_path[3]][0];
			color[pyramid_path[3]][1] = temp_color_update[0];
			color[pyramid_path[3]][2] = temp_color_update[1];
			color[pyramid_path[3]][3] = temp_color_update[2];
			color[pyramid_path[3]][0] = temp_color_botface;

			inner_pyramid_path[0] = 0;
			inner_pyramid_path[1] = 1;
			inner_pyramid_path[2] = 2;

			for(int i=0;i<3;i++){
				int temp_color = inner_pyramid_color[inner_pyramid_path[i]][1];
				inner_pyramid_color[inner_pyramid_path[i]][1] = inner_pyramid_color[inner_pyramid_path[i]][3];
				inner_pyramid_color[inner_pyramid_path[i]][3] = inner_pyramid_color[inner_pyramid_path[i]][2];
				inner_pyramid_color[inner_pyramid_path[i]][2] = temp_color;
			}

			temp_color_update[0] = inner_pyramid_color[inner_pyramid_path[0]][1];
			temp_color_update[1] = inner_pyramid_color[inner_pyramid_path[0]][2];
			temp_color_update[2] = inner_pyramid_color[inner_pyramid_path[0]][3];
			temp_color_botface = inner_pyramid_color[inner_pyramid_path[0]][0];
			inner_pyramid_color[inner_pyramid_path[0]][1] = inner_pyramid_color[inner_pyramid_path[2]][1];
			inner_pyramid_color[inner_pyramid_path[0]][2] = inner_pyramid_color[inner_pyramid_path[2]][2];
			inner_pyramid_color[inner_pyramid_path[0]][3] = inner_pyramid_color[inner_pyramid_path[2]][3];
			inner_pyramid_color[inner_pyramid_path[0]][0] = inner_pyramid_color[inner_pyramid_path[2]][0];
			inner_pyramid_color[inner_pyramid_path[2]][1] = inner_pyramid_color[inner_pyramid_path[1]][1];
			inner_pyramid_color[inner_pyramid_path[2]][2] = inner_pyramid_color[inner_pyramid_path[1]][2];
			inner_pyramid_color[inner_pyramid_path[2]][3] = inner_pyramid_color[inner_pyramid_path[1]][3];
			inner_pyramid_color[inner_pyramid_path[2]][0] = inner_pyramid_color[inner_pyramid_path[1]][0];
			inner_pyramid_color[inner_pyramid_path[1]][1] = temp_color_update[0];
			inner_pyramid_color[inner_pyramid_path[1]][2] = temp_color_update[1];
			inner_pyramid_color[inner_pyramid_path[1]][3] = temp_color_update[2];
			inner_pyramid_color[inner_pyramid_path[1]][0] = temp_color_botface;
		}
	}
}

void init_highlight(){
	for(int i=0;i<6;i++){
		highlight_pyramid[i] = -1;
	}
	for(int i=0;i<3;i++){
		highlight_inner_pyramid[i] = -1;
	}
	highlight_color = 0.0;
	highlight_pyramid_count = 0;
}

void draw_pyraminx(){
	for(int pyramid_count = 0; pyramid_count < 10; pyramid_count++){
		if(pyramid_count == highlight_pyramid[highlight_pyramid_count]){
			highlight_color = 1.0;
			highlight_pyramid_count++;
		}
		else
		{
			highlight_color = 0.0;
		}		
		triangle1(pyramid[pyramid_count].vertices[0],pyramid[pyramid_count].vertices[1],pyramid[pyramid_count].vertices[2],color[pyramid_count][0]);
		triangle1(pyramid[pyramid_count].vertices[0],pyramid[pyramid_count].vertices[2],pyramid[pyramid_count].vertices[3],color[pyramid_count][1]);
		triangle1(pyramid[pyramid_count].vertices[0],pyramid[pyramid_count].vertices[3],pyramid[pyramid_count].vertices[1],color[pyramid_count][2]);
		triangle1(pyramid[pyramid_count].vertices[1],pyramid[pyramid_count].vertices[2],pyramid[pyramid_count].vertices[3],color[pyramid_count][3]);
	}
	for(int inner_pyraminx_count =0; inner_pyraminx_count < 4; inner_pyraminx_count++){
		if(inner_pyraminx_count == highlight_inner_pyramid[highlight_pyramid_count]){
			highlight_color = 1.0;
			highlight_pyramid_count++;
		}
		else
		{	
			highlight_color = 0.0;
		}
		triangle1(inner_pyramid[inner_pyraminx_count].vertices[0][0],inner_pyramid[inner_pyraminx_count].vertices[0][1],inner_pyramid[inner_pyraminx_count].vertices[0][2],inner_pyramid_color[inner_pyraminx_count][0]);
		triangle1(inner_pyramid[inner_pyraminx_count].vertices[1][0],inner_pyramid[inner_pyraminx_count].vertices[1][1],inner_pyramid[inner_pyraminx_count].vertices[1][2],inner_pyramid_color[inner_pyraminx_count][1]);
		triangle1(inner_pyramid[inner_pyraminx_count].vertices[2][0],inner_pyramid[inner_pyraminx_count].vertices[2][1],inner_pyramid[inner_pyraminx_count].vertices[2][2],inner_pyramid_color[inner_pyraminx_count][2]);
		triangle1(inner_pyramid[inner_pyraminx_count].vertices[3][0],inner_pyramid[inner_pyraminx_count].vertices[3][1],inner_pyramid[inner_pyraminx_count].vertices[3][2],inner_pyramid_color[inner_pyraminx_count][3]);
	}
	init_highlight();
}

void draw_front(){
	int x_factor = 10, y_factor = 1;
	glPushMatrix();
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[0][0]]);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*25.98,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*25.98,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[1][0]]);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[2][0]]);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[4][0]]);
	glVertex3f(125.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(125.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[5][0]]);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[6][0]]);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(155.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(155.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[0][0]]);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[1][0]]);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[2][0]]);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glPopMatrix();
}

void draw_right(){
	int x_factor = 40, y_factor = 1;
	glPushMatrix();
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[0][1]]);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*25.98,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*25.98,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[2][1]]);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[3][1]]);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[6][1]]);
	glVertex3f(125.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(125.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[7][1]]);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[8][1]]);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(155.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(155.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[0][1]]);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[2][1]]);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[3][1]]);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glPopMatrix();
}

void draw_left(){
	int x_factor = -20, y_factor = 1;
	glPushMatrix();
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[0][2]]);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*25.98,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*25.98,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[3][2]]);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[1][2]]);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[8][2]]);
	glVertex3f(125.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(125.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[9][2]]);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[4][2]]);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(155.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(155.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[0][2]]);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[3][2]]);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[1][2]]);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glPopMatrix();
}

void draw_bottom(){
	int x_factor = 10, y_factor = -1;
	glPushMatrix();
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[8][3]]);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*25.98,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*25.98,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[9][3]]);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[7][3]]);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[4][3]]);
	glVertex3f(125.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(125.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[5][3]]);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[color[6][3]]);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(155.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(155.0+x_factor, y_factor*0.0,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[3][3]]);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(135.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(145.0+x_factor, y_factor*17.32,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[1][3]]);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(130.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(135.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(colors[inner_pyramid_color[2][3]]);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glLineWidth(linewidth);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(140.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(150.0+x_factor, y_factor*8.66,0.0);
	glVertex3f(145.0+x_factor, y_factor*0.0,0.0);
	glEnd();
	glPopMatrix();
}

void draw_up_arrow(){
	glPushMatrix();
	glLoadIdentity();
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(135.0-5.0, -7.0, 0.0);
	glVertex3f(135.0-2.0, -7.0, 0.0);
	glVertex3f(135.0-5.0, -2.0, 0.0);
	glVertex3f(135.0-5.0, -7.0, 0.0);
	glVertex3f(135.0-5.0, -2.0, 0.0);
	glVertex3f(135.0-3.0, -4.0, 0.0);
	glVertex3f(135.0-5.0, -2.0, 0.0);
	glVertex3f(135.0-7.0, -4.0, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(125.0-5.0, -7.0, 0.0);
	glVertex3f(125.0-2.0, -7.0, 0.0);
	glVertex3f(125.0-5.0, -2.0, 0.0);
	glVertex3f(125.0-5.0, -7.0, 0.0);
	glVertex3f(125.0-5.0, -2.0, 0.0);
	glVertex3f(125.0-3.0, -4.0, 0.0);
	glVertex3f(125.0-5.0, -2.0, 0.0);
	glVertex3f(125.0-7.0, -4.0, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(115.0-5.0, -7.0, 0.0);
	glVertex3f(115.0-2.0, -7.0, 0.0);
	glVertex3f(115.0-5.0, -2.0, 0.0);
	glVertex3f(115.0-5.0, -7.0, 0.0);
	glVertex3f(115.0-5.0, -2.0, 0.0);
	glVertex3f(115.0-3.0, -4.0, 0.0);
	glVertex3f(115.0-5.0, -2.0, 0.0);
	glVertex3f(115.0-7.0, -4.0, 0.0);
	glEnd();
	glPopMatrix();
}

void draw_down_arrow(){
	glPushMatrix();
	glLoadIdentity();
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(165.0+8.0, -3.0, 0.0);
	glVertex3f(165.0+8.0, -6.0, 0.0);
	glVertex3f(165.0+8.0, -6.0, 0.0);
	glVertex3f(165.0+2.0, -6.0, 0.0);
	glVertex3f(165.0+2.0, -6.0, 0.0);
	glVertex3f(165.0+4.0, -8.0, 0.0);
	glVertex3f(165.0+2.0, -6.0, 0.0);
	glVertex3f(165.0+4.0, -4.0, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(175.0+8.0, -3.0, 0.0);
	glVertex3f(175.0+8.0, -6.0, 0.0);
	glVertex3f(175.0+8.0, -6.0, 0.0);
	glVertex3f(175.0+2.0, -6.0, 0.0);
	glVertex3f(175.0+2.0, -6.0, 0.0);
	glVertex3f(175.0+4.0, -8.0, 0.0);
	glVertex3f(175.0+2.0, -6.0, 0.0);
	glVertex3f(175.0+4.0, -4.0, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(185.0+8.0, -3.0, 0.0);
	glVertex3f(185.0+8.0, -6.0, 0.0);
	glVertex3f(185.0+8.0, -6.0, 0.0);
	glVertex3f(185.0+2.0, -6.0, 0.0);
	glVertex3f(185.0+2.0, -6.0, 0.0);
	glVertex3f(185.0+4.0, -8.0, 0.0);
	glVertex3f(185.0+2.0, -6.0, 0.0);
	glVertex3f(185.0+4.0, -4.0, 0.0);
	glEnd();
	glPopMatrix();
}

void mydisplay(char keypressed, int value){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	glRotatef(anglex,1.0,0.0,0.0);
    glRotatef(angley,0.0,1.0,0.0);
	pyraminx_operation(keypressed, value);
    draw_pyraminx();
	draw_front();
	draw_right();
	draw_left();
	draw_bottom();
	draw_up_arrow();
	draw_down_arrow();
	glFlush();
	glutSwapBuffers();
}

int flag_display = 0;

void display(void){
	if(flag_display == 1){
		mydisplay('z',10);
	}
	else{
		flag_display = 1;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glLoadIdentity();
		glRotatef(anglex,1.0,0.0,0.0);
    	glRotatef(angley,0.0,1.0,0.0);
    	tetrahedron();
		draw_front();
		draw_right();
		draw_left();
		draw_bottom();
		draw_up_arrow();
		draw_down_arrow();
		glFlush();
		glutSwapBuffers();
	}
}
int window_width,window_height;
void hover(int x, int y){
	if(x>=1011 && x<=1054 && y<=210*window_height/500 && y>=190*window_height/500){
		highlight_pyramid[0] = 0;
	}
	else if(x>=989 && x<=1075 && y<=230*window_height/500 && y>=210*window_height/500){
		highlight_pyramid[0] = 1;
		highlight_pyramid[1] = 2;
		highlight_pyramid[2] = 3;
		highlight_inner_pyramid[0] = 0;
	}
	else if(x>=968 && x<=1097 && y<=250*window_height/500 && y>=230*window_height/500){
		highlight_pyramid[0] = 4;
		highlight_pyramid[1] = 5;
		highlight_pyramid[2] = 6;
		highlight_pyramid[3] = 7;
		highlight_pyramid[4] = 8;
		highlight_pyramid[5] = 9;
		highlight_inner_pyramid[0] = 1;
		highlight_inner_pyramid[1] = 2;
		highlight_inner_pyramid[2] = 3;
	}
	else if(x>=968 && x<=1097 && y<=270*window_height/500 && y>=250*window_height/500){
		highlight_pyramid[0] = 0;
		highlight_pyramid[1] = 1;
		highlight_pyramid[2] = 2;
		highlight_pyramid[3] = 4;
		highlight_pyramid[4] = 5;
		highlight_pyramid[5] = 6;
		highlight_inner_pyramid[0] = 0;
		highlight_inner_pyramid[1] = 1;
		highlight_inner_pyramid[2] = 2;
	}
	else if(x>=989 && x<=1075 && y<=290*window_height/500 && y>=270*window_height/500){
		highlight_pyramid[0] = 3;
		highlight_pyramid[1] = 7;
		highlight_pyramid[2] = 9;
		highlight_inner_pyramid[0] = 3;
	}
	else if(x>=1011 && x<=1054 && y<=310*window_height/500 && y>=290*window_height/500){
		highlight_pyramid[0] = 8;
	}
	else if(x>=925 && x<=968 && y<=268*window_height/500 && y>=250*window_height/500){
		highlight_pyramid[0] = 4;
	}
	else if(x>=882 && x<=925 && y<=268*window_height/500 && y>=250*window_height/500){
		highlight_pyramid[0] = 1;
		highlight_pyramid[1] = 5;
		highlight_pyramid[2] = 9;
		highlight_inner_pyramid[0] = 1;
	}
	else if(x>=839 && x<=882 && y<=268*window_height/500 && y>=250*window_height/500){
		highlight_pyramid[0] = 0;
		highlight_pyramid[1] = 2;
		highlight_pyramid[2] = 3;
		highlight_pyramid[3] = 6;
		highlight_pyramid[4] = 7;
		highlight_pyramid[5] = 8;
		highlight_inner_pyramid[0] = 0;
		highlight_inner_pyramid[1] = 2;
		highlight_inner_pyramid[2] = 3;
	}
	else if(x>=1097 && x<=1140 && y<=268*window_height/500 && y>=250*window_height/500){
		highlight_pyramid[0] = 6;
	}
	else if(x>=1140 && x<=1183 && y<=268*window_height/500 && y>=250*window_height/500){
		highlight_pyramid[0] = 2;
		highlight_pyramid[1] = 5;
		highlight_pyramid[2] = 7;
		highlight_inner_pyramid[0] = 2;
	}
	else if(x>=1183 && x<=1226 && y<=268*window_height/500 && y>=250*window_height/500){
		highlight_pyramid[0] = 0;
		highlight_pyramid[1] = 1;
		highlight_pyramid[2] = 3;
		highlight_pyramid[3] = 4;
		highlight_pyramid[4] = 8;
		highlight_pyramid[5] = 9;
		highlight_inner_pyramid[0] = 0;
		highlight_inner_pyramid[1] = 1;
		highlight_inner_pyramid[2] = 3;
	}
	// printf("x: %d y: %d\n", x, y);

	mydisplay('z',10);
}

void mouse(int btn, int state, int x, int y){
	char keypressed = 'z';
	int value = 10;
	if(btn==GLUT_LEFT_BUTTON){
		if(state == GLUT_DOWN){
			if(x>=1011 && x<=1054 && y<=210*window_height/500 && y>=190*window_height/500){
				keypressed = 'r';
				value = 1;
			}
			else if(x>=989 && x<=1075 && y<=230*window_height/500 && y>=210*window_height/500){
				keypressed = 'f';
				value = 2;
			}
			else if(x>=968 && x<=1097 && y<=250*window_height/500 && y>=230*window_height/500){
				keypressed = 'v';
				value = 5;
			}
			else if(x>=968 && x<=1097 && y<=270*window_height/500 && y>=250*window_height/500){
				keypressed = 'm';
				value = 5;
			}
			else if(x>=989 && x<=1075 && y<=290*window_height/500 && y>=270*window_height/500){
				keypressed = 'j';
				value = 2;
			}
			else if(x>=1011 && x<=1054 && y<=310*window_height/500 && y>=290*window_height/500){
				keypressed = 'u';
				value = 1;
			}
			else if(x>=925 && x<=968 && y<=268*window_height/500 && y>=250*window_height/500){
				keypressed = 't';
				value = 1;
			}
			else if(x>=882 && x<=925 && y<=268*window_height/500 && y>=250*window_height/500){
				keypressed = 'g';
				value = 2;
			}
			else if(x>=839 && x<=882 && y<=268*window_height/500 && y>=250*window_height/500){
				keypressed = 'b';
				value = 5;
			}
			else if(x>=1097 && x<=1140 && y<=268*window_height/500 && y>=250*window_height/500){
				keypressed = 'y';
				value = 1;
			}
			else if(x>=1140 && x<=1183 && y<=268*window_height/500 && y>=250*window_height/500){
				keypressed = 'h';
				value = 2;
			}
			else if(x>=1183 && x<=1226 && y<=268*window_height/500 && y>=250*window_height/500){
				keypressed = 'n';
				value = 5;
			}
			else{
				keypressed = 'z';
				value = 10;
			}
		}
		else{
			keypressed = 'z';
				value = 10;
		}
	}
	mydisplay(keypressed, value);
}

// GLint win1;

void keys(unsigned char key, int x, int y){
	char keypressed = 'z';
	int value = 10;
	switch(key){
	case 'A':
	case 'a':
		angley += 2;
		if(anglex <= 0){
			anglex += 360;
		}
		break;

	case 'd':
	case 'D':
		angley -= 2;
		if(anglex >=360){
			anglex -= 360;
		}
		break;

	case 'w':
	case 'W':
		anglex += 3;
		if(angley >= 360){
			angley -= 360;
		}
		break;

	case 's':
	case 'S':
		anglex -= 3;
		if(angley <= 0){
			angley += 360;
		}
		break;
	}

	if(key == 'r'){
		keypressed = 'r';
		value = 1;
	}
	else if(key == 't'){
		keypressed = 't';
		value = 1;
	}
	else if(key == 'y'){
		keypressed = 'y';
		value = 1;
	}
	else if(key == 'u'){
		keypressed = 'u';
		value = 1;
	}
	else if(key == 'f'){
		keypressed = 'f';
		value = 2;
	}
	else if(key == 'g'){
		keypressed = 'g';
		value = 2;
	}
	else if(key == 'h'){
		keypressed = 'h';
		value = 2;
	}
	else if(key == 'j'){
		keypressed = 'j';
		value = 2;
	}
	else if(key == 'v'){
		keypressed = 'v';
		value = 5;
	}
	else if(key == 'b'){
		keypressed = 'b';
		value = 5;
	}
	else if(key == 'n'){
		keypressed = 'n';
		value = 5;
	}
	else if(key == 'm'){
		keypressed = 'm';
		value = 5;
	}
	else{
		keypressed = 'z';
		value = 10;
	}
	if(key == 'q'){
		glutDestroyWindow(win1);
	}

	mydisplay(keypressed, value);
}

void myReshape(int w, int h){
	window_height = h;
	window_width = w;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	if(w<=h)
		glOrtho(-50.0,200.0*(GLfloat)h/(GLfloat)w,-100.0*(GLfloat)h/(GLfloat)w, 100.0,-100.0,100.0);
	else
		glOrtho(-50.0*(GLfloat)w/(GLfloat)h, 200.0*(GLfloat)w/(GLfloat)h,-100.0,100.0,-100.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}

// int  main(int argc, char **argv){
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
// 	glutInitWindowSize(500, 500);
//     glutCreateWindow("Pyraminx");
// 	glutFullScreen();
//     glutReshapeFunc(myReshape);
//     glutDisplayFunc(display);
// 	glutPassiveMotionFunc(hover);
// 	glutKeyboardFunc(keys);
// 	glutMouseFunc(mouse);
//     glEnable(GL_DEPTH_TEST);
//     glutMainLoop();
//     return 0;
// }