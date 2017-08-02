#include "call_python.h"

using namespace std;

int main(int argc, char **argv)
{
#if 0
  Py_Initialize();
  
  PyObject *moduleName = PyString_FromString("func1");
  PyObject *pModule = PyImport_Import(moduleName);
  if(!pModule)
  {
    fprintf(stderr, "[Error] Python get module failed!~\n");
    return -1;
  }

  fprintf(stderr, "[Info] Python get module succeed!~\n");
  PyObject *pv = PyObject_GetAttrString(pModule, "func");
  if (!pv || !PyCallable_Check(pv))  
  {
      fprintf(stderr, "[Error] Can't find funftion\n");
      return -2;
  }
  fprintf(stderr, "[Info] Python get function succeed!~\n");
  
  PyObject* args = PyTuple_New(2);   // 2个参数
  PyObject* arg1 = PyInt_FromLong(4);    // 参数一设为4
  PyObject* arg2 = PyInt_FromLong(3);    // 参数二设为3
  PyTuple_SetItem(args, 0, arg1);
  PyTuple_SetItem(args, 1, arg2);

  PyObject *pRet = PyObject_CallObject(pv, args);
  if(pRet)
  {
	  long result = PyInt_AsLong(pRet);
	  fprintf(stderr, "result: %ld\n", result);
  }
  
  Py_Finalize();
#endif

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
