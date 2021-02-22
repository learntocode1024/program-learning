### Segment Tree

#### Code Template

```cpp
int sum[MXx4]{}, tag[MXx4]{};

void push_down(const unsigned curr, const int l, const int r) {
  if (tag[curr] == 0 || r - l == 1) {
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  sum[left] += tag[curr] * (mid - l);
  sum[right] += tag[curr] * (r - mid);
  tag[left] += tag[curr], tag[right] += tag[curr]; // MIND THIS!!!
  tag[curr] = 0;
}

void add(const int val, const unsigned curr,
         const int beg, const int end,
         const int l, const int r) {
  if (beg == l && end == r) {
    sum[curr] += val * (r - l);
    tag[curr] += val;
    return;
  }
  push_down(curr, l, r);
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  if (beg < mid) add(val, left, beg, min(end, mid), l, mid);
  if (end > mid) add(val, right, max(beg, mid), end, mid, r);
  sum[curr] = sum[left] + sum[right];
}

int query(const unsigned curr,
         const int beg, const int end,
         const int l, const int r) {
  if (beg == l && end == r) {
    return sum[curr];
  }
  push_down(curr, l, r);
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  int ans = 0;
  if (beg < mid) ans += query(left, beg, min(end, mid), l, mid);
  if (end > mid) ans += query(right, max(beg, mid), end, mid, r);
  return ans;
}

void build(const unsigned curr, int* const ptr,
           const int l, const int r) {
  if (r - l == 1) {
    sum[curr] = ptr[l];
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  build(left, ptr, l, mid);
  build(right, ptr, mid, r);
  sum[curr] = sum[left] + sum[right];
}
```

#### Reminders

* in function ```push_down()```:  line 10:  
  when dealing with tags: accumulate the previous tags with the current one, rather than overwrite them.  
  examples:  
  use ```tag[left] += tag[curr]```  rather than ```tag[left] = tag[curr]```
