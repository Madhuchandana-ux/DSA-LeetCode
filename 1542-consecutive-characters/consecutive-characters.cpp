class Solution {
public:
    int maxPower(string s) {
       int cnt=1;
       int maxi=1;
        for(int i=1;i<s.length();i++){
if(s[i]==s[i-1]){
    cnt++;
    maxi=max(maxi,cnt);

}
else{
    cnt=1;
}
        }
        return maxi;
        
    }
};