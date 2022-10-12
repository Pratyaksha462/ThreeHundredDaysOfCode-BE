#include <vector>
#include <numeric>
#include <map>
#include <queue>
using namespace std;

class Solution
{
    public:
        vector<vector < int>> kClosest(vector<vector < int>> &points, int k)
        {
            unordered_map<int, vector < int>> mp;
            vector<vector < int>> vec;
            for (int i = 0; i < points.size(); i++)
            {
                int ori = points[i][0] *points[i][0] + points[i][1] *points[i][1];
                points[i].push_back(ori);
            }
            for (int i = 0; i < points.size(); i++)
            {
                swap(points[i][0], points[i][2]);
            }
            sort(points.begin(), points.end());
            for (int i = 0; i < k; i++)
            {
                vec.push_back({ points[i][2],
                    points[i][1] });
            }
            return vec;
        }
};