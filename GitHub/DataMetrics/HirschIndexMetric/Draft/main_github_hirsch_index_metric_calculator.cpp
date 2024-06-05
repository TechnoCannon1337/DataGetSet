#include "./HeaderFiles/github_hirsch_index_metric_calculator.h"

int main()
{
  GitHubHIndexMetricCalculator testGitHubHIndexMetricCalculator;
  testGitHubHIndexMetricCalculator.SetGitHubHIndexMetricData();
  testGitHubHIndexMetricCalculator.GetGitHubHIndexMetricData();
  testGitHubHIndexMetricCalculator.PrintString("PRESS ENTER TO EXIT THIS PROGRAM.");
  std::cin.get();

  return 0;
}
