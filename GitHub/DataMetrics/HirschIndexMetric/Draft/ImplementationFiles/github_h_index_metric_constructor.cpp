//#include "../HeaderFiles/github_hirsch_index_metric_calculator.h"
#include "./github_hirsch_index_metric_calculator.h"

GitHubHIndexMetricCalculator::GitHubHIndexMetricCalculator()
    : github_h_index_2D_metric_array(nullptr),
      total_repository_count_(0),
      current_size_(0),
      github_total_user_metric_report_array(nullptr),
      total_user_and_organization_count_(0),
      total_user_count_(0),
      total_organization_count_(0),
      user_array(nullptr),
      organization_array(nullptr) {}

// Templated function to delete old arrays
template <typename T>
size_t DeleteOldArray(size_t count, T* array) {
    delete[] array;
    return 0;
}

// Specialization for arrays of pointers
template <typename T>
size_t DeleteOldArray(size_t count, T** array) {
    for (size_t i = 0; i < count; ++i) {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}

GitHubHIndexMetricCalculator::~GitHubHIndexMetricCalculator() {
    DeleteOldArray(total_user_count_, user_array);
    DeleteOldArray(total_organization_count_, organization_array);
    DeleteOldArray(total_repository_count_, github_h_index_2D_metric_array);
    DeleteOldArray(total_user_and_organization_count_, github_total_user_metric_report_array);
}

// Explicit template instantiation for types used in the destructor
template size_t DeleteOldArray<std::string>(size_t, std::string*);
template size_t DeleteOldArray<int>(size_t, int**);
template size_t DeleteOldArray<std::string>(size_t, std::string**);
