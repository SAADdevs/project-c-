#include <fstream>
#include "simulation.h"
#include "lifeform.h"
#include "message.h"
#include "constantes.h"
#include "shape.h"
void simulation:: lecture (ifstream& f){
    int p,o,i;
f >> p;
nb_alg=p;
algue* alg = new algue[nb_alg];
double x,y;
 int  age;
    for (int i = 0; i < nb_alg; ++i) {
        f >> x >> y >> age;
        algue a(x,y,age);
        alg[i]=a;
    }
f >> p;
nbr_cor=p;  
   corail* cor = new corail [nbr_cor];
   double x1,y1;
   int age1,nbr_seg;
   double id ;
   int stt_cor,rott_cor,dev_stt;
   for(int i=0 ;i<nbr_cor;i++){
    f>> x1 >> y1 >> age1 >> id >> stt_cor >> rott_cor >> dev_stt >>nbr_seg;
            corail k(x1,y1,age1, id,stt_cor,rott_cor,dev_stt,nbr_seg);
            double *l=new double[nbr_seg];
            double *a=new double[nbr_seg];
            for(int n=0;n<nbr_seg;n++){
                
                f >> a[n];
                f >> l[n];
            }
            k.creation_segment(a,l);
        cor[i]=k;
    }

    
f >> p;
nbr_scav=p;     
scavenger* scav = new scavenger [nbr_scav];
    double x2,y2,r;
    int age2,stt,id_;
    for(int k=0;k<nbr_scav;k++){
        f>> x2 >> y2 >> age2 >>r >> stt >>id_;
        scavenger s (x2,y2,age2,r,stt,id_);
        scav[k]=s;
    }


////////////
for(int i ;i<nb_alg;i++){
    alg[i].age_ver(alg[i].get_age());
    alg[i].center_ver();
}
      /////////////////////

for( int i=0 ;i<nbr_cor;i++){
          cor[i].age_ver(cor[i].get_age());
          cor[i].pos_ver();

          cor[i].dup_ver();
 
          cor[i].long_ver();

          for(int k=0;k<cor[i].get_nb_seg()-1;k++){
          inter_exist(cor[i].get_tab_seg(k),cor[i].get_tab_seg(k+1),cor[i]._id());
            }}


     /////////////////
for (int i=0 ;i<nbr_scav;i++){
        scav[i].age_ver(scav[i].get_age());
        scav[i].center_ver();
        scav[1].radius_ver();
        scav[i].invalid_ver();
     } 
     cout << message::success()<<endl;
     }
    