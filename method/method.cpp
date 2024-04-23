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
    double lenngth_s() {

        double dx = p1.x - p2.x; 
        double dy = p1.y - p2.y;

        return sqrt(dx * dx + dy * dy);
    }
};

struct ivector3d 
{
    int *array;
};

double length_p (Segment * s);
void scale(ivector3d *v, int k) ;




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
    Segment s = { {0.4, 1.4}, {1.2, 6.3} };

    cout << s.lenngth_s() << endl;


    return 0;
}

