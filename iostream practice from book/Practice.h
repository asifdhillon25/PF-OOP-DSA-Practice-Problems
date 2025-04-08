#pragma once
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <fstream>
using namespace std;
#include <queue>
#include <string>
#include <filesystem>
class Practice
{
public:
	void showing_flags();


	void map()
	{
		std::unordered_map<string, int> mymap;

		ifstream file("input.txt");

		if (!file)
		{
			cerr << "file not open\n";
			return;
		}
		string c;

		while (getline(file,c))
		{
			mymap[c]++;
		}

		ofstream myfile("output.txt");

		if (!myfile)
		{
			cerr << "file not open\n";
			return;
		}
		myfile.clear();
		myfile << "horer you doung\n";
		myfile << "horer you doung\n";
		myfile << "horer you doung\n";

		int i = 0;
		for (auto& x : mymap)
		{
			cout << setw(2) << i << "  " << setw(2) << x.first << "  " << x.second << "\n";
			i++;
		}

		
		cout << "frequency of t =: " << mymap[" "];
	}




	bool isAnagram(const std::string& s1, const std::string& s2) {
		if (s1.length() != s2.length()) {
			return false;
		}

		std::unordered_map<char, int> charCount;

		// Increment counts for characters in the first string
		for (char c : s1) {
			charCount[c]++;
		}

		// Decrement counts for characters in the second string
		for (char c : s2) {
			if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
				// If the character is not in the first string or its count is already zero, not an anagram
				return false;
			}
			else {
				charCount[c]--;
			}
		}

		// Check if all counts are zero
		for (const auto& entry : charCount) {
			if (entry.second != 0) {
				return false;
			}
		}

		// If all counts are zero, the strings are anagrams
		return true;
	}

	/*void filesystem()
	{
		std::filesystem::create_directory("mydire");
	}*/

	queue <int> reversequeue(queue <int> myqueue)
	{

		queue<int> queue1 = myqueue;
		queue<int> queue2;

		for (int i = 0; i < myqueue.size(); i++)
		{
			queue1 = myqueue;

			for (int j = 1; j < myqueue.size() - i; j++)
			{
				if (!queue1.empty())
				{
					queue1.pop();
				}
				
			}

			
			queue2.push(queue1.back());
		}

		if (!queue1.empty())
		{
			queue2.push(queue1.back());
		}

		return queue2;
	}


	void checkQueue()
	{
		queue <int> myqueue;

		for (int i = 0; i < 10; i++)
		{
			myqueue.push(i);
		}


		for (int i = 0; i < 10; i++)
		{
			cout<<myqueue.back()<<" ";
			 myqueue.pop();
		}
		cout << "\n\nAfter reverse \n";
		myqueue=reversequeue(myqueue);
		for (int i = 0; i < 10; i++)
		{
			cout << myqueue.back() << " ";
			myqueue.pop();
		}
	}
};
