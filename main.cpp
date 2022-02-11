#include <iostream>
#include <vector>

#include "search/linear_search.h"
#include "search/binary_search.h"
#include "search/jump_search.h"
#include "search/interpolation_search.h"
#include "search/ternary_search.h"

#include "sort/selection_sort.h"
#include "sort/bubble-sort.h"
#include "sort/counting-sort.h"
#include "sort/radix-sort.h"
#include "sort/quick-sort.h"
#include "sort/merge-sort.h"
#include "sort/bucket-sort.h"
#include "sort/pigeonhole-sort.h"
#include "sort/insertion-sort.h"
#include "sort/comb-sort.h"
#include "sort/shell-sort.h"
#include "sort/cycle-sort.h"

#include "divide-and-conquer/power.h"
#include "divide-and-conquer/find-max.h"
#include "divide-and-conquer/median-of-2-array.h"
#include "divide-and-conquer/count-of-inversion.h"

#include "dynamic-programming/longest-common-substring.h"
#include "dynamic-programming/longest-increasing-subseq.h"
#include "dynamic-programming/min-edit-distance.h"
#include "dynamic-programming/min-cost-path.h"
#include "dynamic-programming/change-ways.h"
#include "dynamic-programming/matrix-chain-multiplication.h"
#include "dynamic-programming/binomial-coefficient.h"
#include "dynamic-programming/01-knapsack.h"
#include "dynamic-programming/egg-drop.h"
#include "dynamic-programming/longest-sub-palindrome.h"
#include "dynamic-programming/cutting-rod.h"
#include "dynamic-programming/maximum-sum-increasing-subseq.h"
#include "dynamic-programming/longest-bitonic-seq.h"
#include "dynamic-programming/floyd-warshall.h"
#include "dynamic-programming/fibonacci.h"
#include "dynamic-programming/tiling.h"
#include "dynamic-programming/partition.h"
#include "dynamic-programming/max-length-chain.h"
#include "dynamic-programming/box-stacking.h"
#include "dynamic-programming/min-jump.h"
#include "dynamic-programming/ugly-number.h"
#include "dynamic-programming/largest-contigous-sum.h"
#include "dynamic-programming/subset-sum.h"
#include "dynamic-programming/max-square-size-matrix.h"
#include "dynamic-programming/no-consecutive-ones.h"
#include "dynamic-programming/stair-ways.h"
#include "dynamic-programming/non-decreasing-numbers.h"
#include "dynamic-programming/n-digit-number-of-sum.h"
#include "dynamic-programming/digit-sum-until-n.h"
#include "dynamic-programming/min-no-change.h"
#include "dynamic-programming/min-no-squares.h"
#include "dynamic-programming/ways-for-building.h"
#include "dynamic-programming/max-profit-transactions.h"
#include "dynamic-programming/min-cost-train-path.h"
#include "dynamic-programming/max-As.h"
#include "dynamic-programming/score-ways.h"
#include "dynamic-programming/job-profit.h"

#include "backtracking/permutations-of-string.h"
#include "backtracking/knight-tour.h"
#include "backtracking/rat-in-maze.h"
#include "backtracking/n-queens.h"
#include "backtracking/subset-sum.h"
#include "backtracking/m-color.h"
#include "backtracking/hamiltonian-cycle.h"
#include "backtracking/sudoku.h"
#include "backtracking/tug-of-war.h"
#include "backtracking/cryptarithmetic-puzzle.h"

#include "geometric/line-segment-intersection.h"
#include "geometric/inside-polygon.h"
#include "geometric/convex_hull.h"
#include "geometric/inside-triangle.h"
#include "geometric/is-square.h"

#include "graph/graph.h"
#include "graph/graph-with-edge.h"
#include "graph/DAG-has-cycle.h"
#include "graph/undirected-has-cycle.h"
#include "graph/longest-path-DAG.h"
#include "graph/topological-sort.h"
#include "graph/is-bipartite.h"
#include "graph/is-tree.h"
#include "graph/disjoint-set.h"
#include "graph/prims-MST.h"
#include "graph/kruskal.h"
#include "graph/has-path.h"
#include "graph/is-strongly-connected-DAG.h"
#include "graph/articulation-points.h"
#include "graph/is-biconnected.h"
#include "graph/bridges.h"
#include "graph/is-euler-path-cycle.h"

#include "math/is-multiple-3.h"
#include "math/multiply-7.h"
#include "math/lucky-number.h"
#include "math/base-14-add.h"
#include "math/square-root.h"
#include "math/recursive-multiply.h"
#include "math/power.h"
#include "math/primes.h"
#include "math/distinct-prime-factors.h"
#include "math/divisible-by-7.h"
#include "math/birthday-paradox.h"
#include "math/e-to-x.h"
#include "math/newton-rapson-root.h"
#include "math/bisection-root.h"
#include "math/secant-root.h"

#include "amazon-interview/magic-triplets.h"
#include "amazon-interview/min-number-coins.h"
#include "amazon-interview/stock-profit.h"
#include "amazon-interview/is-num-palindrome.h"
#include "amazon-interview/largest-even-sum.h"

#include "string/naive-search.h"
#include "string/kmp-search.h"
#include "string/rabin-karp.h"
#include "string/optimized-naive-search.h"

#include "microsoft-interview/doubly-list.h"
#include "microsoft-interview/heap.h"
#include "microsoft-interview/suffix-array.h"
#include "microsoft-interview/trie.h"
#include "microsoft-interview/patricia-trie.h"
#include "microsoft-interview/AVL.h"
#include "microsoft-interview/BST.h"

template<class Container>
void print(Container&& container){
    for(auto& el : container){
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

template<class T>
void test(T&& t){
    t = 2;
}

void search_tests(){
    std::vector<int> vec{10, 20, 30, 40, 50};

    // linear search
    std::cout << std::boolalpha << linear_search(vec.begin(), vec.end(), 200) << " ";
    std::cout << std::boolalpha << linear_search(vec.begin(), vec.end(), 20) << " ";
    std::cout << std::boolalpha << linear_search(vec.begin(), vec.end(), 10) << " ";
    std::cout << std::boolalpha << linear_search(vec.begin(), vec.end(), 40) << std::endl;

    // binary search
    std::cout << std::boolalpha << binary_search(vec.begin(), vec.end(), 200) << " ";
    std::cout << std::boolalpha << binary_search(vec.begin(), vec.end(), 20) << " ";
    std::cout << std::boolalpha << binary_search(vec.begin(), vec.end(), 10) << " ";
    std::cout << std::boolalpha << binary_search(vec.begin(), vec.end(), 40) << std::endl;

    // jump search
    std::cout << std::boolalpha << jump_search(vec.begin(), vec.end(), 200) << " ";
    std::cout << std::boolalpha << jump_search(vec.begin(), vec.end(), 20) << " ";
    std::cout << std::boolalpha << jump_search(vec.begin(), vec.end(), 10) << " ";
    std::cout << std::boolalpha << jump_search(vec.begin(), vec.end(), 40) << std::endl;

    // interpolation search
    std::cout << std::boolalpha << interpolation_search(vec.begin(), vec.end(), 200) << " ";
    std::cout << std::boolalpha << interpolation_search(vec.begin(), vec.end(), 20) << " ";
    std::cout << std::boolalpha << interpolation_search(vec.begin(), vec.end(), 10) << " ";
    std::cout << std::boolalpha << interpolation_search(vec.begin(), vec.end(), 40) << std::endl;

    // ternary search
    std::cout << std::boolalpha << ternary_search(vec.begin(), vec.end(), 200) << " ";
    std::cout << std::boolalpha << ternary_search(vec.begin(), vec.end(), 20) << " ";
    std::cout << std::boolalpha << ternary_search(vec.begin(), vec.end(), 10) << " ";
    std::cout << std::boolalpha << ternary_search(vec.begin(), vec.end(), 40) << std::endl;
}

void sort_tests(){
    //std::vector<int> vec{10, 30, 20, 15, 12};

    /*
    // bubble sort
    bubble_sort(vec.begin(), vec.end());
    print(vec);

    // comb sort
    comb_sort(vec.begin(), vec.end());
    print(vec);

    // selection sort
    selection_sort(vec.begin(), vec.end());
    print(vec);

    // counting sort
    counting_sort(vec.begin(), vec.end());
    print(vec);

    // radix sort
    radix_sort(vec.begin(), vec.end());
    print(vec);

    // quick sort
    quick_sort(vec.begin(), vec.end() - 1);
    print(vec);

    // merge sort
    merge_sort(vec.begin(), vec.end() - 1);
    print(vec);

    // bucket sort
    std::vector<float> vec2{ 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    bucket_sort(vec2.begin(), vec2.end());
    print(vec2);

    // pigeonhole sort
    std::vector<int> vec3{8, 3, 2, 7, 4, 6, 8};
    pigeonhole_sort(vec3.begin(), vec3.end());
    print(vec3);

    // insertion sort
    insertion_sort(vec.begin(), vec.end());
    print(vec);

    // shell sort
    shell_sort(vec.begin(), vec.end());
    print(vec);

    // cycle sort
    cycle_sort(vec.begin(), vec.end());
    print(vec);

    // iterative quick sort
    iterative_quick_sort(vec.begin(), vec.end() - 1);
    print(vec);

    // iterative merge sort
    iterative_merge_sort(vec.begin(), vec.end() - 1);
    print(vec);*/
}

int main() {
    //search_tests();

    //sort_tests();

    //std::cout << power(3,4) << std::endl;

    //std::cout << find_max({120, 34, 54, 32, 58, 11, 90}, 0, 6) << std::endl;

    /*std::cout << median_of_2_array({1, 12, 15, 26, 38}, {2, 13, 17, 30, 45}, 0, 0, 4, 4) << std::endl;
    std::cout << median_of_2_array({1, 2, 3, 6}, {4, 6, 8, 10}, 0, 0, 3, 3) << std::endl;*/

    /*std::vector<int> a{ 1, 20, 6, 4, 5 };
    std::cout << inversion_count(a) << std::endl;
    print(a);

    std::vector<int> b{8, 4, 2, 1};
    std::cout << inversion_count(b) << std::endl;
    print(b);

    std::vector<int> c{3, 1, 2};
    std::cout << inversion_count(c) << std::endl;
    print(c);*/

    // see deduced type when forwarding ref is used
    /*const int a = 2;
    test(a);
    test(std::move(a));*/

    //std::cout << lcs("ABCDGH", "AEDFHR") << std::endl;

    /*std::cout << lis({10, 22, 9, 33, 21, 50, 41, 60, 80}) << std::endl;
    std::cout << lis({3, 2}) << std::endl;
    std::cout << lis({50, 3, 10, 7, 40, 80}) << std::endl;*/

    //std::cout << min_edit_distance("geek", "gesek") << std::endl;

    /*int cost[3][3] = { {1, 2, 3},
                       {4, 8, 2},
                       {1, 5, 3} };
    std::cout << min_cost_path(cost, 2, 2) << std::endl;*/

    //std::cout << change_ways({1,2,3}, 4) << std::endl;

    /*std::cout << matrix_chain_multiplication({40, 20, 30, 10, 30}) << std::endl;
    std::cout << matrix_chain_multiplication({10, 20, 30, 40, 30}) << std::endl;
    std::cout << matrix_chain_multiplication({10, 20, 30}) << std::endl;*/

    /*std::cout << binomial_coefficient(4, 2) << std::endl;
    std::cout << binomial_coefficient(4, 0) << std::endl;
    std::cout << binomial_coefficient(4, 1) << std::endl;
    std::cout << binomial_coefficient(0, 0) << std::endl;*/

    //std::cout << knapsack_01({10, 20, 30}, {60, 100, 120}, 50) << std::endl;

    //std::cout << egg_drop(2, 10) << std::endl;

    /*std::cout << longest_sub_palindrome("BBABCBCAB") << std::endl;
    std::cout << longest_sub_palindrome("GEEKSFORGEEKS") << std::endl;*/

    //std::cout << cutting_rod({1, 5, 8, 9, 10, 17, 17, 20}) << std::endl;

    /*std::cout << max_increasing_sum({1, 101, 2, 3, 100, 4, 5}) << std::endl;
    std::cout << max_increasing_sum({10, 5, 4, 3, 2}) << std::endl;*/

    //std::cout << longest_bitonic_seq({0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}) << std::endl;

    /*int graph[4][4] = { { 0, 5, INT32_MAX, 10 },
                        { INT32_MAX, 0, 3, INT32_MAX },
                        { INT32_MAX, INT32_MAX, 0, 1 },
                        { INT32_MAX, INT32_MAX, INT32_MAX, 0 } };
    floyd_warshall(graph);*/

    //std::cout << fibonacci(8) << std::endl;

    //std::cout << tiling(4) << std::endl;

    //std::cout << std::boolalpha << partition({1, 5, 11, 5}) << std::endl;

    //std::cout << max_chain_pairs({{5, 24}, {27, 40}, {50, 90}}) << std::endl;

    //std::cout << box_stacking({ {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }) << std::endl;

    /*std::cout << min_jumps({1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}) << std::endl;
    std::cout << min_jumps({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}) << std::endl;
    std::cout << min_jumps({ 1, 3, 6, 1, 0, 9 }) << std::endl;*/

    //std::cout << ugly_number(150) << std::endl;

    //std::cout << largest_contigous_sum({-2, -3, 4, -1, -2, 1, 5, -3}) << std::endl;

    /*std::cout << std::boolalpha << subset_sum({ 3, 34, 4, 12, 5, 2 }, 9) << std::endl;
    std::cout << std::boolalpha << subset_sum({ 3, 34, 4, 12, 5, 2 }, 1) << std::endl;*/

    /*std::cout << max_square_size_matrix({{0, 1, 1, 0, 1},
                                         {1, 1, 0, 1, 0},
                                         {0, 1, 1, 1, 0},
                                         {1, 1, 1, 1, 0},
                                         {1, 1, 1, 1, 1},
                                         {0, 0, 0, 0, 0}}) << std::endl;*/

    //std::cout << no_consecutive_ones(3) << std::endl;

    //std::cout << stair_ways(4) << std::endl;

    //std::cout << non_decreasing_numbers(3) << std::endl;

    /*std::cout << n_digit_number_of_sum(2, 2) << std::endl;
    std::cout << n_digit_number_of_sum(2, 5) << std::endl;
    std::cout << n_digit_number_of_sum(3, 6) << std::endl;
    std::cout << n_digit_number_of_sum(3, 5) << std::endl;*/

    /*std::cout << digit_sum_until_n(5) << std::endl;
    std::cout << digit_sum_until_n(12) << std::endl;
    std::cout << digit_sum_until_n(328) << std::endl;*/

    /*std::cout << min_no_change({25, 10, 5}, 30) << std::endl;
    std::cout << min_no_change({9, 6, 5, 1}, 11) << std::endl;*/

    /*std::cout << min_no_squares(100) << std::endl;
    std::cout << min_no_squares(6) << std::endl;
    std::cout << min_no_squares(12) << std::endl*/;

    //std::cout << ways_for_building(3) << std::endl;

    /*std::cout << max_profit_transactions({10, 22, 5, 75, 65, 80}) << std::endl;
    std::cout << max_profit_transactions({2, 30, 15, 10, 8, 25, 80}) << std::endl;
    std::cout << max_profit_transactions({90, 80, 70, 60, 50}) << std::endl;*/

    /*std::cout << min_cost_train_path({ {0, 15, 80, 90},
                                       {INT32_MAX, 0, 40, 50},
                                       {INT32_MAX, INT32_MAX, 0, 70},
                                       {INT32_MAX, INT32_MAX, INT32_MAX, 0}
                                     }) << std::endl;*/

    /*std::cout << max_As(7) << std::endl;
    std::cout << max_As(17) << std::endl;*/

    /*std::cout << score_ways({3, 5, 10}, 20) << std::endl;
    std::cout << score_ways({3, 5, 10}, 13) << std::endl;*/

    //std::cout << job_profit({{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}) << std::endl;

    /*std::string s = "ABC";
    permutation_of_string(s, 0, 2);*/

    /*int visited[8][8];
    for(std::size_t i = 0; i < 8; i++){
        for(std::size_t j = 0; j < 8; j++){
            visited[i][j] = -1;
        }
    }
    visited[0][0] = 0;
    knight_tour(visited, 1, 0, 0);*/

    /*int maze[4][4] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    int visited[4][4];
    for(std::size_t i = 0; i < 4; i++){
        for(std::size_t j = 0; j < 4; j++){
            visited[i][j] = 0;
        }
    }
    visited[0][0] = 1;
    rat_in_maze(maze, visited, 0, 0);*/

    /*int board[4][4];
    for(std::size_t i = 0; i < 4; i++){
        for(std::size_t j = 0; j < 4; j++){
            board[i][j] = 0;
        }
    }
    n_queens(board, 0);*/

    /*int a[8] = {15, 22, 14, 26, 32, 9, 16, 8};
    int sol[8] = {0};
    subset_sum(a, sol, 0, 0, 53);*/

    /*int graph[4][4] = { {0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0} };
    int sol[4] = {0};
    if(!m_color(graph, sol, 0, 3)){
        std::cout << "No solution exist!" << std::endl;
    }

    int graph2[4][4] = { {1, 1, 1, 1},
                         {1, 1, 1, 1},
                         {1, 1, 1, 1},
                         {1, 1, 1, 1} };
    int sol2[4] = {0};
    if(!m_color(graph2, sol2, 0, 3)){
        std::cout << "No solution exist!" << std::endl;
    }*/

    /*int graph1[5][5] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 1},
                         {0, 1, 1, 1, 0}};
    int visited1[5] = {0};
    int sol1[5];
    for(std::size_t i = 0; i < 5; i++){
        sol1[i] = -1;
    }
    if(!hamiltonian_cycle(graph1, visited1, sol1, 0)){
        std::cout << "No solution exist!" << std::endl;
    }

    int graph2[5][5] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0}};
    int visited2[5] = {0};
    int sol2[5];
    for(std::size_t i = 0; i < 5; i++){
        sol2[i] = -1;
    }
    if(!hamiltonian_cycle(graph2, visited2, sol2, 0)){
        std::cout << "No solution exist!" << std::endl;
    }*/

    /*int grid[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 1, 0, 0, 8, 0},
                       {9, 0, 0, 8, 6, 3, 0, 0, 5},
                       {0, 5, 0, 0, 9, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    if(!sudoku(grid)){
        std::cout << "No solution exist!" << std::endl;
    }*/

    //tug_of_war({23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4});

    //cryptarithmetic_puzzle("SEND", "MORE", "MONEY");

    /*std::cout << std::boolalpha << line_segments_intersect({{1,1}, {10,1}}, {{1,2}, {10,2}}) << std::endl;
    std::cout << std::boolalpha << line_segments_intersect({{10,0}, {0,10}}, {{0,0}, {10,10}}) << std::endl;
    std::cout << std::boolalpha << line_segments_intersect({{-5,-5}, {0,0}}, {{1,1}, {10,10}}) << std::endl;*/

    /*std::cout << std::boolalpha << inside_polygon({20,20}, {{0, 0}, {10, 0}, {10, 10}, {0, 10}}) << std::endl;
    std::cout << std::boolalpha << inside_polygon({5,5}, {{0, 0}, {10, 0}, {10, 10}, {0, 10}}) << std::endl;
    std::cout << std::boolalpha << inside_polygon({3,3}, {{0, 0}, {5, 5}, {5, 0}}) << std::endl;*/

    /*std::vector<Point> a{{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    for(auto& el : convex_hull(a)){
        std::cout << "(" << el.x << ", " << el.y << "); ";
    }
    std::cout << std::endl;*/

    //std::cout << std::boolalpha << inside_triangle({0, 0}, {20, 0}, {10, 30}, {10, 15}) << std::endl;

    //std::cout << std::boolalpha << is_square({20, 10}, {10, 20}, {20, 20}, {10, 10}) << std::endl;

    /*Graph g{};
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    std::cout << std::boolalpha << directed_has_cycle(g) << std::endl;*/

    /*Graph g{};
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);

    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(1, 2);
    g.add_undirected_edge(0, 2);
    std::cout << std::boolalpha << undirected_has_cycle(g) << std::endl;*/

    /*Graph g{};
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);
    g.add_vertex(5);

    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);

    topological_sort(g);*/

    /*GraphWithEdge g{};
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);
    g.add_vertex(5);

    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 5, 1);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);

    longest_path_DAG(g, 1);*/

    /*Graph g{};
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(0, 3);
    g.add_undirected_edge(1, 2);
    g.add_undirected_edge(2, 3);

    std::cout << std::boolalpha << is_bipartite(g) << std::endl;*/

    /*Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(0, 2);
    g.add_undirected_edge(0, 3);
    g.add_undirected_edge(3, 4);

    std::cout << std::boolalpha << is_tree(g) << std::endl;*/

    /*GraphWithEdge g{};
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    g.add_undirected_edge(0, 1, 10);
    g.add_undirected_edge(0, 2, 6);
    g.add_undirected_edge(0, 3, 5);
    g.add_undirected_edge(1, 3, 15);
    g.add_undirected_edge(2, 3, 4);

    kruskal(g);

    prims(g);*/

    /*Graph g{};
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    std::cout << std::boolalpha << has_path(g, 1, 3) << std::endl;
    std::cout << std::boolalpha << has_path(g, 3, 1) << std::endl;*/

    /*Graph g{};
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);
    g.add_edge(2, 4);
    g.add_edge(4, 2);

    std::cout << std::boolalpha << is_strongly_connected(g) << std::endl;

    Graph g2;
    g2.add_vertex(0);
    g2.add_vertex(1);
    g2.add_vertex(2);
    g2.add_vertex(3);

    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    g2.add_edge(2, 3);

    std::cout << std::boolalpha << is_strongly_connected(g2) << std::endl;*/

    /*Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_undirected_edge(1, 0);
    g.add_undirected_edge(0, 2);
    g.add_undirected_edge(2, 1);
    g.add_undirected_edge(0, 3);
    g.add_undirected_edge(3, 4);

    print(articulation_points(g));*/

    /*Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    g.add_undirected_edge(1, 0);
    g.add_undirected_edge(2, 1);
    g.add_undirected_edge(3, 2);

    print(articulation_points(g));*/

    /*Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);
    g.add_vertex(5);
    g.add_vertex(6);

    g.add_undirected_edge(1, 0);
    g.add_undirected_edge(2, 1);
    g.add_undirected_edge(2, 0);
    g.add_undirected_edge(1, 3);
    g.add_undirected_edge(1, 4);
    g.add_undirected_edge(1, 6);
    g.add_undirected_edge(5, 3);
    g.add_undirected_edge(5, 4);

    print(articulation_points(g));*/

    /*Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_undirected_edge(1, 0);
    g.add_undirected_edge(0, 2);
    g.add_undirected_edge(2, 1);
    g.add_undirected_edge(0, 3);
    g.add_undirected_edge(3, 4);
    g.add_undirected_edge(2, 4);

    std::cout << std::boolalpha << is_biconnected(g) << std::endl;*/

    /*Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_undirected_edge(1, 0);
    g.add_undirected_edge(0, 2);
    g.add_undirected_edge(2, 1);
    g.add_undirected_edge(0, 3);
    g.add_undirected_edge(3, 4);

    bridges(g);*/

    /*Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    g.add_undirected_edge(1, 0);
    g.add_undirected_edge(2, 1);
    g.add_undirected_edge(2, 3);

    bridges(g);*/

    /*Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);
    g.add_vertex(5);
    g.add_vertex(6);

    g.add_undirected_edge(1, 0);
    g.add_undirected_edge(2, 1);
    g.add_undirected_edge(2, 0);
    g.add_undirected_edge(1, 3);
    g.add_undirected_edge(1, 4);
    g.add_undirected_edge(1, 6);
    g.add_undirected_edge(3, 5);
    g.add_undirected_edge(4, 5);

    bridges(g);*/

    /*Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_undirected_edge(1, 0);
    g.add_undirected_edge(0, 2);
    g.add_undirected_edge(2, 1);
    g.add_undirected_edge(0, 3);
    g.add_undirected_edge(3, 4);

    std::cout << std::boolalpha << is_eulerian_path(g) << std::endl;
    std::cout << std::boolalpha << is_eulerian_cycle(g) << std::endl;*/

    /*std::cout << std::boolalpha << is_multiple_of_3(4) << std::endl;
    std::cout << std::boolalpha << is_multiple_of_3(99) << std::endl;*/

    //std::cout << multiply_7(4) << std::endl;

    /*std::cout << std::boolalpha << is_lucky_number(5) << std::endl;
    std::cout << std::boolalpha << is_lucky_number(13) << std::endl;*/

    //std::cout << base14_add("DC2", "0A3") << std::endl;

    /*std::cout << square_root_floor(97) << std::endl;
    std::cout << square_root_floor(100) << std::endl;*/

    //std::cout << multiply_special(5, -11) << std::endl;

    //std::cout << special_power(2, 5) << std::endl;

    //primes(30);

    //distinct_prime_factors(4, 10);

    //std::cout << std::boolalpha << is_divisible_by_7(616) << std::endl;

    //std::cout << birthday_paradox(23) << std::endl;

    //std::cout << e_to_x(1) << std::endl;

    //std::cout << newton_rapson() << std::endl;

    //std::cout << bisection(-200, 300) << std::endl;

    //std::cout << secant(-200, 300) << std::endl;

    /*std::vector<int> triplets;
    magic_triplets({10, 3, -4, 1, -6, 9}, 0, triplets, 0);*/

    /*std::vector<int> triplets;
    magic_triplets({12, 34, -46}, 0, triplets, 0);*/

    /*std::vector<int> triplets;
    magic_triplets({0, 0, 0}, 0, triplets, 0);*/

    /*std::vector<int> triplets;
    std::set<std::string> unique_triplets1;
    magic_triplets({-2, 2, 0, -2, 2}, 0, unique_triplets1, triplets, 0);
    print(unique_triplets1);

    std::vector<int> numbers{-2, 2, 0, -2, 2};
    std::set<std::string> unique_triplets2;
    magic_triplets(numbers, unique_triplets2);
    print(unique_triplets2);*/

    //std::cout << min_coins({1, 3, 5}, 9) << std::endl;

    //std::cout << max_profit({2, 3, 10, 6, 4, 8, 1}) << std::endl;

    //std::cout << std::boolalpha << is_palindrome(1234321) << std::endl;

    /*std::vector<int> vec1{4, 9, 8, 2, 6};
    std::cout << largest_even_sum(vec1, 3) << std::endl;
    std::vector<int> vec2{7, 7, 7, 7, 7};
    std::cout << largest_even_sum(vec2, 1) << std::endl;
    std::vector<int> vec3{5, 6, 3, 4, 2};
    std::cout << largest_even_sum(vec3, 5) << std::endl;*/

    /*print(naive_search("THIS IS A TEST TEXT", "TEST"));
    print(naive_search("AABAACAADAABAABA", "AABA"));*/

    /*print(kmp_search("THIS IS A TEST TEXT", "TEST"));
    print(kmp_search("AABAACAADAABAABA", "AABA"));*/

    /*print(rk_search("THIS IS A TEST TEXT", "TEST"));
    print(rk_search("AABAACAADAABAABA", "AABA"));*/

    //print(optimized_naive_search("ABCEABCDABCEABCD", "ABCD"));

    /*DoublyList dl{};

    // push_back 10 elements
    for(int i = 0; i <= 10; i++){
        dl.push_back(i);
    }
    dl.print();

    // erase from middle
    dl.erase(5);
    dl.print();

    // erase from head
    dl.erase(0);
    dl.print();

    // erase from tail
    dl.erase(10);
    dl.print();

    // erase all
    for(int i = 0; i <= 10; i++){
        dl.erase(i);
    }
    dl.print();*/

    ///////////////////////

    /*Heap heap{};

    // push 10 elements
    for(int i = 10; i >= 0; i--){
        heap.push(i);
    }
    heap.print();

    // print top
    std::cout << heap.top() << std::endl;

    // pop min
    heap.pop();
    heap.print();

    // pop all
    while(heap.size() > 0){
        heap.pop();
    }
    heap.print();*/

    /*SuffixArray suffix_array("banana");
    std::cout << std::boolalpha << suffix_array.search("nana") << std::endl;
    std::cout << std::boolalpha << suffix_array.search("ara") << std::endl;*/

    /*
    std::string keys[] = {"the", "a", "there",
                          "answer", "any", "by",
                          "bye", "their" };
    Trie trie;
    for (int i = 0; i < 8; i++){
        trie.insert(keys[i]);
    }
    std::cout << std::boolalpha << trie.search("the") << std::endl;
    std::cout << std::boolalpha << trie.search("these") << std::endl;
    trie.insert("these");
    trie.remove("the");
    std::cout << std::boolalpha << trie.search("the") << std::endl;
    std::cout << std::boolalpha << trie.search("these") << std::endl;*/

    /*std::string keys[] = {"romane", "romanus", "romulus",
                          "rubens", "ruber", "rubicon",
                          "rubicundus" };

    PatriciaTrie pat_trie;
    for (int i = 0; i < 7; i++){
        pat_trie.insert(keys[i]);
    }
    for (int i = 0; i < 7; i++){
        std::cout << std::boolalpha << pat_trie.search(keys[i]) << std::endl;
    }
    for (int i = 0; i < 7; i++){
        pat_trie.remove(keys[i]);
    }
    for (int i = 0; i < 7; i++){
        std::cout << std::boolalpha << pat_trie.search(keys[i]) << std::endl;
    }*/

    /*AVL avl;
    avl.insert(9);
    avl.insert(5);
    avl.insert(10);
    avl.insert(0);
    avl.insert(6);
    avl.insert(11);
    avl.insert(-1);
    avl.insert(1);
    avl.insert(2);
    avl.preorder();

    avl.remove(10);
    avl.preorder();*/

    /*BST bst;
    bst.insert(9);
    bst.insert(5);
    bst.insert(10);
    bst.insert(0);
    bst.insert(6);
    bst.insert(11);
    bst.insert(-1);
    bst.insert(1);
    bst.insert(2);
    bst.preorder();

    bst.remove(10);
    bst.preorder();*/


    return 0;
}
