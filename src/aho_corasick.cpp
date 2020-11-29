#include "matching.hpp"

#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <string>
#include <queue>

class aho_corasick : public matching {
public:
  aho_corasick(std::string path, std::vector<std::string> keywords);
  void build_goto(std::vector<std::string> keywords);
  void build_fail();

private:
  std::map<int, std::unordered_map<unsigned char, int> > PMM;
  int* failure;
  std::unordered_map<int, std::set<std::string> > output;
  int closest_ancestor(int s, unsigned char c);
};

aho_corasick::aho_corasick(std::string path, std::vector<std::string> keywords) {
  build_goto(keywords);
  build_fail();

	txt.open(path);
	std::string line;
	int cur;
	bool mark;

	while (std::getline(txt, line)) {
		mark = 0;
    cur = 0;
		for (unsigned char c : line) {
			while (!PMM[cur][c] && cur != -1) {
        cur = failure[cur];
      }
      if (cur == -1) cur = 0;
      else {
    		cur = PMM[cur][c];
    		if (!output[cur].empty()) {
    			if (!mark) {
    				lines.push_back(line);
    				mark = 1;
    			}
    			occ += output[cur].size();
    		}
      }
		}
	}

  delete[] failure;
	txt.close();
}

void aho_corasick::build_goto(std::vector<std::string> keywords) {
  int cur, i = 0;
  for (std::string kwd : keywords) {
    cur = 0;
    for (unsigned char c : kwd) {
      if (!PMM[cur][c]) {
        PMM[cur][c] = ++i;
        cur = i;
      } else {
        cur = PMM[cur][c];
      }
    }
    output[cur].insert(kwd);
	}
  failure = new int[i+1]();
  failure[0] = -1;
}

void aho_corasick::build_fail() {
  std::queue<int> q;
  for (auto t : PMM[0]) {
    q.push(t.second);
  }
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (auto t : PMM[s]) {
      int f = closest_ancestor(s, t.first);
      failure[t.second] = f;
      for (std::string kwd : output[f]) {
        output[t.second].insert(kwd);
      }
      q.push(t.second);
    }
  }
}

int aho_corasick::closest_ancestor(int s, unsigned char c) {
  int temp = failure[s];
  while (temp != -1) {
    for (auto t : PMM[temp]) {
      if (t.first == c) return t.second;
    }
    s = temp;
    temp = failure[temp];
  }
  return s;
}
