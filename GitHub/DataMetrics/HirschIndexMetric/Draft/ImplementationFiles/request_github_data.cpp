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
