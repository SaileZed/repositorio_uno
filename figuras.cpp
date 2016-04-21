#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

	


	

void init(void)
{

//Ubicamos la fuente de luz en el punto
	GLfloat punto_luz[] = {1.0, 1.0, 1.0, 0.0};
	GLfloat luz_ambiente[] = {0.5,0.5,0.5}; 

	//Activamos la fuente de luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //Activamos las luces en 0
	glDepthFunc(GL_LESS); //comparación de profundidad
	glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_POSITION, punto_luz);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
glLoadIdentity();
// Usamos proyeccion ortogonal
glOrtho(-3, 3, -3, 3, -3, 3);
// Activamos la matriz de modelado/visionado.
glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
glLoadIdentity();
}

void display(void)
{
// Propiedades del material
GLfloat mat_ambient[] = { 0.0f,0.05f,0.05f};
GLfloat mat_diffuse[] = { 0.4f,0.5f,0.5f};
GLfloat mat_specular[] = { 0.04f,0.7f,0.7f};
GLfloat shine[] = {0.078125};
/* "Limpiamos" el frame buffer con el color de "Clear", en este caso negro.*/
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_MODELVIEW_MATRIX );
glLoadIdentity();

glRotated(25.0, 1.0, 0.0, 0.0);// Rotacion de 25 grados en torno al eje x
glRotated(-30.0, 0.0, 1.0, 0.0);// Rotacion de -30 grados en torno al eje y
glPushMatrix();// Dibujamos una "Tetera" y le aplico el material

//setMaterial
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shine);

glutSolidSphere(0.8, 50, 50);


glMatrixMode( GL_MODELVIEW_MATRIX );
glLoadIdentity();
glRotated(25.0, 1.0, 0.0, 0.0);// Rotacion de 25 grados en torno al eje x
glRotated(-30.0, 0.0, 1.0, 0.0);// Rotacion de -30 grados en torno al eje y
glutSolidTorus(0.5, 1.0, 50, 50);

glFlush();
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);// Inicializo OpenGL
glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);// Activamos buffer simple y colores del tipo RGB
glutInitWindowSize (800, 600);// Definimos una ventana de medidas 800 x 600 para visualizar la ventana.
glutInitWindowPosition (0, 0);// Posicionamos la ventana en la esquina superior izquierda de la pantalla.
glutCreateWindow ("Tetera con materiales");// Creamos el nombre de la ventana
init();// Inicializamos el sistema
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
