#include <iostream>
#include <curl/curl.h>

//Declare Class, Methods, and Variables.
class GitHubHIndexMetricCalculator {

private:
  string user_name_;
  string organization_name_;
  string repository_name_;
  string user_and_organization_url_;
  int rate_limit_;
  int rate_limit_reset_time_;
  int user_ID_;
  int total_user_and_organization_count_;
  int organization_ID_;
  int repository_ID_;
  int repository_forks_;
  int repository_stars_;
  int total_repository_count_;
  int total_pages_;
  int page_number_;
  bool repository_fork_status_;
  int github_h_index_result_;
  int **github_h_index_2D_metric_array;
  int **github_total_user_metric_report_array;
  string top_ten_user_array[11][5];
  string top_ten_organization_array[11][5];
  size_t current_size_;

public:
  GitHubHIndexMetricConstructor();
  ~GitHubHIndexMetricConstructor();
  void PrintString();
  void RequestGitHubHIndexMetric();
  void SetGitHubHIndexMetricData();
  void DeleteOldArray();
  int PartitionGitHubHIndexMetricData();
  void SortGitHubHIndexMetricData();
  void CalculateGitHubHIndex();
  void PartitionTopTenResults();
  void SortTopTenResults();
  int GetGitHubHIndexMetricData();

};

//Initialize & Define Constructor, Methods, and Variables.
GitHubHIndexMetricCalculator::GitHubHIndexMetricConstructor(nullptr) : github_h_index_2D_metric_array(), total_repository_count_(0), current_size(0), github_total_user_metric_report_array(), total_user_and_organization_count_(0) {}

DeleteOldArray(int count, int array){
  for (size_t i = 0; i < count; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

GitHubHIndexMetricCalculator::PrintString(string output_String, int output_Data = '\0') {
  if (output_Data == '\0'){
    std::cout << output_String << '\nl';
  } else{
    std::cout << output_String << output_Data << '\nl';
  }
}

GitHubHIndexMetricCalculator::~GitHubHIndexMetricConstructor(){
  DeleteOldArray(total_repository_count_, github_h_index_2D_metric_array);
  DeleteOldArray(total_user_and_organization_count_, github_total_user_metric_report_array);
}

GitHubHIndexMetricCalculator::RequestGitHubHIndexMetric(){}

GitHubHIndexMetricCalculator::SetGitHubHIndexMetricData(){}

GitHubHIndexMetricCalculator::PartitionGitHubHIndexMetricData(){}

GitHubHIndexMetricCalculator::SortGitHubHIndexMetricData(){}

GitHubHIndexMetricCalculator::CalculateGitHubHIndex(){}

GitHubHIndexMetricCalculator::PartitionTopTenResults(){}

GitHubHIndexMetricCalculator::SortTopTenResults(){}

GitHubHIndexMetricCalculator::GetGitHubHIndexMetricData(){}

//Define, Initialize, and run main class.
int main(){
  GitHubHIndexMetricCalculator testGitHubHIndexMetricCalculator;
  testGitHubHIndexMetricCalculator.SetGitHubHIndexMetricData();
  testGitHubHIndexMetricCalculator.GetGitHubHIndexMetricData();
  testGitHubHIndexMetricCalculator.PrintString("PRESS ENTER TO EXIT THIS PROGRAM.");
  std::cin.get();


  return 0;
}
