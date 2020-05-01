#ifndef RUBIXCUBE_H
#define RUBIXCUBE_H

extern GLint win2;

void polygon(int a, int b, int c , int d, int x, int y, int z);
void updateXRotation(int count, int a, int b, int c, int d);
void updateYRotation(int count, int a, int b, int c, int d);
void updateZRotation(int count, int a, int b, int c, int d);
void polygon1(int a,int b, int c, int d,int x, int y, int z, int keypressedx, int keypressedy, int keypressedz);
void colorcube1(int keypressedx, int keypressedy, int keypressedz);
void colorcube();
void mydisplay1(int keypressedx, int keypressedy, int keypressedz);
void display1(void);
void mouse1(int btn, int state, int x, int y);
void keys1(unsigned char key, int x, int y);
void myReshape1(int w, int h);


#endif
