class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { //use priority queue
        map<int, int> freq;
        vector<int> top;
        map<int, int>::iterator iter;

        for (int i=0; i<nums.size(); i++) { //calculate element frequency
            iter = freq.find(nums[i]);
            if (iter == freq.end()) {
                freq[nums[i]] = 1;
            }else{
                freq[nums[i]]++;
            }
        }

        vector<int> pq;
        int i, temp;
        for (iter = freq.begin(); iter != freq.end(); iter++) { //bubble up
            pq.push_back(iter->first);
            i = pq.size()-1;
            while(i > 0 && (freq[pq[i]] > freq[pq[(i-1)/2]])) {
                temp = pq[i];
                pq[i] = pq[(i-1)/2];
                pq[(i-1)/2] = temp;
                i = (i-1)/2;
            }
        }

        for (iter = freq.begin(); iter != freq.end(); iter++) {
            cout << iter->first << "-" << iter->second << endl;
        }

        for (int i=0; i<pq.size(); i++) {
            cout << pq[i] << " ";
        }
        cout << endl;

      //  i = 0;
        for (int j=0; j<k; j++) {   //bubble down
            i = 0;
            top.push_back(pq[0]);
            pq[0] = pq[pq.size()-1];
            pq.pop_back();
            while (2*i+2 <= pq.size()) {    
                if ((2*i+2) == pq.size() && freq[pq[i]] < freq[pq[2*i+1]]) {    //node has 1 child
                    temp = pq[i];
                    pq[i] = pq[i*2+1];
                    pq[i*2+1] = temp;
                    i = i*2+1;
                } else if ((2*i+2) < pq.size() &&
                        (freq[pq[i]] < freq[pq[2*i+1]] || freq[pq[i]] < freq[pq[2*i+2]])) { //node has 2 children
                    int s = (freq[pq[2*i+1]] > freq[pq[2*i+2]]? 2*i+1:2*i+2);
                    temp = pq[i];
                    pq[i] = pq[s];
                    pq[s] = temp;
                    i = s;
                } else break;
            }
        }

        return top;
    }
};
