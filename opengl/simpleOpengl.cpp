#include <stdio.h>
#include "GL/gl.h"
#include "GL/freeglut.h"


#define MIN_SCALE 0.5
#define MAX_SCALE 1.5

static GLfloat m_rotate = 0.0;
static GLfloat m_scale = MIN_SCALE;
static bool m_isAdd = true;

void display_init();
void display_loop();
void display_resize(int w, int h);

void mouse_event_process(int button, int state, int x, int y);

void update_rotate();

int main(int argc, char** argv)
{
	//init
	glutInit(&argc,argv);

	//set display mode
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

	glutInitWindowSize(400,400);
	glutInitWindowPosition(100,100);

	glutCreateWindow("simple opengl");

	display_init();

	//funcs register
	glutDisplayFunc(display_loop);
	glutReshapeFunc(display_resize);
	glutMouseFunc(mouse_event_process);


	glutMainLoop();

	return 0;
}

void display_init(){
	printf("display_init \n");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display_resize(int w, int h){
	printf("display_resize[%d x %d]\n", w, h);

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-50.0, 50, -50, 50, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void display_loop(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();		
		glRotatef(m_rotate, 0.0, 0.0, 1.0);
		glScalef(m_scale, m_scale, 1.0f);
		glColor3f(1.0, 1.0, 1.0);
		glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();

	glColor3f(1.0,0,0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(-50,-50);
		glVertex2f(50,50);
		glVertex2f(20,30);
	glEnd();

	//enable vertex array
	glEnableClientState(GL_VERTEX_ARRAY);
	GLint array[] = {10,20,20,10,30,30,26,29};
	glVertexPoint(2,GL_INT,0,array);
	

	glutSwapBuffers();
}

void mouse_event_process(int button, int state, int x, int y){
	printf("mouse_event_process [button:%d,state:%d,x:%d,y:%d]\n", button, state, x, y);
	switch(button){
		case GLUT_LEFT_BUTTON:
			glutIdleFunc(update_rotate);
		break;
		default:
			glutIdleFunc(NULL);
		break;
	}
}

void update_rotate(){
	m_rotate+=2.0;
	if(m_rotate > 360){
		m_rotate-=360;
	}
	if(m_scale > MAX_SCALE){
		m_isAdd = false;
	}else if(m_scale < MIN_SCALE){
		m_isAdd = true;
	}
	if(m_isAdd){
		m_scale+=0.008;
	}else{
		m_scale-=0.008;
	}
	
	glutPostRedisplay();
}