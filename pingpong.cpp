#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define janela_altura 600
#define janela_largura 800
#define PI 3.14159265359

float transY[] = { 0, 0 };
float tx, ty, xStep, yStep;

void start();
void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
void arrow_keys(int tecla, int x, int y);
void anima(int valor);

int main(int argc, char** argv) {
	start();
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(janela_largura, janela_altura);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("PingPong");

	glutReshapeFunc(tela);
	glutDisplayFunc(display);
	glutSpecialFunc(arrow_keys);
	glutTimerFunc(50, anima, 1);
	glutKeyboardFunc(&keyboard);
	glutMainLoop();

	return(0);
}

void start() {
	tx = 0;
	ty = 0;
	transY[0] = 0;
	transY[1] = 0;
	xStep = 2;
	yStep = 2;
}

void anima(int valor) {

	if(tx > 380 || tx < -(380)) {
		start();
	}

	if (ty >= transY[0]  && ty <= (transY[0] +200) && tx < -290) {
		if (xStep > 0) {
			xStep += 2;
		}else {
			xStep -= 2;
		}
		xStep = -xStep;
	}

	if (ty >= transY[1] && ty <= (transY[1] + 200) && tx > 290) {
		if (xStep > 0) {
			xStep += 2;
		}else {
			xStep -= 2;
		}
		xStep = -xStep;
	}

	if (ty > 280 || ty < -280) {
		yStep = -yStep;
	}

	tx += xStep;
	ty += yStep;

	glutPostRedisplay();
	glutTimerFunc(50, anima, 1);
}

void keyboard(unsigned char tecla, int x, int y) {
	if (tecla == 'w') {
		transY[0] = transY[0] + 10;

	}if (tecla == 's') {
		transY[0] = transY[0] - 10;
	}
	glutPostRedisplay();
}

void arrow_keys(int tecla, int x, int y) {
	if (tecla == GLUT_KEY_UP) {
		transY[1] = transY[1] + 8;
	}if (tecla == GLUT_KEY_DOWN) {
		transY[1] = transY[1] - 8;
	}
	glutPostRedisplay();
}

void bola() {
	GLfloat circ_pnt = 100;
	GLfloat ang, raioX = 10.0f, raioY = 10.0f;

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();
}

void barra() {
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.75, 1);
	glVertex2f(0, 0);
	glVertex2f(0, 200);
	glVertex2f(50, 200);
	glVertex2f(50, 0);
	glEnd();
}


void desenhar() {
	glPushMatrix();

	if (transY[0] > 100) {
		transY[0] = 100;
	}
	if (transY[0] < -300) {
		transY[0] = -300;
	}

	glTranslatef(-350, transY[0], 0);
	barra();
	glPopMatrix();

	glPushMatrix();

	if (transY[1] > 100) {
		transY[1] = 100;
	}
	if (transY[1] < -300) {
		transY[1] = -300;
	}

	glTranslatef(300, transY[1], 0);
	barra();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(tx, ty, 0);
	bola();
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