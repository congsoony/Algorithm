#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> num={0,4,5,6,1,2,3};

//https://www.geogebra.org/m/adpwcpvb 정육면체 전개도 참고
vector<vector<int>>rec[11]={
   {
      {3,0,0,0},
      {1,2,4,5},
      {6,0,0,0}
   },
   {
      {0,6,0,0},
      {1,2,4,5},
      {3,0,0,0}
   },
   {
      {0,0,3,0},
      {4,5,1,2},
      {6,0,0,0}
   },
   {
      {0,0,0,6},
      {2,1,5,4},
      {3,0,0,0}
   },
   {
      {0,3,0,0},
      {1,2,4,5},
      {0,6,0,0}
   },
   {
      {0,0,6,0},
      {1,2,4,5},
      {0,3,0,0}
   },
   {
      {0,0,3,5,6},
      {1,2,4,0,0}
   },
   {
      {0,0,5,6},
      {0,3,4,0},
      {1,2,0,0}
   },
   {
      {0,0,3,4},
      {2,1,5,0},
      {6,0,0,0}
   },
   {
      {5,3,0,0},
      {0,1,2,4},
      {0,6,0,0}
   },
   {
      {0,3,0,0},
      {1,2,4,0},
      {0,0,6,5}
   }
};
vector<vector<vector<int>>> diagram[11];
vector<vector<int>> board;


vector<vector<int>> reverse(vector<vector<int>> &v){
   int n = v.size();
   int m = v[0].size();
   vector<vector<int>> temp=v;
   for(int i =0;i<n;i++){
      for(int j =0,j2=m-1;j<m/2;j++,j2--){
         swap(temp[i][j],temp[i][j2]);
      }
   }
   return temp;
}
vector<vector<int>> rotate(vector<vector<int>> &v){
   int n = v.size();
   int m = v[0].size();
   vector<vector<int>> temp(m,vector<int>(n));
   for(int i =0,j2=n-1;i<n;i++,j2--){
      for(int j =0,i2=0;j<m;j++,i2++){
         temp[i2][j2]=v[i][j];
      }
   }

   return temp;
}
void input() {
   board =vector<vector<int>>(6,vector<int>(6));
   for(int i =0;i<6;i++){
      for(int j =0;j<6;j++){
         cin>>board[i][j];
      }
   }
}

int check(vector<vector<int>> &v,int y,int x){
   int n = v.size();
   int m = v[0].size();
   int cnt = 0;
   int cy=0,cx=0;
   for(int i =0;i<n;i++){
      for(int j =0;j<m;j++){
         if(board[y+i][x+j] && v[i][j])
            cnt++;
         if(board[y+i][x+j]==1){
            cy=i;
            cx=j;
         }
      }
   }
   if(cnt==6){
      for(int i =0;i<n;i++){
         for(int j=0;j<m;j++){
            if(num[v[cy][cx]]==v[i][j]){
               return board[y+i][x+j];
            }
         }
      }
   }
   return -1;
}



void solve() {
   
   for(int i =0;i<11;i++){
      vector<vector<int>> temp = rec[i], rtemp = reverse(rec[i]);
      for(int j=0;j<4;j++){
         diagram[i].push_back(temp);
         diagram[i].push_back(rtemp);
         temp = rotate(temp);
         rtemp = rotate(rtemp);
      }
   }
   for(int i=0;i<11;i++){
      for(int j=0;j<diagram[i].size();j++){
         int n = diagram[i][j].size();
         int m = diagram[i][j][0].size();
         for(int y=0;y<=6-n;y++){
            for(int x =0 ;x<=6-m;x++){
               int c =check(diagram[i][j],y,x); 
               if(c!=-1){
                  cout<<c<<"\n";
                  return;
               }
            }
         }
      }
   }
   cout<<0<<"\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	input();
   solve();
 
}