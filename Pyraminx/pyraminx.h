#ifndef PYRAMINX_H
#define PYRAMINX_H

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
void draw_text_pyraminx(GLfloat x, GLfloat y, GLfloat z, const char* text, int font);
void mydisplay_pyraminx(char keypressed, int value);
void display_pyraminx(void);
void hover_pyraminx(int x, int y);
void mouse_pyraminx(int btn, int state, int x, int y);
void keys_pyraminx(unsigned char key, int x, int y);
void myReshape_pyraminx(int w, int h);

#endif
