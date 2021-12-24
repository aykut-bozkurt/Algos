#pragma once

#include <vector>

struct Job{
    int start;
    int finish;
    int profit;
};

int job_profit(std::vector<Job> jobs);
