#include <iostream>
#include <vector>
#include <algorithm>
#define x first
#define y second

using namespace std;


int main(){
   int n, st, ed; 
   cin >> st >> ed >> n;
   vector<pair<int, int>> inte(n); 
   for(int i = 0; i < n; ++ i){
       cin >> inte[i].x >> inte[i].y;
   }
   sort(inte.begin(), inte.end());
   int res = 0;
   bool success = true;
   for(int i = 0; i < n; ++ i){
       int j = i, r = -2e9;
       while(j < n && inte[j].x <= st){
           r = max(r, inte[j].y);
           ++ j;
       }
       
       if(r < st){
           success = false;
           break;
       }
       res ++;
       st = r;
       if(st >= ed){
          break; 
       }
   }
   if(!success || st < ed) cout << -1 << endl;
   else
   cout << res << endl;
   return 0;
   
    
}
