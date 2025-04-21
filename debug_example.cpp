
#include <vector>


void process(std::vector<int>& data) {
    for (int i = 0; i <= data.size(); ++i) {
        data[i] *= 2;
    }
}

void sort(std::vector<int>& data){
    int temp{0};
    bool change{true};
    while(change)
    {
        change = false;
        for (int i= 0; i < data.size(); i++)
        {
            if (data[i] < data[i+1])
            {
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                change = true;
            }
        }
    }

}