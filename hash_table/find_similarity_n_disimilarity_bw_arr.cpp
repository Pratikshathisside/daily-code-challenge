#include <bits/stdc++.h> 
#include<vector>
using namespace std;
#include<map>
#include<unordered_map>
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m)  {   
	 int count1=0;    int count2=0;    
	 sort(arr1.begin(),arr1.end());    
	 sort(arr2.begin(),arr2.end());    
	 pair <int, int> p1;    
	 int i=0;    int j=0;    
	 while(i<n && j<m)    {        
		 if(arr1[i]==arr2[j])        {            
			 count1++;            i++;            j++;        }  
			       else if (arr1[i]<arr2[j])        {            i++;   
				   
				        }        else        {            j++;  
						      }    } 
							     p1.first = count1; 
								    p1.second = n+m-count1;    return p1; }
                    
