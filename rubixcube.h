#ifndef RUBIXCUBE_H
#define RUBIXCUBE_H

void polygon(int a, int b, int c , int d, int x, int y, int z);
void updateXRotation(int count, int a, int b, int c, int d);
void updateYRotation(int count, int a, int b, int c, int d);
void updateZRotation(int count, int a, int b, int c, int d);
void polygon1(int a,int b, int c, int d,int x, int y, int z, int keypressedx, int keypressedy, int keypressedz);
void colorcube1(int keypressedx, int keypressedy, int keypressedz);
void colorcube();
void draw_text_cube(GLfloat x, GLfloat y, GLfloat z, const char* text, int font);
void draw_square();
void mydisplay_cube(int keypressedx, int keypressedy, int keypressedz);
void display_cube(void);
void mouse_cube(int btn, int state, int x, int y);
void keys_cube(unsigned char key, int x, int y);
void myReshape_cube(int w, int h);


#endif
