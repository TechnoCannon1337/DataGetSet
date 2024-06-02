#include <iostream>

using namespace std;

//Declare Class, Methods, and Variables.
class GitHubHIndexMetricCalculator {

private:
  string user_name;
  string organization_name;
  string repository_name;
  string user_and_organization_url;
  int rate_limit;
  int rate_limit_reset_time;
  int user_ID;
  int total_user_and_organization_count;
  int organization_ID;
  int repository_ID;
  int repository_forks;
  int repository_stars;
  int total_repository_count;
  int total_pages;
  int page_number;
  bool repository_fork_status;
  int github_h_index_result;
  int **github_h_index_2D_metric_array;
  int **github_total_user_metric_report_array;
  string top_ten_user_array[11][5];
  string top_ten_organization_array[11][5];
  size_t current_size;

public:
  GitHubHIndexMetricConstructor();
  ~GitHubHIndexMetricConstructor();
  void printString();
  void RequestGitHubHIndexMetric();
  void SetGitHubHIndexMetricData();
  int PartitionGitHubHIndexMetricData();
  void SortGitHubHIndexMetricData();
  void CalculateGitHubHIndex();
  void PartitionTopTenResults();
  void SortTopTenResults();
  int GetGitHubHIndexMetricData();

};

//Initialize & Define Constructor, Methods, and Variables.
GitHubHIndexMetricCalculator::GitHubHIndexMetricConstructor(nullptr) : github_h_index_2D_metric_array(), total_repository_count(0), current_size(0) {}
GitHubHIndexMetricCalculator::GitHubHIndexMetricConstructor(nullptr) : github_total_user_metric_report_array(), total_user_and_organization_count(0), current_size(0) {}

GitHubHIndexMetricCalculator::~GitHubHIndexMetricConstructor(){
  for (size_t i = 0; i < total_repository_count; ++i) {
        delete[] github_h_index_2D_metric_array[i];
    }
    delete[] github_h_index_2D_metric_array;

  for (size_t i = 0; i < total_user_and_organization_count; ++i) {
        delete[] github_total_user_metric_report_array[i];
    }
    delete[] github_total_user_metric_report_array;

}

GitHubHIndexMetricCalculator::printString(string output_String, int output_Data = '\0') {
  if (output_Data == '\0'){
    cout << output_String << endl;
  } else{
    cout << output_String << output_Data << endl;
  }
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
  testGitHubHIndexMetricCalculator.printString("PRESS ENTER TO EXIT THIS PROGRAM.");
  cin.get();
  cin.get();

  return 0;
}
