#include <iostream>
#include <curl/curl.h>

//Declare Class, Methods, and Variables.
class GitHubHIndexMetricCalculator
{
private:
  int response_status_code_;
  int curl_header_ = "Accept: application/vnd.github+json", "Authorization: Bearer <YOUR-TOKEN>" , "X-GitHub-Api-Version: 2022-11-28";
  string get_rate_limit_curl_=  "https://api.github.com/rate_limit";
  int rate_limit_;
  int rate_limit_reset_time_;
  int total_per_page_ = 100;
  int total_pages_;
  int page_number_ = 1;
  string list_all_organizations_curl_=  "https://api.github.com/organizations?per_page={total_per_page_}&page={page_number_}";
  string list_all_users_curl_=  "https://api.github.com/user";
  string **user_array[][5];
  string **organization_array[][5];
  int total_user_count_;
  int total_organization_count_;
  string user_name_;
  int user_ID_;
  string organization_name_;
  int organization_ID_;
  int total_repository_count_;
  string repos_url_;
  string user_and_organization_url_;
  string list_all_user_repo_curl_=  "{user_array[i][3]}?per_page={total_per_page_}&page={page_number_}";
  string list_all_org_repo_curl_=  "{organization_array[i][3]}?per_page={total_per_page_}&page={page_number_}";
  bool repository_fork_status_;
  string repository_name_;
  int repository_ID_;
  int repository_forks_;
  int repository_stars_;
  int github_h_index_result_;
  int **github_h_index_2D_metric_array;
  int **github_total_user_metric_report_array;
  string top_ten_user_array[11][5];
  string top_ten_organization_array[11][5];
  size_t current_size_;

public:
  GitHubHIndexMetricConstructor();
  ~GitHubHIndexMetricConstructor();
  int PrintString(string output_String, int output_Data);
  void RequestGitHubAccounts();
  void RequestGitHubHIndexMetric();
  void SetGitHubHIndexMetricData();
  void DeleteOldArray();
  int PartitionGitHubHIndexMetricData(int** arr, int left, int right);
  void SortGitHubHIndexMetricData(int** arr, int left, int right));
  void CalculateGitHubHIndex();
  void PartitionTopTenResults(int** arr, int left, int right));
  void SortTopTenResults(int** arr, int left, int right));
  int GetGitHubHIndexMetricData();
};

//Initialize & Define Constructor, Methods, and Variables.
GitHubHIndexMetricCalculator::GitHubHIndexMetricConstructor(nullptr) : github_h_index_2D_metric_array(), total_repository_count_(0), current_size(0), github_total_user_metric_report_array(), total_user_count_(0), total_organization_count_(0), user_array(), organization_array() {}

DeleteOldArray(int count, int array)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete[] array[i];
  }
  delete[] array;
}

GitHubHIndexMetricCalculator::PrintString(string output_String, int output_Data = '\0')
{
  if (output_Data != '\0')
  {
    std::cout << output_String << output_Data << '\nl';
    return 0;
  }
  std::cout << output_String << '\nl';
  return 0;
}

GitHubHIndexMetricCalculator::~GitHubHIndexMetricConstructor()
{
  DeleteOldArray(total_repository_count_, github_h_index_2D_metric_array);
  DeleteOldArray(total_user_and_organization_count_, github_total_user_metric_report_array);
}
GitHubHIndexMetricCalculator::RequestGitHubAccounts(){}
GitHubHIndexMetricCalculator::RequestGitHubHIndexMetric(){}
GitHubHIndexMetricCalculator::SetGitHubHIndexMetricData(){}
GitHubHIndexMetricCalculator::PartitionGitHubHIndexMetricData(int** arr, int left, int right)){}
GitHubHIndexMetricCalculator::SortGitHubHIndexMetricData(int** arr, int left, int right)){}
GitHubHIndexMetricCalculator::CalculateGitHubHIndex(){}
GitHubHIndexMetricCalculator::PartitionTopTenResults(int** arr, int left, int right)){}
GitHubHIndexMetricCalculator::SortTopTenResults(int** arr, int left, int right)){}
GitHubHIndexMetricCalculator::GetGitHubHIndexMetricData(){}

//Define, Initialize, and run main class.
int main()
{
  GitHubHIndexMetricCalculator testGitHubHIndexMetricCalculator;
  testGitHubHIndexMetricCalculator.SetGitHubHIndexMetricData();
  testGitHubHIndexMetricCalculator.GetGitHubHIndexMetricData();
  testGitHubHIndexMetricCalculator.PrintString("PRESS ENTER TO EXIT THIS PROGRAM.");
  std::cin.get();

  return 0;
}
