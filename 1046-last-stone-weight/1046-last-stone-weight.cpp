class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int x : stones) {
            pq.push(x);
        }

        while(pq.size() > 1) {
            int largest = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            if(largest != second) {
                pq.push(largest - second);
            }
        }

        if(pq.empty()) return 0;

        return pq.top();
    }
};