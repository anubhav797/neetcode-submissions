class Solution {
public:
    int calPoints(vector<string>& operations) {

        vector<int> st;

        for(string op : operations){
            if(op == "C"){
                st.pop_back();
            }
            else if(op == "D"){
                st.push_back(2 * st.back());
            }
            else if(op == "+"){
                int last = st.back();
                int secondLast = st[st.size() - 2];

                st.push_back(last + secondLast);
            }
            else{
                st.push_back(stoi(op));
            }
        }

        int ans = 0;

        while(!st.empty()){
            ans = ans + st.back();
            st.pop_back();
        }

        return ans;
        
    }
};