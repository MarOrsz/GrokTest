
#include <vector>
#include <algorithm>


void process(std::vector<int>& data) {
    if(data.empty())
        return;
    for (int i = 0; i < data.size(); ++i) {
        data[i] *= 2;
    }
}

void sort(std::vector<int>& data){
    if(data.size() < 2)
        return;
        
    std::sort(data.begin(), data.end(), std::greater<int>());
}