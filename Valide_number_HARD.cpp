class Solution {
public:
    bool isNumber(string s) {
        if(s.length()==0)
            return 0;
        
        bool sign,exp,dec,num;
        sign=exp=dec=num=0;
        int i=0;
        while(i<s.length() && s[i]==' ')
            i++;
        int j=s.length()-1;
        while(j>=0 && s[j]==' ')
            j--;
        if(s[i]=='-'||s[i]=='+')
            sign=1,i++;
        while(i<=j){
            if(s[i]<'0'||s[i]>'9'){
                if(s[i]=='.'){
                    if(dec||exp)
                        return 0;
                    dec=1;
                }
                else if(s[i]=='e'){
                    if(num==0||exp)
                        return 0;
                    exp=1;
                    num=0;
                    if(i+1<s.length() && (s[i+1]=='-'||s[i+1]=='+'))
                        i++;
                }
                else
                return 0;
            }
            else
                num=1;
            i++;
            
        }
        return num;
    }   
};