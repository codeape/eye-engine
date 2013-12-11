/* A Pseudo Random Number Generator - Mersenne twister
 * http://en.wikipedia.org/wiki/Mersenne_twister
 * http://my.opera.com/metrallik/blog/2013/04/19/c-class-for-random-generation-with-mersenne-twister-method
 */

#ifndef PSEUDORNG_HPP
#define PSEUDORNG_HPP

class PseudoRNG {
    private:
        static const unsigned int length=624;
        static const unsigned int bitMask_32=0xffffffff;
        static const unsigned int bitPow_31=1<<31;
        unsigned int mt[length];
        unsigned int idx;
    public:
        PseudoRNG(unsigned int seed);
        unsigned int get();
        void gen();
        ~PseudoRNG();
};

#endif
