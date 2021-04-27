# Pandora
A bazel workspace for pinocchio  
https://github.com/stack-of-tasks/pinocchio

## Environment 

### Ubuntu 20 Focal + Vscode + Bazel 4.0.0 + GCC9

#### bazel install 
https://docs.bazel.build/versions/master/install-ubuntu.html

#### Optional
> sudo apt install clang-format-11


## Examples

> bazel run //examples:interpolation-SE3

> ...

> bazel test //tests:all --test_output=all

## LCoV for code analysis

> sudo apt install lcov

then....
> ./coverage/coverage_analysis.sh 

![lcov_report](https://user-images.githubusercontent.com/19366407/116270834-07b12800-a7b2-11eb-8e0d-9d2e382c02a9.png)
