#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define janela_altura 480
#define janela_largura 640
int on = 1;
float x = 0.0, y = 0.0, z = 0.0;

float mat_ambient[] = { 0.23f, 0.23f, 0.23f, 1.0f };
float mat_diffuse[] = { 0.27f, 0.27f, 0.27f, 1.0f };
float mat_specular[] = { 0.77f, 0.77f, 0.77f, 1.0f };
float shine[] = { 90.0f };

void reshape(GLsizei largura, GLsizei altura);
void display();
void keyboard(unsigned char key, int a, int b);
void conf_luz();
void switch_shapes_color();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(janela_largura, janela_altura);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("iluminacao");
    conf_luz();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
void conf_luz(void) {
    float ambiente[] = { 0.0, 0.0, 0.0, 1.0 };
    float diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    float specular[] = { 1.0, 1.0, 1.0, 1.0 };
    float posicao[] = { 1.5, 0.0 };
    float lmodel_ambiente[] = { 0.4, 0.4, 0.4, 1.0 };
    float local_view[] = { 0.0 };

    glClearColor(0.0, 0.1, 0.1, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, posicao);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambiente);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void reshape(GLsizei largura, GLsizei altura) {
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
    float padrao[] = { 0.0, 0.0, 0.0, 1.0 };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glPushMatrix();
    glTranslatef(-1.5f, 0.0f, -6.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    glMaterialfv(GL_FRONT, GL_EMISSION, padrao);
    glutSolidSphere(1.0, 60, 60);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, 0.0f, -6.0f);
    glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    glMaterialfv(GL_FRONT, GL_EMISSION, padrao);
    glutSolidCube(1.5f);
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int a, int b) {
    if (key == 'c') {
        switch_shapes_color();
        glutPostRedisplay();
    }
}

void switch_shapes_color() {
    float mat_ambient_inox[] = { 0.23f, 0.23f, 0.23f, 1.0f };
    float mat_diffuse_inox[] = { 0.27f, 0.27f, 0.27f, 1.0f };
    float mat_specular_inox[] = { 0.77f, 0.77f, 0.77f, 1.0f };
    float shine_inox[] = { 90.0f };

    float mat_ambient_cobre[] = { 0.2125f, 0.1275f, 0.054f, 1.0f };
    float mat_diffuse_cobre[] = { 0.714f, 0.4284f, 0.18144f, 1.0f };
    float mat_specular_cobre[] = { 0.393548f, 0.271906f, 0.166721f, 1.0f };
    float shine_cobre[] = { 25.6f };


    if (on) {
        for (int i = 0; i < 4; i++) {
            mat_ambient[i] = mat_ambient_cobre[i];
            mat_diffuse[i] = mat_diffuse_cobre[i];
            mat_specular[i] = mat_specular_cobre[i];
        }

        shine[0] = shine_cobre[0];

        on = 0;
    }
    else {
        for (int i = 0; i < 4; i++) {
            mat_ambient[i] = mat_ambient_inox[i];
            mat_diffuse[i] = mat_diffuse_inox[i];
            mat_specular[i] = mat_specular_inox[i];
        }

        shine[0] = shine_inox[0];
        on = 1;
    }
}