


#include <iostream>
#include <string>
#include <map>
#include <string>
#include <queue>
#include <Windows.h>

using namespace std;

struct Node
{
	char c;
	int freq;
	Node* left, * right;
};


Node* newNode(char c, int freq, Node* left, Node* right)
{
	Node* node = new Node();
	node->c = c;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

struct compare
{
	bool operator()(Node* node1, Node* node2)
	{
		if(node1->freq != node2->freq){
			return node1->freq > node2->freq;
		}
		return node1->c > node2->c;
	}
};

void encode(Node* root, string str, map<char, string>& huffmanCode)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		huffmanCode[root->c] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}





int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	std::string input="кучерук николай петрович";
	getline(cin, input);
	
	map<char, int> freq;

	for (char c : input) {
		freq[c]++;
	}



	priority_queue<Node*, vector<Node*>, compare> pq;

	for (auto p : freq) {
		pq.push(newNode(p.first, p.second, nullptr, nullptr));
	}

	std::priority_queue<Node*, vector<Node*>, compare > copy = pq;
	std::cout << "Приоритетная очередь:\n";
	while (!copy.empty()) {
		std::cout << " " << copy.top()->c<<" "<<copy.top()->freq<<"\n";
		copy.pop();
	}
	std::cout << std::endl;

	while (pq.size() != 1)
	{
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top();	pq.pop();

		int sum = left->freq + right->freq;
		pq.push(newNode('\0', sum, left, right));
	}

	Node* root = pq.top();

	map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Кодировка Хаффмана:\n";
	for (auto p : huffmanCode) {
		cout << p.first << " " << p.second << '\n';
	}

	cout << "\nВведенная строка :\n" << input << '\n';

	string str = "";
	for (char c : input) {
		str += huffmanCode[c];
	}
	cout << "\nЗакодированная строка: \n" << str << '\n';
}

