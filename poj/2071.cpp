#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Bid;
struct Item {
  int id;
  int min_price;
  int end_time;
  Bid *bid;
  Item(int i, int m, int e) : id(i), min_price(m), end_time(e), bid(NULL) {}

  static bool cmp(const Item *rhs, const Item *lhs) {
    return rhs->end_time < lhs->end_time;
  }
};

struct Bidder {
  int id;
  int amount;
  Bidder(int i, int a) : id(i), amount(a) {}
};

struct Bid {
  int item_id;
  int bidder_id;
  int amount;
  int bid_time;
  Bid *prev;
  Bid(int i, int b, int a, int t)
      : item_id(i), bidder_id(b), amount(a), bid_time(t), prev(NULL) {}

  static bool cmp(const Bid *rhs, const Bid *lhs) {
    return rhs->bid_time < lhs->bid_time;
  }
};

vector<Item*> items;
map<int, Item*> map_items;
map<int, Bidder*> map_bidders;
vector<Bid*> bids;

int main(void) {
  int I;
  scanf("%d", &I);
  for (int i = 0; i < I; i++) {
    int item_id, price1, price2, hour, min, sec;
    scanf("%d%d.%d%d:%d:%d", &item_id, &price1, &price2, &hour, &min, &sec);
    Item *item = new Item(item_id, price1*100+price2, (hour*60+min)*60+sec);
    map_items[item_id] = item;
    items.push_back(item);
  }

  scanf("%d", &I);
  for (int i = 0; i < I; i++) {
    int bidder_id, price1, price2;
    scanf("%d%d.%d", &bidder_id, &price1, &price2);
    map_bidders[bidder_id] = new Bidder(bidder_id, price1*100+price2);
  }

  scanf("%d", &I);
  for (int i = 0; i < I; i++) {
    int item_id, bidder_id, price1, price2, hour, min, sec;
    scanf("%d%d%d.%d%d:%d:%d", &item_id, &bidder_id, &price1, &price2,
          &hour, &min, &sec);
    bids.push_back(new Bid(item_id, bidder_id, price1*100+price2,
                           (hour*60+min)*60+sec));
  }

  sort(bids.begin(), bids.end(), &Bid::cmp);
  for (unsigned int i = 0; i < bids.size(); i++) {
    Bid &bid = *bids[i];
    Item &item = *map_items[bid.item_id];
    if (bid.bid_time > item.end_time) continue;
    if (bid.amount < item.min_price) continue;
    if (item.bid != NULL && item.bid->amount >= bid.amount) {
      Bid *pbid = item.bid;
      while (pbid->prev != NULL) {
        if (pbid->prev->amount < bid.amount) break;
        pbid = pbid->prev;
      }
      bid.prev = pbid->prev;
      pbid->prev = &bid;
    } else {
      bid.prev = item.bid;
      item.bid = &bid;
    }
  }

  sort(items.begin(), items.end(), &Item::cmp);
  for (unsigned int i = 0; i < items.size(); i++) {
    Item &item = *items[i];
    Bid *pbid = item.bid;
    while (pbid != NULL) {
      if (pbid->amount <= map_bidders[pbid->bidder_id]->amount) {
        map_bidders[pbid->bidder_id]->amount -= pbid->amount;
        printf("Item %d Bidder %d Price %d.%02d\n", item.id, pbid->bidder_id,
               pbid->amount / 100, pbid->amount % 100);
        break;
      }
      pbid = pbid->prev;
    }
    if (pbid == NULL) {
      printf("Item %d Reserve not met.\n", item.id);
    }
  }
  return 0;
}
