/**
 * @file    camara.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;


class Point3{
public:
    float x,y,z;
    void set(float dx, float dy, float dz){x = dx; y = dy; z = dz;}
    void set(Point3& p){x = p.x; y = p.y; z = p.z;}
    Point3(float xx,     float yy, float zz){x = xx; y = yy; z = zz;}
    Point3(){x = y = z = 0;}
    void build4tuple(float v[])
    {
        v[0] = x; v[1] = y; v[2] = z; v[3] = 1.0f;
    }
};

class Vector3{
public:
    float x,y,z;
    void set(float dx, float dy, float dz){ x = dx; y = dy; z = dz;}
    void set(Vector3 & v){ x = v.x; y = v.y; z = v.z;}
    void flip(){x = -x; y = -y; z = -z;}
    void setDiff(Point3 & a, Point3 & b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z;}
    void normalize()
    {
        double sizeSq = x * x + y * y + z * z;
        if(sizeSq < 0.0000001)
        {
            cerr << "\nnormalize() sees vector (0,0,0)!";
            return;
        }
        float scaleFactor = 1.0/(float)sqrt(sizeSq);
        x *= scaleFactor; y *= scaleFactor; z *= scaleFactor;
    }

    Vector3(float xx, float yy, float zz){x = xx; y = yy; z = zz;}
    Vector3(const Vector3 & v){x = v.x; y = v.y; z = v.z;}
    Vector3(){x = y = z = 0;}

    Vector3 cross(Vector3 b)
    {
       Vector3 c(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
       return c;
    }
    float dot(Vector3 b)
 {
        return x * b.x + y * b.y + z * b.z;}
};

class Camera{
  private:
    Point3 eye;
    Vector3 u,v,n;
    double viewAngle, aspect, nearDist, farDist;
    void setModelViewMatrix();

  public:
    Camera();
    void set(Point3 eye, Point3 look, Vector3 up);
    void roll(float angle);
    void pitch(float angle);
    void yaw(float angle);
    void slide(float delU, float delV, float delN);
    void setShape(float vAng, float asp, float nearD, float farD);
};
