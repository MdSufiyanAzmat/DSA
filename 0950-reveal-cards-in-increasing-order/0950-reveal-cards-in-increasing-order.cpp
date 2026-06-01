class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> res(n);
        deque<int> d;
        for(int i=0; i<n; i++){
            d.push_back(i);
        }
        for(int i=0; i<n; i++){
            int idx = d.front();
            d.pop_front();
            res[idx] = deck[i];
            if(!d.empty()){
                d.push_back(d.front());
                d.pop_front();
            }
        }
        return res;
    }
};