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
