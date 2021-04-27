#!/bin/bash -x

# sudo apt install lcov

TEST_PATH="tests"
PRJ_NAME="unit_test_se" #unit_test_qr
TARGET_DIR=$(bazel info output_path)


TARGET_FILE=${TARGET_DIR}/k8-fastbuild/testlogs/${TEST_PATH}/${PRJ_NAME}/coverage.dat
if [[ -f "$TARGET_FILE" ]]; then
    rm -f  ${TARGET_FILE}
fi

bazel coverage -s \
--experimental_cc_coverage \
--instrument_test_targets \
--build_tests_only \
--compilation_mode="fastbuild" \
--combined_report=lcov \
--coverage_report_generator=@bazel_tools//tools/test/CoverageOutputGenerator/java/com/google/devtools/coverageoutputgenerator:Main \
--test_output=all \
--verbose_failures \
--build_runfile_links \
--cache_test_results=false  \
--javabase=@bazel_tools//tools/jdk:remote_jdk11 \
--coverage_support=@bazel_tools//tools/test:coverage_support  \
--collect_code_coverage \
--instrumentation_filter=[:] \
--test_output=summary \
--test_env=LCOV_BINARY=/usr/bin/lcov \
//${TEST_PATH}:${PRJ_NAME}



genhtml --branch-coverage ${TARGET_FILE} --output-directory ~/Document/cpp-otp 

xdg-open ~/Document/cpp-otp/index.html &