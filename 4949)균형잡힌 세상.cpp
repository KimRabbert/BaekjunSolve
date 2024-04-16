#include <iostream>
#include <stack>
using namespace std;

int main() {
	char a = '\0', b = '\0';
	stack <char> st;
	bool is_balanced;

	while (true) {
		while (!st.empty())
			st.pop();

		is_balanced = true;
		cin >> a;
		if (cin.eof())
			break;

		while (a != '.') {
			if (a == '(' || a == '[') {
				st.push(a);
			}
			else if (a == ')') {
				if (b == ' ') {
					if (!st.empty() && st.top() == ' ') {
						st.pop();
						if (!st.empty() && st.top() == '(') {
							st.pop();
						}
						else {
							is_balanced = false;
							break;
						}
					}
				}
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					is_balanced = false;
					break;
				}
			}
			else if (a == ']') {
				if (b == ' ') {
					if (!st.empty() && st.top() == ' ') {
						st.pop();
						if (!st.empty() && st.top() == '[') {
							st.pop();
						}
						else {
							is_balanced = false;
							break;
						}
					}
				}
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					is_balanced = false;
					break;
				}
			}
			else if (a == ' ') {
				if (b == '[' || b == '(')
					st.push(' ');
			}

			b = a;
			cin >> a;

		}

		if (is_balanced) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	b = '\0';
}