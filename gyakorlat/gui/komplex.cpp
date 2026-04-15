//
// Created by heged on 3/25/2026.
//

#include "komplex.h"
komplex::komplex(double real, double imag) : r(real), i(imag) {}


double komplex::re() const {
    return r;
}


double komplex::im() const {
    return i;
}


komplex komplex::operator+(const komplex& Masik) const {
    return komplex(r + Masik.r, i + Masik.i);
}


komplex komplex::operator*(const komplex& Masik) const {
    return komplex(
        r * Masik.r - i * Masik.i,
        r * Masik.im() + i * Masik.re()
    );
}

komplex komplex::from_screen(int x, int y, int XX, int YY, double cx, double cy, double zoom) {
    double pr = (x - XX / 2.0) * (4.0 / (XX * zoom)) + cx;
    double pi = (y - YY / 2.0) * (4.0 / (YY * zoom)) + cy;
    return komplex(pr, pi);
}