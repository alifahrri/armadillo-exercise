#include <Eigen/Dense>
#include <unsupported/Eigen/AutoDiff>

#include <type_traits>
#include <iostream>

namespace traits {
    template <typename T, typename = void>
    struct has_scalar_member_type : std::false_type {};

    template <typename T>
    struct has_scalar_member_type<T, 
        std::void_t<decltype(std::declval<typename T::Scalar>())> 
    > : std::true_type {};

    template <typename T, typename = void>
    struct has_value_type_member_type : std::false_type {};

    template <typename T>
    struct has_value_type_member_type<T, 
        std::void_t<decltype(std::declval<typename T::ValueType>())> 
    > : std::true_type {};

    template <typename T, typename = void>
    struct has_input_type_member_type : std::false_type {};

    template <typename T>
    struct has_input_type_member_type<T, 
        std::void_t<decltype(std::declval<typename T::InputType>())> 
    > : std::true_type {};
} // namespace traits

template <typename DataType, typename InputDataType>
struct Function {
    static_assert(traits::has_scalar_member_type<DataType>::value, 
        "DataType needs to have `Scalar` member type!!"
    );
    using ValueType = DataType;
    using InputType = InputDataType;
    using Scalar = typename ValueType::Scalar;

    Function(const Scalar gain) : gain(gain) {}
    Function(const Function &f) : gain(f.gain) {}

    const Scalar gain;

    template <typename input_type, typename output_type>
    void operator()(const input_type &input, output_type *output, const Scalar dt) const 
    {
        output_type &o = *output;

        /* integrator using AD */
        o[0] = input[0] + input[1] * dt * this->gain;
        o[1] = input[1] * this->gain;
    }

    /* testing */
    template <typename input_type, typename output_type, typename jacobian_type>
    void operator()(const input_type &input, output_type *output, jacobian_type *jacobian, const Scalar dt) const 
    {
        output_type &o = *output;

        o[0] = input[0] + input[1] * dt * this->gain;
        o[1] = input[1] * this->gain;

        if (jacobian) {
            jacobian_type &j = *jacobian;
            j(0,0) = 1;
            j(0,1) = dt * this->gain;
            j(1,0) = 0;
            j(1,1) = this->gain;
        }
    }
}; // struct Function

template <typename F>
void forward_jacobian(const F &f)
{
    static_assert(traits::has_input_type_member_type<F>::value);
    static_assert(traits::has_value_type_member_type<F>::value);
    using InputType = typename F::InputType;
    using ValueType = typename F::ValueType;
    using JacobianType = typename Eigen::AutoDiffJacobian<F>::JacobianType;
    
    InputType x = InputType::Random(InputType::RowsAtCompileTime);
    ValueType y, yref;
    JacobianType j, jref;

    const typename F::Scalar dt = 0.5;

    jref.setZero();
    yref.setZero();
    f(x, &yref, &jref, dt);

    Eigen::AutoDiffJacobian<F> autoj(f);
    autoj(x, &y, &j, dt);

    std::cout << "yref : " << yref << std::endl;
    std::cout << "jref : " << jref << std::endl;

    std::cout << "y : " << y << std::endl;
    std::cout << "j : " << j << std::endl;
}

int main(int argc, char** argv)
{
    using Vec = Eigen::Matrix<double,2,1>;
    using Func = Function<Vec,Vec>;

    forward_jacobian(Func(10.));
}