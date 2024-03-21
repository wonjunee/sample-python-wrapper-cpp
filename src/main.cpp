#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/numpy.h>
#include <iostream>
#include <vector>

namespace py = pybind11;

void function1(py::array_t<double, py::array::c_style | py::array::forcecast> out_np){
   
    py::buffer_info out_buf = out_np.request();
    double *out = static_cast<double *>(out_buf.ptr);

    int n1 = out_buf.shape[0];
    int n2 = out_buf.shape[1];

    for(int i=0;i<n2;++i){
        for(int j=1;j<n1;++j){
            out[i*n1+j] = i + j;
        }
    }
}

class HelperClass{
public:
// variatbles
    int n_;
    
    HelperClass(const int n):n_(n) { }
    
    double show(){
        return n_*2;
    }
};

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

PYBIND11_MODULE(example, m) {
    // optional module docstring
    m.doc() = "C++ example code";

    m.def("function1", &function1, "example 1");
    
    py::class_<HelperClass>(m, "HelperClass")
        .def(py::init<int>()) // py::array_t<double, py::array::c_style | py::array::forcecast> phi_np, const double dx, const double dy
        .def("show", &HelperClass::show);
}
