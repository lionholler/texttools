#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "[ERROR] missing args. use: justify <limit:int> <text:string>" << endl;
		return -1;
	}
	const int LIMIT = stoi(argv[1]);
	string IN = argv[2];

	cout << endl;

	int p = 0;
	int x = -1;
	int end;
	int start = 0;
	for (int i = 0; i < IN.size(); i++) {
		if (p == LIMIT || IN[i] == '\n' || i == IN.size()-1) {
			if (i == IN.size()-1) {
				end = IN.size();
				++x;
			} else if (IN[i] == '\n') {
				end = i;
				++x;
			}
			while (IN[start] == '\n') {
				cout << endl;
				++start;
			}
			if (x > 0) {
				const int len = end - start;
				const int miss = LIMIT - len;
				const int n = miss / x;
				const int m = miss % x;
				int y = 0;
				for (int j = start; j < end; j++) {
					cout << IN[j];
					if (IN[j] == ' ') {
						for (int k = 0; k < n; k++) {
							cout << ' ';
						}
						if (y < m) {
							cout << ' ';
						}
						++y;
					}
				}
				cout << endl;
			} else {
				for (int j = start; j < end; j++) {
					cout << IN[j];
				}
				cout << endl;
			}
			i = end + 1;
			start = i;
			p = 0;
			x = -1;
		}
		if (IN[i] == ' ') {
			end = i;
			++x;
		}
		if (IN[i] != '\n') {
			++p;
		}
	}
	cout << endl;
} 
