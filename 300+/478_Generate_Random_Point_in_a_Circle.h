#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution { //Wrong Answer 不知道为什么。。 //我知道了这是错的。。 r dr dtheta
public:
    Solution(double radius, double x_center, double y_center): r(radius), x(x_center), y(y_center) {}
    
    vector<double> randPoint() {
        //double rho = r * double(rand()) / double(RAND_MAX);
        //double phi = twopi * double(rand()) / double(RAND_MAX);
        double rho = r * sqrt(drand48());
        double phi = 2. * M_PI * drand48();
        return {rho * cos(phi) + x, rho * sin(phi) + y};
    }

private:
    double x, y;
    double r;
};

class Solution {
public:
    Solution(double radius, double x_center, double y_center): r(radius), x(x_center), y(y_center) {}
    
    vector<double> randPoint() {
        double a, b;
        do{
            a = drand48() * 2. - 1.;
            b = drand48() * 2. - 1.;
        }while(a * a + b * b > 1.);
        return {r * a + x, r * b + y};
    }

private:
    double x, y;
    double r;
};