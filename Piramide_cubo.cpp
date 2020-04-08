#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define janela_altura 480
#define janela_largura 640

void reshape(GLsizei largura, GLsizei altura);
void display();
void piramide();
void cubo();

int main(int argc, char** argv){
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE); 
	glutInitWindowSize(janela_largura, janela_altura); 
	glutInitWindowPosition(50, 50); 
	glutCreateWindow("desenho 3d"); 
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape); 
	glutMainLoop();

	return 0;
}

void reshape(GLsizei largura, GLsizei altura){
	if (altura == 0) altura = 1; 

	GLfloat aspecto = (GLfloat)largura / (GLfloat)altura;

	glViewport(0, 0, largura, altura);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0f, aspecto, 0.1f, 100.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glEnable(GL_DEPTH_TEST); 
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

	//piramide
	glTranslatef(-1.5f, 0.0f, -6.0f);
	piramide();

	//cubo
	glTranslatef(2.5f, 0.0f, 0.0f); 
	glRotatef(110.0, 0.0, 1.0, 0.0);
	glRotatef(50.0, 1.0, 0.0, 0.0);
	cubo();

	glutSwapBuffers();
}

void piramide() {
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);	glVertex3f(1.0f, -1.0f, 1.0f);
	
	glColor3f(1.0f, 0.0f, 0.0f);	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);	glVertex3f(1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);	glVertex3f(1.0f, -1.0f, -1.0f);

	glColor3f(1.0f, 0.0f, 0.0f);	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);	glVertex3f(1.0f, -1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);

	glColor3f(1.0f, 0.0f, 0.0f);	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);

	glEnd();
}

void cubo() {
	glBegin(GL_QUADS);

	glColor3f(1, 0, 0);	glVertex3f(1, -1, 1);
	glColor3f(0, 1, 0);	glVertex3f(1, 1, 1);
	glColor3f(0, 0, 1);	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 1);	glVertex3f(-1, -1, 1);

	glColor3f(1, 0, 0);	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 0);	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);	glVertex3f(-1, 1, 1);

	glColor3f(1, 0, 0);	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 0);	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);	glVertex3f(-1, -1, 1);
	glColor3f(0, 1, 1);	glVertex3f(-1, -1, -1);

	glColor3f(1, 0, 0);	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 0);	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);	glVertex3f(1, -1, 1);

	glColor3f(1, 0, 0);	glVertex3f(-1, -1, 1);
	glColor3f(0, 1, 0);	glVertex3f(-1, 1, 1);
	glColor3f(0, 0, 1);	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);	glVertex3f(-1, -1, -1);

	glEnd();
}