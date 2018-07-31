/*KMP algorithm*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenh = haystack.size();
        int lenn = needle.size();
        if (haystack.size() == 0 && needle.size() == 0 || needle.size() == 0)
            return 0;

        vector<int> next(lenn);
        
        getnextval(needle,next);
        int i = 0, j = 0;

        while(i < lenh && j < lenn){
            if(j == -1 || haystack[i] == needle[j]){
                ++i;
                ++j;
            }
            else{
                j = next[j];
            }
        }
        
        if(j == lenn){
            return i - j;
        }
        else{
            return -1;
        }
        
    }
    
private:
    void getnextval(string needle, vector<int>& next){
        int len = needle.size();
        next[0] = -1;
        int k = -1;
        int j = 0;
        while(j < len - 1){
            if(k == -1 || needle[k] == needle[j]){
                ++j;
                ++k;
                if(needle[k] != needle[j]){
                  next[j] = k;
                }
                else{
                    next[j] = next[k];
                }
            }
            else{
                k = next[k];
            }
        }
    }
};