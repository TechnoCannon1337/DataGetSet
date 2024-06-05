#ifndef GITHUB_HIRSCH_INDEX_METRIC_CALCULATOR.H
#define GITHUB_HIRSCH_INDEX_METRIC_CALCULATOR.H

#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

//Declare Class, Methods, and Variables.
class GitHubHIndexMetricCalculator
{
private:
  size_t current_size_;
  int i;
  int response_status_code_;
  struct MemoryStruct { char *memory; size_t size;};
  static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);
  CURL *curl;
  struct curl_slist *header_list_ = NULL;
  string get_rate_limit_curl_=  "https://api.github.com/rate_limit";
  int rate_limit_;
  int rate_limit_reset_time_;
  int total_per_page_ = 100;
  int total_pages_;
  int page_number_ = 1;
  string list_all_organizations_curl_=  "https://api.github.com/organizations";
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
  string final_url_;
  string user_and_organization_url_;
  ofstream organizationCSVFile("GitHubOrganizationCSVFile.csv");
  ofstream userCSVFile("GitHubUserCSVFile.csv");
  string list_all_user_repo_curl_=  user_array[{i}][3];
  string list_all_org_repo_curl_=  organization_array[{i}][3];
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
  ofstream TopTenOrganizationCSVFile("TopTenGitHubOrganizationCSVFile.csv");
  ofstream TopTenUserCSVFile("TopTenGitHubUserCSVFile.csv");

public:
  GitHubHIndexMetricConstructor();
  ~GitHubHIndexMetricConstructor();
  int PrintString(string output_String, int output_Data);
  auto RequestGitHubAccounts(string base_url, int perPage, int pageNumber);
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
#endif
