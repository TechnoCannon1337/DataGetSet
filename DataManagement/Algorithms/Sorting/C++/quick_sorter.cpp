#include <iostream>

using namespace std;

class QuickSorter {
private:
    static const int array_Column_Size = 6;
    int Index_Array[2][array_Column_Size] = {
        {1, 2, 3, 4, 5, 6},
        {5, 25, 8, 3, 3, 5}
    };

public:
    int partition(int arr[2][array_Column_Size], int left, int right){
        int pivot = arr[1][(left + right) / 2];
        while (left <= right){
            //Change the less than operator to a greater than operator to sort in descending order
            //while (arr[1][left] > pivot) left++;
            while (arr[1][left] < pivot) left++;
            //Change the greater than operator to a less than operator to sort in descending order
            //while (arr[1][right] < pivot) right--;
            while (arr[1][right] > pivot) right--;
            if (left <= right){
                for(int i = 0; i < 2; i++) {
                    int temp_swap = arr[i][left];
                    arr[i][left] = arr[i][right];
                    arr[i][right] = temp_swap;
                }
                left++;
                right--;
            }
        }
        return left;
    }

    void sortIndex(int arr[2][array_Column_Size], int left, int right){
        int index = partition(arr, left, right);
        if (left < index - 1){
            sortIndex(arr, left, index - 1);
        }
        if (index < right) {
            sortIndex(arr, index, right);
        }
    }

    void startQuickSort(){
        sortIndex(Index_Array, 0, array_Column_Size - 1);
        for (int i = 0; i < 1; i++){
            for (int j = 0; j < array_Column_Size; j++){
                cout << Index_Array[1][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    QuickSorter testQuickSorter;
    testQuickSorter.startQuickSort();
    return 0;
}
