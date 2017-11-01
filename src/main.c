#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/**
 * @brief renders the scene
 */
void render() {
}

/**
 * @brief program starting function
 */
int main(int argc, char* argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(
        WINDOW_WIDTH,
        WINDOW_HEIGHT
    );
    glutCreateWindow(NULL);

    glutDisplayFunc(render);
    glutMainLoop();

    return 0;
}
