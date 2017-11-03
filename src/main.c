#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define MAP_LENGTH 100
#define NODES_PER_LINE 10
#define WIDTH 10
#define HEIGHT 10
#define MINIMUM -3
#define MAXIMUM 3

#define SQUARE_DIMENSION 0.1f
#define MAP_HALF_DIMENSION 0.5f

extern void get_map(
    int8_t* map,
    uint8_t width,
    uint8_t height,
    uint8_t minimum,
    uint8_t maximum
);

/* TODO: #7 no way found to get this variable from render()
 * if not declared at global; glutDisplayFunc()
 * does not provide any additional parameter */
int8_t map[MAP_LENGTH];

/**
 * @brief renders the scene
 */
void render() {

    float x_position = -MAP_HALF_DIMENSION;
    float z_position = -MAP_HALF_DIMENSION;

    /* clear the whole content of the current enabled buffer */
    glClear(GL_COLOR_BUFFER_BIT);

    /* TODO: must be documented */
    glLoadIdentity();

    gluLookAt(
        0.2f,
        0.3f,
        -0.05f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        1.0f,
        0.0f
    );

    for (
        unsigned int j = 0;
        j < NODES_PER_LINE;
        j += 1
    ) {

        glBegin(GL_LINE_STRIP);

        for (
            unsigned int i = 0;
            i < NODES_PER_LINE;
            i += 1
        ) {
            glVertex3f(
                x_position,
                SQUARE_DIMENSION * map[j * NODES_PER_LINE + i],
                z_position
            );

            x_position += SQUARE_DIMENSION;
        }

        glEnd();

        z_position += SQUARE_DIMENSION;
        x_position = -MAP_HALF_DIMENSION;
    }

    x_position = -MAP_HALF_DIMENSION;
    z_position = -MAP_HALF_DIMENSION;

    for (
        unsigned int j = 0;
        j < NODES_PER_LINE;
        j += 1
    ) {

        glBegin(GL_LINE_STRIP);

        for (
            unsigned int i = 0;
            i < NODES_PER_LINE;
            i += 1
        ) {
            glVertex3f(
                x_position,
                SQUARE_DIMENSION * map[i * NODES_PER_LINE + j],
                z_position
            );

            z_position += SQUARE_DIMENSION;
        }

        glEnd();

        x_position += SQUARE_DIMENSION;
        z_position = -MAP_HALF_DIMENSION;
    }

    glFlush();
}

/**
 * @brief program starting function
 */
int main(int argc, char* argv[]) {

    /* TODO: #5 check how to pass parameters to the program
     * in order to have a grid with dimensions;
     * for now, it throws a segmentation fault when initializing glut */

    get_map(
        map,
        WIDTH,
        HEIGHT,
        MINIMUM,
        MAXIMUM
    );

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
