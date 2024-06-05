#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

CURLcode curl_global_init(long flags);

//Declare Class, Methods, and Variables.
class GitHubHIndexMetricCalculator
{
private:
  size_t current_size_;
  int i;
  int response_status_code_;
  CURL *curl;
  struct curl_slist *header_list_ = NULL;
  string get_rate_limit_curl_=  "https://api.github.com/rate_limit";
  int rate_limit_;
  int rate_limit_reset_time_;
  int total_per_page_ = 100;
  int total_pages_;
  int page_number_ = 1;
  string list_all_organizations_curl_=  "https://api.github.com/organizations?per_page={total_per_page_}&page={page_number_}";
  string list_all_users_curl_=  "https://api.github.com/user";
  std::string readBuffer;
  string **user_array[][5];
  string **organization_array[][5];
  int total_user_count_;
  int total_organization_count_;
  int total_user_and_organization_count_;
  string user_name_;
  int user_ID_;
  string organization_name_;
  int organization_ID_;
  int total_repository_count_;
  string repos_url_;
  string user_and_organization_url_;
  string list_all_user_repo_curl_=  "{user_array[{i}][3]}?per_page={total_per_page_}&page={page_number_}";
  string list_all_org_repo_curl_=  "{organization_array[{i}][3]}?per_page={total_per_page_}&page={page_number_}";
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

public:
  GitHubHIndexMetricConstructor();
  ~GitHubHIndexMetricConstructor();
  int PrintString(string output_String, int output_Data);
  void RequestGitHubAccounts(string url, int perPage, int pageNumber);
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
GitHubHIndexMetricCalculator::GitHubHIndexMetricConstructor(nullptr) : github_h_index_2D_metric_array(), total_repository_count_(0), current_size(0), github_total_user_metric_report_array(), total_user_count_(0), total_user_and_organization_count_(0), total_organization_count_(0), user_array(), organization_array() {}

DeleteOldArray(int count, int array)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete[] array[i];
  }
  delete[] array;
}

GitHubHIndexMetricCalculator::~GitHubHIndexMetricConstructor()
{
  DeleteOldArray(total_user_count_, user_array);
  DeleteOldArray(total_organization_count_, organization_array);
  DeleteOldArray(total_repository_count_, github_h_index_2D_metric_array);
  DeleteOldArray(total_user_and_organization_count_, github_total_user_metric_report_array);
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

GitHubHIndexMetricCalculator::RequestGitHubAccounts(string url, int perPage, int pageNumber)
{
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  CURLcode response;
  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
    header_list_ = curl_slist_append(header_list_, "Accept: application/vnd.github+json");
    header_list_ = curl_slist_append(header_list_, "Authorization: Bearer <YOUR-TOKEN>");
    header_list_ = curl_slist_append(header_list_, "X-GitHub-Api-Version: 2022-11-28");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list_);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    response = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(header_list_);
  }
  PrintString(readBuffer);
  curl_global_cleanup();
}

GitHubHIndexMetricCalculator::RequestGitHubHIndexMetric(){}
GitHubHIndexMetricCalculator::SetGitHubHIndexMetricData(){}
GitHubHIndexMetricCalculator::PartitionGitHubHIndexMetricData(int** arr, int left, int right)){}
GitHubHIndexMetricCalculator::SortGitHubHIndexMetricData(int** arr, int left, int right)){}
GitHubHIndexMetricCalculator::CalculateGitHubHIndex(){}
GitHubHIndexMetricCalculator::PartitionTopTenResults(int** arr, int left, int right)){}
GitHubHIndexMetricCalculator::SortTopTenResults(int** arr, int left, int right)){}
GitHubHIndexMetricCalculator::GetGitHubHIndexMetricData()
{
  ofstream organizationCSVFile("GitHubOrganizationCSVFile.csv");
  ofstream userCSVFile("GitHubUserCSVFile.csv");
  ofstream TopTenOrganizationCSVFile("TopTenGitHubOrganizationCSVFile.csv");
  ofstream TopTenUserCSVFile("TopTenGitHubUserCSVFile.csv");
}

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
