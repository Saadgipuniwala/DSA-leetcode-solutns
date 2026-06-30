class Solution {
private:
    bool valid(char ch){
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9')){
            return true;
        }
        return false;
    }

    char tolowercase(char ch){
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9')){
            return ch;
        }
        else{
            return ch - 'A' + 'a';
        }
    }

    bool checkpallindrome(string a){
        int s = 0;
        int e = a.length() - 1;

        while(s <= e){
            if(a[s] != a[e]){
                return false;
            }
            s++;
            e--;
        }

        return true;
    }

public:
    bool isPalindrome(string s) {

        string temp = "";

        for(int j = 0; j < s.length(); j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }

        for(int j = 0; j < temp.length(); j++){
            temp[j] = tolowercase(temp[j]);
        }

        return checkpallindrome(temp);
    }
};