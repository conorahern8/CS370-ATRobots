//
// Created by conor on 2/18/2018.
//

//#include <iostream>
//#include <fstream>
#include <cmath>
#include <sstream>
#include <QtGui/QColor>
//#include <sstream>
#include "atr2func.h"
#include <chrono>
#include <thread>
#include <QThread>

const double pi = 3.1415926535897932385;

double atr2func::sint[] = {0.0};
double atr2func::cost[] = {0.0};

atr2func::atr2func() {

}

std::string atr2func::hex(int num) {
    std::stringstream ss;
    ss << std::hex << num;
    std::string s(ss.str());
    s = atr2func::ucase(s);
    return s;
}

double atr2func::valuer(std::string i) {
    double s;
    int n;

    s = std::stoi(i);
    return s;
}

long atr2func::value(std::string i) {
    long s;
    int n;

    s = std::stoi(i);
    return s;
}

std::string atr2func::cstrr(double i) {
    std::string s1;

    s1 = std::to_string(i);
    return s1;
}

std::string atr2func::cstr(long i) {
    std::string s1;

    s1 = std::to_string(i);
    return s1;
}

std::string atr2func::zero_pad(long n, long l) {
    std::string s;

    s = atr2func::cstr(n);
    while (s.length() < l) {
        s = "0" + s;
    }

    return s;
}

std::string atr2func::zero_pads(std::string s, long l) {
    std::string s1;

    s1 = s;
    while (s.length() < l) {
        s1 = "0" + s1;
    }

    return s1;
}

std::string atr2func::addfront(std::string b, int l) {
    while (b.length() < l) {
        b = " " + b;
    }
    return b;
}

std::string atr2func::addrear(std::string b, int l) {
    while (b.length() < l) {
        b = b + " ";
    }
    return b;
}

std::string atr2func::ucase(std::string s) {
    int i;
    if((int)s.length() >= 1) {
        for (i = 0; i < s.length(); i++) {
            s[i] = (char)toupper(s[i]);
        }
    }
    return s;
}

std::string atr2func::lcase(std::string s) {
    int i;
    if((int)s.length() >= 1) {
        for (i = 0; i < s.length(); i++) {
            s[i] = (char)tolower(s[i]);
        }
    }
    return s;
}

std::string atr2func::space(uint8_t i) {
    std::string s;
    int k;

    s.clear();
    if (i > 0) {
        for (k = 0; k < i; i++) {
            s = s + " ";
        }
    }

    return s;
}

std::string atr2func::ltrim(std::string s1) {
    while(((int)s1.length() > 0) && ((s1.compare(0, 1, " ") == 0) ||
            (s1.compare(0, 1, "\b") == 0) || (s1.compare(0, 1, "\t") == 0))) {
        s1.erase(0, 1);
    }
    return s1;
}

std::string atr2func::rtrim(std::string s1) {
    while(((int)s1.length() > 0) && ((s1.compare(s1.length() - 1, 1, " ") == 0) ||
            (s1.compare(s1.length() - 1, 1, "\b") == 0) ||
            (s1.compare(s1.length() - 1, 1, "\t") == 0))) {
        s1.erase(s1.length() - 1, 1);
    }
    return s1;
}

std::string atr2func::btrim(std::string s1) {
    return atr2func::ltrim(atr2func::rtrim(s1));
}

std::string atr2func::lstr(std::string s1, int l) {
    if ((int)s1.length() <= l) {
        return s1;
    } else {
        s1.erase((unsigned int)(l), std::string::npos);
        return s1;
    }
}

std::string atr2func::rstr(std::string s1, int l) {
    if ((int)s1.length() <= 1) {
        return s1;
    } else {
        s1.erase(0, (s1.length() - l));
        return s1;
    }
}

void atr2func::time_delay(int n) {
    long i, l;

    /*if(delay_per_sec == 0) {
        calibrate_timing();
    }*/

    //l = (long)round(n / 1000 * delay_per_sec)
    //std::this_thread::sleep_for(std::chrono::milliseconds(n));
    QThread::msleep(n);
}

int atr2func::rol(int n, int k) {
    n = ~(~0U << 16) & ((n << 1) + (n & (1 << 16)?1:0));
    return n;
}

int atr2func::ror(int n, int k) {
    n = ~(~0U << 16) & (((unsigned)n >> 1) + ((n & 1 << 0) << 15));
    return n;
}

int atr2func::sal(int n, int k) {

    if (k >= 0) {
        n = n << k;
    }

    return n;
}

int atr2func::sar(int n, int k) {

    if (k >= 0) {
        n = n >> k;
    }

    return n;
}

void atr2func::make_tables() {
    int i, j, k;

    for (i = 0; i <= 255; i++) {
        atr2func::sint[i] = std::sin((double)i / 128 * pi);
        atr2func::cost[i] = std::cos((double)i / 128 * pi);
    }
}

QColor atr2func::robot_color(int n) {

    switch(n % 14) {
        case 0:
            return QColor(84, 252, 84);   //light green   - 10
        case 1:
            return QColor(252, 84, 84);   //light red     - 12
        case 2:
            return QColor(84, 84, 252);   //light blue    - 9
        case 3:
            return QColor(84, 252, 252); //light cyan    - 11
        case 4:
            return QColor(252, 84, 252); //light magenta - 13
        case 5:
            return QColor(252, 252, 84); //yellow        - 14
        case 6:
            return QColor(168, 168, 168); //light gray  - 7
        case 7:
            return QColor(168, 84, 0);  //brown         - 6
        case 8:
            return QColor(0, 168, 0);   //dark green    - 2
        case 9:
            return QColor(168, 0, 0);   //dark red      - 4
        case 10:
            return QColor(0, 0, 168);  //dark blue     - 1
        case 11:
            return QColor(0, 168, 168); //dark cyan     - 3
        case 12:
            return QColor(168, 0, 168); //dark magenta  - 5
        case 13:
            return QColor(252, 252, 252); //white       - 15
        default:
            return QColor(252, 252, 252); //white
    }
}

void chirp() {

}

void click() {

}

int atr2func::hex2int(std::string s) {
    uint16_t w;
    int i;

    i = 0;
    w = 0;
    while(i < s.length()) {
        if (s[i] == '0') {
            w = (uint16_t)((w << 4) | 0);
        } else if (s[i] == '1') {
            w = (uint16_t)((w << 4) | 1);
        } else if (s[i] == '2') {
            w = (uint16_t)((w << 4) | 2);
        } else if (s[i] == '3') {
            w = (uint16_t)((w << 4) | 3);
        } else if (s[i] == '4') {
            w = (uint16_t)((w << 4) | 4);
        } else if (s[i] == '5') {
            w = (uint16_t)((w << 4) | 5);
        } else if (s[i] == '6') {
            w = (uint16_t)((w << 4) | 6);
        } else if (s[i] == '7') {
            w = (uint16_t)((w << 4) | 7);
        } else if (s[i] == '8') {
            w = (uint16_t)((w << 4) | 8);
        } else if (s[i] == '9') {
            w = (uint16_t)((w << 4) | 9);
        } else if (s[i] == 'A') {
            w = (uint16_t)((w << 4) | 10);
        } else if (s[i] == 'B') {
            w = (uint16_t)((w << 4) | 11);
        } else if (s[i] == 'C') {
            w = (uint16_t)((w << 4) | 12);
        } else if (s[i] == 'D') {
            w = (uint16_t)((w << 4) | 13);
        } else if (s[i] == 'E') {
            w = (uint16_t)((w << 4) | 14);
        } else if (s[i] == 'F') {
            w = (uint16_t)((w << 4) | 15);
        } else {
            i = s.length();
        }
        i++;
    }

    return (int)w;
}

int atr2func::str2int(std::string s) {
    long i, j, k;
    bool neg;

    neg = false;
    s = atr2func::btrim(atr2func::ucase(s));
    if (s.empty()) {
        k = 0;
    } else {
        if (s[0] == '-') {
            neg = true;
            s = atr2func::rstr(s, s.length() - 1);
        }
        k = 0;
        if (atr2func::lstr(s, 2) == "0X") {
            k = atr2func::hex2int(atr2func::rstr(s, s.length() - 2));
        } else if (atr2func::rstr(s, 1) == "H") {
            k = atr2func::hex2int(atr2func::lstr(s, s.length() - 1));
        } else {
            k = atr2func::value(s);
        }
        if (neg) {
            k = 0 - k;
        }
    }
    return k;
}

double atr2func::distance(double x1, double y1, double x2, double y2) {
    return std::abs(std::sqrt(std::pow(y1-y2, 2) + std::pow(x1-x2, 2)));
}

double atr2func::find_angle(double xx, double yy, double tx, double ty) {
    double v, z, q;

    q = 0;
    v = (int)std::abs(std::round(tx - xx));
    if (v == 0) {
        if ((tx == xx) && (ty > yy)) {
            q = pi;
        }
        if ((tx == xx) && (ty < yy)) {
            q = 0;
        }
    } else {
        z = (int)std::abs(std::round(ty - yy));
        q = std::abs(std::atan(z / v));
        if ((tx > xx) && (ty > yy)) {
            q = pi / 2 + q;
        }
        if ((tx > xx) && (ty < yy)) {
            q = pi / 2 - q;
        }
        if ((tx < xx) && (ty < yy)) {
            q = pi + pi / 2 + q;
        }
        if ((tx < xx) && (ty > yy)) {
            q = pi + pi / 2 - q;
        }
        if ((tx == xx) && (ty > yy)) {
            q = pi / 2;
        }
        if ((tx == xx) && (ty < yy)) {
            q = 0;
        }
        if ((tx < xx) && (ty == yy)) {
            q = pi + pi / 2;
        }
        if ((tx > xx) && (ty == yy)) {
            q = pi / 2;
        }
    }

    return q;
}

int atr2func::find_anglei(double xx, double yy, double tx, double ty) {
    int i;

    i = (int)std::round(atr2func::find_angle(xx, yy, tx, ty) / pi * 128 + 256);
    while (i < 0) {
        i = i + 256;
    }
    i = i & 255;

    return i;
}


//Our custom functions:
QColor atr2func::pascal_color(int n) {
    switch(n) {
        case 0: //Black
            return QColor(0, 0, 0);
        case 1: //Dark Blue
            return QColor(0, 0, 168);
        case 2: //Dark Green
            return QColor(0, 168, 0);
        case 3: //Dark Cyan
            return QColor(0, 168, 168);
        case 4: //Dark Red
            return QColor(168, 0, 0);
        case 5: //Dark Magenta
            return QColor(168, 0, 168);
        case 6: //Brown
            return QColor(168, 84, 0);
        case 7: //Light Gray
            return QColor(168, 168, 168);
        case 8: //Dark Gray
            return QColor(84, 84, 84);
        case 9: //Light Blue
            return QColor(84, 84, 252);
        case 10: //Light Green
            return QColor(84, 252, 84);
        case 11: //Light Cyan
            return QColor(84, 252, 252);
        case 12: //Light Red
            return QColor(252, 84, 84);
        case 13: //Light Magenta
            return QColor(252, 84, 252);
        case 14: //Yellow
            return QColor(252, 252, 84);
        case 15: //White
            return QColor(252, 252, 252);
        default:
            std::cout << "Color #" << std::to_string(n) << " not found!" << std::endl;
            return QColor(0, 0, 0); //Return black
    }
}

int atr2func::robot_color_i(int n) {
    switch(n % 14) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 9;
        case 3:
            return 11;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 7;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 3;
        case 12:
            return 5;
        case 13:
            return 15;
        default:
            return 15;
    }
}
