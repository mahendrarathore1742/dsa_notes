#include <bits/stdc++.h>
using namespace std;

int fun(int days,int flag,vector<vector<int>> &nums,vector<vector<int>> &dp){

	if(days == nums.size()) return 0;

	if(dp[days][flag] != -1) return dp[days][flag];

	int maxi=0;

	if(flag==0){

		maxi = max(maxi,nums[days][1] + fun(days+1,1,nums,dp));
		maxi = max(maxi,nums[days][2] + fun(days+1,2,nums,dp));
		maxi = max(maxi,nums[days][3] + fun(days+1,3,nums,dp));

	} else if(flag==1){

		maxi = max(maxi,nums[days][2] + fun(days+1,2,nums,dp));
		maxi = max(maxi,nums[days][3] + fun(days+1,3,nums,dp));

	} else if(flag==2){

		maxi = max(maxi,nums[days][1] + fun(days+1,1,nums,dp));
		maxi = max(maxi,nums[days][3] + fun(days+1,3,nums,dp));
	} else{
		maxi = max(maxi,nums[days][1] + fun(days+1,1,nums,dp));
		maxi = max(maxi,nums[days][2] + fun(days+1,2,nums,dp));

	}

	return dp[days][flag] = maxi;
}

int main(){

	int n;
	cin>>n;

	vector<vector<int>> dp(n+1,vector<int>(4,-1));

	vector<vector<int>> nums(n,vector<int>(3));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <=3; ++j)
		{
			cin>>nums[i][j];	
		}
	}

	cout<<fun(0,0,nums,dp)<<endl;

}