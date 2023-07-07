#include "Maths.h"

int Maths::gcd(int m, int n){
	int oldm, oldn;
	while( m % n != 0 ){
		oldm = m;
		oldn = n;

		m = oldn;
		n = oldm % oldn;
	}
	return n;
}
