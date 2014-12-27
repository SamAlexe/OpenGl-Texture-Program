#include "model.h"


    model::Model(string modelFilename, string textureFilename)
    {
        m_ModelFilename = modelFilename;
        m_TextureName = textureFilename;
        //load model function//
        LoadTexture(m_TextureName);
    }
    GLuint model::loadTexture(string TextureName) 
    {
        string filename = TextureName;
        filename.append(".bmp");
        BitMapFile *image[1];
        image[0] = getBMPData(filename);
        glGenTextures(1, &textureId); //Make room for our texture
        glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
    	//Map the image to the texture
    	glTexImage2D(GL_TEXTURE_2D,                
    				 0,                            
    				 GL_RGB,                       
    				 image[0]->width, image[0]->height,  
    				 0,                            
    				 GL_RGB, 
    				 GL_UNSIGNED_BYTE, 
    				 image[0]->data);               //The actual pixel data
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    
    void model::initrendering()
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_TEXTURE_2D);
        //for background color
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glShadeModel(GL_SMOOTH);
        glClearColor(0.7f, 0.9f, 1.0f, 1.0f - last one doesn't matter);
    }
    void model::ambem()
    {
        GLfloat lightColor0[] = {0.0f, 0.0f, 0.1f, 1.0f}; //Color (0.5, 0.5, 0.5)
        GLfloat lightPos0[] = {2.0f, 0.0f, 4.0f, 0.0f}; //Positioned at (4, 0, 8)
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    }
    void model::drawscene()
    {
        glBindTexture(GL_TEXTURE_2D, textureId);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
	    model.SetCenterX(0);
        model.SetCenterY(0); 
        model.SetCenterZ(12);
        glTranslatef(m_CenterX, m_CenterY, m_CenterZ);
        ambem();
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS); 
        glVertex3f(-0.5f, 0.5f, 0.0f);
        glVertex3f(0.5f, 0.5f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
        glVertex3d(-0.05f, -0.5, 0.0f)
        glEnd();
    	glutSwapBuffers();
    }
    void model::handleKeypress(unsigned char key, int x, int y)
    {   
        switch (key) {
            case 27: //Escape key
                exit(0); //Exit the program
        }
    }
                   //The far z clipping coordinate
    void model::handleResize(int w, int h) 
    {
        //Tell OpenGL how to convert from coordinates to pixel values
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
        
        //Set the camera perspective
        glLoadIdentity(); //Reset the camera
        gluPerspective(45.0,                  //The camera angle
                       (double)w / (double)h, //The width-to-height ratio
                       1.0,                   //The near z clipping coordinate
                      //Shading
                       200.0);  
    }
