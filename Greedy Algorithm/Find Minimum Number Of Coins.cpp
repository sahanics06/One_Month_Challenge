/*
Problem statement
Given an infinite supply of Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins and an amount 'N'.

Find the minimum coins needed to make the sum equal to 'N'. You have to return the list containing the value of coins required in decreasing order.

For Example
For Amount = 70, the minimum number of coins required is 2 i.e an Rs. 50 coin and a Rs. 20 coin.
Note
It is always possible to find the minimum number of coins for the given amount. So, the answer will always exist.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1
13
Sample Output 1
10 2 1
Explanation of Sample Input 1
The minimum number of coins to change is 3 {1, 2, 10}.
Sample Input 2
50
Sample Output 2
50
Constraints
1 <= 'N' <= 10^5

Time Limit: 1 sec

*/

// Solution- Keep currency in decreasing order in a tmp array. and then or every currency run a while(n>=tmp[i]) loop to add that currency in vector ans

vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int>tmp={1000, 500, 100, 50, 20, 10, 5, 2, 1}, ans;
    
    for(int i=0; i<9; i++)
    {
        while(n>=tmp[i])
        {
            ans.push_back(tmp[i]);
            n-=tmp[i];
        }        
        //cout<<n<<endl;
    }
    return ans;
}
