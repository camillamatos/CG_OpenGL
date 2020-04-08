#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define janela_altura 600
#define janela_largura 800
#define PI 3.14159

float transX[] = { 0, 0 };
float l[] = { -150, 150 };

void display(void);
void tela(GLsizei w, GLsizei h);
void MouseClick(int button, int state, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(janela_largura, janela_altura);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("joguinho1");

	glutReshapeFunc(tela);
	glutDisplayFunc(display);
	glutMouseFunc(MouseClick);
	glutMainLoop();

	return(0);
}


void MouseClick(int button, int state, int x, int y)
{
	int pos = 0;
	if (button == GLUT_LEFT_BUTTON) {
		if (x > 400) {
			l[1] -= 5;
		}
		else {
			l[0] += 5;
		}
	}
	
	
	pos = l[1] - l[0];

	if (pos < 0) {
		pos *= -1;
	}


	if (pos <= 100) {
		l[0] = -400;
		l[1] = 400;
	}
	glutPostRedisplay();

}

void bola() {
	GLfloat circ_pnt = 100;
	GLfloat ang, raioX = 50.0f, raioY = 50.0f;


	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();
}

void linha() {
	glBegin(GL_LINES);
	glVertex2f(l[0], 0);
	glVertex2f(l[1], 0);
	glEnd();
}


void desenhar() {

	glPushMatrix();
	glTranslatef(l[0], 0, 0);

	glColor3f(0, 0, 0);
	bola();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(l[1], 0, 0);

	glColor3f(1, 1, 1);
	bola();

	glPopMatrix();

	glLineWidth(3.0f);
	glColor3f(1, 0, 0);
	linha();


}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.04, 0.325, 0.75, 1);
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





