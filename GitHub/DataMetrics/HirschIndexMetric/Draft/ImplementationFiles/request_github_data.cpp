#include "../HeaderFiles/github_hirsch_index_metric_calculator.h"

std::string GitHubHIndexMetricCalculator::RequestGitHubAccounts(std::string base_url, int perPage, int pageNumber)
{
  if (perPage != 0 && pageNumber != 0)
  {
    final_url_= base_url + "?per_page=" + std::to_string(total_per_page_)+ "&page=" + std::to_string(page_number_);
  }
  else
  {
    final_url_ = base_url;
  }

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  if (curl == NULL)
  {
    std::cout << "HTTP request failed." << '\n';
  }

  CURLcode response;
  struct MemoryStruct chunk;
  chunk.memory = (char*)malloc(1);
  chunk.size = 0;

  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, final_url_);
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
    curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
    header_list_ = curl_slist_append(header_list_, "Accept: application/vnd.github+json");
    header_list_ = curl_slist_append(header_list_, "Authorization: Bearer <YOUR-TOKEN>");
    header_list_ = curl_slist_append(header_list_, "X-GitHub-Api-Version: 2022-11-28");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list_);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    response = curl_easy_perform(curl);

    if (response != CURLE_OK)
    {
      // curl_easy_strerror() will return a string with the error message
      std::cout << curl_easy_strerror(response) << '\n';
    }

    std::cout << response << '\n';
    std::cout << readBuffer << '\n';
    for (int i = 0; i <= chunk.size; i++)
    {
      std::cout << i << '\n';
    }
    curl_easy_cleanup(curl);
    free(chunk.memory);
    curl_slist_free_all(header_list_);
  }


  curl_global_cleanup();

  return readBuffer;
}
