/* Problem : Search Pattern - Robin-Karp Algorithm
Time Complexity : O(N+M)
Space Complexity : O(M)
*/


class Solution {
     pair<int,int> find_lps(string str1)
    {
         int n=str1.length();
        int lps[n];
        lps[0]=0;
        int len=0;
        int maxx=0;
        for(int i=1;i<n;)
        {
            if(str1[i]==str1[len])
            {
                len++;
                lps[i]=len;
                maxx=max(maxx,lps[i]);
                i++;
            }
            else
            {
                if(len>0)
                    len=lps[len-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return {lps[n-1],maxx};
    }
public:
    int repeatedStringMatch(string a, string b) {
        string s=b+"#"+a;
        auto [last,maxx]=find_lps(s);
        if(maxx==b.length())return 1;

        if(!last)return -1;
        int res=1e9;
        for(int i=-1;i<last;i++)
        {
            int temp=i==-1?0:1;
            int j;
            bool f=0;
            for(j=i+1;;j+=a.length())
            {
                if(j+a.length()>=b.length())break;
                if(b.substr(j,a.length())!=a){f=1;break;}
                temp++;
            }
            if(f)continue;
            if(j==b.length())res=min(res,temp);
            if(b.substr(j)!=a.substr(0,b.length()-j))continue;
            res=min(res,temp+1);
        }
        return res==1e9?-1:res;
    }
};
