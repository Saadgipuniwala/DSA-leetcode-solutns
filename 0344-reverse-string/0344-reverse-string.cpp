/*class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0, e=s.size()-1;
        while(st<e){
            swap(s[st++],s[e--]);
        }

    }
};*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        // Push all characters into the stack
        for (char ch : s) {
            st.push(ch);
        }

        // Pop back into the vector
        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};