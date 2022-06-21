#include "manzhuk/manzhuk.h"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <QObject>
#include <QtTest/qtest.h>

enum TestName {
    Notest, Duffing, LC, RC, RLC, VanDerPole, Dib15i
};

class tst_ManZhuk : public QObject
{
    Q_OBJECT
public:
    explicit tst_ManZhuk();
    friend void global_fcttask(double z[],double px[],double f[],double rj1[],double rj2[],
                               int n,int m,double t,double h,int ncon,int *nbad,int ip[]);
    friend void global_outtask(double z[],double px[],int n,int m,double t,double t0,
                               double tk,double h,double *tkv,int ncon,int ip[]);

private slots:
    void initTestCase();
    void tstDuffing();
    void tstLC();
    void tstDIB();

private:
    //task001 task002 - Duffing equation
    inline void fcttask001(double z[],double px[],double f[],double rj1[],double rj2[],
                           int n,int m,double t,double h,int ncon,int *nbad,int ip[]);
    inline void outtask001(double z[],double px[],int n,int m,double t,double t0,
                           double tk,double h,double *tkv,int ncon,int ip[]);

    inline void fcttaskLC(double z[],double px[],double f[],double rj1[],double rj2[],
                           int n,int m,double t,double h,int ncon,int *nbad,int ip[]);
    inline void outtaskLC(double z[],double px[],int n,int m,double t,double t0,
                           double tk,double h,double *tkv,int ncon,int ip[]);

    inline void fcttaskDib(double z[],double px[],double f[],double rj1[],double rj2[],
                           int n,int m,double t,double h,int ncon,int *nbad,int ip[]);
    inline void outtaskDib(double z[],double px[],int n,int m,double t,double t0,
                           double tk,double h,double *tkv,int ncon,int ip[]);

public:
    TestName m_currentTest = Notest;

private:
    // Common variables for manzhuk ODE systems solver
    double rj1[2500], rj2[2500];
    double z[50], px[50], z1[50], xp1[50], f[50], t, t0, tk, h, hmn, hmx, eps, tkv;
    int n, nm, m, ncon, nbad, ier, ip[10000];
    FILE *f01,*f02;
    // Tasks&tests for ODE sets
    int i;
    double pi4, om, tstartp, tendp, deltatp, tkp;
    double mu0, mu1;
    double c1, c2, l, r;
    double mu;
    double c01, c02, c03, l01, l02, l03, a;
    double b, g, a1, a11, a12, a13, a21, a22, a23, a31, a32, a33;

    // Dib problem
    const int IZv = 2;
    const int Jdib = 2;
    double ki[2], kAl[2], kd[2], kp[2], C0[2], Cp0[2];
    double M0 = 1.5, Mp0 = 0;
    double Al0 = 0.012;
    double y0[2], Y[2], y1[2], y2[2], v0[2], v1[2], v2[2], P1[2], Pp1[2], P1I[2], P1dI[2], P1d[2];
    int TotalTime = 100;
};
