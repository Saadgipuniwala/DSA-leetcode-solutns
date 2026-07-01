class Solution {
private:

    
    bool checkEqual(int count1[26], int count2[26]) {
        for(int i = 0; i < 26; i++) {
            if(count1[i] != count2[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {

        
        if(s1.length() > s2.length()) {
            return false;
        }

        
        int count1[26] = {0};

        for(int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        
        int count2[26] = {0};

        int windowSize = s1.length();
        int i = 0;

        
        while(i < windowSize) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        
        if(checkEqual(count1, count2)) {
            return true;
        }

        
        while(i < s2.length()) {

            
            int newIndex = s2[i] - 'a';
            count2[newIndex]++;

            
            int oldIndex = s2[i - windowSize] - 'a';
            count2[oldIndex]--;

            
            if(checkEqual(count1, count2)) {
                return true;
            }

            i++;
        }

        return false;
    }
};