class Solution {
public:

int breaking(int n){
    int rem;
    int sum = 0;
    while(n != 0){
        int rem = n % 10;
        n = n / 10;
        sum += rem*rem;
    }
    return sum;
}
    bool isHappy(int n) {
    unordered_set<int> seen;
       while(n != 1 && seen.find(n) == seen.end()){
        seen.insert(n);
        n = breaking(n);
       }
        return n ==  1;
    }
};