#define _CRT_DISABLE_PERFCRIT_LOCKS
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;

/*MACROS*/
//FUNCTIONS
#define in_range(i, l, r) for(ll i = l; i < r; i++)

#define all(v) begin(v), end(v)
#define rall(v) (v).rbegin(), (v).rend()

#define tr(it, container) for(auto it = begin(container); it != end(container); it++)
#define rtr(it, container) for(auto it = (container).rbegin(); it != (container).rend(); it++)

#define present(element, container) ((container).find(element) != end(container))

//ABBREVIATIONS
#define sz(c) (ll(c.size()))
#define pb push_back
#define fst first
#define scd second
#define cmpBy(T, field) [](const T& x, const T& y){ return x.field < y.field; }

//TYPE SAFETY
#define sqrt(x) sqrt(1.0*(x))
#define pow(x, n) pow(1.0*(x), n)

//CONSTANTS
#define INF INT_MAX
#define MINF INT_MIN
#define LINF LONG_LONG_MAX
#define LMINF LONG_LONG_MIN
#define EPS (double)1e-9
#define PI (long double)3.14159265358979311600

/*TYPES*/
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*TEMPLATE FUNCTIONS*/
//BIT OPERATIONS
template<typename T> inline int checkbit(T n, T i){return ((n >> i) & T(1));}
inline int bitcount(int n){return __builtin_popcount(n); }
inline int bitcount(ll n){return __builtin_popcountll(n); }
template<typename T> inline bool isPowerOfTwo(T n){return (n != 0 and ((n&(n-1)) == 0)); }
inline int binlog(int n){ assert(n > 0); return 32-__builtin_clz(n)-1; }
inline int binlog(ll n) { assert(n > 0); return 64-__builtin_clzll(n)-1;  }
template<typename A, typename B, typename C>
function<C(A)> combine(function<B(A)> f, function<C(B)> g) {
    return bind(g, bind(f, placeholders::_1));
}

/*TEMPLATE ALGORITHMS*/
template<typename T> inline T sqr(T x){T x_ = (x); return x_*x_;}
template<typename T> inline T qbr(T x){T x_ = (x); return ((x_*x_)*x_);}
template<typename T> inline int sign(T x){T x_ = (x); return ((x_>T(0))-(x_<T(0)));}
template<typename T> inline T mod(T x, T m){T x_ = (x); return (((x_) >= 0) ? ((x_) % (m)) : ((((x_) % (m))+(m))%(m)));}
template<typename T> inline T gcd(T a, T b){while(b){T t = a % b; a = b; b = t;} return a;}
template<typename T> inline T gcd_ex(T a, T b, T& x, T& y){if(b==0){x=1,y=0; return a;}T x1, y1;T d=gcd_ex(b,a%b,x1,y1);x = y1;y = x1-(a/b)*y1;return d;}
template<typename T> inline T lcm(T a, T b){return (a*(b/gcd(a, b)));}

/*COMBINATORS*/
template <typename Collection, typename UnaryOperation> void foreach(Collection &col, UnaryOperation op){for_each(all(col), op);}
template <typename Collection, typename UnaryOperation> Collection fmap(Collection &col, UnaryOperation op){transform(all(col), col.begin(), op); return col;}
template <typename Collection, typename binop> Collection zip(Collection& fc, Collection& sc,binop op) {transform(all(fc), sc.begin(), fc.begin(), op); return fc;}
template <typename Collection, typename Condition> bool exists(Collection& col,Condition con) {auto exist = find_if(all(col), con); return exist != col.end();}
template <typename Collection, typename Predicate> Collection filterNot(Collection& col, Predicate predicate) {auto returnIterator = remove_if(all(col), predicate); col.erase(returnIterator, end(col)); return col;}

//STL INPUT
template<class T1, class T2> istream& operator >>(istream& in, pair<T1, T2>& P){in >> P.fst >> P.scd; return in;}
template<class T> istream& operator >>(istream& in, vector<T>& Col){for(auto &el : Col) in >> el; return in;}

//STL OUTPUT
template<class T1, class T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p){os << "(" << p.fst << ", " << p.scd << ")"; return os;}
template<class T> ostream& operator <<(ostream& os, const vector<vector<T>>& v){for(auto &row : v){ for(auto &el : row) os << el << " "; os << "\n";} return os;}
template<class T> ostream& operator <<(ostream& os, const vector<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> ostream& operator <<(ostream& os, const set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T1, class T2> ostream& operator <<(ostream& os, const map<T1, T2>& Col){for(auto &el : Col) os << el << " "; return os;}

//VARIADIC INPUT
template<typename First> void read(First& t){ cin >> t; }
template<typename First, typename... Args> void read(First& f, Args&... args){ cin >> f; read(forward<Args&>(args)...); }

//VARIADIC OUTPUT
template<typename T> void print(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void print(First&& f, Args&&... args){ cout << f << " "; print(forward<Args&&>(args)...); }
template<typename T> void printLn(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void printLn(First&& f, Args&&... args){ cout << f << "\n"; printLn(forward<Args&&>(args)...); }

//VARIADIC TYPE DECLARATION
template <typename T, size_t N> struct MakeTensor{ template <typename... Args> static auto make_tensor(size_t first, Args... sizes) -> vector<decltype(MakeTensor<T, N-1>::make_tensor(sizes...))> { auto inner = MakeTensor<T, N-1>::make_tensor(sizes...); return vector<decltype(inner)>(first, inner);} };
template <typename T> struct MakeTensor<T, 1> { static vector<T> make_tensor(size_t size) { return vector<T>(size); }};
template <typename T, typename... Args> auto make_tensor(Args... args) -> decltype(MakeTensor<T, sizeof...(Args)>::make_tensor(args...)){ return MakeTensor<T, sizeof...(Args)>::make_tensor(args...); }

//__int128 -- use if supported
//typedef __int128 bigInt;
//istream& operator >>(istream& in, bigInt& n){
//    in >> ws; n = 0;
//    for(char ch = getchar(); isdigit(ch); ch = getchar()){
//        n = n*bigInt(10) + bigInt(ch-'0');
//    }
//    return in;
//}
//ostream& operator <<(ostream& out, bigInt n){
//    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int representation[36];
//    int pos = 0;
//    while(n){
//        representation[pos++] = digits[n % 10];
//        n /= 10;
//    }
//    for(int i = pos-1; i >= 0; i--){
//        out << representation[i];
//    }
//    return out;
//}

//DEBUG
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)         cerr<<#a<<" = "<<(a)<<"\n"
#define DBN2(a,b)       cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<"\n"
#define DBN3(a,b,c)     cerr<<#a<<" = "<<(a)<<", "<<#b<<" = " <<(b)<<", "<<#c<<" = "<<(c)<<"\n"
#define DBN4(a,b,c,d)   cerr<<#a<<" = "<<(a)<<", "<<#b<<" ="<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)

//#define DEBUG

//EXTREMELY FAST I/O
/*const int BUFFSIZE = 2048;
static char inbuff[BUFFSIZE + 16];
static char *inp = inbuff;
static char *linp = inbuff + BUFFSIZE;

int read_int(){
	while (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
	bool minus = false;
	if (*inp == '-') minus = true, ++inp;
	if (*inp == 0) {
		memset(inbuff, 0, BUFFSIZE);
		cin.read(inbuff, BUFFSIZE);
		inp = inbuff;
	}
	int res = *inp++ - '0';
	if (inp == linp) {
		memset(inbuff, 0, BUFFSIZE);
		cin.read(inbuff, BUFFSIZE);
		inp = inbuff;
	}
	while (*inp >= '0' && *inp <= '9') {
		res = res*10 + *inp - '0';
		++inp;
		if (inp == linp) {
			memset(inbuff, 0, BUFFSIZE);
			cin.read(inbuff, BUFFSIZE);
			inp = inbuff;
		}
	}
	return minus ? -res : res;
}

static char outbuff[BUFFSIZE + 16];
static char *outp = outbuff;
static char *loutp = outbuff+BUFFSIZE;

void write_int(int x, bool last = false) {
	char *begp = outp;
	while(x) {
		int quot = x/10;
		char c = x - 10*quot + '0';
		*outp++ = c;
		x = quot;
	}
	char *endp = outp-1;
	while(begp < endp) {
		swap(*begp, *endp);
		++begp, --endp;
	}
	*outp++ = '\n';
	if (last || outp > loutp) {
		cout.write(outbuff, outp - outbuff);
		outp = outbuff;
	}
}
*/

void fastIO(){ ios::sync_with_stdio(false); cin.tie(nullptr); }

typedef pair<double, double> point_t;
typedef pair<point_t, point_t> points_t;

inline double d(double x1, double x2){ return abs(x1-x2); }
inline double d(point_t p1, point_t p2) { return hypot(p1.fst-p2.fst, p1.scd-p2.scd); }

//requires sorted (along some axis) array S
pair<double, pair<double, double>> CP_1D_brute (const vector<double>& S) {
    if (sz(S) < 2) { return {1e20, {0, 0}}; }

    pair<double, pair<double, double>> result = {d(S[0], S[1]), {S[0], S[1]}};
    for (auto i = begin(S); i != (end(S)-1); i++) {
        for (auto j = i+1; j != end(S); j++) {
            double newDistance = d(*j, *i);
            if (newDistance < result.fst) {
                result = {newDistance, {*i, *j}};
            }
        }
    }
    return result;
}
pair<double, pair<double, double>> ClosestPoints1D (const vector<double>& S) {
    int N = sz(S);
    if (N <= 3){
        return CP_1D_brute(S);
    }
    vector<double> S1(begin(S), begin(S) + N/2);
    vector<double> S2(begin(S)+N/2, end(S));
    auto p1 = ClosestPoints1D(S1);
    auto p2 = ClosestPoints1D(S2);
    auto minPair = (p1.fst < p2.fst) ? p1 : p2;
    auto result = minPair;
    vector<double> S12;
    double M = S[N/2];
    copy_if(all(S), back_inserter(S12), [&minPair, &M](const double& x){
        return d(x, M) < minPair.fst;
    });
    if (sz(S12) >= 2) {
        for (auto i = begin(S); i != (end(S)-1); i++) {
            for (auto j = i+1; j != end(S); j++) {
                double newDistance = d(*j, *i);
                if (newDistance < result.fst) {
                    result = {newDistance, {*j, *i}};
                }
            }
        }
    }
    return result;
}
pair<double, points_t> CP_2D_brute (const vector<point_t>& S) {
    if (sz(S) < 2) { return {1e20, {{0, 0}, {0, 0}}}; }

    pair<double, points_t> result = {d(S[0], S[1]), {S[0], S[1]}};
    for (auto i = begin(S); i != (end(S)-1); i++) {
        for (auto j = i+1; j <= end(S); j++) {
            double newDistance = d(*i, *j);
            if (newDistance < result.fst) {
                result = {newDistance, {*i, *j}};
            }
        }
    }
    return result;
}
pair<double, points_t> ClosestPoints2D (const vector<point_t>& xS, const vector<point_t>& yS) {
    int N = sz(xS);
    if (N <= 3) {
        return CP_2D_brute(xS);
    }

    double xM = xS[N/2].fst;
    vector<point_t> xL (begin(xS), begin(xS)+N/2);
    vector<point_t> xR (begin(xS)+N/2, end(xS));
    vector<point_t> yL, yR;
    copy_if(all(yS), back_inserter(yL), [&xM](const point_t& p){
        return p.fst <= xM;
    });
    copy_if(all(yS), back_inserter(yR), [&xM](const point_t& p){
        return p.fst > xM;
    });
    auto p1 = ClosestPoints2D (xL, yL);
    auto p2 = ClosestPoints2D (xR, yR);
    auto minPair = (p1.fst < p2.fst) ? p1 : p2;
    vector<point_t> yP;
    copy_if(all(yS), back_inserter(yP), [&xM, &minPair](const point_t& p){
        return d(p.fst, xM) < minPair.fst;
    });
    auto result = minPair;
    if (sz(yP) >= 2) {
        for (auto i = begin(yP); i != (end(yP)-1); i++) {
            for (auto j = i+1; j != end(yP) && (d(j->scd, i->scd) < minPair.fst); j++) {
                double newDistance = d(*j, *i);
                if (newDistance < result.fst) {
                    result = {newDistance, {*j, *i}};
                }
           }
        }
    }
    return result;
};

int main(){
//    fastIO();
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
     default_random_engine re(chrono::system_clock::to_time_t(chrono::system_clock::now()));
     uniform_real_distribution<double> urd(-500.0, 500.0);
     vector<double> points1D(100);
     generate(all(points1D), [&urd, &re](){
         return 1000 + urd(re);
     });
     sort(all(points1D));
     auto answer1D = ClosestPoints1D(points1D);
     print(answer1D);
     vector<point_t> points2D(100);
     generate(all(points2D), [&urd, &re](){
         return point_t {1000 + urd(re), 1000 + urd(re)};
     });
     sort(all(points2D), cmpBy(point_t, fst));
     auto xS = points2D;
     sort(all(points2D), cmpBy(point_t, scd));
     auto yS = points2D;
     auto answer2D = ClosestPoints2D(xS, yS);
     print(answer2D);
    return 0;
}
