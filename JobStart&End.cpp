#include <iostream>
#include <algorithm>
using namespace std;

/*———————————————————————————————————————————————————————————————————————————*/
struct Job {
   int start, end, profit;
};

/*———————————————————————————————————————————————————————————————————————————*/
bool comp(Job job1, Job job2) {
   return (job1.end < job2.end);
}

/*———————————————————————————————————————————————————————————————————————————*/
int nonConflictJob(Job jobList[], int i) {       //non conflicting job of jobList[i]
    for (int j = i - 1; j >= 0; j--) {
        if (jobList[j].end <= jobList[i-1].start)
            return j;
    }
    return -1;
}

/*———————————————————————————————————————————————————————————————————————————*/
int findMaxProfit(Job jobList[], int n) {
    sort(jobList, jobList + n, comp);           //sort jobs based on the ending time

    int *table = new int[n];       //create job table
    table[0] = jobList[0].profit;
       
    //Job display[n];
    //display[0] = jobList[0];

    for (int i=1; i<n; i++) {
        // Find profit including the current job
        int addProfit = jobList[i].profit;
        int l = nonConflictJob(jobList, i);
        if (l != -1)
            addProfit += table[l];

        if (addProfit > table[i-1]){
            table[i] = addProfit;
            cout << jobList[i-1].start << " - " << jobList[i-1].end << " - " << jobList[i-1].profit << "\n";
        }
        else{
            table[i] = table[i-1];
            cout << jobList[i-1].start << " - " << jobList[i-1].end << " - " << jobList[i-1].profit << "\n";
        }
    }

    int result = table[n-1];
    delete[] table;                 //clear table from memory
    return result;
}

/*———————————————————————————————————————————————————————————————————————————*/
int main() {
    Job jobList[] = {
                     {3, 5, 25},
                     {1, 2, 50},
                     {6, 15, 75},
                     {2, 100, 100}
                    };

    int n = 4;
    cout << "The maximum profit : \n" << findMaxProfit(jobList, n);
    return 0;
}
