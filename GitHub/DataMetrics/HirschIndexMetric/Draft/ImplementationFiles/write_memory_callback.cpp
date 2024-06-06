#include "../HeaderFiles/github_hirsch_index_metric_calculator.h"
//#include "./github_hirsch_index_metric_calculator.h"

struct MemoryStruct {
  char *memory;
  size_t size;
};

size_t GitHubHIndexMetricCalculator::WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  char *ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
  if(ptr == NULL) {
    /* out of memory! */
    std::cout << "not enough memory (realloc returned NULL)\n";
    return 0;
  }

  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}
