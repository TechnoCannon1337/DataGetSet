#include <iostream>

/*
The h-index is an author-level metric that measures both the productivity and citation impact of the publications, initially used for an individual scientist or scholar. The h-index correlates with success indicators such as winning the Nobel Prize, being accepted for research fellowships and holding positions at top universities.

The index is based on the set of the scientist's most cited papers and the number of citations that they have received in other publications.

The index was suggested in 2005 by Jorge E. Hirsch, a physicist at UC San Diego, as a tool for determining theoretical physicists' relative quality

The h-index is defined as the maximum value of h such that the given author/journal has published at least h papers that have each been cited at least h times

*/

using namespace std;

class HIndexCalculator {

private:
    int **H_Index_Array;
    int publication_count;
    int citation_Count;
    int H_Index_Summation;
    size_t current_size;

public:
    HIndexCalculator();
    ~HIndexCalculator();
    void printString(string output_String, int output_Data);
    int getUserInput();
    void setData();
    int partition(int** arr, int left, int right);
    void sortHIndex(int** arr, int left, int right);
    void calculateHIndex();
    int getData();

};

HIndexCalculator::HIndexCalculator() : H_Index_Array(nullptr), publication_count(0), current_size(0) {}

HIndexCalculator::~HIndexCalculator() {
    for (size_t i = 0; i < 2; ++i) {
        delete[] H_Index_Array[i];
    }
    delete[] H_Index_Array;
}

void HIndexCalculator::printString(string output_String, int output_Data = '\0') {
  if (output_Data == '\0'){
    cout << output_String << endl;
  } else{
    cout << output_String << output_Data << endl;
  }
}

int HIndexCalculator::getUserInput() {
    int input;
    cin >> input;
    return input;
}

int HIndexCalculator::partition(int** arr, int left, int right) {
    int pivot = arr[1][(left + right) / 2];
    while (left <= right) {
        while (arr[1][left] > pivot) left++;
        while (arr[1][right] < pivot) right--;
        if (left <= right) {
            int temp_swap = arr[1][left];
            arr[1][left] = arr[1][right];
            arr[1][right] = temp_swap;
            left++;
            right--;
        }
    }
    return left;
}

void HIndexCalculator::sortHIndex(int** arr, int left, int right) {
    int index = partition(arr, left, right);
    if (left < index - 1) {
        sortHIndex(arr, left, index - 1);
    }
    if (index < right) {
        sortHIndex(arr, index, right);
    }
}

void HIndexCalculator::setData() {
    printString("ENTER TOTAL NUMBER OF PUBLICATION TITLES AS NUMERICAL INTEGERS AND PRESS ENTER.");
    publication_count = getUserInput();

    H_Index_Array = new int*[2];
    for (size_t i = 0; i < 2; ++i) {
        H_Index_Array[i] = new int[publication_count];
        int* new_row = new int[publication_count];
        for (size_t j = 0; j < publication_count; ++j) {
            new_row[j] = H_Index_Array[i][j];
        }
        delete[] H_Index_Array[i];
        H_Index_Array[i] = new_row;
    }
    current_size = publication_count;

    for (int j = 0; j < publication_count; j++) {
        printString("ENTER TOTAL NUMBER OF CITATIONS AS NUMERICAL INTERGERS FOR PUBLICATION NUMBER " , j + 1);
        H_Index_Array[0][j] = j;
        H_Index_Array[1][j] = getUserInput();
    }
    sortHIndex(H_Index_Array, 0, publication_count - 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < publication_count; j++) {
            if (H_Index_Array[1][j] >= H_Index_Array[0][j]) {
                H_Index_Summation = H_Index_Array[0][j];
            } else {
                break;
            }
        }
    }
}

int HIndexCalculator::getData() {
    printString("THE H-INDEX IS ", H_Index_Summation);
    return H_Index_Summation;
}

int main() {
    HIndexCalculator testHIndexCalculator;
    testHIndexCalculator.setData();
    testHIndexCalculator.getData();
    testHIndexCalculator.printString("PRESS ENTER TO EXIT THIS PROGRAM.");
    cin.get();
    cin.get();
    return 0;
}
