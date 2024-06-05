GitHubHIndexMetricCalculator::GitHubHIndexMetricConstructor(nullptr) : github_h_index_2D_metric_array(), total_repository_count_(0), current_size(0), github_total_user_metric_report_array(), total_user_and_organization_count_(0), total_user_count_(0), total_organization_count_(0), user_array(), organization_array() {}

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
