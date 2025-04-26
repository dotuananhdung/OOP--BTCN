#include <bits/stdc++.h>
using namespace std;

class TuLanh {
private:
    string nhanhieu;
    string maso;
    string nuocsx;
    bool tkdien;
    int dungtich;
    int gia;

public:
    TuLanh();
    TuLanh(string nh, string ms, string nsx, bool tk, int dt, int g);
    TuLanh(const TuLanh& other);
    void makeCopy(const TuLanh& tl);
    void nhapThongTin();
    void hienThi() const;
    string layNhanHieu() const ;
    int layGia() const;
    int soNguoiSD() const;
    bool cungNhanHieu(const TuLanh& tl) const;
    bool nhHon(const TuLanh& tl) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename) ;
};

TuLanh :: TuLanh() {
    nhanhieu = "Elextrolux";
    maso = "UNKNOWN";
    nuocsx = "Việt Nam";
    tkdien = true;
    dungtich = 256;
    gia = 7000000;
}

TuLanh :: TuLanh(string nh, string ms, string nsx, bool tk, int dt, int g) : nhanhieu(nh), maso(ms), nuocsx(nsx), tkdien(tk), dungtich(dt), gia(g) {}

TuLanh :: TuLanh(const TuLanh& other) {
    nhanhieu = other.nhanhieu;
    maso = other.maso;
    nuocsx = other.nuocsx;
    tkdien = other.tkdien;
    dungtich = other.dungtich;
    gia = other.gia;
}

void TuLanh :: makeCopy(const TuLanh& tl) {
    nhanhieu = tl.nhanhieu;
    maso = tl.maso;
    nuocsx = tl.nuocsx;
    tkdien = tl.tkdien;
    dungtich = tl.dungtich;
    gia = tl.gia;
}

void TuLanh :: nhapThongTin() {
    getline(cin, nhanhieu);
    getline(cin, maso);
    getline(cin, nuocsx);
    string temp;
    getline(cin, temp);
    tkdien = (temp == "True");
    cin >> dungtich;
    cin >> gia;
    cin.ignore();
}

void TuLanh :: hienThi() const {
    cout << "==========\n";
    cout << "Nhãn hiệu: " << nhanhieu << endl;
    cout << "Mã số:" << maso << endl;
    cout << "Nước SX:" << nuocsx << endl;
    cout << "T/K điện:" << (tkdien ? "Có" : "Không") << endl;
    cout << "Dung tích:" << dungtich << "L" << endl;
    cout << "Giá: " << gia << endl;
    cout << "==========\n";
}

string TuLanh :: layNhanHieu() const {
    return nhanhieu;
}

int TuLanh :: layGia() const {
    return gia;
}

int TuLanh :: soNguoiSD() const {
    return dungtich / 100;
}

bool TuLanh :: cungNhanHieu(const TuLanh& tl) const {
    return nhanhieu == tl.nhanhieu;
}

bool TuLanh :: nhHon(const TuLanh& tl) const {
    return dungtich < tl.dungtich;
}

void TuLanh :: saveToFile(const string& filename) const {
    ofstream out(filename, ios::binary);
    size_t len;

    len = nhanhieu.size();
    out.write((char*)&len, sizeof(len));
    out.write(nhanhieu.c_str(), len);

    len = maso.size();
    out.write((char*)&len, sizeof(len));
    out.write(maso.c_str(), len);

    len = nuocsx.size();
    out.write((char*)&len, sizeof(len));
    out.write(nuocsx.c_str(), len);

    out.write((char*)&tkdien, sizeof(tkdien));
    out.write((char*)&dungtich, sizeof(dungtich));
    out.write((char*)&gia, sizeof(gia));

    out.close();
}

void TuLanh :: loadFromFile(const string& filename) {
    ifstream in(filename, ios::binary);
    size_t len;
    char* buffer;

    in.read((char*)&len, sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    nhanhieu = buffer;
    delete[] buffer;

    in.read((char*)&len, sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    maso = buffer;
    delete[] buffer;

    in.read((char*)&len, sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    nuocsx = buffer;
    delete[] buffer;

    in.read((char*)&tkdien, sizeof(tkdien));
    in.read((char*)&dungtich, sizeof(dungtich));
    in.read((char*)&gia, sizeof(gia));

    in.close();
}