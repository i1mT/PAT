#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<algorithm> 

using namespace std;

struct Book {
	int id;
	string title;
	string author;
	vector<string> keywords;
	string publisher;
	int year;
};


int N, M;
vector<Book> datas;
vector<Book> result;

void queryTitle(string key) {
	for (int i = 0; i < datas.size(); i++) {
		if (key == datas[i].title) {
			result.push_back(datas[i]);
		}
	}
}
void queryAuthor(string key) {
	for (int i = 0; i < datas.size(); i++) {
		if (key == datas[i].author) {
			result.push_back(datas[i]);
		}
	}
}
void queryKeyWords(string key) {
	for (int i = 0; i < datas.size(); i++) {
		for (int j = 0; j < datas[i].keywords.size(); j++) {
			if (key == datas[i].keywords[j]) {
				result.push_back(datas[i]);
			}
		}
		
	}
}
void queryPublisher(string key) {
	for (int i = 0; i < datas.size(); i++) {
		if (key == datas[i].publisher) {
			result.push_back(datas[i]);
		}
	}
}

int str2int(string key) {
	int ratio = 1;
	int sum = 0;
	for (int i = key.size() - 1; i >= 0; i--) {
		sum += (key[i] - '0') * ratio;

		ratio *= 10;
	}

	return sum;
}

void queryYear(string key) {
	int num = str2int(key);
	for (int i = 0; i < datas.size(); i++) {
		if (num == datas[i].year) {
			result.push_back(datas[i]);
		}
	}
}

bool cmp(Book a, Book b) {
	return a.id < b.id;
}

void solve() {
	string words, key;
	vector<string> keys;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		Book tmp;
		vector<string> keys;
		scanf("%d", &tmp.id);

		getline(cin, words); // 缓冲，无其他作用

		getline(cin, tmp.title);
		getline(cin, tmp.author);
		getline(cin, words);
		for (int j = 0; j <= words.size(); j++) {
			if (j == words.size() || words[j] == ' ') {
				keys.push_back(key);
				key = "";
				continue;
			}
			key += words[j];
		}
		tmp.keywords = keys;
		getline(cin, tmp.publisher);
		
		scanf("%d", &tmp.year);

		datas.push_back(tmp);
	}

	sort(datas.begin(), datas.end(), cmp);

	scanf("%d", &M);
	getline(cin, words); // 缓冲，无其他作用
	int op;
	string dist;
	for (int i = 0; i < M; i++) {
		getline(cin, dist);
		op = dist[0] - '0';
		dist = dist.substr(3);
		result.clear();

		switch (op) {
			case 1: 
				queryTitle(dist);
				break;
			case 2:
				queryAuthor(dist);
				break;
			case 3:
				queryKeyWords(dist);
				break;
			case 4:
				queryPublisher(dist);
				break;
			case 5:
				queryYear(dist);
				break;
		}
		printf("%d: ", op);
		cout << dist << endl;
		if (result.size() == 0) {
			printf("Not Found\n");
			continue;
		}
		for (int j = 0; j < result.size(); j++) {
			printf("%07d\n", result[j].id);
		}
	}
}

int main() {
	solve();
	return 0;
}
