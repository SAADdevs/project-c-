#ifndef LIFEFORM_H_INCLUDED
#define LIFEFORM_H_INCLUDED
#include"shape.h"
class  algue{
private:
s2d position;
int age;
// *************************************************************************
public:
algue(double, double ,int);//
algue();//
void age_ver(int);//
void center_ver();//
int get_age();

};
// *************************************************************************
class corail{
private:
int id;
s2d position;
Status_cor status;
Status_dev status_dev;
 Dir_rot_cor dir;
int age;
int nb_seg;
segment *seg;
static int *t_id;
static int tstatic;//mazal


public:
corail();
corail(double x, double y, int _age,int id,int status,int dir, int status_dev  , int _nb_seg );
void age_ver(int);//
void pos_ver();//
void dup_ver();//
void angle_ver();//
void long_ver();//
void creation_segment(double* a,double* l);
int* get_idtab();
int  getstatic_id();
segment get_tab_seg(int); 
int _id();
int get_nb_seg();
int get_age();

};
// *************************************************************************
class scavenger{
private:
s2d position;
int age;
double r;
int id_cor;
Status_sca status;
public:
scavenger();
scavenger(double x ,double y ,int age,double r,int status,int id);
void age_ver(int);//
void center_ver();//
void radius_ver();//
void invalid_ver();
int get_age();


};
// *************************************************************************

#endif