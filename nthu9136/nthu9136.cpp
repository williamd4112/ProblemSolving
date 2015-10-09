#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cfloat>
#include <cmath>

#define EP DBL_EPSILON

using namespace std;

double distance(const double x1, const double y1, const double x2, const double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(void)
{
    double x1, y1, x2, y2, x3, y3, px, py;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&px,&py) == 8)
    {
        double amx = (x1 + x2) / 2.0;
        double amy = (y1 + y2) / 2.0;
        double am;
        double ac;

        double bmx = (x2 + x3) / 2.0;
        double bmy = (y2 + y3) / 2.0;
        double bm;
        double bc;

        double ox;
        double oy;

        if(fabs(y2 - y1) <= EP)
        {
            bm = -(x3 - x2) / (y3 - y2);
            bc = (-bm * bmx) + bmy;

            ox = amx;
            oy = bm * ox + bc;
        }
        else if(fabs(y3 - y2) <= EP)
        {
            am = -(x2 - x1) / (y2 - y1);
            ac = (-am * amx) + amy;

            ox = bmx;
            oy = am * ox + ac;
        }
        else
        {
            am = -(x2 - x1) / (y2 - y1);
            ac = (-am * amx) + amy;

            bm = -(x3 - x2) / (y3 - y2);
            bc = (-bm * bmx) + bmy;

            ox = (-(ac - bc)) / (am - bm);
            oy = am * ox + ac;
        }

        printf("%s\n", (distance(ox, oy, px, py) > distance(ox, oy, x1, y1) ? "yes" : "no"));
    }

    return 0;
}
