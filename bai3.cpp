#include <bits/stdc++.h>

using namespace std;

class Point {
private:
    int x, y;

public:
    Point();
    Point(int , int );
    void nhap();
    void in() const;
    void diChuyen(int dx, int dy);
    int getX() const;
    int getY() const;
    double khoangCachDenGocToaDo() const;
    double khoangCachHaiDiem(const Point& P) const;
};

Point :: Point(){
    x = 0;
    y = 1;
}

Point :: Point(int x, int y){
    this->x = x;
    this->y = y;
}

void Point :: nhap(){
    cin >> x >> y;
}

void Point :: in()const{
    cout << "(" << x << ", " << y << ")" << endl;
}

void Point :: diChuyen(int dx, int dy){
    x += dx;
    y += dy;
}

int Point :: getX()const{
    return x;
}

int Point :: getY()const{
    return y;
}

double Point :: khoangCachDenGocToaDo() const{
    return sqrt(x * x + y * y);
}

double Point :: khoangCachHaiDiem(const Point&P)const{
    int dx = x - P.x;
        int dy = y - P.y;
        return sqrt(dx * dx + dy * dy);
}

class LineSegment {
    private:
        Point d1, d2;
    
    public:
        LineSegment();
        LineSegment(Point d1, Point d2);
        LineSegment(int x1, int y1, int x2, int y2);
        LineSegment(const LineSegment& S);
        void nhap();
        void in() const;
        void diChuyen(int , int);
        double doDai() const;
        int angle() const;
};

LineSegment :: LineSegment() : d1(8, 5), d2(1, 0) {}

LineSegment :: LineSegment(Point d1, Point d2) : d1(d1), d2(d2) {}

LineSegment :: LineSegment(int x1, int y1, int x2, int y2) : d1(x1, y1), d2(x2, y2) {}

LineSegment :: LineSegment(const LineSegment& S) : d1(S.d1), d2(S.d2) {}

void LineSegment :: nhap(){
    int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        d1 = Point(x1, y1);
        d2 = Point(x2, y2);
}

void LineSegment :: in()const{
    cout << "[";
    d1.in();
    cout << "; ";
    d2.in();
    cout << "]" << endl;
}

void LineSegment :: diChuyen(int dx, int dy){
    d1.diChuyen(dx, dy);
    d2.diChuyen(dx, dy);
}

double LineSegment :: doDai() const{
    return d1.khoangCachHaiDiem(d2);
}

int LineSegment :: angle() const {
    int dx = d2.getX() - d1.getX();
    int dy = d2.getY() - d1.getY();
    double rad = atan2(dy, dx);
    double deg = rad * 180.0 / M_PI;
    if (deg < 0) deg += 360.0;
    return static_cast<int>(round(deg));
}