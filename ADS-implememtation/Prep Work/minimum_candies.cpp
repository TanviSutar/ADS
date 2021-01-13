//There are N children standing in a line with some rating value. You want to distribute a minimum number of candies to these children such that: Each child must have at least one candy. The children with higher ratings will have more candies than their neighbors. You need to write a program to calculate the minimum candies you must give

#include <iostream>
#include <vector>
using namespace std;
int candy(std::vector<int> &ratings) {
    int result = 0;
    int size = ratings.size();
    std::vector<int> lefttoright(size, 1);
    std::vector<int> righttoleft(size, 1);
    
    for (auto l = 1; l<size; ++l)
        if (ratings[l] > ratings[l-1])
            lefttoright[l] = lefttoright[l-1] + 1;
        else 
            lefttoright[l]=1;
    
    for (auto r = size-2; r>=0; --r)
        if (ratings[r] > ratings[r+1])
            righttoleft[r] = righttoleft[r+1] + 1;
        else 
            righttoleft[r]=1;
            
    for (auto i = 0; i<size; ++i)
        result += std::max(lefttoright[i], righttoleft[i]);
        
    return result;
}

int my_candy(std::vector<int> &vec){
    std::vector<int> left(vec.size(),1);
    std::vector<int> right(vec.size(),1);
    for(int i=1;i<vec.size();i++)
        if(vec[i-1] < vec[i]) left[i] = left[i-1]+1;
    for(int i=vec.size()-2;i>=0;i--)
        if(vec[i+1] < vec[i]) right[i] = right[i+1]+1;
    int sum=0;
    for(int i=0;i<vec.size();i++){
        sum += std::max(left[i],right[i]);
    }
    return sum;
}

int main()
{
    std::vector<int> vect; 
    vect.push_back(1); 
    vect.push_back(2);
    vect.push_back(2);
    //vect.push_back(1);  1, 2, 2
    int result = my_candy(vect);
    cout<<result<<endl;
  
}
  