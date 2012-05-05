#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

struct file {
  string name;
};

struct directory {
  string name;
  directory *parent;
  vector <directory*> subdirs;
  vector <file*> files;

  directory() : parent(NULL) {}

  void delete_all(void) {
    for (int i = 0; i < files.size(); i++) {
      delete files[i];
    }

    for (int i = 0; i < subdirs.size(); i++) {
      subdirs[i]->delete_all();
    }

    delete this;
  }
};

directory *root_dir;

void make_path(directory *pdir, string s) {
  size_t slash_pos = s.find('/', 1);
  if (slash_pos == string::npos) {

    file *new_file = new file();
    new_file->name = s.substr(1);
    pdir->files.push_back(new_file);

  } else {

    string dir_name = s.substr(0, slash_pos).substr(1);
    string rest = s.substr(slash_pos);
    directory *new_dir = NULL;

    for (int i = 0; i < pdir->subdirs.size(); i++) {
      if (pdir->subdirs[i]->name == dir_name) {
        new_dir = pdir->subdirs[i];
        break;
      }
    }

    if (new_dir == NULL) {
      new_dir = new directory();
      new_dir->name = dir_name;
      new_dir->parent = pdir;
      pdir->subdirs.push_back(new_dir);
    }

    make_path(new_dir, rest);
  }
}

file *query(directory *pdir, string s) {
  if (pdir == NULL) return NULL;
  size_t slash_pos = s.find('/', 1);

  if (slash_pos == string::npos) {
    string file_name = s.substr(1);
    if (file_name.size() == 0 || file_name == ".") {
      for (int i = 0; i < pdir->files.size(); i++) {
        if (pdir->files[i]->name == "index.html") {
          return pdir->files[i];
        }
      }
    } else if (file_name == "..") {
      return query(pdir->parent, "/");
    } else {
      for (int i = 0; i < pdir->files.size(); i++) {
        if (pdir->files[i]->name == file_name) {
          return pdir->files[i];
        }
      }

      for (int i = 0; i < pdir->subdirs.size(); i++) {
        if (pdir->subdirs[i]->name == file_name) {
          directory *dir = pdir->subdirs[i];
          for (int k = 0; k < dir->files.size(); k++) {
            if (dir->files[k]->name == "index.html") {
              return dir->files[k];
            }
          }
        }
      }
    }
  } else {
    string dir_name = s.substr(0, slash_pos).substr(1);
    string rest = s.substr(slash_pos);
    if (dir_name == ".") {
      return query(pdir, rest);
    } else if (dir_name == "..") {
      return query(pdir->parent, rest);
    } else {
      for (int i = 0; i < pdir->subdirs.size(); i++) {
        if (pdir->subdirs[i]->name == dir_name) {
          return query(pdir->subdirs[i], rest);
        }
      }
    }
  }
  return NULL;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    root_dir = new directory();
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      make_path(root_dir, s);
    }

    for (int i = 0; i < m; i++) {
      string s, t;
      cin >> s >> t;
      file *fs = query(root_dir, s);
      file *ft = query(root_dir, t);

      if (fs == NULL) {
        cout << "not found" << endl;
      } else if (ft == NULL) {
        cout << "not found" << endl;
      } else if (fs == ft) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }

    root_dir->delete_all();
  }
  return 0;
}
