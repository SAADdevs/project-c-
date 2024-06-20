#ifndef SHAPE_H
#define SHAPE_H
#include "message.h"
#include <cmath>
#include<iostream>
#include"constantes.h"
using namespace std;
const double EPSILON_ZERO = 1e-5;

struct s2d {
    double x, y;
    };

struct segment {
    s2d    base;
    double alpha;
    double longeure;
    int    indice;
    s2d    extr;
};

s2d initialise_s2d(double a, double b);
segment intialise_segment(double x, double y, double ang, double l);
double norm(s2d v);
double ecart(segment a, segment b);
double orientation(s2d p, s2d q, s2d r);
bool onsegment(s2d p, s2d q, s2d r);
bool intersection(segment a, segment b);
void inter_exist(segment a, segment b,int d1 , int d2);
void inter_exist(segment a, segment b,int id);


#endif 
