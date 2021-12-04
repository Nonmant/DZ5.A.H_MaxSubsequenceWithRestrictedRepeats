//https://contest.yandex.ru/contest/27794/problems/H/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    int n, k;
    input >> n >> k;
    input.ignore();

    std::vector<char> line(n);
    std::copy_n(std::istream_iterator<char>(input), n, line.begin());

    long deltaMax = 0, leftDeltaMax = 0;
    std::map<char, long> chars;
    auto left = line.begin();
    long delta;
    for(auto right = line.begin(); right!=line.end(); ++right){
        ++chars[*right];
        while (chars[*right] > k){
            --chars[*left];
            ++left;
        }
        delta = std::distance(left,right)+1;
        if(delta>deltaMax){
            deltaMax = delta;
            leftDeltaMax = std::distance(line.begin(), left)+1;
        }
    }

    output << deltaMax << ' ' << leftDeltaMax;
}
