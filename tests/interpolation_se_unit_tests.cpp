
#include <gtest/gtest.h>

#include <iostream>

#include "pinocchio/multibody/liegroup/liegroup-base.hpp"
#include "pinocchio/multibody/liegroup/liegroup.hpp"

using namespace pinocchio;

class SpecialEuclideanOperationTplFixture : public virtual ::testing::Test
{
  public:
    typedef double Scalar;

    typedef SE3Tpl<Scalar> SE3;
    typedef SpecialEuclideanOperationTpl<3, Scalar> SE3Operation;
    typedef typename SE3Operation::JacobianMatrix_t JacobianMatrix_t;
    typedef typename SE3Operation::ConstQuaternionMap_t ConstQuaternionMap_t;

    typedef SpecialEuclideanOperationTpl<2, Scalar> SE2Operation;

    void SetUpTwoPoseOnSE3()
    {
        // Starting configuration
        se3_pose_s_.setZero();
        se3_pose_s_(0) = 1.0;
        se3_pose_s_(1) = 1.0;
        se3_pose_s_(2) = 1;
        se3_pose_s_(3) = -0.13795;
        se3_pose_s_(4) = 0.13795;
        se3_pose_s_(5) = 0.69352;
        se3_pose_s_(6) = 0.69352;
        aSE3_.normalize(se3_pose_s_);
        ASSERT_TRUE(aSE3_.isNormalized(se3_pose_s_));

        // Goal configuration
        se3_pose_g_.setZero();
        se3_pose_g_(0) = 4;
        se3_pose_g_(1) = 3;
        se3_pose_g_(2) = 3;
        se3_pose_g_(3) = -0.46194;
        se3_pose_g_(4) = 0.331414;
        se3_pose_g_(5) = 0.800103;
        se3_pose_g_(6) = 0.191342;
        aSE3_.normalize(se3_pose_g_);
        ASSERT_TRUE(aSE3_.isNormalized(se3_pose_g_));
    }

    void SetUpTwoPoseOnSE2()
    {
        // Starting configuration
        se2_pose_s_.setZero();
        se2_pose_s_(0) = 1.0;
        se2_pose_s_(1) = 1.0;
        se2_pose_s_(2) = cos(M_PI / 4.0);
        se2_pose_s_(3) = sin(M_PI / 4.0);
        aSE2_.normalize(se2_pose_s_);

        ASSERT_TRUE(aSE2_.isNormalized(se2_pose_s_));

        // Goal configuration
        se2_pose_g_.setZero();
        se2_pose_g_(0) = 4;
        se2_pose_g_(1) = 3;
        se2_pose_g_(2) = cos(-M_PI / 2.0);
        se2_pose_g_(3) = sin(-M_PI / 2.0);
        aSE2_.normalize(se2_pose_g_);
        ASSERT_TRUE(aSE2_.isNormalized(se2_pose_g_));
    }

  protected:
    SE2Operation aSE2_;
    SE3Operation aSE3_;
    SE3Operation::ConfigVector_t se3_pose_s_;
    SE3Operation::ConfigVector_t se3_pose_g_;

    SE2Operation::ConfigVector_t se2_pose_s_;
    SE2Operation::ConfigVector_t se2_pose_g_;
};

TEST_F(SpecialEuclideanOperationTplFixture, SE3OperationDifferenceAndIntegrateTest)
{
    /// Initial input data
    SetUpTwoPoseOnSE3();

    SE3Operation::TangentVector_t delta_u;

    aSE3_.difference(se3_pose_s_, se3_pose_g_, delta_u);
    std::cout << "delta_u: " << delta_u.transpose() << std::endl;

    SE3Operation::ConfigVector_t pose_check;
    aSE3_.integrate(se3_pose_s_, delta_u, pose_check);
    std::cout << "pose_check: " << pose_check.transpose() << std::endl;
    std::cout << "pose_g: " << se3_pose_g_.transpose() << std::endl;

    EXPECT_TRUE(pose_check.isApprox(se3_pose_g_));
}

TEST_F(SpecialEuclideanOperationTplFixture, SE3OperationInterpolateTest)
{
    /// Initial input data
    SetUpTwoPoseOnSE3();

    std::cout << "ConfigVector_t: " << se3_pose_s_.size() << std::endl;
    SE3Operation::ConfigVector_t pole_u;

    // Interpolate operation
    aSE3_.interpolate(se3_pose_s_, se3_pose_g_, 0.5, pole_u);

    /// Vertify result
    std::cout << "Interpolated configuration-x: " << pole_u.transpose() << std::endl;
}

TEST_F(SpecialEuclideanOperationTplFixture, SE3OperationspecificTests)
{
    SE3Operation::ConfigVector_t q[2];
    q[0] = aSE3_.random();
    q[1] = aSE3_.random();

    ConstQuaternionMap_t quat0(q[0].template tail<4>().data()), quat1(q[1].template tail<4>().data());
    JacobianMatrix_t J[2];

    aSE3_.template dDifference<ArgumentPosition::ARG0>(q[0], q[1], J[0]);
    aSE3_.template dDifference<ArgumentPosition::ARG1>(q[0], q[1], J[1]);

    SE3 om0(typename SE3::Quaternion(q[0].template tail<4>()).matrix(), q[0].template head<3>());
    SE3 om1(typename SE3::Quaternion(q[1].template tail<4>()).matrix(), q[1].template head<3>());
    SE3 _1m2(om1.actInv(om0));

    EXPECT_TRUE((J[1] * _1m2.toActionMatrix()).isApprox(-J[0], 1e-8));

    // Test against SE3::Interpolate
    const Scalar u = 0.3;
    SE3Operation::ConfigVector_t q_interp = aSE3_.interpolate(q[0], q[1], u);
    ConstQuaternionMap_t quat_interp(q_interp.template tail<4>().data());
    SE3 M0(quat0, q[0].template head<3>());
    SE3 M1(quat1, q[1].template head<3>());
    SE3 M_u = SE3::Interpolate(M0, M1, u);
    SE3 M_interp(quat_interp, q_interp.template head<3>());

    EXPECT_TRUE(M_u.isApprox(M_interp));
}

TEST_F(SpecialEuclideanOperationTplFixture, SE2OperationDifferenceAndIntegrateTest)
{
    /// Initial input data
    SetUpTwoPoseOnSE2();

    /// Computes the differences (expressed in the tangent space of the configuration space) between the starting and
    /// the goal configuration
    SE2Operation::TangentVector_t delta_u;
    aSE2_.difference(se2_pose_s_, se2_pose_g_, delta_u);
    std::cout << "difference: " << delta_u.transpose() << std::endl;

    //. Check that the composition of the starting configuration and the difference vector gives the goal configuration
    SE2Operation::ConfigVector_t pose_check;
    aSE2_.integrate(se2_pose_s_, delta_u, pose_check);
    std::cout << "goal configuration (from composition): " << pose_check.transpose() << std::endl;
    std::cout << "goal configuration: " << se2_pose_g_.transpose() << std::endl;

    EXPECT_TRUE(se2_pose_g_.isApprox(pose_check));
}

TEST_F(SpecialEuclideanOperationTplFixture, SE2OperationInterpolationBoundaryTest)
{
    /// Initial input data
    SetUpTwoPoseOnSE2();

    SE2Operation::ConfigVector_t q_interpolate = aSE2_.interpolate(se2_pose_s_, se2_pose_g_, 0.);

    EXPECT_TRUE(q_interpolate.isApprox(se2_pose_s_));

    q_interpolate = aSE2_.interpolate(se2_pose_s_, se2_pose_g_, 1.);

    EXPECT_TRUE(q_interpolate.isApprox(se2_pose_g_));
}

TEST_F(SpecialEuclideanOperationTplFixture, SE2OperationInterpolateTest)
{
    /// Initial input data
    SetUpTwoPoseOnSE2();

    std::cout << "ConfigVector_t on SE2 size: " << se2_pose_g_.size() << std::endl;

    SE2Operation::ConfigVector_t pole_u;
    aSE2_.interpolate(se2_pose_s_, se2_pose_g_, 0.5, pole_u);
    std::cout << "Interpolated configuration-x: " << pole_u.transpose() << std::endl;
}
