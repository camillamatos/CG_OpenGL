#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define janela_altura 400
#define janela_largura 600
float transH[] = { 0, 0, 0 };
float transV[] = { 0, 0, 0 };
float zoom[] = { 1, 1, 1 };
int op = 0;

void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
void arrow_keys(int tecla, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(janela_largura, janela_altura);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("rotacao");

	glutReshapeFunc(tela);
	glutDisplayFunc(display);
	glutSpecialFunc(arrow_keys);
	glutKeyboardFunc(&keyboard);
	glutMainLoop();

	return(0);
}

void keyboard(unsigned char tecla, int x, int y) {
	if (tecla == '1') {
		op = 0;
	}
	else if (tecla == '2') {
		op = 1;
	}
	else if (tecla == '3') {
		op = 2;
	}

	if (tecla == '+') {
		zoom[op] = zoom[op] + 0.05;
	}if (tecla == '-') {
		zoom[op] = zoom[op] - 0.05;
	}

	glutPostRedisplay();
}

void arrow_keys(int tecla, int x, int y) {

	if (tecla == GLUT_KEY_UP) {
		transV[op] = transV[op] + 10;
	}if (tecla == GLUT_KEY_DOWN) {
		transV[op] = transV[op] - 10;
	}if (tecla == GLUT_KEY_RIGHT) {
		transH[op] = transH[op] + 10;
	}if (tecla == GLUT_KEY_LEFT) {
		transH[op] = transH[op] - 10;
	}

	glutPostRedisplay();
}

void desenhar() {

	glPushMatrix();
	glScalef(zoom[0], zoom[0], 0);
	glTranslatef(transH[0], transV[0], 0);

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(-180, -100);
	glVertex2f(-150, -100);
	glVertex2f(-150, 100);
	glVertex2f(-180, 100);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glScalef(zoom[1], zoom[1], 0);
	glTranslatef(transH[1], transV[1], 0);

	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(-50, -100);
	glVertex2f(50, -100);
	glVertex2f(50, 0);
	glVertex2f(-50, 0);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glScalef(zoom[2], zoom[2], 0);
	glTranslatef(transH[2], transV[2], 0);

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0);
	glVertex2f(100, -100);
	glVertex2f(150, -100);
	glVertex2f(125, -50);
	glEnd();

	glPopMatrix();

}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);

	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();

	glFlush();
}

void tela(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, janela_largura, 0, janela_altura);

	glMatrixMode(GL_MODELVIEW);
}
