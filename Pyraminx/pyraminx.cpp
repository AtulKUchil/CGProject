#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>

GLfloat v[4][3] = {{0.0,45.0,0.0},{-12.245,25.0,7.07},{12.245,25.0,7.07},{0.0,25.0,-14.14}};
GLfloat colors[4][3] = {{1.0,0.0,0.0}, {0.0,0.0,1.0}, {0.0,1.0,0.0}, {1.0,1.0,0.0}};
int count =0;
float anglex=0, angley=0, CamDist = 50;

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

void triangle1(GLfloat *a, GLfloat *b,GLfloat*c, int color_value){
	glBegin(GL_POLYGON);
	glColor3fv(colors[color_value]);
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
			int temp_color = color[0][0];
			color[0][0] = color[0][2];
			color[0][2] = color[0][1];
			color[0][1] = temp_color;
		}
		if(keypressed == 't'){
			int temp_color = color[4][0];
			color[4][0] = color[4][2];
			color[4][2] = color[4][3];
			color[4][3] = temp_color;
		}
		if(keypressed == 'y'){
			int temp_color = color[6][0];
			color[6][0] = color[6][3];
			color[6][3] = color[6][1];
			color[6][1] = temp_color;
		}
		if(keypressed == 'u'){
			int temp_color = color[8][1];
			color[8][1] = color[8][3];
			color[8][3] = color[8][2];
			color[8][2] = temp_color;
		}
	}
	if(value == 2){
		int pyramid_path[3] = {0};
		if(keypressed == 'f'){
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

			int temp_inner_pyramid_color = inner_pyramid_color[1][0];
			inner_pyramid_color[1][0] = inner_pyramid_color[1][2];
			inner_pyramid_color[1][2] = inner_pyramid_color[1][3];
			inner_pyramid_color[1][3] = temp_inner_pyramid_color;
		}
		if(keypressed == 'h'){
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

			int temp_inner_pyramid_color = inner_pyramid_color[2][0];
			inner_pyramid_color[2][0] = inner_pyramid_color[2][3];
			inner_pyramid_color[2][3] = inner_pyramid_color[2][1];
			inner_pyramid_color[2][1] = temp_inner_pyramid_color;
		}
		if(keypressed == 'j'){
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


void draw_pyraminx(){
	for(int pyramid_count = 0; pyramid_count < 10; pyramid_count++){
		triangle1(pyramid[pyramid_count].vertices[0],pyramid[pyramid_count].vertices[1],pyramid[pyramid_count].vertices[2],color[pyramid_count][0]);
		triangle1(pyramid[pyramid_count].vertices[0],pyramid[pyramid_count].vertices[2],pyramid[pyramid_count].vertices[3],color[pyramid_count][1]);
		triangle1(pyramid[pyramid_count].vertices[0],pyramid[pyramid_count].vertices[3],pyramid[pyramid_count].vertices[1],color[pyramid_count][2]);
		triangle1(pyramid[pyramid_count].vertices[1],pyramid[pyramid_count].vertices[2],pyramid[pyramid_count].vertices[3],color[pyramid_count][3]);
	}
	for(int inner_pyraminx_count =0; inner_pyraminx_count < 4; inner_pyraminx_count++){
		triangle1(inner_pyramid[inner_pyraminx_count].vertices[0][0],inner_pyramid[inner_pyraminx_count].vertices[0][1],inner_pyramid[inner_pyraminx_count].vertices[0][2],inner_pyramid_color[inner_pyraminx_count][0]);
		triangle1(inner_pyramid[inner_pyraminx_count].vertices[1][0],inner_pyramid[inner_pyraminx_count].vertices[1][1],inner_pyramid[inner_pyraminx_count].vertices[1][2],inner_pyramid_color[inner_pyraminx_count][1]);
		triangle1(inner_pyramid[inner_pyraminx_count].vertices[2][0],inner_pyramid[inner_pyraminx_count].vertices[2][1],inner_pyramid[inner_pyraminx_count].vertices[2][2],inner_pyramid_color[inner_pyraminx_count][2]);
		triangle1(inner_pyramid[inner_pyraminx_count].vertices[3][0],inner_pyramid[inner_pyraminx_count].vertices[3][1],inner_pyramid[inner_pyraminx_count].vertices[3][2],inner_pyramid_color[inner_pyraminx_count][3]);
	}
}

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;
int flag_display = 0;


void mydisplay(char keypressed, int value){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	float ex,ey,ez;
	ex = CamDist*sin(angley);
	ey = CamDist*sin(anglex);
	ez = CamDist*cos(anglex)*cos(angley);
	gluLookAt(ex,ey,ez, 0,0,0, 0,1,0);
	pyraminx_operation(keypressed, value);
    draw_pyraminx();
	glFlush();
	glutSwapBuffers();
}


void display(void){
	if(flag_display == 1){
		mydisplay('z',10);
	}
	else{
		flag_display = 1;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glLoadIdentity();
		float ex,ey,ez;
		ex = CamDist*sin(angley);
		ey = CamDist*sin(anglex);
		ez = CamDist*cos(anglex)*cos(angley);
		gluLookAt(ex,ey,ez, 0,0,0, 0,1,0);
    	tetrahedron();
		glFlush();
		glutSwapBuffers();
	}
}

// void mouse(int btn, int state, int x, int y){
//     if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//         axis = 0;
//     if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
//         axis = 2;
//     if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//         axis = 1;
//     theta[axis] += 22.5;
//     printf("Axis: %d\n",axis);

// 	if( theta[axis] > 360.0 )
//         theta[axis] -= 360.0;
//     printf("theta[axis]: %f\n",theta[axis]);
// 	mydisplay();
// }

void keys(unsigned char key, int x, int y)
{
	char keypressed = 'z';
	int value = 10;
	switch(key){
	case 'A':
	case 'a':
		angley -= 0.05;
		break;

	case 'd':
	case 'D':
		angley += 0.05;
		break;

	case 'w':
	case 'W':
		anglex += 0.05;
		break;

	case 's':
	case 'S':
		anglex -=0.05;
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
	mydisplay(keypressed, value);
}

void myReshape(int w, int h){
	int window_height = h;
	int window_width = w;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	if(w<=h)
		glOrtho(-100.0,100.0*(GLfloat)h/(GLfloat)w,-100.0*(GLfloat)h/(GLfloat)w, 100.0,-100.0,100.0);
	else
		glOrtho(-100.0*(GLfloat)w/(GLfloat)h, 100.0*(GLfloat)w/(GLfloat)h,-100.0,100.0,-100.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}

int  main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Pyraminx");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    // glutMouseFunc(mouse);
    glutKeyboardFunc(keys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
