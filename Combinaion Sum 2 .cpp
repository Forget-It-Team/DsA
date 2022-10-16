//Question Combination sum2
//Given an array of integers arr, length of the array  N and an integer K, find all the unique combinations in arr where the sum of the combination is equal to K.
//Each number can only be used once in a combination.

private:
    void getAns(vector<int>arr,int target,vector<vector<int>>&output, vector<int>&answer,int index)
    {
        
        if(target==0)
        {
            output.push_back(answer);
            return;
        }
        
        for(int i=index;i<arr.size();i++)
        {
          // as we dont want to take the same copy of the element so we taking a check step 
          // if both the previsos element and new elemnt are same then we will skip the index
          
            if(i>index and arr[i]==arr[i-1]) continue;
            
          // if target element become smaller than the current element then break as this will not give the write answer
            if(arr[i]>target)break;
            
                answer.push_back(arr[i]);
                getAns(arr,target-arr[i],output,answer,i+1);   
                answer.pop_back();
            
        }
        
    }

public:


    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        
        vector<int>answer;
        vector<vector<int>>output;
        
        sort(arr.begin(),arr.end());
        getAns(arr,k,output,answer,0);
        
        return output;
        
    }
};
