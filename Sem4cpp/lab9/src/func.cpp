#include "func.h"

void swapit(SkomplikowanaKlasa&a,SkomplikowanaKlasa&b) {
    SkomplikowanaKlasa tmp=a;
    a=b;
    b=tmp;
}