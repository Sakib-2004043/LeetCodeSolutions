class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int i,n,arrow;
        n=points.size();
        sort(points.begin(),points.end());
        i=0,arrow=0;
        while(i<n){
            arrow++;
            int last = points[i][1];
            while(i<n && points[i][0]<=last){
                last = min(last,points[i][1]);
                i++;
            }
        }
        return arrow;
    }
};