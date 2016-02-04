#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(){
	int numOfTests = 0;
	int n = 0, noOfIntInSeq = 0;
	int chkPos = 1;
	int tmpMaxCorrect = 0, maxCorrect = 0, tmpNoRot = 0, numberRotMaxCorrect = 0;
	std::string intString;
	std::stringstream ss;
	std::vector<int> intSeq;
	std::vector< std::vector<int> > solutions;

	std::cin >> numOfTests;

	if (numOfTests > 1000 || numOfTests < 0){
		std::cout << "Error: Number of tests have to be from 0 to 1000.\n";
		return 0;
	}
	else{
		for (int i = 0; i < numOfTests; i++){
			//reset
			noOfIntInSeq = 0;
			ss.clear();
			intSeq.clear();

			//get n and n integers
			std::cin >> n;
			std::cin.clear();
			std::getline(std::cin, intString);
			if (n > 100 || n < 0){
				std::cout << "Error: Number of integers have to be from 0 to 100.\n";
				return 0;
			}

			std::getline(std::cin, intString);
			//tokenize and store
			ss << intString;
			while (!ss.eof()){
				ss >> tmpNoRot;
				intSeq.push_back(tmpNoRot);
				noOfIntInSeq++;
			}

			if (noOfIntInSeq == n){
				tmpNoRot = 0;
				numberRotMaxCorrect = 0;
				maxCorrect = 0;

				do{
					if (tmpNoRot == n){
						//perform final rotation to answer...
						rotate(intSeq.begin(), intSeq.begin() + numberRotMaxCorrect, intSeq.end());
						solutions.push_back(intSeq);
					}
					else{
						chkPos = 1;
						tmpMaxCorrect = 0;
						//check number of items in correct position..
						for (int i = 0; i<n; i++){
							if (intSeq[i] == chkPos) tmpMaxCorrect++;
							chkPos++;
						}
						//update highest correct positions
						if (tmpMaxCorrect == n || tmpMaxCorrect > maxCorrect){
							maxCorrect = tmpMaxCorrect;
							numberRotMaxCorrect = tmpNoRot;
						}
						//rotate left once.
						rotate(intSeq.begin(), intSeq.begin() + 1, intSeq.end());
					}
					tmpNoRot++;
				} while (tmpNoRot <= n);
			}
			else{
				std::cout << "Error in one of the input values. More/Less than n integers detected.\n";
				return 0;
			}
		}
	}
	//print all solutions.
	std::cout << "\nOutput:\n";
	for (int i = 0; i < solutions.size(); i++){
		for (int j = 0; j < solutions[i].size(); j++){
			std::cout << solutions[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}