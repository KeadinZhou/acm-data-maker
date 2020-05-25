#include "ACM_DATA_MAKER.H"

_Targs _args={
    {10,(int)1e2},
    {50,(int)1e3},
    {100,(int)1e6},
    {100,(int)1e9},
};

void randomData(Targs args){
    int N = args[0];
    int maxAI = args[1];

    writeln(N);
    writeln(randomVectorOfInt(N,0,maxAI));
}

void sp1(){
    writeln(10);
    writeln(1,2,3,4,5,6,7,8,9,10);
}

void sp2(){
    writeln(0);
    writeln(vector<int>());
}

int main(){
    makerInit();
    new RandomDataBuilder(_args,randomData);
    new SpecialDataBuilder({sp1,sp2});
}
