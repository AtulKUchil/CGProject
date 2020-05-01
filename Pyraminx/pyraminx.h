#ifndef PYRAMINX_H
#define PYRAMINX_H

extern GLint win1;

void triangle(GLfloat *a, GLfloat *b,GLfloat*c);
void triangle1(GLfloat *a, GLfloat *b,GLfloat*c, int color_value);
void tetrahedron();
void pyraminx_operation(char keypressed, int value);
void init_highlight();
void draw_pyraminx();
void draw_front();
void draw_right();
void draw_left();
void draw_bottom();
void draw_up_arrow();
void draw_down_arrow();
void mydisplay(char keypressed, int value);
void display(void);
void hover(int x, int y);
void mouse(int btn, int state, int x, int y);
void keys(unsigned char key, int x, int y);
void myReshape(int w, int h);

#endif
