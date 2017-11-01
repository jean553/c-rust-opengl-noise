#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/**
 * @brief renders the scene
 */
void render() {

    /* clear the whole content of the current enabled buffer */
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

/**
 * @brief program starting function
 */
int main(int argc, char* argv[]) {

    /* there is no need to pass input parameters to glut */
    glutInit(&argc, NULL);

    /* only one single buffer drawn and displayed at the same time */
    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(
        WINDOW_WIDTH,
        WINDOW_HEIGHT
    );
    glutCreateWindow("c-rust-opengl-noise");

    glutDisplayFunc(render);
    glutMainLoop();

    return 0;
}
