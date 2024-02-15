#include <Python.h>
#include <iostream>
#include <stdio.h>

int main(int argc, char **argv)
{
    int number;
    if (argc == 1)
    {
        number = 2;
    }
    else 
    {
        number = std::atoi(argv[1]);
    }

    Py_Initialize();

    PyRun_SimpleString("import sys; sys.path.insert(0, '.')");

    PyObject* module = PyImport_ImportModule("printing_tests");
    if (module == NULL)
    {
        printf("No Module Found \n");
        return 0;
    }

    PyObject* function = PyObject_GetAttrString(module, (char*)"printString");
    if (function == NULL)
    {
        printf("No Function Found\n");
        return 0;
    }


    PyObject* args = PyTuple_Pack(2, PyLong_FromLong(number), PyUnicode_FromString("test"));    
    PyObject* result = PyObject_CallObject(function, args);

    int res = (int) PyLong_AsLong(result);
    std::cout<<"C++: "<<res<<std::endl;

    Py_DECREF(module);
    Py_DECREF(function);
    Py_DECREF(args);
    Py_DECREF(result);

    Py_Finalize();
}