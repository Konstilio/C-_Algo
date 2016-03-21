// WordSearch2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <set>
using namespace std;

class Solution {

private:

	class PreTree {
	public:
		struct Node
		{
			Node* n[26];
			bool bLeaf;

			Node()
			{
				bLeaf = false;
				for (int i = 0; i < 26; ++i)
					n[i] = NULL;
			}

			~Node()
			{
				for (int i = 0; i < 26; ++i)
					delete n[i];
			}
		};

		Node* root;

		PreTree() : root(new Node) {
		}

		~PreTree() { delete root; }

		void insert(string const& word)
		{
			Node* it = root;

			for (size_t i = 0; i < word.size(); ++i)
			{
				int index = word[i] - 'a';
				if (!(it->n[index]))
					(it->n[index]) = new Node();

				it = it->n[index];
			}
			it->bLeaf = true;
		}

	};

public:
	void dfs(vector<vector<char>> &board, PreTree::Node* node, int i, int j, vector<string> &o_res, string& word)
	{
		if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
			return;

		if (board[i][j] == '*')
			return;

		char curr = board[i][j];
		int index = curr - 'a';
		word.push_back(curr);

		if (node->n[index] && node->n[index]->bLeaf)
		{
			o_res.push_back(word);
			node->n[index]->bLeaf = false;
		}
		else if (!node->n[index])
		{
			word.pop_back();
			return;
		}

		board[i][j] = '*';

		dfs(board, node->n[index], i + 1, j, o_res, word);
		dfs(board, node->n[index], i - 1, j, o_res, word);
		dfs(board, node->n[index], i, j + 1, o_res, word);
		dfs(board, node->n[index], i, j - 1, o_res, word);

		board[i][j] = curr;
		word.pop_back();
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> vec;
		if (board.empty() || words.empty())
			return vec;

		set<string> res;

		PreTree tree;
		for (string word : words)
			tree.insert(word);

		int height = board.size();
		int width = board[0].size();
		vector<bool> used;
		used.resize(width * height, false);

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				string temp;
				dfs(board, tree.root, i, j, vec, temp);
			}
		}
		return vec;

	}
};

int main()
{	
	vector<vector<char>> board;
	board.push_back({ 'o','a','a','n' });
	board.push_back({ 'e','t','a','e' });
	board.push_back({ 'i','h','k','r' });
	board.push_back({ 'i','f','l','v' });

	vector<string> words;
	words.push_back("oath");
	words.push_back("pea");
	words.push_back("eat");
	words.push_back("rain");

	Solution s;
	auto res = s.findWords(board, words);

	return 0;
}

