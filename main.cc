#include "call_python.h"

using namespace std;

int main(int argc, char **argv)
{
  CallPython *cp = new CallPython("func1");
  if(!cp)
  {
	  fprintf(stderr, "[Error] CallPython failed!~\n");
	  return -1;
  }
  
  cp->setArgc(2);
  for(int i=0;i<2;++i)
	  cp->feedArgv(i, i+1);
  cp->executePythonFunction("func");
  delete cp;

  return 0;
}
