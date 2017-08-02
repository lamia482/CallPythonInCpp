#ifndef _LAMIA_CALL_PYTHON_H_
#define _LAMIA_CALL_PYTHON_H_

#include <Python.h>
#include <iostream>

class CallPython
{
public:
	CallPython(const char *pyfile = nullptr);
	~CallPython(void);
	void setArgc(const int &n);
	void feedArgv(const int &i, const int &v);
	void executePythonFunction(const char *pyfunction = nullptr);
private:
	PyObject *m_pModuleName;
	PyObject *m_pModule;
	PyObject *m_pFunction;
	PyObject *m_pArgs;
	PyObject **m_ppArgv;
	PyObject *m_pRet;
	int m_argsNum;
};


#endif