vector<int> prefix(string s){
  int N = s.size();
  vector<int> prefix_arr(N, 0);

  for(int i = 1; i < N; i++){
    int j = prefix_arr[i - 1];

    while(j > 0 and s[i] != s[j]) j = prefix_arr[j - 1];

    if(s[i] == s[j]) j ++;
      prefix_arr[i] = j;
    }
  
  return prefix_arr;
};
