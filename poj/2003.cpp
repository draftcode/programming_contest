#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <list>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)


struct Person {
  string name;
  Person *boss;
  list<Person*> subordinates;

  Person(string n) : name(n), boss(NULL) { }
};
Person *CEO;
map<string, Person*> m;

void print(Person *p, int n) {
  rep (i, n) cout << '+';
  cout << p->name << endl;
  each (it, p->subordinates) {
    print(*it, n+1);
  }
}

void fire(Person *p) {
  if (p->subordinates.empty()) {
    p->boss->subordinates.erase(find(p->boss->subordinates.begin(), p->boss->subordinates.end(), p));
    delete p;
  } else {
    p->name = p->subordinates.front()->name;
    m[p->name] = p;
    if (p->subordinates.front()->subordinates.empty()) {
      p->subordinates.pop_front();
    } else {
      fire(p->subordinates.front());
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  string first, second, third;
  cin >> first;
  CEO = new Person(first);
  m[first] = CEO;
  while (cin >> first) {
    if (first == "print") {
      print(CEO, 0);
      cout << "------------------------------------------------------------" << endl;
    } else if (first == "fire") {
      cin >> second;
      fire(m[second]);
    } else {
      cin >> second >> third;
      Person *p = m[third] = new Person(third);
      p->boss = m[first];
      p->boss->subordinates.push_back(p);
    }
  }
  return 0;
}
