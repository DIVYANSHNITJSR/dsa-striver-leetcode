class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int i=*min_element(bloomDay.begin(), bloomDay.end()), j=*max_element(bloomDay.begin(), bloomDay.end());
        while(i<j){
            int mid=i+(j-i)/2;
            int cnt=0, ans=0;
            for(auto it: bloomDay){
                if(it>mid){cnt=0;}
                else{
                    cnt++;
                    if(cnt==k){
                        cnt=0;
                        ans++;
                    }
                }
                if(ans>=m){break;}
            }
            if(ans>=m){j=mid;}
            else{i=mid+1;}
        }
        int cnt=0, ans=0;
        for(auto it: bloomDay){
            if(it>i){cnt=0;}
            else{
                cnt++;
                if(cnt==k){
                    cnt=0;
                    ans++;
                }
            }
            if(ans>=m){break;}
        }
        if(ans>=m){return i;}
        return -1;
    }
};



















// class Solution {
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
//          int min_day=-1;
//          int low=INT_MAX;
//          int high=INT_MIN;
//          for(int i=0;i<bloomDay.size();i++)
//          {
//              low=min(low,bloomDay[i]);
//              high=max(high,bloomDay[i]);
//          }
//          while (low<=high)
//          {
//              int mid=(low+high)/2;
//              if(bouquets_formed(bloomDay,m,k))
//                  min_day=mid;
//                  high=mid-1;
//               else
//                   low=mid+1;
//          }
//         return min_day;
         
         
//     }
//     public:
//          bool bouquets_formed(vector <int>& bloomDay,int m,int k)
//            {
//                int bouquets=0;
//                int h=k;
//                int low=INT_MAX;

//                for (int i=0;i<bloomDay.size();i++)
//                     {
//                           low=min(low,bloomDay[i]);
//                           high=max(high,bloomDay[i])
//                     }
//                 for(int i=low;i<=high;i++)
//                 {
//                     if(bloomDay[])
//                 }
//            }



// };