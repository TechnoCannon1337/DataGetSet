#include "../HeaderFiles/github_hirsch_index_metric_calculator.h"

int main()
{
  GitHubHIndexMetricCalculator testGitHubHIndexMetricCalculator;
  testGitHubHIndexMetricCalculator.RequestGitHubAccounts("https://api.github.com/rate_limit");
  std::cin.get();

  return 0;
}
