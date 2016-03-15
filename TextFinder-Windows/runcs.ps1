cd Debug
echo  "  ------------------------------"
echo  "  - Project 1 of DO            -"
echo  "  - 6 test cases in total      -"
echo  "  ------------------------------"
echo  "  case 1:"
echo  "  **************************************************"
echo  "  search <distributed> in testcases file folder"
echo  "  **************************************************"
./csClient.exe search ../testcases distributed 
pause

echo  "  case 2:"
echo  "  **************************************************"
echo  "  search <objects> in testcases file folder"
echo  "  **************************************************"
./csClient.exe search ../testcases objects
pause

echo  "  case 3:"
echo  "  ************************************************************"
echo  "  search <distributed> and <objects> in testcases file folder"
echo  "  result files only contain any these two keywords"
echo  "  ************************************************************"
./csClient.exe search ../testcases distributed objects /O
pause

echo  "  case 4:"
echo  "  ************************************************************"
echo  "  search <distributed> and <objects> in testcases file folder"
echo  "  result files must contain all these two keywords"
echo  "  ************************************************************"
./csClient.exe search ../testcases distributed objects
pause

echo  "  case 5:"
echo  "  ************************************************************"
echo  "  search <iostream> and <text> in upper directory"
echo  "  result files only contain any these two keywords"
echo  "  ************************************************************"
./csClient.exe search ../ iostream text /O
pause

echo  "case 6:"
echo  "************************************************************"
echo  "search <iostream> and <text> in testcases file folder"
echo  "result files must contain all these two keywords"
echo  "************************************************************"
./csClient.exe search ../ iostream text

cd ../
pause