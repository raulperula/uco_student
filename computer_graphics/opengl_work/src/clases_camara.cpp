#ifdef WIN32
#include<windows.h>
#endif
#ifdef WIN32
#include<windows.h>
#endif
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<fstream>
#ifndef WIN32
#include <iostream>
#endif
#include "camara.h"


void Camera :: setModelViewMatrix(void)
{ // carga la matriz modelview  con los valores de la camera
	float m[16];
	Vector3 eVec(eye.x, eye.y, eye.z); // a vector version of eye 
	m[0] =  u.x; m[4] =  u.y; m[8]  =  u.z;  m[12] = -eVec.dot(u);
	m[1] =  v.x; m[5] =  v.y; m[9]  =  v.z;  m[13] = -eVec.dot(v);
	m[2] =  n.x; m[6] =  n.y; m[10] =  n.z;  m[14] = -eVec.dot(n);
	m[3] =  0;   m[7] =  0;   m[11] =  0;    m[15] = 1.0;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(m);
}

Camera::Camera()
{


}


void Camera:: set(Point3 Eye, Point3 look, Vector3 up)
{	
        Vector3 auxiliar;
	eye.set(Eye);
	n.set(eye.x - look.x, eye.y - look.y, eye.z - look.z); 
	
	auxiliar = up.cross(n);
	
	u.set(auxiliar); 
	n.normalize(); u.normalize();
	
	auxiliar = n.cross(u);
	
	v.set(auxiliar); 
	setModelViewMatrix(); 
}
void Camera:: slide(float delU, float delV, float delN)
{
	eye.x += delU * u.x + delV * v.x + delN * n.x;
	eye.y += delU * u.y + delV * v.y + delN * n.y;
	eye.z += delU * u.z + delV * v.z + delN * n.z;
	setModelViewMatrix();
}
void Camera:: roll(float angle)
//"roll" inclina la cámara el ángulo en grados
{
	float cs = cos(3.14159265/180 * angle);
	float sn = sin(3.14159265/180 * angle);
	Vector3 t = u; //recuerda el valor de u antiguo
	u.set(cs*t.x-sn*v.x, cs*t.y - sn*v.y, cs*t.z - sn*v.z);
	v.set(sn*t.x + cs*v.x, sn*t.y + cs*v.y, sn*t.z + cs*v.z);
	setModelViewMatrix();
}

//"pitch" eleva la cámara el ángulo en grados
void Camera::pitch(float angle)
{
float cs = cos(3.14159265/180 * angle);
	float sn = sin(3.14159265/180 * angle);
	Vector3 t = v; //recuerda el valor de u antiguo
	v.set(cs*t.x-sn*n.x, cs*t.y - sn*n.y, cs*t.z - sn*n.z);
	n.set(sn*t.x + cs*n.x, sn*t.y + cs*n.y, sn*t.z + cs*n.z);
	setModelViewMatrix();
}
//"yaw" cabezada de la cámara
void Camera::yaw(float angle)
{
float cs = cos(3.14159265/180 * angle);
	float sn = sin(3.14159265/180 * angle);
	Vector3 t = n; //recuerda el valor de u antiguo
	n.set(cs*t.x-sn*u.x, cs*t.y - sn*u.y, cs*t.z - sn*u.z);
	u.set(sn*t.x + cs*u.x, sn*t.y + cs*u.y, sn*t.z + cs*u.z);
	setModelViewMatrix();
}
//Definición de la forma de la cámara
void Camera::setShape(float vAng,float asp,float nearD,float farD)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(vAng,asp,nearD,farD);
}
