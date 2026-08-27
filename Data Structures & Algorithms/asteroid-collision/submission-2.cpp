class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();
        stack<int> st;

        for(int i = 0 ; i < n ; i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else{
                //first negative element occurs
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop();
                }
                else if(st.empty() || st.top() < 0){ //surviving negative elements
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> ans(st.size());

        // Stack to vector
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;

        
    }
};