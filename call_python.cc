#include "call_python.h"

CallPython::CallPython(const char *pyfile)
{
	Py_Initialize();
	m_pModuleName = PyString_FromString(pyfile);
	m_pModule = PyImport_Import(m_pModuleName);
	if(!m_pModule)
	{
		fprintf(stderr, "[Error] Python get module failed!~\n");
	}
	return;
	fprintf(stderr, "[Info] Python get module succeed!~\n");
}
CallPython::~CallPython(void)
{
	Py_Finalize();
	free(m_ppArgv);
}
void CallPython::setArgc(const int &n)
{
	m_argsNum = n;
	m_pArgs = PyTuple_New(m_argsNum);
	m_ppArgv = (PyObject**)calloc(m_argsNum, sizeof(PyObject*));
}
void CallPython::feedArgv(const int &i, const int &v)
{
	m_ppArgv[i] = PyInt_FromLong(v);
	PyTuple_SetItem(m_pArgs, i, m_ppArgv[i]);
}
void CallPython::executePythonFunction(const char *pyfunction)
{
	m_pFunction = PyObject_GetAttrString(m_pModule, pyfunction);
	m_pRet = PyObject_CallObject(m_pFunction, m_pArgs);
	if(m_pRet)
	{
	  long result = PyInt_AsLong(m_pRet);
	  fprintf(stderr, "result: %ld\n", result);
	}
}
