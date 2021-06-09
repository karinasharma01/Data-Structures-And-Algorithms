class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(k==1)
            return "";
        //stack to store charcters & their consecutive frequencies
        stack<pair<char,int>> st;
        for(int i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                st.push(make_pair(s[i],1));
            }
            else
            {
                if(s[i]==(st.top().first))
                {
                    st.push(make_pair(s[i],st.top().second+1));
                    if(st.top().second==k)
                    {
                        int count = k;
                        while(count--)
                        {
                            st.pop();
                        }
                    }
                }
                else
                {
                    st.push(make_pair(s[i],1));
                }
            }
        }
        string res;
        while(!st.empty())
        {
            char ch=st.top().first;
            res+=ch;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
