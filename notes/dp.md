### Dynamic Programming

#### Reminders

* **dependencies** between state spaces
  * The current processing state space can depend on others.
    **DO NOT** update a state space until it's confirmed not required anymore!  
  * mind the right order of loops (which variable comes first?)  
  * mind the order of iteration (++ or --?)  
  * Always keep the loops of fundamental variables in outer layer.  
* always remember to ignore **invalid** status  
  * array out-of-range  
  * **logical invalid decision**  
* proper initialization values
* to solve some problems we cannot use dp.  
  e.g. [Luogu1169](../luogu/Luogu1169_dp.cpp)
  
  #### Avoid Superfluous Calculation
  
  ##### When DFS
  
  Caution the **list-liked data**(tree). Such data can cause deep recursion layer,
  and unnecessary / repeated calculation.  
  see [this(Luogu3177)](../luogu/Luogu3177.cpp) line 31:
  
  ```cpp
  // use special method to avoid superfluous calculates.
  dfs(...) {
  do DFS...
  for child of curr {
    ...
    // dp
    memset(temp, 0, sizeof(temp));
    for (int i = size[curr]; i >= 0; --i) {
      for (int j = 0; j <= size[child]; ++j) {
        if (i + j > limit) continue;
        long long val = calculate value with i, j;
        temp[i + j] = max(temp[i + j], dp[curr][i] + dp[child][j] + val);
      }
    }
    for(int j=0;j<=size[curr]+size[child];j++) dp[curr][j] = temp[j];
    size[curr] += size[child];
  }
  }
  ```
  
  Worst O()

rather than

```cpp
// dp
for (int i = min(k, size[curr]); i >= 0; --i) {
  for (int j = 0; j <= min(i, size[child]); ++j) {
    if (dp[curr][i - j] == -1) continue;
    long long val = calculate value with i, j;
    dp[curr][i] = max(dp[curr][i], dp[curr][i - j] + dp[child][j] + val);
  }
}
```

Worst O()  

#### DP on tree

* to avoid search back: use `if (~size[])` rather than `bool vis[]`
  
  #### Monotonic Queue optimize
* use on a scrolling forward range
* when keeping a maximum / minimum value