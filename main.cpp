#include <iostream>
#include <xnnpack.h>
#include <limits>
using namespace std;

void run(){
    xnn_operator_t binary_op = nullptr;
    const float sum_min = -std::numeric_limits<float>::infinity(),
                sum_max = std::numeric_limits<float>::infinity();
    const uint32_t flags = 0;
    xnn_status status = xnn_create_add_nd_f32(sum_min, sum_max, flags, &binary_op);

    size_t* a_shape_ptr = new size_t[1];
    a_shape_ptr[0] = 3;
    size_t* b_shape_ptr = new size_t[1];
    b_shape_ptr[0] = 3;
    float* a_buf = new float[3];
    float* b_buf = new float[3];
        for (size_t i = 0; i < 3; i++)
    {
        a_buf[i] = 0.1f * i;
        b_buf[i] = 0.1f * i;
    }
    float* out_buf = new float[3];
    status =
      xnn_setup_add_nd_f32(binary_op, 1, a_shape_ptr, 1, b_shape_ptr,
               a_buf, b_buf, out_buf, nullptr);
    xnn_run_operator(binary_op, nullptr);
    for(int i = 0; i < 3; i++){
        cout << out_buf[i] << endl;
    }

    delete[] a_shape_ptr;
    delete[] b_shape_ptr;
    delete[] a_buf;
    delete[] b_buf;
    delete[] out_buf;
    
}


int main(int argc, char const *argv[]){
    xnn_initialize(nullptr);
    run();
    cout << "Hello World!" << endl;
    return 0;
}