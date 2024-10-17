#include <iostream>

using namespace std;

int flip_max_sequence(int sequence[], int size) {
    if (size == 0 || size == 1) {
        return size;
    }

    if (sequence[0] < sequence[size - 1]) {
        return size;
    }
    return flip_max_sequence(sequence + 1, size - 1);
}

int main() {
    int sequence[] = {3,4,5,1,6,3,2};
    int size = sizeof(sequence) / sizeof(sequence[0]);

    int result = flip_max_sequence(sequence, size);
    if (result ==  size-1)
        cout << "Max flip-max sequence length: " << result << endl;
    else
        cout<<"No flip-max sequence"<<endl;

    return 0;
}
