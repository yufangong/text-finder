echo  "  ------------------------------"
echo  "  - Project 1 of DO            -"
echo  "  - 6 test cases in total      -"
echo  "  ------------------------------"
cd cppClient
echo  "  case 1:"
echo  "  **************************************************"
echo  "  search <distributed> in testcases file folder"
echo  "  **************************************************"
./dist/Debug/GNU-Linux-x86/cppclient search ../testcases distributed 
read -p "Press Enter to continue." key

echo  "  case 2:"
echo  "  **************************************************"
echo  "  search <objects> in testcases file folder"
echo  "  **************************************************"
./dist/Debug/GNU-Linux-x86/cppclient search ../testcases objects
read -p "Press Enter to continue." key

echo  "  case 3:"
echo  "  ************************************************************"
echo  "  search <distributed> and <objects> in testcases file folder"
echo  "  result files only contain any these two keywords"
echo  "  ************************************************************"
./dist/Debug/GNU-Linux-x86/cppclient search ../testcases distributed objects /O
read -p "Press Enter to continue." key

echo  "  case 4:"
echo  "  ************************************************************"
echo  "  search <distributed> and <objects> in testcases file folder"
echo  "  result files must contain all these two keywords"
echo  "  ************************************************************"
./dist/Debug/GNU-Linux-x86/cppclient search ../testcases distributed objects
read -p "Press Enter to continue." key

echo  "  case 5:"
echo  "  ************************************************************"
echo  "  search <iostream> and <text> in upper directory"
echo  "  result files only contain any these two keywords"
echo  "  ************************************************************"
./dist/Debug/GNU-Linux-x86/cppclient search ../ iostream text /O
read -p "Press Enter to continue." key

echo  "case 6:"
echo  "************************************************************"
echo  "search <iostream> and <text> in testcases file folder"
echo  "result files must contain all these two keywords"
echo  "************************************************************"
./dist/Debug/GNU-Linux-x86/cppclient search ../ iostream text

cd ../
read -p "Press Enter to continue." key