using namespace std;

int gcd (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
    
}

long long solution(int w,int h) {
    long long answer = 1;
    answer = (long long)w * (long long)h - (w + h) + gcd(w, h);
    return answer;
}