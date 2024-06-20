#include "shape.h"

double norm(s2d v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

 s2d initialise_s2d(double a,double b){
    s2d p;
    p.x=a, p.y=b;
    return p;
    
  }
segment intialise_segment(double x, double y, double ang, double l) {
    s2d b, e;
    b = initialise_s2d(x, y);
    e = initialise_s2d(x + l * cos(ang), y + l * sin(ang));
    segment seg;
    seg.alpha = ang;
    seg.longeure = l;
    seg.base = b;
    seg.extr = e;
    return seg;
}

double ecart(segment a, segment b) {
    double x, y;
    x = a.extr.x - a.base.x;
    y = a.extr.y - a.base.y;
    s2d p = initialise_s2d(x, y);
    x = b.extr.x - b.base.x;
    y = b.extr.y - b.base.y;
    s2d q = initialise_s2d(x, y);
    double theta = acos((p.x * q.x + p.y * q.y) / (a.longeure * b.longeure));
    while (theta > M_PI) {
        theta -= 2 * M_PI;
    }
    while (theta <= -M_PI) {
        theta += 2 * M_PI;
    }
    return theta;
}

double orientation(s2d p, s2d q, s2d r) {
    s2d pq = initialise_s2d(q.x - p.x, q.y - p.y);
    s2d pr = initialise_s2d(r.x - p.x, r.y - p.y);
    double val = (pq.x) * (pr.y) - (pr.x) * (pq.y);
    double distance = val / norm(pq);
    return (fabs(distance) < EPSILON_ZERO) ? 0 : distance;
}

bool onsegment(s2d p, s2d q, s2d r) {
    s2d pq = initialise_s2d(q.x - p.x, q.y - p.y);
    s2d pr = initialise_s2d(r.x - p.x, r.y - p.y);
    double n = norm(pq);
    double s = pr.x * pq.x + pr.y * pq.y;
    double x = s / n;
    return (-EPSILON_ZERO <= x && x <= (n + EPSILON_ZERO)) ? true : false;
}

bool intersection(segment a, segment b) {
    double d1 = orientation(a.base, a.extr, b.base);
    double d2 = orientation(a.base, a.extr, b.extr);
    double d3 = orientation(b.base, b.extr, a.base);
    double d4 = orientation(b.base, b.extr, a.extr);
    if (d1 != d2 && d3 != d4) 
        return true; 

    if (d1 == 0 && onsegment(a.base, b.base, a.extr))
        return true;
    if (d2 == 0 && onsegment(a.base, b.extr, a.extr))
        return true;
    if (d3 == 0 && onsegment(b.base, a.base, b.extr))
        return true;
    if (d4 == 0 && onsegment(b.base, a.extr, b.extr))
        return true;

    return false;
}


void inter_exist(segment a, segment b ,int id){
if(intersection( a,  b)  ==  false)
cout << message::segment_superposition( id, a.indice, b.indice);

}
void inter_exist(segment a, segment b,int d1 , int d2){
if(ecart( a,  b)  < EPSILON_ZERO){
    
cout << message::segment_collision(d1,a.indice, d2, b.indice);
}
}
 


