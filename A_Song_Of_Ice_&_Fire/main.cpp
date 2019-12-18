#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include <windows.h>
#include <GL/glut.h>
#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle,ang=0.0,angd=0.0,el=-100,er=100,mouseX,mouseY,time=0.0,time2=0.0;
double g=175,incx=50, incy,sx=-80,sy=80,xj=0,jy1=0,nx=15.6,n1=0.02,ny=-10,gl=400,ice=0,m=70,dx=0,dx2=170,dx3=180,d2=170,d3=180,dy=-57,jl=-73.6,jr=-55,ju,jd=-57,nl=100.8,nu=-30,lx=0,ly=0,qf=-55;
int state,score=0,fire1=0,jump1=0,sc=0,level=0,n=0,go=0;
bool mclick=false;
struct point
{
	double x,y,z;
};
struct point pos,l,u,r;
double X=0,Z=0;
int Y=-1;
struct point arra[100];

const int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;

void drawAxes()
{

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
}


void drawGrid()
{
	int i;

    glColor3f(0.6, 0.6, 0.6);	//grey
    glBegin(GL_LINES);{
        for(i=-8;i<=8;i++){

            if(i==0)
                continue;	//SKIP the MAIN axes

            //lines parallel to Y-axis
            glVertex3f(i*10, -90, 0);
            glVertex3f(i*10,  90, 0);

            //lines parallel to X-axis
            glVertex3f(-90, i*10, 0);
            glVertex3f( 90, i*10, 0);
        }
    }glEnd();

}

void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,2);
		glVertex3f( a,-a,2);
		glVertex3f(-a,-a,2);
		glVertex3f(-a, a,2);
	}glEnd();
}


void drawCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();
}

void halfCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();
}

void rec_animation()
{
    glColor3f(0,1,0);
    glRotatef(5*angle,0,0,1);
    glTranslatef(incx,incy,0);
    glRotatef(5*angle,0,0,1);
    drawSquare(5);

}
void draw_rec()
{
    //glColor3f(0,1,0);
    drawSquare(5);

}


void mountain()
{
    glBegin(GL_TRIANGLES);{
		glColor3f(1,1,1);
		glVertex3f( -100, 30,0);
        glColor3f(0.27,0.27,0.27);
		glVertex3f( -50,30,0);
		glColor3f(1,1,1);
		glVertex3f(-70,40,0);
	}glEnd();
}

void flag()
{
     glPushMatrix();
        glColor3f(0.27,0,0.27);
        glTranslatef(-10,40,0);
        glScaled(0.05,1,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.27,0,0.27);
        glBegin(GL_TRIANGLES);{
		glColor3f(1,1,1);
		glVertex3f( -9.75, 41,0);
        glColor3f(0.17,0.17,0.27);
		glVertex3f( 0,44,0);
		glColor3f(0,0,0);
		glVertex3f(-9.75,45,0);
	}glEnd();

    glPopMatrix();
}


void snow()
{
         glPushMatrix();
        glTranslatef(sx,sy,0);
        glColor3f(1,1,1);
        drawCircle(0.75,0.75);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx,sy+30,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx,sy,0);
        glColor3f(1,1,1);
        drawCircle(0.65,0.65);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+10,sy+20,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+10,sy-10,0);
        glColor3f(1,1,1);
        drawCircle(0.65,0.65);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+10,sy+20,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+20,sy-15,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+20,sy+35,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+30,sy+10,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+30,sy+50,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+40,sy-20,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+45,sy+30,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+45,sy+20,0);
        glColor3f(1,1,1);
        drawCircle(0.65,0.65);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+50,sy-30,0);
        glColor3f(1,1,1);
        drawCircle(0.75,0.75);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+55,sy+20,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+60,sy+5,0);
        glColor3f(1,1,1);
        drawCircle(0.65,0.65);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+65,sy+45,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+70,sy+13,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+77,sy+33,0);
        glColor3f(1,1,1);
        drawCircle(0.65,0.65);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+80,sy-20,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+85,sy+20,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+90,sy-5,0);
        glColor3f(1,1,1);
        drawCircle(0.65,0.65);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+100,sy-17,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+105,sy+25,0);
        glColor3f(1,1,1);
        drawCircle(0.75,0.75);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+110,sy,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+120,sy+10,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+130,sy,0);
        glColor3f(1,1,1);
        drawCircle(0.75,0.75);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+140,sy-5,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+144,sy+25,0);
        glColor3f(1,1,1);
        drawCircle(0.5,0.5);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(sx+150,sy+10,0);
        glColor3f(1,1,1);
        drawCircle(0.75,0.75);
        glPopMatrix();
}

void sky()
{
    glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3f(0.69, 0.87, 0.88);
        glVertex2f(100, 30);
        glColor3f(0.0, 0.74, 1.0);
        glVertex2f(100, 85);
        glColor3f(0.68, 0.93, 0.93);
        glVertex2f(-100, 85);
        glColor3f(0.0, 0.74, 1.0);
        glVertex2f(-100, 30);
        glEnd();
        glPopMatrix();
}
void mountains()
{
    glPushMatrix();
        mountain();
         glPushMatrix();
        glTranslatef(m,-12,0);
        glScaled(1.4,1.5,0);
        mountain();
        glPopMatrix();
         glPushMatrix();
        glTranslatef(m+60,-15,0);
        glScaled(1.4,1.5,0);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(m-50,-12,0);
        glScaled(1,1.4,0);
        mountain();
        glPopMatrix();
         glPushMatrix();
        glTranslatef(m-25,0,0);
        glScaled(1.4,1,0);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(m-30,0,0);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(m+30,0,0);
        glScaled(1.4,1,0);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(100,0,0);
        glScaled(1.4,1,0);
        mountain();
        glPopMatrix();
         glPushMatrix();
        glTranslatef(m+115,-45,0);
        glScaled(1.5,2.5,0);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(185,-45,0);
        glScaled(1.5,2.5,0);
        mountain();
        glPopMatrix();
        glPopMatrix();
        glPushMatrix();
        mountain();
        glPopMatrix();
}

void nightsky()
{
    glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3f(0.18,0.18,0.18);
        glVertex2f(100, -85);
        glColor3f(0,0,0);
        glVertex2f(100, 85);
        glColor3f(0.12, 0.12, 0.12);
        glVertex2f(80, 85);
        glColor3f(0,0,0);
        glVertex2f(-100, 85);
        glColor3f(0.18,0.18,0.18);
        glVertex2f(-100, -85);
        glEnd();
        glPopMatrix();
}

void back()
{


        glPushMatrix();
        glTranslatef(m-125,0,0);
        flag();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(m-20,0,0);
        flag();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(m+20,20,0);
        flag();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(155,20,0);
        flag();
        glPopMatrix();
        glPushMatrix();
        flag();
        glPopMatrix();

        //mountain
        mountains();

        snow();
}
void icestone()
{
     glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(ice,-75,0);
        glScaled(0.3,0.5,1);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(ice-20,-75,0);
        glScaled(0.3,0.5,1);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(ice+50,-75,0);
        glScaled(0.3,0.5,1);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(ice+90,-75,0);
        glScaled(0.3,0.5,1);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(ice+93,-72,0);
        glScaled(0.2,0.4,1);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(ice-65,-75,0);
        glScaled(0.3,0.5,1);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(0,-25,0);
        glScaled(0.3,0.5,1);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(60,-45,0);
        glScaled(0.3,0.4,1);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(65,-50,0);
        glScaled(0.3,0.5,1);
        mountain();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.93,0.91,0.91);
        glTranslatef(-60,-15,0);
        glScaled(0.3,0.5,1);
        mountain();
        glPopMatrix();
}
void background()
{

       //iceground
        glPushMatrix();
            //glTranslatef(-50,-56,0);
            glRotatef(10,0,0,1);
            glColor3f(0.80,0.78,0.80);
            drawCircle(400,53);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-50,-56,0);
            glRotatef(10,0,0,1);
            glColor3f(0.80,0.78,0.80);
            drawCircle(400,53);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0,-30,0);
            glRotatef(-4,0,0,1);
            glColor3f(0.93,0.91,0.91);
            drawCircle(400,50);
        glPopMatrix();
        //stone
        glPushMatrix();
        glTranslatef(0,-30,0);
            glRotatef(-4,0,0,1);
            glColor3f(0.80,0.78,0.80);
            drawCircle(180,50);
        glPopMatrix();
         glPushMatrix();
        glTranslatef(0,-30,0);
            glRotatef(-4,0,0,1);
            glColor3f(0.93,0.91,0.91);
            drawCircle(120,50);
        glPopMatrix();
         glPushMatrix();
        glTranslatef(0,-30,0);
            glRotatef(16,0,0,1);
            glColor3f(0.93,0.91,0.91);
            drawCircle(90,45);
        glPopMatrix();
        //path
        glPushMatrix();
            //glColor3f(0.93,0.91,0.91);
            glBegin(GL_POLYGON);
        glColor3f(0.41,0.41,0.41);
        glVertex2f(gl, -60);
        glColor3f(0.41,0.41,0.41);
        glVertex2f(gl-600, -60);
        glColor3f(1,1,1);
        glVertex2f(gl-600, -90);
        glColor3f(1,1,1);
        glVertex2f(gl, -90);
        glEnd();
        glPopMatrix();
        //ice
        icestone();
        sky();
        back();
        //sky


}


void johnsnow()
{



    //shrug
    glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3f(0.27,0.27,0.27);
        glVertex2f(-8, 7);
        glColor3f(0.27,0.27,0.27);
        glVertex2f(-10, 7);
        glColor3f(0.41,0.41,0.41);
        glVertex2f(-12, -5);
        glColor3f(0,0,0);
        glVertex2f(-13, -7);
        glColor3f(0,0,0);
        glVertex2f(-15,-12);
        glColor3f(0.27,0.27,0.27);
        glVertex2f(-17, -40);
       glColor3f(0.27,0.27,0.27);
        glVertex2f(-19, -40);
        glColor3f(0.27,0.27,0.27);
        glVertex2f(0, -35);
        glColor3f(0,0,0);
        glVertex2f(15, -38);
        glColor3f(0.27,0.27,0.27);
        glVertex2f(17, -37);
        glColor3f(0.27,0.27,0.27);
        glVertex2f(22, -34);
        glColor3f(0,0,0);
        glVertex2f(20, -32);
        glColor3f(0.27,0.27,0.27);
        glVertex2f(17, -30);
        glColor3f(0.27,0.27,0.27);
        glVertex2f(19, -30);
        glColor3f(0.27,0.27,0.27);
        glVertex2f(21, -32);
        glColor3f(0,0,0);
        glVertex2f(12, 0);
        glEnd();

    glPopMatrix();
    //face
    glPushMatrix();
        glColor3f(1,0.87,0.67);
        glTranslatef(0,18,0);
        glScaled(2,3,0);
        drawCircle(5,5);
    glPopMatrix();
    //eyes
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(3.75,18,0);
        drawCircle(1,1);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-3.75,18,0);
        drawCircle(1,1);
    glPopMatrix();
    //darkcircle
    glPushMatrix();
        glColor3f(0.93,0.77,0.56);
        glTranslatef(3.75,17,0);
        glRotated(180,0,0,1);
        glScaled(1.4,0.8,0);
        halfCircle(1.5,1);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.93,0.77,0.56);
        glTranslatef(-3.75,17,0);
        glRotated(180,0,0,1);
        glScaled(1.4,0.8,0);
        halfCircle(1.5,1);
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLES);{
		glColor3f(0,0,0);
		glVertex3f( -7, 18,0);
		glVertex3f( -1,18,0);
		glVertex3f(-3,19,0);
	}glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_TRIANGLES);{
		glColor3f(0,0,0);
		glVertex3f( 7, 18,0);
		glVertex3f( 1,18,0);
		glVertex3f(3,19,0);
	}glEnd();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(4,19.5,0);
        glRotated(-8,0,0,1);
        glScaled(0.5,0.09,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-4,19.5,0);
        glRotated(8,0,0,1);
        glScaled(0.5,0.09,0);
        draw_rec();
    glPopMatrix();

    //nose
    glPushMatrix();
        glColor3f(0.93,0.77,0.56);
        glTranslatef(0,15,0);
        glRotated(180,0,0,1);
        glScaled(0.2,0.4,0);
        draw_rec();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.80,0.40,0.27);
        glTranslatef(-1.75,13.5,0);
        halfCircle(1,0.5);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.80,0.40,0.27);
        glTranslatef(1.75,13.5,0);
        halfCircle(1,0.5);
    glPopMatrix();

    //moustache
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-1,12,0);
        glRotated(-27,0,0,1);
        glScaled(0.3,0.15,0);
        draw_rec();
    glPopMatrix();
     glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(1,12,0);
        glRotated(27,0,0,1);
        glScaled(0.3,0.15,0);
        draw_rec();
    glPopMatrix();

     glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-3.25,10,0);
        glRotated(-37,0,0,1);
        glScaled(0.15,0.6,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(3.25,10,0);
        glRotated(37,0,0,1);
        glScaled(0.15,0.6,0);
        draw_rec();
    glPopMatrix();


    //lips
    glPushMatrix();
        glColor3f(0.93,0.38,0.38);
        glTranslatef(-0.5,9.5,0);
        glRotated(-27,0,0,1);
        glScaled(0.15,0.09,0);
        draw_rec();
    glPopMatrix();
     glPushMatrix();
        glColor3f(0.93,0.38,0.38);
        glTranslatef(0.5,9.5,0);
        glRotated(27,0,0,1);
        glScaled(0.15,0.09,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.93,0.38,0.38);
        glTranslatef(-1.25,9.25,0);
        glRotated(-50,0,0,1);
        glScaled(0.05,0.2,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.93,0.38,0.38);
        glTranslatef(1.25,9.25,0);
        glRotated(50,0,0,1);
        glScaled(0.05,0.2,0);
        draw_rec();
    glPopMatrix();

     //hair

     glPushMatrix();
         glColor3f(0,0,0);
        glTranslatef(5,28,0);
        glRotated(-35,0,0,1);
        glScaled(1,0.7,0);
        halfCircle(8,8);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-5,28,0);
        glRotated(35,0,0,1);
        glScaled(1,0.7,0);
        halfCircle(8,8);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(3,29.5,0);
        glScaled(1.2,0.5,0);
        draw_rec();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-4,26.5,0);
        glRotated(-7,0,0,1);
        halfCircle(6,6);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-12,18,0);
        glScaled(0.6,1.7,0);
        draw_rec();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(12,18,0);
        glScaled(0.6,1.7,0);
        draw_rec();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-12,26,0);
        drawCircle(3.5,3);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(12,26,0);
        drawCircle(3.5,3);
    glPopMatrix();


//hair behind ear
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-15,25,0);
        glRotated(180,0,0,1);
        halfCircle(4,4);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(15,25,0);
        glRotated(180,0,0,1);
        halfCircle(4,4);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(15,25,0);
        glRotated(180,0,0,1);
        halfCircle(4,4);
    glPopMatrix();

    //ear
    glPushMatrix();
        glColor3f(1,0.87,0.67);
        glTranslatef(-11,18,0);
        glRotated(90,0,0,1);
        halfCircle(3,3);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,0.87,0.67);
        glTranslatef(11,18,0);
        glRotated(-90,0,0,1);
        halfCircle(3,3);
    glPopMatrix();

    //right hand
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(14,-5,0);
        glRotated(45,0,0,1);
        glScaled(0.4,1.8,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(12,-5,0);
        glRotated(55,0,0,1);
        glScaled(0.5,1.8,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(23,-6,0);
        glRotated(-55,0,0,1);
        glScaled(0.5,1,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.12,0.12,0.12);
        glTranslatef(28,-2,0);
        drawCircle(3.75,3.5);
    glPopMatrix();




    //halfbody
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(0,-5.5,0);
        glScaled(1.8,1.8,0);
        draw_rec();
    glPopMatrix();



    //rightleg
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(8,-18,0);
        glRotated(35,0,0,1);
        glScaled(0.6,2.1,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(6,-20,0);
        glRotated(45,0,0,1);
        glScaled(0.7,2.1,0);
        draw_rec();
    glPopMatrix();

    glPushMatrix();
        glRotated(angle,0,0,1);
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(12.5,-31,0);
        glScaled(0.75,1.3,0);
        draw_rec();
    glPopMatrix();

    //right-shoe
    glPushMatrix();
        glColor3f(0.12,0.12,0.12);
        glTranslatef(17,-41,0);
        drawCircle(6,3);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(12.5,-40,0);
        glScaled(0.8,0.6,0);
        draw_rec();
        glPopMatrix();

        glPopMatrix();
    //leftleg
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-6,-19,0);
        glRotated(-20,0,0,1);
        glScaled(0.8,1.5,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-4,-20,0);
        glRotated(-25,0,0,1);
        glScaled(0.8,1.5,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
    glRotated(-angle,0,0,1);
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-7,-29,0);
        glRotated(-15,0,0,1);
        glScaled(0.8,1.5,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-8.5,-29,0);
        glScaled(0.75,1.3,0);
        draw_rec();
    glPopMatrix();



    //leftshoe
    glPushMatrix();
    glTranslatef(17,-1.75,0);
    glRotated(-19,0,0,1);
    glPushMatrix();
        glColor3f(0.12,0.12,0.12);
        glTranslatef(-10,-46,0);
        drawCircle(6,3);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-13.5,-44,0);
        glScaled(0.8,0.7,0);
        draw_rec();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

    //lefthand half
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-13,-3,0);
        glRotated(-47,0,0,1);
        glScaled(0.4,1.7,0);
        draw_rec();
    glPopMatrix();
     glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-11,-3,0);
        glRotated(-57,0,0,1);
        glScaled(0.5,1.7,0);
        draw_rec();
    glPopMatrix();

    //cross
    glPushMatrix();
        glColor3f(0.34,0.34,0.34);
        glTranslatef(0,-4,0);
        glRotated(-51,0,0,1);
        glScaled(0.3,2.2,0);
        draw_rec();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.34,0.34,0.34);
        glTranslatef(0,-4,0);
        glRotated(51,0,0,1);
        glScaled(0.3,2.2,0);
        draw_rec();
    glPopMatrix();

    //shoulder
    glPushMatrix();
        glColor3f(0.12,0.12,0.12);
        glTranslatef(-6.5,0,0);
        glScaled(1.8,1.8,0);
        halfCircle(3.3,3.3);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.27,0.27,0.27);
        glTranslatef(-9,2,0);
        glScaled(1.8,1.8,0);
        halfCircle(2.8,2.8);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.12,0.12,0.12);
        glTranslatef(6.5,0,0);
        glScaled(1.8,1.8,0);
        halfCircle(3.3,3.3);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.27,0.27,0.27);
        glTranslatef(9,2,0);
        glScaled(1.8,1.8,0);
        halfCircle(2.8,2.8);
    glPopMatrix();

    //beard
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-6.5,8,0);
        glRotated(42,0,0,1);
        glScaled(0.25,1,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(6.5,8,0);
        glRotated(-42,0,0,1);
        glScaled(0.25,1,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(0,5,0);
        glRotated(90,0,0,1);
        glScaled(0.25,0.6,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(0,7.5,0);
        glRotated(90,0,0,1);
        glScaled(0.1,0.2,0);
        draw_rec();
    glPopMatrix();

    //belt
    glPushMatrix();
        glColor3f(0.54,0.27,0.14);
        glTranslatef(0,-14,0);
        glScaled(1.8,0.4,0);
        draw_rec();
    glPopMatrix();

    //left hand part2


    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-11,-11,0);
        glRotated(58,0,0,1);
        glScaled(0.5,1.5,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.12,0.12,0.12);
        glTranslatef(-5,-14,0);
        drawCircle(3.75,3.5);
    glPopMatrix();

    //sword
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(-2,-15,0);
        glRotated(100,0,0,1);
        glScaled(0.7,0.1,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-12,0,0);
    glRotated(33,0,0,1);
    glBegin(GL_TRIANGLES);{
		glColor3f(1,1,1);
		glVertex3f( 1, -14.5,0);
        glColor3f(0.27,0.27,0.27);
		glVertex3f( 1,-20.5,0);
		glColor3f(0.27,0.27,0.27);
		glVertex3f(60,-12,0);
	}glEnd();
	glPopMatrix();




}


void nightking() {

	glPushMatrix();
	glTranslated(40,-30,0);
	glScaled(0.4,0.4,1);


	//horns
    glPushMatrix();
        //glRotated(180,0,0,1);
        //glTranslated(5,0,0);
        glBegin(GL_TRIANGLES);
            glColor3f(0.69,0.77,0.87);
            glVertex2f(4, 52);
            glColor3f(0.69,0.77,0.87);
            glVertex2f(4.5, 45);
            glColor3f(0.25,0.41,0.88);
            glVertex2f(-4.5, 45);
            //glVertex2f(2, 10);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        //glRotated(180,0,0,1);
        //glTranslated(5,0,0);
        glBegin(GL_TRIANGLES);
            glColor3f(0.69,0.77,0.87);
            glVertex2f(-3, 55);
            glColor3f(0.69,0.77,0.87);
            glVertex2f(0, 45);
            glColor3f(0.25,0.41,0.88);
            glVertex2f(-6.5, 45);
            //glVertex2f(2, 10);
        glEnd();
    glPopMatrix();
    //head
    glPushMatrix();
        glTranslated(0,39,0);
        glColor3f(0.69,0.77,0.87);
        drawCircle(9,10);
    glPopMatrix();



    //right ear
    glPushMatrix();
        glTranslated(10,39,0);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,2);
    glPopMatrix();

    //left ear
    glPushMatrix();
        glTranslated(-10,39,0);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,2);
    glPopMatrix();

    //eyes
    glPushMatrix();
        glTranslated(4,39,0);
        glColor3f(0,0,1);
        drawCircle(3,1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-4,39,0);
        glColor3f(0,0,1);
        drawCircle(3,1);
    glPopMatrix();


    //neck
    glPushMatrix();
        glTranslated(0,20,0);
        glColor3f(0.29,0.44,0.55);
        glScaled(0.7,2,0);
        draw_rec();
    glPopMatrix();

    //right arm
    glPushMatrix();
        glTranslated(18,14,0);
        glRotated(45,0,0,1);
        glColor3f(0.13,0.13,0.13);
        glScaled(0.7,1.8,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glTranslated(33,24,0);
        glColor3f(0.69,0.77,0.87);
        drawCircle(5,5);
    glPopMatrix();
    glPushMatrix();
        glTranslated(33,25,0);
        glRotated(35,0,0,1);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,7);
    glPopMatrix();
    glPushMatrix();
        glTranslated(35,25,0);
        //glRotated(45,0,0,1);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,7);
    glPopMatrix();
    glPushMatrix();
        glTranslated(35,25,0);
        glRotated(-45,0,0,1);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,7);
    glPopMatrix();
    glPushMatrix();
        glTranslated(37,23,0);
        glRotated(-45,0,0,1);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,7);
    glPopMatrix();

     glPushMatrix();
        glTranslated(26,15,0);
        glRotated(-45,0,0,1);
        glColor3f(0.13,0.13,0.13);
        glScaled(0.7,1.8,0);
        draw_rec();
    glPopMatrix();

    //left arm
    glPushMatrix();
        glTranslated(-18,14,0);
        glRotated(-45,0,0,1);
        glColor3f(0.13,0.13,0.13);
        glScaled(0.7,1.8,0);
        draw_rec();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-33,24,0);
        glColor3f(0.69,0.77,0.87);
        drawCircle(5,5);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-33,25,0);
        glRotated(-35,0,0,1);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,7);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-35,25,0);
        //glRotated(45,0,0,1);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,7);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-35,25,0);
        glRotated(45,0,0,1);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,7);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-37,23,0);
        glRotated(45,0,0,1);
        glColor3f(0.69,0.77,0.87);
        drawCircle(2,7);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-26,15,0);
        glRotated(45,0,0,1);
        glColor3f(0.13,0.13,0.13);
        glScaled(0.7,1.8,0);
        draw_rec();
    glPopMatrix();


    //black-belt
    glPushMatrix();
        glTranslated(0,12,0);
        glColor3f(0.13,0.13,0.13);
        glScaled(2,2,0);
        draw_rec();
    glPopMatrix();

    //chest plate
    glPushMatrix();
        glTranslated(9,22,0);
        glRotated(45,0,0,1);
        glScaled(1.2,1.2,0);
        glColor3f(0.34,0.34,0.34);
        draw_rec();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-9,22,0);
        glRotated(-45,0,0,1);
        glScaled(1.2,1.2,0);
        glColor3f(0.34,0.34,0.34);
        draw_rec();
    glPopMatrix();

    //blue-belt
    glPushMatrix();
        glTranslated(0,8,0);
        glColor3f(0.29,0.44,0.55);
        glScaled(2,0.5,0);
        draw_rec();
    glPopMatrix();

    //black-belt
    glPushMatrix();
        glTranslated(0,4,0);
        glColor3f(0.13,0.13,0.13);
        glScaled(2,0.5,0);
        draw_rec();
    glPopMatrix();

    //skirt
    glPushMatrix();
        glTranslated(0,-15,0);
        glColor3f(0.34,0.34,0.34);
        glScaled(4,1,0);
        draw_rec();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-6.5,0);
        glColor3f(0.34,0.34,0.34);
        glScaled(3,1,0);
        draw_rec();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.34,0.34,0.34);
        glScaled(2,0.5,0);
        draw_rec();
    glPopMatrix();

    //skirt's zipper
    glPushMatrix();
        glTranslated(0,-9,0);
        glColor3f(0.29,0.44,0.55);
        glScaled(0.8,2.2,0);
        draw_rec();
    glPopMatrix();

    //leg animation
    glPushMatrix();
    //glRotate(angle,0,0,1);
    glTranslated(lx,ly,0);
    //left-leg
    glPushMatrix();
        glTranslated(-10,-30,0);
        glColor3f(0.13,0.13,0.13);
        glScaled(1,2,0);
        draw_rec();
    glPopMatrix();

    //left-shoe
    glPushMatrix();
        glTranslated(-16,-50,0);
        glBegin(GL_POLYGON);
            glColor3f(0.34,0.34,0.34);
            glVertex2f(10, 10);
            glVertex2f(10, 0);
            glVertex2f(-10, 0);
            glVertex2f(2, 10);
        glEnd();
 glPopMatrix();
 glPopMatrix();
    //right-leg
    glPushMatrix();
        glTranslated(10,-30,0);
        glColor3f(0.13,0.13,0.13);
        glScaled(1,2,0);
        draw_rec();
    glPopMatrix();




    //right-shoe
    glPushMatrix();
        glTranslated(16,-50,0);
        glBegin(GL_POLYGON);
            glColor3f(0.34,0.34,0.34);
            glVertex2f(-10, 10);
            glVertex2f(-10, 0);
            glVertex2f(10, 0);
            glVertex2f(-2, 10);
        glEnd();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();

}

void dragonglass()
{

    glPushMatrix();
    glTranslated(dx,dy,0);
    glRotated(45,0,0,1);
    glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3f(0,0,0.80);
        glVertex2f(0, 0);
        glColor3f(0.0, 0.74, 1.0);
        glVertex2f(5, 0);
        glColor3f(0,0,0.80);
        glVertex2f(5, -5);
        glColor3f(0.0, 0.74, 1.0);
        glVertex2f(0, -5);
        glEnd();
        glPopMatrix();
        glPopMatrix();
}

void whitewalker()
{
    glPushMatrix();
    glTranslated(nx,ny,0);
    //glTranslated(10,-27,0);
    glScaled(0.8,1,1);
	nightking();
	glPopMatrix();
/*
	glPushMatrix();
	glTranslated(-nx,ny+55,0);
	nightking();
	glPopMatrix();*/
}
void fire()
{
    glPushMatrix();
    glPushMatrix();
    glRotated(-35,0,0,1);
    glScaled(0.5,0.5,1);
    glColor3f(1,1,0);
    draw_rec();
	glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,0);
    drawCircle(2.5,2.5);
	glPopMatrix();
	glPushMatrix();
	glRotated(55,0,0,1);
    glColor3f(1,1,0);
    drawCircle(2,1);
	glPopMatrix();
	glPopMatrix();
}
void sign()
{
       //PlaySound("BananaSong.wav", NULL, SND_FILENAME| SND_ASYNC);
       glPushMatrix();//1
	   glTranslated(-2,0,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//2
	   glTranslated(-10,15,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//3
	   glTranslated(2,35,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//4
	   glTranslated(15,50,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//5
	   glTranslated(25,60,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//6
	   glTranslated(10,8,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//7
	   glTranslated(10,-15,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//8
	   glTranslated(0,-20,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//9
	   glTranslated(-13,-10,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//10
	   glTranslated(-25,0,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//11
	   glTranslated(-26,25,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//12
	   glTranslated(-18,45,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//13
	   glTranslated(20,20,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//14
	   glTranslated(33,24,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//15
	   glTranslated(48,25,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//16
	   glTranslated(18,-30,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//17
	   glTranslated(-13,-30,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//18
	   glTranslated(-28,-20,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//19
	   glTranslated(-40,-6,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//20
	   glTranslated(-13,-10,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//21
	   glTranslated(5,-40,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//22
	   glTranslated(-8,-50,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//23
	   glTranslated(-13,-10,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//24
	   glTranslated(25,-10,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//25
	   glTranslated(38,-8,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//26
	   glTranslated(52,-15,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//27
	   glTranslated(-23,-54,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//28
	   glTranslated(-48,18,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//29
	   glTranslated(25,-50,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//30
	   glTranslated(16,-68,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//31
	   glTranslated(65,-40,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
	   glPushMatrix();//32
	   glTranslated(-40,-50,0);
	   glScaled(0.2,0.3,1);
	   nightking();
	   glPopMatrix();
}

void keyboardListener(unsigned char key, int xx,int yy){
    double x,y,z;
    double rate = 0.01;
	switch(key){

	    case 'b':
            if(xj<=135 && xj>-10)
            {
                xj-=0.5;
                jl-=0.5;
                jr-=0.5;
            }
            break;
        case 'f':
            if(xj<=135 && xj>=-10)
            {
                xj+=0.5;
                jl+=0.5;
                jr+=0.5;
            }
            break;
        case 'r':
            fire1=1;
            break;

        case 'j':
            jump1=1;
            break;

        case 's':
            level=1;
            break;


		default:
			break;
	}

}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
		    if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				/*bullet =1;
				double length = 649;
				//double length = (649/cos(angle_c_x*pi/180))/cos(angle_t_x*pi/180);
                printf("---> %lf\n",length);
                //X = length* sin(angle_c_z*pi/180);
                X= length* tan(angle_c_z*pi/180);

                Z=-100*sin(angle_c_x*pi/180)-(649-100*cos(angle_c_x*pi/180))*tan((angle_t_x+angle_c_x)*pi/180);*/

                //level=1;


			}
			break;

/*
		case GLUT_RIGHT_BUTTON:
		    if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				drawaxes=1-drawaxes;
				//(600/cos(angle_c_x*pi/180))/cos(angle_t_x*pi/180);
			}
			break;
			//........

		case GLUT_MIDDLE_BUTTON:
			//........
			break;
*/
		default:
			break;
	}
}
void mouseClick(int buttonPressed ,int state ,int x, int y) {

	if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseX = x;
		mouseY = y;
		mclick = true;
	}
		printf("X: %f, Y: %f\n", mouseX, mouseY);
	/*} else
		mclick = false;
	display();*/

	if(mouseX>=455 && mouseX<=685 && mouseY>=565 && mouseY<=595 )
    {
        if(mclick)
        {
            level=1;


        }
    }
    if(mouseX>=455 && mouseX<=685 && mouseY>=605 && mouseY<=635 )
    {
        if(mclick)
        {
            level=2;
        }
    }

}


void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void display(){


	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.95,0.95,0.95,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	gluLookAt(0,0,100,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);



	//add objects
	if(level==0)
    {

       glPushMatrix();
       //nightsky();
       //snow();
       //mountains();
       glPopMatrix();

       /*glPushMatrix();
       glTranslated(-55,-32,0);
       glScaled(3.2,8,1);
       glColor3f(1.0f, 1.0f, 1.0f);
       draw_rec();
	   glPopMatrix();*/
	   glPushMatrix();
       //glRotated(180,0,1,0);
       glTranslated(xj,0,0);
       //glTranslated(-60,-30,0);
       glScaled(0.6,0.9,1);
	   johnsnow();
	   glPopMatrix();
	   glPushMatrix();
       glTranslated(3,-54,0);
       glScaled(3.5,0.8,1);
       glColor3f(0, 0, 0);
       draw_rec();
	   glPopMatrix();

	   glPushMatrix();
       glTranslated(3,-64,0);
       glScaled(3.5,0.8,1);
       glColor3f(0, 0, 0);
       draw_rec();
	   glPopMatrix();

	   glPushMatrix();
       glTranslated(el,41,0); //el=-8.5
       glScaled(2.5,0.8,1);
       glColor3f(0, 0, 0);
       draw_rec();
	   glPopMatrix();
	   glPushMatrix();
       glTranslated(er,41,0); //er=16
       glScaled(2.5,0.8,1);
       glColor3f(0,0,0);
       draw_rec();
	   glPopMatrix();

	   /*if(n==1)
       {

	   glPushMatrix();
	   glTranslated(-19,76,0);
	   glScaled(0.5,0.6,1);
	   nightking();
	   glPopMatrix();
       }*/


	   char s [50];
    sprintf(s, "A", score);
    glColor3f(1,1,1);
    renderBitmapString(-20,40,(void *)font, s);
    sprintf(s, "SONG", score);
    glColor3f(1,1,1);
    renderBitmapString(-14.5,40.0,(void *)font, s);
    sprintf(s, "OF", score);
    glColor3f(1,1,1);
    renderBitmapString(-2.0,40.0,(void *)font, s);
    sprintf(s, "ICE", score);
    glColor3f(1,1,1);
    renderBitmapString(6.0,40.0,(void *)font, s);
    sprintf(s, "&", score);
    glColor3f(1,1,1);
    renderBitmapString(15.0,40.0,(void *)font, s);
    sprintf(s, "FIRE", score);
    glColor3f(1,1,1);
    renderBitmapString(20.0,40.0,(void *)font, s);
    sprintf(s, "WINTER  IS  COMING", score);
    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(-15,-48.0,(void *)font, s);
    sprintf(s, "START  GAME", score);
    glColor3f(1,1,1);
    renderBitmapString(-9.5,-57,(void *)font, s);
    sprintf(s, "ABOUT", score);
    glColor3f(1,1,1);
    renderBitmapString(-4,-67,(void *)font, s);
    }

    if(level==2)
    {
        if(time<=40){
           sign();

        char rs [100];
        sprintf(rs, "THE  LONG  NIGHT  IS  COMING... ", score);
        glColor3f(0.0f, 0.0f, 0.0f);
        renderBitmapString(-80,60.0,(void *)font, rs);
        sprintf(rs, "AND  THE  WHITE  WALKERS  ARE  COMING  TOO", score);
        glColor3f(0.0f, 0.0f, 0.0f);
        renderBitmapString(-65,50.0,(void *)font, rs);
        }
        else
        {
            level=3;
            time=0.0;
        }



    }

    if(level==3)
    {
    glPushMatrix();
    glTranslated(-35,5,0);
    glScaled(0.6,0.9,1);
    johnsnow();
	glPopMatrix();

    glPushMatrix();
    glRotated(2*angd,0,0,1);
    glPushMatrix();
    glTranslated(10,60,0);
    glScaled(1.3,1.6,1);
    dragonglass();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
    glRotated(-angd,0,0,1);
    glPushMatrix();
    glTranslated(10,60,0);
    glScaled(1.3,1.6,1);
    dragonglass();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
       glTranslated(55,-63,0);
       glScaled(1.8,0.8,1);
       glColor3f(0, 0, 0);
       draw_rec();
	   glPopMatrix();

	char rs [100];
        sprintf(rs, "TO  DEFEAT  THE  ARMY  OF  THE  DEAD, ", score);
        glColor3f(0.0f, 0.0f, 0.0f);
        renderBitmapString(5,25.0,(void *)font, rs);
        sprintf(rs, "JON  SNOW  NEEDS", score);
        glColor3f(0.0f, 0.0f, 0.0f);
        renderBitmapString(44,5.0,(void *)font, rs);
        sprintf(rs, "DRAGONGLASS", score);
        glColor3f(0.0f, 0.0f, 1.0f);
        renderBitmapString(50,-15.0,(void *)font, rs);
        sprintf(rs, "BACK", score);
        glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(50,-65.0,(void *)font, rs);

        if(mouseX>=855 && mouseX<=975 && mouseY>=600 && mouseY<=635 )
    {
        if(mclick)
        {
            level=0;
        }
    }



    }

	if(level==1)
    {

    background();

	glPushMatrix();
	whitewalker();
	glPopMatrix();

	glPushMatrix();
	dragonglass();
	/*glPopMatrix();
	glPushMatrix();
	glTranslated(dx2,8,0);
	dragonglass();
	glPopMatrix();
	glPushMatrix();
	glTranslated(dx3,15,0);
	dragonglass();*/
	//if((jl>=dx&&jl<(dx+0.04))||(jl>=(dx+dx+dx2+20))&&(jl<(dx+dx+dx2+20.1))||(jl>=(dx+dx+dx3)&&(jl<(dx+dx+dx3+0.1))))
    if(jl>=dx&&jl<(dx+0.04))
    {
        score++;
        dx+=150;
        dx2-=150;
        dx3-=150;
    }
    glFlush();

	glPopMatrix();

	 glPushMatrix();
    glTranslated(0,jy1,0);
    glTranslated(xj,0,0);
    glTranslated(-70,-39,0);
    glScaled(0.4,0.5,1);
	johnsnow();
	glPopMatrix();

	if(fire1==1)
    {
        //fire1=0;
        glPushMatrix();
        glTranslated(ang,0,0);
        glPushMatrix();
        glTranslated(jl+21.6,-30,0); //glTranslated(-55,-30,0);
        fire();
        glPopMatrix();
        glPopMatrix();
        if((jl+21.6)>=(nx+10)&&(jl+21.6)<(nx+10.1))
    {
        nx+=150;
        score+=5;
        fire1=0;
    }
    if((jl+21.6)>=100)
    {

        fire1=0;
    }

    }

    if(jl>=(nx+10)&&jl<(nx+10.1))
    {

       /*score=-1;
       char buf [50];
    sprintf(buf, "game over");
    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(-55.0,75.0,(void *)font, buf);*/
    //level=4;
    n1=0.0;
    go=1;

    }




    //score
    char buffer [50];
    sprintf(buffer, "DragonGlass: %d", score);
    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(55.0,75.0,(void *)font, buffer);

    sprintf(buffer, "GAME  OVER", score);
    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(0.0,g,(void *)font, buffer);
    }

    glFlush();

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();

}


void animate(){
    //rotation
    //angle+=0.005;
    if(go==1)
    {
        jy1-=0.1;
        if(g>0){
          g-=0.1;
        }

    }
    if(level==0)
    {
       if(el<-8.5)
       {
           el+=0.05;
       }
       if(er>16)
       {
           er-=0.05;
       }
       if (el>=-8.5)
       {
           n=1;
       }

       if(sx>-80)
    {
        sx+=0.5;
    }

    if(sx<=-80)
    {
        sx=-80;
    }
    if(sy>-10)
    {
        sy-=0.1;
    }

    else if(sy<=-10)
    {
        sy=80;
    }
    }
    if(level==3)
    {
        if(angd<40){
          angd+=0.005;
        }

        if(time2<=40)
        {
            time2+=0.1;
        }
    }
    if(level==2)
    {
        if(time<=40)
        {
            time+=0.1;
        }
    }

    if(level==1){

    ang+=0.005;
    qf+=0.05;


    if(state ==0 && angle>2){ state =1;}
    if(state ==1 && angle<-6){state =0;}

    if(state == 0) angle+=0.05;
    else angle-=0.05;
	//codes for any changes in Models, Camera
	//linear_oscillation

    /*if(state ==0 && incx>50){ state =1;}
    if(state ==1 && incx <-50){state =0;}

    if(state == 0) incx+=0.05;
    else incx-=0.05;*/


    if(m>-90)
    {
        m-=0.3;
    }
    else m=90;

    if(gl>100)
    {
        gl-=1;
    }
    else gl=400;

    if(ice>-100)
    {
        ice-=0.3;
    }
    else ice=0;
/*
    if(state ==0 && nx>120){ state =1;}
    if(state ==1 && nx <-90){state =0;}

    if(state == 0) nx-=0.02;
    else nx=-500;*/
        nx-=n1;
        nl-=0.08;

     if(dx>-150)
    {
        dx-=0.02;

    }
    else {
            dx+=250;
    }
    if(dx2>-150)
    {
        dx2-=0.02;

    }


    if(sx>-80)
    {
        sx+=0.05;
    }

    if(sx<=-80)
    {
        sx=-80;
    }
    if(sy>20)
    {
        sy-=0.05;
    }

    else if(sy<=20)
    {
        sy=80;
    }
    }


	glutPostRedisplay();
}

void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;

	//clear the screen
	glClearColor(0,0,0,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	pos.x=0;
    pos.y=0;
    pos.z=-20;
    l.x=0;u.x=-1;r.x=0;
    l.y=0;u.y=0;r.y=1;
    l.z=1;u.z=0;r.z=0;
    PlaySound("GOT.wav", NULL, SND_FILENAME| SND_ASYNC);
	glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (1100, 700);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("A Song of Ice & Fire");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	//glutTimerFunc(1000, timer, g_counter);
	glutKeyboardFunc(keyboardListener);
	glutMouseFunc(mouseClick);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}



