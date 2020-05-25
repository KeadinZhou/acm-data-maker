/// By @KeadinZhou
/// Version @0.3

#ifndef _KEADIN_ACM_DATA_MAKER_H
#define _KEADIN_ACM_DATA_MAKER_H

#define _KEADIN_ACM_DATA_MAKER_VERSION "0.3"

/// stdc++
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ll long long


///////////////////////////////////////
#ifndef _KEADIN_SIMPLE_OUT
#define _KEADIN_SIMPLE_OUT

/// Simple Out
#define lnn putchar('\n')
#define see putchar(' ')
string vectorSpacing=" ";
void changeVectorSpacing(string s){
    vectorSpacing=s;
}

template <typename T>
ostream& operator<<(ostream& out,vector<T> vec){
    for(typename vector<T>::iterator ite(vec.begin()); ite!=vec.end();ite++){
        out<<*ite;
        if(vec.end()!=ite+1) cout<<vectorSpacing;
    }
    return out;
}

template<typename T>
inline void write(T x) {
    cout<<x;
}

template<typename T, typename... REST>
inline void write(T x, REST... rest) {
    write(x),see;
    write(rest...);
}

template<typename... REST>
inline void writeln(REST... rest) {
    write(rest...),lnn;
}

#endif // _KEADIN_SIMPLE_OUT
///////////////////////////////////////



///////////////////////////////////////
#ifndef _KEADIN_FILE_GENERATE
#define _KEADIN_FILE_GENERATE

#define MAX_FILENAME_LEN 100
char name[MAX_FILENAME_LEN];
const char* getName(int x,char ex[],int bit=0){
    string Name="";

    if(!x) Name="0";
    while(x){
        Name=char(x%10+'0')+Name;
        x/=10;
    }
    int len=Name.size();
    for(int i=len;i<bit;i++) Name='0'+Name;

    Name+='.';

    for(int i=0;ex[i];i++) Name+=ex[i];

    Name="_data/"+Name;

    const char* out=Name.c_str();
    for(int i=0;name[i]=out[i];i++);
    return name;
}

int newFile(){
    static int index=0;
    freopen(getName(++index,"in"),"w",stdout);
    return index;
}

int newFile(int index){
    freopen(getName(index,"in"),"w",stdout);
    return index;
}

void backToTerminal(){
    freopen("CON","w",stdout);
}

#endif // _KEADIN_FILE_GENERATE
///////////////////////////////////////



///////////////////////////////////////
#ifndef _KEADIN_DATA_GENERATE
#define _KEADIN_DATA_GENERATE

void randInit(){
    static bool _f=false;
    if(!_f){
        srand(time(NULL));
        _f=true;
    }
}

int randomInt(){
    randInit();
    return rand();
}

int randomInt(int MIN,int MAX){

    assert(MIN<=MAX);
    assert(MIN>=0);
    assert(MAX<=32768);

    randInit();
    return rand()%(MAX-MIN+1)+MIN;
}

#include <windows.h>
#include <sys/time.h>
LL getCurrentTime(){    /// by @taoting
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*1000+tv.tv_usec/1000;
}

static default_random_engine e(getCurrentTime());
LL randomBigInt(LL MIN, LL MAX) {    /// by @taoting
    uniform_int_distribution<LL> u(MIN, MAX);
    return u(e);
}

double randomDouble(LL MIN, LL MAX) {
    uniform_real_distribution<double> u(MIN, MAX);
    return u(e);
}

const string LOWERCASE_STRING = "abcdefghijklmnopqrstuvwxyz";
const string UPPERCASE_STRING = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string DIGIT_STRING = "0123456789";
const string ALPHA_STRING = LOWERCASE_STRING + UPPERCASE_STRING;
string randomString(int len,string pool=ALPHA_STRING){
    string res="";
    while(res.size()<len){
        res+=pool[randomInt(0,pool.size()-1)];
    }
    return res;
}

vector<int>randomVectorOfInt(int len,int MIN,int MAX,bool distinct=false){
    assert(!distinct || len<=MAX-MIN+1);
    vector<int>res;
    set<int>se;
    while(res.size()<len){
        int tmp = randomBigInt(MIN,MAX);
        if(!distinct || se.insert(tmp).second){
            res.push_back(tmp);
        }
    }
    return res;
}

vector<int>randomVectorOfIntWithInit(int len,int MIN,int MAX,vector<int> initVe,bool distinct=false){
    vector<int>res=initVe;
    set<int>se;
    for(auto it:initVe) se.insert(it);
    while(res.size()<len){
        int tmp = randomBigInt(MIN,MAX);
        if(!distinct || se.insert(tmp).second){
            res.push_back(tmp);
        }
    }
    return res;
}

vector<int>randomVectorOfIntWithSumLimit(int len,int MIN,int MAX,int sumLimit){
    assert(sumLimit>=len*MIN && sumLimit<=len*MAX);
    vector<int>res;
    int _rest=sumLimit-len*MIN;
    for(int i=0;i<len;i++){
        res.push_back(MIN);
    }
    while(_rest){
        int _index=randomBigInt(0,len-1);
        if(res[_index]+1>MAX){
            continue;
        }
        res[_index]++;
        _rest--;
    }
    return res;
}

vector<LL>randomVectorOfLLWithSumLimit(int len,LL MIN,LL MAX,LL sumLimit){
    assert(sumLimit>=len*MIN && sumLimit<=len*MAX);
    vector<LL>res;
    LL _rest=sumLimit-len*MIN;
    for(int i=0;i<len;i++){
        res.push_back(MIN);
    }
    while(_rest){
        int _index=randomBigInt(0,len-1);
        if(res[_index]+1>MAX){
            continue;
        }
        res[_index]++;
        _rest--;
    }
    return res;
}

vector<LL>randomVectorOfLL(int len,LL MIN,LL MAX,bool distinct=false){
    assert(!distinct || len<=MAX-MIN+1);
    vector<LL>res;
    set<LL>se;
    while(res.size()<len){
        LL tmp = randomBigInt(MIN,MAX);
        if(!distinct || se.insert(tmp).second){
            res.push_back(tmp);
        }
    }
    return res;
}

vector<string>randomVectorOfString(int len,int minStringLen,int maxStringLen,string pool,bool distinct=false){
    vector<string>res;
    set<string>se;
    while(res.size()<len){
        string tmp = randomString(randomBigInt(minStringLen,maxStringLen),pool);
        if(!distinct || se.insert(tmp).second){
            res.push_back(tmp);
        }
    }
    return res;
}

vector<string>randomVectorOfStringWithSumLimit(int len,int sumLimit,string pool){
    vector<string> res;
    vector<int> _len = randomVectorOfIntWithSumLimit(len,1,sumLimit,sumLimit);
    for(auto it:_len){
        res.push_back(randomString(it,pool));
    }
    return res;
}

vector<string>randomVectorOfStringWithSumLimitAndEachLimit(int len,int minEach,int maxEach,int sumLimit,string pool){
    vector<string> res;
    vector<int> _len = randomVectorOfIntWithSumLimit(len,minEach,maxEach,sumLimit);
    for(auto it:_len){
        res.push_back(randomString(it,pool));
    }
    return res;
}

#endif // _KEADIN_DATA_GENERATE
///////////////////////////////////////



///////////////////////////////////////
#ifndef _KEADIN_DATA_BUILDER
#define _KEADIN_DATA_BUILDER

typedef vector<int> Targs;
typedef vector<Targs> _Targs;

class RandomDataBuilder{
public:
    RandomDataBuilder(_Targs args,void(*func)(Targs)){
        int _cnt=0;
        for(auto it:args){
            int _index=newFile();
            func(it);
            backToTerminal();
            writeln("RandomDataBuilder write to {#",_index,".in} done.  (",++_cnt,'/',args.size(),')');
        }
    }
};

class SpecialDataBuilder{
public:
    SpecialDataBuilder(vector<void(*)()> sp_list){
        int _cnt=0;
        for(auto it:sp_list){
            int _index=newFile();
            it();
            backToTerminal();
            writeln("SpecialDataBuilder write to {#",_index,".in} done.  (",++_cnt,'/',sp_list.size(),')');
        }
    }
};

#endif // _KEADIN_DATA_BUILDER
///////////////////////////////////////



///////////////////////////////////////
#ifndef _KEADIN_OUT_MAKER
#define _KEADIN_OUT_MAKER

void writeWindowsScript(){
    freopen("_data/__makeout.bat","w",stdout);
    puts("g++ std.cpp -o std.exe -std=c++11");
    puts("for /L %%i in (0,1,100) do (");
    puts("	if exist %%i.in (");
    puts("		python __win2nix.py %%i.in %%i.in");
    puts("		std.exe <%%i.in >%%i.out");
    puts("		python __win2nix.py %%i.out %%i.out");
    puts("	)");
    puts(")");
    puts("del *.ans");
    puts("ren *.out *.ans");
    puts("del std.exe");
    puts("del __win2nix.py");
//    puts("pause");
    puts("del __makeout.bat");
}

void writePythonScript(){
    freopen("_data/__win2nix.py","w",stdout);
    puts("import sys");
    puts("def fixed(path_input, path_output):");
    puts("    file_input = open(path_input, 'rb')");
    puts("    all_text = None");
    puts("    try:");
    puts("        all_text = file_input.read()");
    puts("    except:");
    puts("        print(\"read %s failed!\" % path)");
    puts("        return");
    puts("    finally:");
    puts("        file_input.close()");
    puts("    all_text = all_text.replace(b'\\r\\n', b'\\n')");
    puts("    file_output = open(path_output, 'wb')");
    puts("    file_output.write(all_text)");
    puts("    file_output.close()");
    puts("");
    puts("if __name__ == \"__main__\":");
    puts("    if len(sys.argv) == 3:");
    puts("        fixed(sys.argv[1], sys.argv[2])");
    puts("    elif len(sys.argv) == 2:");
    puts("        fixed(sys.argv[1], sys.argv[1])");
    puts("    else:");
    puts("        print(\"need more argument\")");
}

void makerInit(){
    puts("ACM Data Maker");
    puts("By @KeadinZhou");
    printf("Version ");
    puts(_KEADIN_ACM_DATA_MAKER_VERSION);
    puts("");
    puts("");
    system("mkdir _data");
    system("copy std.cpp _data\\std.cpp");
    system("explorer _data");
    writeWindowsScript();
    writePythonScript();
    backToTerminal();
    writeln("");
    writeln("DataMaker is running...");
    writeln("");
}

#endif // _KEADIN_OUT_MAKER
///////////////////////////////////////

#endif // _KEADIN_ACM_DATA_MAKER_H
