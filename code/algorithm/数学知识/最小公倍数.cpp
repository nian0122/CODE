int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}