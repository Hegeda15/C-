//
// Created by heged on 3/25/2026.
//

#ifndef CLIONGRAPHICSKIT_KOMPLEX_H
#define CLIONGRAPHICSKIT_KOMPLEX_H


class komplex {
private:
    double r, i;

public:

    komplex(double real = 0.0, double imag = 0.0);


    double re() const;
    double im() const;


    komplex operator+(const komplex& Masik) const;
    komplex operator*(const komplex& Masik) const;

    static komplex from_screen(int x, int y, int XX, int YY, double cx, double cy, double zoom);
};


#endif //CLIONGRAPHICSKIT_KOMPLEX_H