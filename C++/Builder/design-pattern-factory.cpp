#include <iostream>
#include <math.h>

using namespace std;

// class GeometricFigure 
class GeometricFigure {
public:

    static GeometricFigure * newCircle(double radio){
        return new GeometricFigure(M_PI*radio*radio);
    }

    static GeometricFigure * newTrapezoid(double lb, double sb, double h){
        return new GeometricFigure(0.5 * (lb + sb) * h);
    }

    static GeometricFigure * newRectangle(double b, double h){
        return new GeometricFigure(b * h);
    }

    static GeometricFigure * newSquare(double b, double h){
        return new GeometricFigure(b * h);
    }

    static GeometricFigure * newTriangle(double sa, double sb, double sc){
        // Area of a triangle using Heron's formula
        double s = (sa + sb + sc)/2;
        return new GeometricFigure(sqrt(s*(s-sa)*(s-sb)*(s-sc)));
    }

    double getArea(){
        return area;
    }

    double getArea() const{
        return area;
    }

    friend ostream & operator<<(ostream &os, const GeometricFigure &inst);

private:
    GeometricFigure(double a){
        area = a;
    }
    double area;
};

ostream & operator<<(ostream &os, const GeometricFigure &inst) {
    os << "GeometricFigure( area = " << inst.getArea() << " )" << endl;
    return os;
}

int main(){

    GeometricFigure *triangle1 = GeometricFigure::newTriangle(3.0, 4.0, 5.0);
    GeometricFigure *triangle2 = GeometricFigure::newTriangle(4.0, 4.0, 4.0);
    GeometricFigure *triangle3 = GeometricFigure::newTriangle(5.0, 4.0, 5.0);

    GeometricFigure *rectangle = GeometricFigure::newRectangle(4.0, 5.0);
    GeometricFigure *square = GeometricFigure::newSquare(4.0, 4.0);
    GeometricFigure *trapeze = GeometricFigure::newTrapezoid(4.0, 6.0, 3.0);

    cout << *triangle1 << *triangle2 << *triangle3 << *rectangle << *square << *trapeze;

    return 0;
}