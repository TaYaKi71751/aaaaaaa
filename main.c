#include "./main.h"

uint64_t count_shr(uint64_t *n){
	uint64_t t = (*n),c = 0;
	while(t != 1){
		++c;
		t >>= 1;
	}
	return c;
}

uint128_t *uint64_mul(uint64_t *a,uint64_t *b){
	uint128_t *r = calloc(1,sizeof(uint128_t));
	uint64_t al = count_shr(a) + 1;
	uint64_t bl = count_shr(b) + 1;
	uint64_t x = 0,y = 0;
	uint64_t xt = 0,yt = 0;
	uint64_t xc = 0,yc = 0;
	uint64_t xcc = 0,ycc = 0;
	if(!a || !b) abort();
	if(!(*a) || !(*b)) return r;
	xt = __UINT64_MAX__;
	xcc = (uint64_t)(((uint64_t)xt) - ((uint64_t)xt >> 1));
	x = ((uint64_t)(*a));
	yt = __UINT64_MAX__;
	ycc = (uint64_t)1;
	y = ((uint64_t)(*a));
	
	while(x){
		if((uint64_t)xcc & (uint64_t)(*b)) (\
			(r->x = ((uint64_t)(r->x)) + ((uint64_t)(x)))\
		);
		xcc = (uint64_t)((uint64_t)xcc >> (uint64_t)1);
		x = (uint64_t)((uint64_t)x >> (uint64_t)1);
	}
	while(y){
		if((uint64_t)ycc & (uint64_t)(*b)) {
			(r->y = ((uint64_t)(r->y)) + ((uint64_t)(y)));
			if((((uint64_t)y) > ((uint64_t)(r->y))) || (((uint64_t)(r->y) + (uint64_t)y) < ((uint64_t)(r->y)))) (
				(r->x = (uint64_t)((uint64_t)(r->x) + (uint64_t)1))
			);
		}
		ycc = (uint64_t)((uint64_t)ycc << (uint64_t)1);
		y = (uint64_t)((uint64_t)y << (uint64_t)1);
	}
return r;
}

int main(){
	// uint64_t a = __UINT64_MAX__,b = __UINT64_MAX__;
 // uint64_t a = 0xFF00FF00FF00FF00,b = 0xFF00FF00FF00FF;
	uint64_t a = 0b1010,b = 0b101;
	uint128_t* r = uint64_mul(&a,&b);
	printf("0x%016llx 0x%016llx",(r->x),(r->y));
	free(r);
}
