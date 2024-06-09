class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        std::vector<int> ret(size, 0);
        std::stack<int> st;
        for (int i = 0; i < size; i++) {
            if (st.empty()) {
                st.push(i);
                continue;
            }
            while (!st.empty()) {
                int index = st.top();
                int v = temperatures[index];
                int cur_v = temperatures[i];
                if (cur_v > v) {
                    ret[index] = i - index;
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(i);
        }
        while(!st.empty()) {
            int index = st.top();
            ret[index] = 0;
            st.pop();
        }

        return ret;
    }
};