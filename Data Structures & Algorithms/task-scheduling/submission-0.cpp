class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size=tasks.size();
        vector<int> num_tasks(26,0);
        for(char task: tasks)
            num_tasks[task-'A']++;
        priority_queue<int> pq;
        for(int num:num_tasks)
            pq.push(num);
        int cycles=pq.top()-1;
        pq.pop();
        int last=1;
        while(pq.top()-1==cycles){
            last++;
            pq.pop();
        }
        return max(size,(n+1)*cycles+last);
    }
};
