methods:
-------------------------
glClearColor(r,g,b,a)
glClear(mode|mode)
glFlush()
glFinish   -> force flush, block until render finish
glViewport  -> set view area

vertex:
	glBegin();
		glVertex(sif) ..
		...
	glEnd();

state:
	glEnable(genum)
	glDisable(genum)
	glIsEnabled(genum)  ->  query

vertex array:
	glEnableClientState(mode|mode);	
 