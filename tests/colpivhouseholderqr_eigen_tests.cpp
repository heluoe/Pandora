
#include <gtest/gtest.h>

#include <iostream>

#include "third_party/eigen/Eigen/Dense"

namespace
{
const std::int32_t kEigenMatrixMaximumNumberOfCols = 10;
const std::int32_t kEigenMatrixMaxNumberOfRows = 80;
const std::int32_t kEigenDynamic = -1;
enum class EigenAlignOption : std::int32_t
{
    kEigenColMajor = 0,
    kEigenRowMajor = 0x1,
    kEigenAutoAlign = 0,
    kEigenDontAlign = 0x2
};

class SpecialEuclideanOperationTplFixture : public virtual ::testing::Test
{
  public:
    using DefMatrixA = Eigen::Matrix<float,
                                     kEigenDynamic,
                                     kEigenDynamic,
                                     static_cast<int>(EigenAlignOption::kEigenAutoAlign),
                                     kEigenMatrixMaxNumberOfRows,
                                     kEigenMatrixMaximumNumberOfCols>;
    using DefVectorb = Eigen::Matrix<float,
                                     kEigenDynamic,
                                     kEigenDynamic,
                                     static_cast<int>(EigenAlignOption::kEigenAutoAlign),
                                     kEigenMatrixMaxNumberOfRows,
                                     1U>;
    using DefVectorx = Eigen::Matrix<float,
                                     kEigenDynamic,
                                     kEigenDynamic,
                                     static_cast<int>(EigenAlignOption::kEigenAutoAlign),
                                     kEigenMatrixMaximumNumberOfCols,
                                     1U>;
    bool InitializeSolver(const std::int32_t number_of_rows, const std::int32_t number_of_cols)
    {
        bool ret = false;
        if (number_of_rows <= kEigenMatrixMaxNumberOfRows && number_of_cols <= kEigenMatrixMaximumNumberOfCols)
        {
            matrix_a_.resize(number_of_rows, number_of_cols);
            vector_b_.resize(number_of_rows, 1);
            vector_x_.resize(number_of_cols, 1);

            matrix_a_.setZero();
            vector_b_.setZero();

            matrix_a_.block(0, 0, number_of_rows, number_of_cols).setRandom();
            vector_b_.block(0, 0, number_of_rows, 1).setRandom();

            vector_x_.setZero();

            number_of_rows_ = number_of_rows;
            number_of_cols_ = number_of_cols;

            ret = true;
        }
        return ret;
    }

  protected:
    DefMatrixA matrix_a_;
    DefVectorb vector_b_;
    DefVectorx vector_x_;

    std::int32_t number_of_rows_;
    std::int32_t number_of_cols_;
};

TEST_F(SpecialEuclideanOperationTplFixture, CaculateXTest)
{
    const std::int32_t kNumOfRows = 10;
    const std::int32_t kNumOfCols = 6;

    EXPECT_TRUE(InitializeSolver(kNumOfRows, kNumOfCols));

    Eigen::ColPivHouseholderQR<DefMatrixA> qr(matrix_a_.block(0, 0, kNumOfRows, kNumOfCols));
    std::cout << qr.matrixQR() << std::endl;
}

}  // namespace
