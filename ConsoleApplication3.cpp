#include <iostream>
#include <deque>
using namespace std;

int main() {

	int N, M;
	cin >> N >> M;
	deque<int> dq;

	int arr[50];
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	int idx = 0;
	int sum = 0;

	while (idx < M) {
		deque<int> temp;
		int left = 0;
		int right = 0;

		while (1) {
			if (dq.front() == arr[idx]) break;
			temp.push_back(dq.front());
			dq.pop_front();
			left++;
		}
		while (temp.size() != 0) {
			dq.push_front(temp.back());
			temp.pop_back();
		}

		while (1) {
			if (temp.size() != 0 && temp.front() == arr[idx]) break;
			int back = dq.back();
			dq.pop_back();
			right++;

			temp.push_front(back);
		}

		while (temp.size() != 0) {
			dq.push_back(temp.front());
			temp.pop_front();
		}

		if (left < right) {
			sum += left;

			while (left--) {
				int temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
			}
			dq.pop_front();
		}
		else {
			sum += right;
			while (right--) {
				int temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
			}
			dq.pop_front();
		}

		idx++;
	}

	cout << sum << endl;
	return 0;
}