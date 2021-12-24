#include "job-profit.h"

#include <numeric>
#include <algorithm>

static int latest_nonconflicting(const std::vector<Job>& jobs, const int with){
    for(std::ptrdiff_t i = with-1; i >= 0; i--){
        if(jobs[i].finish <= jobs[with].start){
            return i;
        }
    }

    return -1;
}

int job_profit(std::vector<Job> jobs){
    int sol[jobs.size()] = {0};

    std::sort(jobs.begin(), jobs.end(), [](Job& job1, Job& job2){
        return job1.finish < job2.finish;
    });

    sol[0] = jobs[0].profit;
    // for each end idx
    for(std::size_t i = 1; i < jobs.size(); i++){
        auto excl = sol[i-1];
        auto incl = jobs[i].profit;
        auto latest_possiblejob = latest_nonconflicting(jobs, i);
        if(latest_possiblejob != -1){
            incl += sol[latest_possiblejob];
        }

        sol[i] = std::max(incl , excl);
    }

    return sol[jobs.size()-1];
}

