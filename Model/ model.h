#ifndef __MODEL_H__
#define __MODEL_H__


class model
{
    public:
    model(string modelFilename, string textureFilename);
    void initrendering();
    void drawscene();
    void handlekeypress(unsigned char key, int x, int y);
    void handleResize(int w, int h);
    float getCenterX() { return m_CenterX; }
    float getCenterY() { return m_CenterY; }
    float getCenterZ() { return m_CenterZ; }
    void SetCenterX(float x) { m_CenterX = x; }
    void SetCenterY(float y) { m_CenterY = y; }
    void SetCenterZ(float z) { m_CenterZ = z; }
    GLuint loadTexture(string filename);
    
    private:
    string m_ModelFilename;
    string m_TextureName;
    GLuint textureId;
    float m_CenterX, m_CenterY, m_CenterZ;
};

#endif
