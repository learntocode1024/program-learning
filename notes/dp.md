# luogu
AC one problem every day!
### Accepted problems
P1015 P1083 P1104 P1169(bug) P1525 P2239 P3379 P4377
P1642
### problems to solve
P1169_dp.cpp
##Notes
###DP
* **dependencies** between state spaces
    * The current processing state space can depend on others.
      **DO NOT** update a state space until it's confirmed not required anymore!
      
    * mind the right order of loops (which variable comes first?)
    * mind the order of iteration (++ or --?)
    * Always keep the loops of fundamental variables in outer layer.
* proper initialization values
* to solve some problems we cannot use dp.  
e.g. [Luogu1169](../luogu/Luogu1169_dp.cpp)
####DP on tree