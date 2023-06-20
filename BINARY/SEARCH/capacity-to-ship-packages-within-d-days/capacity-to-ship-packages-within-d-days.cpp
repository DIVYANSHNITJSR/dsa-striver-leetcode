class Solution { 
public:
    int shipWithinDays(vector<int>& weights, int days)
     {   int ans=-1;
        int low=1;
        int high=1e9;
        
        while (low<=high)
           {
               int mid=(low+high)/2;
               if(min_capacity_ship(weights,mid,days))
                   {ans=mid;
                     high=mid-1;
                   }
                else
                    low=mid+1;
           }
           return ans;
    }
    public:
        bool min_capacity_ship(vector <int>& weights,int mid,int days)
        { int needed_day=1;
            int sum=0;
            for(int i=0;i<weights.size();i++)
               {
                  if(weights[i]>mid)
                     return false;
                   if(sum+weights[i]>mid)
                    {
                        needed_day++;
                        sum=weights[i];
                    }
                    else
                     sum+=weights[i];
                      
                      
               }
            //    cout<<mid<<" " <<needed_day<<endl;
               return needed_day<=days;
        }
};