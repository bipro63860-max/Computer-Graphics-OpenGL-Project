#include <windows.h>
#include <GL/glut.h>
#include <cmath>


#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


#define PI 3.1416




float angle = 240.0f;
bool running = true;
bool soundOn = true;


void idle()

{
    if (running)
    {
        angle += 0.0005f;  // slow smooth rotation speed
        if (angle > 360.0f) angle -= 360.0f;
    }

    glutPostRedisplay();
}


void reshape(GLsizei width, GLsizei height)

{
    if (height == 0) height = 1;

    float aspect = (float)width / height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float size = 190.0f;

    if (width >= height)
    {
        gluOrtho2D(-size * aspect, size * aspect, -size, size);
    }
    else
    {
        gluOrtho2D(-size, size, -size / aspect, size / aspect);
    }

    glMatrixMode(GL_MODELVIEW);
}




void Timer(int value)
{
   glutPostRedisplay();
   glutTimerFunc(16, Timer, 0);
}




void keyboard(unsigned char key, int x, int y)
{
    // Exit
    if (key == 'e' || key == 'E')
    {
        exit(0);
    }

    // Pause / Resume
    if (key == ' ' )
    {

        running = !running;


        if (!running)
        {
                        PlaySound(NULL, NULL, 0); //if paused then sound off


            MessageBox(
                NULL,
                "Press SPACE to continue",
                "Paused",
                MB_OK
            );
        }

        else {PlaySound(// if click space than sound on
                "music.wav",
                NULL,
                SND_FILENAME | SND_ASYNC | SND_LOOP
            );

            }
    }

    // Sound on/off
    if (key == 'm' || key == 'M'  )
    {
        soundOn = !soundOn;

        if (soundOn)
        {
            PlaySound(
                "music.wav",
                NULL,
                SND_FILENAME | SND_ASYNC | SND_LOOP
            );
        }
        else
        {
            PlaySound(NULL, NULL, 0);
        }
    }
}




void drawText(const char* text, float x, float y)


{
    glRasterPos2f(x, y);

    for (int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,
                            text[i]);
    }
}






void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float SIZE = 1.20f;






// Galaxy 1

glPushMatrix();


glTranslatef(-290.0f, 120.0f, 0.0f);

glRotatef(angle * 1.1f * 57.2958f, 0.0f, 0.0f, 1.0f);

glScalef(0.3f, 0.3f, 1.0f);

glBegin(GL_POINTS);

for (int i = 0; i < 400; i++)
{
    float t = i * 0.12f;

    float r = 20 + (i % 140);

    float x = r * cos(t);
    float y = r * sin(t);

    float core = 1.0f - (r / 160.0f);
    float glow = 0.9f + core * 0.6f;

glColor3f(glow,
          glow * 0.9f,
          glow * 0.2f);

    glVertex2f(x, y);
}

glEnd();

glColor3f(1,1,1);
drawText("Andromeda Galaxy", 130, 130);

glPopMatrix();





// Galaxy 2 (same calculation + transformation)

glPushMatrix();

// move galaxy
glTranslatef(270.0f, -120.0f, 0.0f);

// rotate whole galaxy
glRotatef(-angle * 63.0f, 0.0f, 0.0f, 1.0f);

// scale galaxy
glScalef(3.0f, 3.0f, 1.0f);

glBegin(GL_POINTS);

for (int i = 0; i < 1000; i++)
{
    float t = i * 0.14f;

    float r = 25 + (i % 150);

    // same galaxy shape calculation
    float x = r * cos(t);
    float y = r * sin(t);

    float core = 1.0f - (r / 170.0f);
    float glow = 0.25f + core * 0.55f;

    glColor3f(glow, glow * 0.8f, glow * 0.9f);

    glVertex2f(x, y);
}

glEnd();

glColor3f(1,1,1);
drawText("Milky Way Galaxy", 10,10);

glPopMatrix();








//  Galaxy 3

glPushMatrix();

// move galaxy base position
glTranslatef(290.0f, 160.0f, 0.0f);
// rotation (same spin effect)
glRotatef(angle * 1.1f * 57.2958f, 0.0f, 0.0f, 1.0f);

// optional scale
glScalef(0.1f, 0.1f, 1.0f);

glBegin(GL_POINTS);

for (int i = 0; i < 400; i++)
{
    float t = i * 0.12f;

    float r = 20 + (i % 140);

    // same spiral structure (unchanged)
    float x = r * cos(t);
    float y = r * sin(t);

    float core = 1.0f - (r / 160.0f);
    float glow = 0.9f + core * 0.1f;

    glColor3f(glow * 0.6f,
              glow * 0.7f,
              glow);

    glVertex2f(x, y);
}

glEnd();

glColor3f(1,1,1);
drawText("LMC", 140, 140);

glPopMatrix();




//Galaxy4


glPushMatrix();

// move galaxy base position
glTranslatef(-280.0f, -150.0f, 0.0f);
// rotation (same spin effect)
glRotatef(angle * 1.1f * 57.2958f, 0.0f, 0.0f, 1.0f);

// optional scale
glScalef(0.05f, 0.05f, 1.0f);

glBegin(GL_POINTS);

for (int i = 0; i < 400; i++)
{
    float t = i * 0.12f;

    float r = 20 + (i % 140);

    // same spiral structure (unchanged)
    float x = r * cos(t);
    float y = r * sin(t);

    float core = 1.0f - (r / 160.0f);
    float glow = 0.9f + core * 0.1f;

    glColor3f(glow * 0.6f,
              glow * 0.7f,
              glow);

    glVertex2f(x, y);
}

glEnd();

glColor3f(1,1,1);
drawText("SMC", 222, 222);

glPopMatrix();





//  BLACK HOLE 2


glPushMatrix();

// position
glTranslatef(280.0f, -120.0f, 0.0f);

//  rotation
glRotatef(angle * 2.0f * 57.2958f,
          0, 0, 1);
          glScalef(0.7,0.7,1.0f);

//  wide glowing ring

glColor3f(1.0f, 0.8f, 0.1f);

glBegin(GL_LINE_LOOP);

for (int i = 0; i < 400; i++)
{
    float t = 2 * PI * i / 400;

    glVertex2f(35 * cos(t),
               14 * sin(t));
}

glEnd();



//  inner glow ring

glColor3f(1.0f, 0.6f, 0.0f);

glBegin(GL_LINE_LOOP);

for (int i = 0; i < 400; i++)
{
    float t = 2 * PI * i / 400;

    glVertex2f(24 * cos(t),
               10 * sin(t));
}

glEnd();

//  black core

glColor3f(0.0f, 0.0f, 0.0f);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 400; i++)
{
    float t = 2 * PI * i / 400;

    glVertex2f(12 * cos(t),
               12 * sin(t));
}

glEnd();



glPopMatrix();



//  BLACK HOLE 1


glPushMatrix();

// position
glTranslatef(-300.0f, 0.0f, 0.0f);

// rotation
glRotatef(-angle * 2.0f * 57.2958f,
          0, 0, 1);

//  glowing ring

glColor3f(0.4f, 0.2f, 0.8f);

glBegin(GL_LINE_LOOP);

for (int i = 0; i < 300; i++)
{
    float t = 2 * PI * i / 300;

    glVertex2f(20 * cos(t),
               8 * sin(t));
}

glEnd();

//  dark core

glColor3f(0.0f, 0.0f, 0.0f);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 300; i++)
{
    float t = 2 * PI * i / 300;

    glVertex2f(10 * cos(t),
               10 * sin(t));
}

glEnd();

glColor3f(1,1,1);
drawText("Black Hole", 15, 15);

glPopMatrix();




    // Star System
static float starX[1500], starY[1500];
static bool first = true;

if (first)
{
    for (int i = 0; i < 1500; i++)
    {
        starX[i] = (rand() % 1200 - 600);
        starY[i] = (rand() % 1200 - 600);
    }
    first = false;
}

glPushMatrix();

glPointSize(2);
glBegin(GL_POINTS);

for (int i = 0; i < 1600; i++)
{
    float glow = 0.4f + 0.6f * sinf(angle * 0.01f + i);

    glColor3f(glow, glow, glow);

    glVertex2f(starX[i], starY[i]);
}

glEnd();

glPopMatrix();

// METEOROIDS

glPushMatrix();

// optional transformations
glRotatef(angle * 0.3f, 0, 0, 1);
glTranslatef(180.0f, 0.0f, 0.0f);
glScalef(1.0f, 1.0f, 1.0f);

glPointSize(3);

glBegin(GL_POINTS);

for (int i = 0; i < 80; i++)
{
    float t = angle * 0.2f + i;

float r = 120 + (i % 300);
    // same calculation
    float x = r * cos(t);
    float y = r * sin(t);

    glColor3f(0.9f, 0.9f, 0.9f);

    glVertex2f(x, y);
}

glEnd();

glPopMatrix();







//  ELLIPSE ORBITS


float orbit[] =
{
    35+10,45+10,60+10, 80+10,
    125+10, 150+10, 170+10,
    195+10, 215+10, 235+10,265+10
};

glPushMatrix();

glColor3f(0.2f, 0.2f, 0.25f);

for (int j = 0; j < 11; j++)
{
    glPushMatrix();

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 300; i++)
    {
        float t = 2 * PI * i / 300;

        // ellipse orbit
        float x = orbit[j] * cos(t);
        float y = orbit[j] * 0.6f * sin(t);

        glVertex2f(x, y);
    }

    glEnd();

    glPopMatrix();
}

glPopMatrix();




// ASTEROID BELT
// =========================

glPushMatrix();

// optional transformations
glTranslatef(0.0f, 0.0f, 0.0f);
glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
glScalef(1.0f, 1.0f, 1.0f);

glPointSize(2);

glBegin(GL_POINTS);

float inner = orbit[3] + 7;   // outside Mars
float outer = orbit[4] - 13;   // before Jupiter

for (int i = 0; i < 1500; i++)
{
    float a = (rand() % 360) * PI / 180.0f;

    float r =
        inner +
        (rand() % 1000) / 1000.0f * (outer - inner);

    // same asteroid calculation

float x = r * cos(a);
float y = r * 0.6f * sin(a);

glVertex2f(x, y);

    float shade =
        0.3f + (rand() % 50) / 100.0f;

    glColor3f(
        shade,
        shade * 0.9f,
        shade * 0.8f
    );

    glVertex2f(x, y);
}

glEnd();

glColor3f(1,1,1);
drawText("Asteroid Belt", 50, 50);

glPopMatrix();




//  KUIPER  BELT


glPushMatrix();

// optional transformations
glTranslatef(0.0f, 0.0f, 0.0f);
glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
glScalef(1.0f, 1.0f, 1.0f);

glPointSize(2);

glBegin(GL_POINTS);

float inner2 = orbit[9] ;   // outside Mars
float outer2 = orbit[10] ;   // before Jupiter

for (int i = 0; i < 3000; i++)
{
    float a = (rand() % 360) * PI / 180.0f;

    float r =
        inner2 +
        (rand() % 1000) / 1000.0f * (outer2 - inner2);

    // same asteroid calculation

float x = r * cos(a);
float y = r * 0.6f * sin(a);

glVertex2f(x, y);

    float shade =
        0.3f + (rand() % 50) / 100.0f;

    glColor3f(
        shade,
        shade * 0.9f,
        shade * 0.8f
    );

    glVertex2f(x, y);
}

glEnd();


glColor3f(1,1,1);
drawText("Kuiper Belt", 130, 130);

glPopMatrix();






//  SUN
glPushMatrix();

//  SUN BODY

glColor3f(1.0f, 0.6f, 0.1f);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0.0f, 0.0f);

for (int i = 0; i <= 100; i++)
{
    float t = 2 * PI * i / 100;

    float x = 17 * cos(t);
    float y = 17 * sin(t);

    glVertex2f(x, y);
}

glEnd();

// SIMPLE FLAMES

glColor3f(1.0f, 0.8f, 0.2f);

glBegin(GL_LINES);

for (int i = 0; i < 80; i++)
{
    float t = 2 * PI * i / 40;

    float flicker = 2.0f + (rand() % 222) / 80.0f;

    float x1 = 17 * cos(t);
    float y1 = 17 * sin(t);

    float x2 = (17 + flicker) * cos(t);
    float y2 = (17 + flicker) * sin(t);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
}

glEnd();


glColor3f(1,1,1);
drawText("Sun", 15, 15);

glPopMatrix();





// Mercury

  glPushMatrix();


  float t0 = angle * 4.0f;

glTranslatef(
    orbit[0] * cos(t0),
    orbit[0] * 0.6f * sin(t0),
    0
);


glColor3f(0.6, 0.6, 0.6);

glBegin(GL_TRIANGLE_FAN);

// center
glVertex2f(0, 0);

for (int i = 0; i <= 60; i++)
{
    float t = 2 * PI * i / 60;

    glVertex2f(2.4 * SIZE * cos(t),
               2.4 * SIZE * sin(t));
}

glEnd();

glColor3f(1,1,1);
drawText("Mercury", 6, 6);


glPopMatrix();




//  Venus

glPushMatrix();

float t1 = angle * 3.0f;

glTranslatef(
    orbit[1] * cos(t1),
    orbit[1] * 0.6f * sin(t1),
    0
);

glColor3f(0.95, 0.75, 0.4);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 70; i++)
{
    float t = 2 * PI * i / 70;

    glVertex2f(3.4 * SIZE * cos(t),
               3.4 * SIZE * sin(t));
}

glEnd();

glColor3f(1,1,1);
drawText("Venus", 6, 6);


glPopMatrix();





//  Earth

glPushMatrix();

float t2 = angle * 2.0f;

glTranslatef(
    orbit[2] * cos(t2),
    orbit[2] * 0.6f * sin(t2),
    0
);

// EARTH
glColor3f(0.2, 0.5, 0.9);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 90; i++)
{
    float t = 2 * PI * i / 90;

    glVertex2f(3.8 * SIZE * cos(t),
               3.8 * SIZE * sin(t));
}

glEnd();


glColor3f(1,1,1);
drawText("Earth", 8, 8);


//  MOON
glRotatef(angle * 6.0f * 57.2958f, 0, 0, 1);
glTranslatef(10.0f, 0, 0);

glColor3f(0.9, 0.9, 0.9);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 80; i++)
{
    float t = 2 * PI * i / 80;

    glVertex2f(2.2 * SIZE * cos(t),
               2.2 * SIZE * sin(t));
}

glEnd();

glColor3f(1,1,1);
drawText("Moon", 6, 6);

glPopMatrix();






//  Mars
 glPushMatrix();

float t3 = angle * 1.6f;

glTranslatef(
    orbit[3] * cos(t3),
    orbit[3] * 0.6f * sin(t3),
    0
);

glColor3f(0.85, 0.3, 0.2);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 70; i++)
{
    float t = 2 * PI * i / 70;

    glVertex2f(3.0 * SIZE * cos(t),
               3.0 * SIZE * sin(t));
}

glEnd();
glColor3f(1,1,1);
drawText("Mars", 8, 8);

glPopMatrix();



//  Jupiter

glPushMatrix();

float t4 = angle * 1.2f;

glTranslatef(
    orbit[4] * cos(t4),
    orbit[4] * 0.6f * sin(t4),
    0
);

glColor3f(0.95, 0.85, 0.65);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 130; i++)
{
    float t = 2 * PI * i / 130;

    glVertex2f(9.0 * SIZE * cos(t),
               9.0 * SIZE * sin(t));
}

glEnd();

glColor3f(1,1,1);
drawText("Jupiter", 12, 12);

glPopMatrix();




// SATURN (REALISTIC)

glPushMatrix();

//  orbit around sun


float t5 = angle * 1.0f;

glTranslatef(
    orbit[5] * cos(t5),
    orbit[5] * 0.6f * sin(t5),
    0
);

//  SATURN ASTEROID RING

glPushMatrix();

// slow ring rotation
glRotatef(angle * 2.0f * 57.2958f,
          0, 0, 1);

glPointSize(2);

glBegin(GL_POINTS);

for (int i = 0; i < 5000; i++)
{
    // random angle
    float t =
    (rand() % 360) * PI / 180.0f;

    // ring width
    float r =
    14.0f +
    (rand() % 700) / 100.0f;

    // ellipse ring shape
    float x =
    r * SIZE * cos(t);

    float y =
    (r - 5.0f) * SIZE * sin(t);

    // realistic dusty color
float base = 0.78f;
float noise = (rand() % 15) / 100.0f;

float shade = base + noise;

// light ash / dusty grey tone
glColor3f(shade * 0.85f,
          shade * 0.85f,
          shade * 0.88f);

    glVertex2f(x, y);
}

glEnd();

glPopMatrix();

// SATURN BODY


glColor3f(0.92f, 0.84f, 0.62f);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 200; i++)
{
    float t = 2 * PI * i / 200;

    glVertex2f(7.0f * SIZE * cos(t),
               7.0f * SIZE * sin(t));
}

glEnd();




glColor3f(1,1,1);
drawText("Saturn", 22, 22);

glPopMatrix();




//  Uranus

  glPushMatrix();

float t6 = angle * 0.8f;

glTranslatef(
    orbit[6] * cos(t6),
    orbit[6] * 0.6f * sin(t6),
    0
);

glColor3f(0.6, 0.9, 0.9);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 90; i++)
{
    float t = 2 * PI * i / 90;

    glVertex2f(6.0 * SIZE * cos(t),
               6.0 * SIZE * sin(t));
}

glEnd();

glColor3f(1,1,1);
drawText("Uranus", 10, 10);

glPopMatrix();




//  Neptune

glPushMatrix();

float t7 = angle * 0.6f;

glTranslatef(
    orbit[7] * cos(t7),
    orbit[7] * 0.6f * sin(t7),
    0
);

glColor3f(0.1, 0.3, 0.85);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 90; i++)
{
    float t = 2 * PI * i / 90;

    glVertex2f(5.8 * SIZE * cos(t),
               5.8 * SIZE * sin(t));
}

glEnd();

glColor3f(1,1,1);
drawText("Neptune", 9, 9);

glPopMatrix();




//  Pluto
glPushMatrix();

float t8 = angle * 0.4f;

glTranslatef(
    orbit[8] * cos(t8),
    orbit[8] * 0.6f * sin(t8),
    0
);

glColor3f(0.65, 0.65, 0.7);

glBegin(GL_TRIANGLE_FAN);

glVertex2f(0, 0);

for (int i = 0; i <= 70; i++)
{
    float t = 2 * PI * i / 70;

    glVertex2f(2.0 * SIZE * cos(t),
               2.0 * SIZE * sin(t));
}

glEnd();

glColor3f(1,1,1);
drawText("Pluto", 8, 8);

glPopMatrix();







    glutSwapBuffers();
}

void init() {
    glClearColor(0,0,0,0); // Background color

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);


    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Solar System");
glutFullScreen();
    init();

    //sound ans ssetting linker add winmm
PlaySound(
    "C:\\Users\\bipro\\OneDrive\\Desktop\\Computer Graphics\\GL\\Lab1\\music.wav",
    NULL,
    SND_FILENAME | SND_ASYNC | SND_LOOP
);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutTimerFunc(3, Timer, 0);      // keeps animation running
glutKeyboardFunc(keyboard);// for keyboard fung
glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
