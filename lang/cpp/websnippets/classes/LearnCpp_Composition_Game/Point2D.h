/*
 * Simple game showcasing objectComposition.
 * Source: http://www.learncpp.com/cpp-tutorial/102-composition/
 */

/* 
 * File:   Point2D.h
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 17:47
 */

#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
private:
    int m_x;
    int m_y;

public:
    // A default constructor

    Point2D()
    : m_x(0), m_y(0) {
    }

    // A specific constructor

    Point2D(int x, int y)
    : m_x(x), m_y(y) {
    }

    // An overloaded output operator

    friend std::ostream& operator<<(std::ostream& out, const Point2D &point) {
        out << "(" << point.m_x << ", " << point.m_y << ")";
        return out;
    }

    // Access functions

    void setPoint(int x, int y) {
        m_x = x;
        m_y = y;
    }

};


#endif /* POINT2D_H */
