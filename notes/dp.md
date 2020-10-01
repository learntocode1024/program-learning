### DP
* **dependencies** between state spaces
    * The current processing state space can depend on others.
      **DO NOT** update a state space until it's confirmed not required anymore!
      
    * mind the right order of loops (which variable comes first?)
    * mind the order of iteration (++ or --?)
    * Always keep the loops of fundamental variables in outer layer.
* proper initialization values
* to solve some problems we cannot use dp.  
e.g. [Luogu1169](../luogu/Luogu1169_dp.cpp)
#### DP on tree