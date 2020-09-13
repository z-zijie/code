#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval){
    vector<vector<int>> ans;
    int i = 0,  n = intervals.size();

    // If interval[i] < newInterval
    while(i < n && intervals[i][1] < newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }

    // If interval[i] overlap newInterval
    while (i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    ans.push_back(newInterval);
    
    //If interval[i] > newInterval
    while (i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}


int main()
{
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};
    intervals = insert(intervals, newInterval);

    //Print Answer
    cout << "[";
    for(int i = 0; i < intervals.size() - 1; i++){
        cout << "[";
        for(int j = 0; j < intervals[i].size() - 1; j++){
            cout << intervals[i][j] << ',';
        }
        cout << intervals[i].back() << "],";
    }
    cout << "[";
    for(int j = 0; j < intervals.back().size() - 1; j++){
        cout << intervals.back()[j] << ",";
    }
    cout << intervals.back().back() << "]]" << endl;
    return 0;
}