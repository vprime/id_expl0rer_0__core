

#include "renderer.cpp"
#include <engine/app.h>

app::app mainApp;

void timer_cb ( int value )
{
    /* Function called at regular intervals to update the positions of the points */

    /* Set the next timed callback */
    glutTimerFunc ( 30, timer_cb, 0 ) ;

    glutPostRedisplay () ;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    if (Args(argc, argv) == GL_FALSE) {
        exit(1);
    }

    glutInitWindowPosition(0, 0); glutInitWindowSize( 300, 300);

    windType = (rgb) ? GLUT_RGB : GLUT_INDEX;
    windType |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;
    glutInitDisplayMode(windType);

    if (glutCreateWindow("Bitmap Test") == GL_FALSE) {
        exit(1);
    }

    InitMap();

    Init();

    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Key);
    glutDisplayFunc(Draw);

    mainApp = new app::app();

    glutTimerFunc ( 30, timer_cb, 0 ) ;

    glutMainLoop();
    return 0;
}
