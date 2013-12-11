#include "PseudoRNG.hpp"

PseudoRNG::PseudoRNG(unsigned int seed) {
    idx = 0;
    mt[0] = seed;
    for(unsigned int i = 1; i < length; i++) {
        mt[i] = (1812433253*(mt[i-1]^(mt[i-1]>>30))+i)&bitMask_32;
    }
}

unsigned int PseudoRNG::get(){
    if(idx==0){
        gen();
    }
    unsigned int y=mt[idx];
    y ^= y >> 11;
    y ^= (y << 7) & 2636928640;
    y ^= (y << 15) & 4022730752;
    y ^=  y >> 18;
    idx = (idx+1)%length;
    return y;
}

void PseudoRNG::gen(){
    for(unsigned int i = 0; i < length; i++){
        unsigned int y = (mt[i]&bitPow_31)+(mt[(i+1)%length]&(bitPow_31-1));
        mt[i] = mt[(i+397)%length]^(y>>1);
        if(y%2) {
            mt[i] ^= 2567483615;
        }
    }
}

PseudoRNG::~PseudoRNG(){
}


