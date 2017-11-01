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

    float x_position = -0.5f;
    float z_position = -0.5f;

    /* clear the whole content of the current enabled buffer */
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);

        for (
            unsigned int i = 0;
            i < MAP_LENGTH;
            i += 1
        ) {
            glVertex3f(
                x_position,
                0.1f * map[i],
                z_position
            );

            x_position += 0.1f;

            if (
                i % NODES_PER_LINE == 0 &&
                i != 0
            ) {
                z_position += 0.1f;
                x_position = -0.5f;
            }
        }

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
