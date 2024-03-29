string removeKdigits(string s, int k){
  stack<char>st;
  int c=0;
  for(int i=0;i<s.size();i++){
      if(!st.empty() && st.top()>s[i]){
          while(!st.empty() && st.top()>s[i] && c<k){
              st.pop();
              c++;
          }
          st.push(s[i]);
      }
      else{
          st.push(s[i]);
      }
  }
  string ans;
  while(c<k and !st.empty()){
      st.pop();
      c++;
  }
  while(!st.empty()){
      ans+=st.top();
      st.pop();
  }
  
  for(int j=ans.size()-1;j>=0;j--){
      if(ans[j]!='0') break;
      else ans.erase(j,1);
  }
  reverse(ans.begin(),ans.end());
  if(ans.size()==0) return "0";
  return ans;
}
