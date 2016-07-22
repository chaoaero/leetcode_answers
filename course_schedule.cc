/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     course_schedule.cc
 *   author:       Meng Weichao
 *   created:      2016/03/10
 *   description:  
 *
 ================================================================*/
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int> > graph(numCourses);
    vector<int> in_degree(numCourses, 0);
    //vector<int> woca;
    int count = 0;
    stack<int> stk;
    //for(int i = 0; i < numCourses; i++)
    //    in_degree[i] = 0;
    for(vector<pair<int, int>>::const_iterator iter = prerequisites.begin(); iter != prerequisites.end(); iter++) {
        in_degree[iter->first] += 1;
        graph[iter->second].push_back(iter->first);
    }
    for(int i = 0; i < numCourses; i++) {
        if(in_degree == 0)
            stk.push(i);
    }
    while(!stk.empty()) {
        int tmp = stk.top();
        stk.pop();
     //   woca.push_back(tmp);
        count++;
        for(int i = 0; i< graph[tmp].size(); i++) { 
            in_degree[graph[tmp][i]]--;
            if(in_degree[graph[tmp][i]] == 0) {
                stk.push(graph[tmp][i]);
            }

        }
    }
    if(woca.size() < numCourses)
        return false;
    return true;
}
