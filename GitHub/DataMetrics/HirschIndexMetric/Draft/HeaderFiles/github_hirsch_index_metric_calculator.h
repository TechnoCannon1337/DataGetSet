#ifndef GITHUB_HIRSCH_INDEX_METRIC_CALCULATOR_H
#define GITHUB_HIRSCH_INDEX_METRIC_CALCULATOR_H

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
  std::stringget_rate_limit_curl_=  "https://api.github.com/rate_limit";
  int rate_limit_;
  int rate_limit_reset_time_;
  int total_per_page_ = 100;
  int total_pages_;
  int page_number_ = 1;
  std::stringlist_all_organizations_curl_=  "https://api.github.com/organizations";
  std::stringlist_all_users_curl_=  "https://api.github.com/user";
  std::stringreadBuffer;
  std::string**user_array[][5];
  std::string**organization_array[][5];
  int total_user_count_;
  int total_organization_count_;
  int total_user_and_organization_count_;
  std::stringuser_name_;
  int user_ID_;
  std::stringorganization_name_;
  int organization_ID_;
  int total_repository_count_;
  std::stringrepos_url_;
  std::stringfinal_url_;
  std::stringuser_and_organization_url_;
  ofstream organizationCSVFile("GitHubOrganizationCSVFile.csv");
  ofstream userCSVFile("GitHubUserCSVFile.csv");
  std::stringlist_all_user_repo_curl_=  user_array[{i}][3];
  std::stringlist_all_org_repo_curl_=  organization_array[{i}][3];
  bool repository_fork_status_;
  std::stringrepository_name_;
  int repository_ID_;
  int repository_forks_;
  int repository_stars_;
  int github_h_index_result_;
  int **github_h_index_2D_metric_array;
  int **github_total_user_metric_report_array;
  std::stringtop_ten_user_array[11][5];
  std::stringtop_ten_organization_array[11][5];
  ofstream TopTenOrganizationCSVFile("TopTenGitHubOrganizationCSVFile.csv");
  ofstream TopTenUserCSVFile("TopTenGitHubUserCSVFile.csv");

public:
  GitHubHIndexMetricConstructor();
  ~GitHubHIndexMetricConstructor();
  int PrintString(std::stringoutput_String, int output_Data);
  auto RequestGitHubAccounts(std::stringbase_url, int perPage, int pageNumber);
  int WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);
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
