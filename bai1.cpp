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