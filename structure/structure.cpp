#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Point
{
    double x;
    double y;
};

struct Segment
{
    Point p1;
    Point p2;
};

struct ivector3d 
{
    int *array;
};

double lenngth_s(Segment s);
double length_p (Segment * s);
void scale(ivector3d *v, int k) ;


double lenngth_s(Segment s) {

    double dx = s.p1.x - s.p2.x; 
    double dy = s.p1.y - s.p2.y;

    return sqrt(dx * dx + dy * dy);
}

double length_p (Segment * s) {
    double dx = s->p1.x - s->p2.x;
    double dy = (*s).p1.y - (*s).p2.y;

    return sqrt(dx * dx + dy * dy);
}

void scale(ivector3d *v, int k) 
{
    for (int i = 0; i != 3; ++i)
        v->array[i] *= k;
}




int main(int argc, char const *argv[])
{
    Point p1 = {0.4, 1.4};
    Point p2 = {1.2, 6.3};

    Segment s = {p1, p2};

    int mass[3] = {1, 1, 1};

    ivector3d iv3d;

    iv3d.array = mass;

    cout << lenngth_s(s) << endl;
    cout << length_p(&s) << endl;

    scale(&iv3d, 2);

    return 0;
}

