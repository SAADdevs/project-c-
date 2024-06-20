#include "lifeform.h"
// *************************************************************************constructeurs

algue::algue() {}
algue::algue(double x, double y, int age)
{
    position.x = x;
    position.y = y;
    age = age;
}
corail::corail() {}
corail::corail(double x, double y, int _age, int id, int status, int dir, int status_dev, int _nb_seg)
{
    id = id;
    t_id[tstatic] = id;
    tstatic++;
    position.x = x;
    position.y = y;
    status = status;
    status_dev = status_dev;
    age = _age;
    nb_seg = _nb_seg;
    seg = new segment[nb_seg];
    for (int i = 0; i < nb_seg; i++)
    {
        seg->indice = i;
    }
}
void corail::creation_segment(double *a, double *l)
{
    for (int i = 0; i < nb_seg; i++)
    {
        seg[i].longeure = l[i];
        seg[i].alpha = a[i];
    }
}
segment corail::get_tab_seg(int i)
{
    return seg[i];
}
int corail::_id()
{
    return id;
}

scavenger::scavenger() {}
scavenger::scavenger(double x, double y, int age, double r, int status, int id)
{
    position.x = x;
    position.y = y;
    age = age;
    r = r;
    id_cor = id;
    status = status;
}

// *************************************************************************partie algue

void algue::age_ver(int age)
{

    if (!(age > 0))
    {
        cout << message::lifeform_age(age) << endl;
        exit(EXIT_FAILURE);
    }
}
void algue::center_ver()
{

    if (!(position.x >= 1 && position.x < dmax - 1 && position.y >= 1 && position.y < dmax - 1))
    {
        std::cout << message::lifeform_center_outside(position.x, position.y) << endl;
        exit(EXIT_FAILURE);
    }
}
// *************************************************************************partie corail
int corail::get_nb_seg() { return nb_seg; }
int *corail::get_idtab()
{
    return t_id;
}
int corail::getstatic_id()
{

    return this->tstatic; //
}
void corail::age_ver(int age)
{

    if (age <= 0)
    {
        cout << age << endl;
        cout << message::lifeform_age(age) << endl;
        exit(EXIT_FAILURE);
    }
}
void corail::pos_ver()
{
    if (!(position.x > 0 && position.x < dmax && position.y > 0 && position.y < dmax))
    {
        cout << message::lifeform_computed_outside(id, position.x, position.y) << endl;
        exit(EXIT_FAILURE);
    }
}
void corail::long_ver()
{

    for (int i = 0; i < nb_seg; i++)
    {
        if (!(seg[i].longeure >= l_repro - l_seg_interne && seg[i].longeure < l_repro))
        {
            cout << message::segment_length_outside(this->_id(), seg[i].longeure) << endl;
            exit(EXIT_FAILURE);
        }
    }
}
void corail::angle_ver()
{
    for (int i = 0; i < nb_seg; i++)
    {
        if (!(seg[i].alpha <= -M_PI && seg[i].alpha >= M_PI))
        {
            cout << message::segment_angle_outside(this->id, seg[i].alpha) << endl;
        }
    }
}
int corail::tstatic = 0;
int *corail::t_id = new int[15];
void corail::dup_ver()
{
    int k = 0;
    for (int i = 0; i < tstatic; i++)
    {
        if (t_id[i] == id)
            k++;
    }
    if (k != 0 && k != 1)
    {
        cout << message::lifeform_duplicated_id(id) << endl;
    }
}
// *************************************************************************partie scavenger

void scavenger::age_ver(int age)
{

    if (age < 0)
    {

        cout << message::lifeform_age(age) << endl;
        exit(EXIT_FAILURE);
    }
}
void scavenger::center_ver()
{
    if (!(position.x >= 1 && position.x < dmax - 1 && position.y >= 1 && position.y < dmax - 1))
    {
        cout << message::lifeform_center_outside(position.x, position.y) << endl;
        exit(EXIT_FAILURE);
    }
}

void scavenger::radius_ver()
{

    if (r > r_sca || r < r_sca_repro)
    {
        cout << message::scavenger_radius_outside(r) << endl;
        exit(EXIT_FAILURE);
    }
};


void scavenger::invalid_ver()
{
    int k = 0;
    corail a;
    int *t = a.get_idtab();
    for (int i = 0; i < a.getstatic_id(); i++)
    {
        if (t[i] == id_cor)
            k++;
    }
    if (k == 0)
    {
        cout << message::lifeform_invalid_id(id_cor) << endl;
        exit(EXIT_FAILURE);
    }
}

int algue::get_age() { return age; }
int corail::get_age() { return age; }
int scavenger::get_age() { return age; }

//*************************************************************************END
