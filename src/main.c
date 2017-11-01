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

    glBegin(GL_LINE_STRIP);

      /* TODO: use glVertex3f to draw a strip line */

    glEnd();

    glFlush();
}

/**
 * @brief program starting function
 */
int main(int argc, char* argv[]) {

    /* TODO: #5 check how to pass parameters to the program
     * in order to have a grid with dimensions;
     * for now, it throws a segmentation fault when initializing glut */

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
