class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(source==nullptr) return -1;
        else if(target==nullptr) return -1;
        int len1 = strlen(source);
        int len2 = strlen(target);
        if(len1==0 && len2==0) return 0;
        else if(len1==0) return -1;
        else if(len2==0) return 0;
        
        char* ptr = (char*)source;
        char* ret = (char*)target;
        for(int i=0;i<len1;++i){
            int j=i;
            int k=0;
            while(ptr[j]==ret[k] && j<len1 && k<len2){
                j++;
                k++;
            }
            if(k==len2) return i;
        }
        
        return -1;
    }
};