#include <iostream>
#include <stdlib.h> //Needed for "exit" function

//Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "model.h"
#include "bitmap.h"


using namespace std;

int main(int argc, char** argv) {

    model model;
    string textureFilename;
    string modelFilename;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400); 
    glutCreateWindow("Texture Program");
    cout << "Print in your texture name: ";
    cin >> textureFilename;
    cout << "Print in your texture object name: ";
    cin >> modelFilename;
    model.Model(modelFilename,textureFilename)
    model.initRendering(); //Initialize rendering
    glutDisplayFunc(model.drawScene);
    glutKeyboardFunc(model.handleKeypress);
    glutReshapeFunc(model.handleResize);
    glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
    return 0; //This line is never reached
}
