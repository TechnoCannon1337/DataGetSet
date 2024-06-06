#ifndef GITHUB_HIRSCH_INDEX_METRIC_CALCULATOR_H
#define GITHUB_HIRSCH_INDEX_METRIC_CALCULATOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <cstring>  // For memcpy
#include <cstdlib>  // For realloc

//Declare Class, Methods, and Variables.
class GitHubHIndexMetricCalculator
{
private:
  size_t current_size_;
  int i;
  int response_status_code_;
  struct MemoryStruct
  {
    char *memory;
    size_t size;
  };
  CURL *curl;
  CURLcode response;
  struct curl_slist *header_list_ = NULL;
  std::string get_rate_limit_curl_=  "https://api.github.com/rate_limit";
  int rate_limit_;
  int rate_limit_reset_time_;
  int total_per_page_ = 100;
  int total_pages_;
  int page_number_ = 1;
  std::string list_all_organizations_curl_=  "https://api.github.com/organizations";
  std::string list_all_users_curl_=  "https://api.github.com/user";
  std::string readBuffer;
  int total_user_count_;
  int total_organization_count_;
  int total_user_and_organization_count_;
  std::string user_name_;
  int user_ID_;
  std::string organization_name_;
  int organization_ID_;
  int total_repository_count_;
  std::string repos_url_;
  std::string final_url_;
  std::string user_and_organization_url_;
  std::string list_all_user_repo_curl_;
  std::string list_all_org_repo_curl_;
  bool repository_fork_status_;
  std::string repository_name_;
  int repository_ID_;
  int repository_forks_;
  int repository_stars_;
  int github_h_index_result_;
  int **github_h_index_2D_metric_array;
  int **github_total_user_metric_report_array;
  std::string top_ten_user_array[11][5];
  std::string top_ten_organization_array[11][5];
  std::string **user_array;
  std::string **organization_array;
  static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);

public:
  GitHubHIndexMetricCalculator();
  ~GitHubHIndexMetricCalculator();
  int PrintString(std::string output_String, int output_Data = '\0');
  std::string RequestGitHubAccounts(std::string base_url, int perPage = 0, int pageNumber = 0);
  void RequestGitHubHIndexMetric();
  void SetGitHubHIndexMetricData();
  //size_t DeleteOldArray(size_t count, auto array);
  int PartitionGitHubHIndexMetricData(int** arr, int left, int right);
  void SortGitHubHIndexMetricData(int** arr, int left, int right);
  void CalculateGitHubHIndex();
  void PartitionTopTenResults(int** arr, int left, int right);
  void SortTopTenResults(int** arr, int left, int right);
  int GetGitHubHIndexMetricData();
  template <typename T>
    size_t DeleteOldArray(size_t count, T* array);
  template <typename T>
    size_t DeleteOldArray(size_t count, T** array);
};
#endif
