#include"Round.h"
#include<math.h>
void  rounding(double *num, int pos){
	int factor=1;
	for(int i=0;i<pos;i++){
		factor*=10;
	}
	*num=(int)(*num *factor+0.5)/(double)factor;
}
