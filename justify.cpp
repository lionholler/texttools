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
	const string IN = argv[2];

	vector<string> a;
	string t;
	for (int i = 0; i < IN.size(); i++) {
		if (IN[i] == ' ') {
			if (t.size() > LIMIT) {
				cout << "[ERROR] specify a higher limit." << endl;
				return -1;
			}
			a.push_back(t);
			t = "";
			continue;
		}
		t += IN[i];
	}
	a.push_back(t);

	cout << endl;
	int p = 0;
	while (p < a.size()) {
		vector<string> line;
		int count = 0;
		int words = 0;
		while (count + a[p].size() < LIMIT && p < a.size()) {
			line.push_back(a[p]);
			line.push_back(" ");
			count += a[p].size() + 1;
			++p;
			++words;
		}
		count--;
		words--;
		if (words > 0) {
			const int diff = LIMIT - count;
			const int n = diff / words;
			const int m = diff % words;
			int x = 0;
			for (int i = 0; i < line.size() - 1; i++) {
				if (line[i] == " ") {
					for (int j = 0; j < n; j++) {
						line[i] += ' ';
					}
					if (x < m) {
						line[i] += ' ';
					}
					++x;
				}
			}
		}

		for (const auto &i : line) {
			cout << i;
		}
		cout << endl;
	}
} 
