#include "../HeaderFiles/github_hirsch_index_metric_calculator.h"
GitHubHIndexMetricCalculator::RequestGitHubAccounts(string base_url, int perPage = '\0', int pageNumber = '\0')
{
  if (perPage != '\0' && pageNumber != '\0')
  {
    final_url_= base_url + "?per_page=" + std::to_string(total_per_page_)+ "&page=" + std::to_string(page_number_);
  }
  else
  {
    final_url_ = base_url;
  }

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if (curl == NULL)
  {
    PrintString("HTTP request failed.", stderr);
    return -1;
  }

  CURLcode response;

  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, final_url_);
    curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
    header_list_ = curl_slist_append(header_list_, "Accept: application/vnd.github+json");
    header_list_ = curl_slist_append(header_list_, "Authorization: Bearer <YOUR-TOKEN>");
    header_list_ = curl_slist_append(header_list_, "X-GitHub-Api-Version: 2022-11-28");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list_);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    response = curl_easy_perform(curl);

    if (response != CURLE_OK)
    {
      // curl_easy_strerror() will return a string with the error message
      PrintString(curl_easy_strerror(response), stderr);
      return -1;
    }

    PrintString(response);
    PrintString(readBuffer);
    curl_easy_cleanup(curl);
    curl_slist_free_all(header_list_);
  }


  curl_global_cleanup();

  return response;
}
