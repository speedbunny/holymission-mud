#include "util.h"

int Number( int To, int From) {
    int Temp;
    if( From > To ) {
	Temp = From;
	From = To;
	To= Temp;
    }
    return ( random(From-To)+To+1);
}

int Dice( int Rolls, int Size ) {
    int Sum;
    Sum=0;
    if(Size <= 0 || Rolls <=0)
	return 0;
    while(Rolls-- > 0)
	Sum+=(random(Size)+1);
    return Sum;
}


int Min(int A, int B) {
    return A < B ? A : B;
}


int Max( int A, int B ) {
    return A > B ? A : B;
}
