#include <vector>
#include <map>
#include "problem4.h"


/* you have a const reference to a vector of Routers, each a struct like above
 these are all broken; we are finding which of them is shallowest, bring the deeper ones to the shallowest one's lvl
 by pointing up through *source, then checking for equality */


const Router* potentiallyBrokenRouter(const std::vector<const Router*>& routersReportingErrors) {
    std::vector<const Router*> tempRoutersVector = routersReportingErrors;
    std::map<long long, int> countermap;
    

    
    while (1) {
        for (auto it = tempRoutersVector.begin(); it < tempRoutersVector.end(); it++) {
            // skip null
            if (*it == NULL) {
                continue;
            }
            
            // incre counter
            if (countermap.find((long long)*it) != countermap.end()) {
                countermap[(long long)*it] += 1;
            }
            else {
                // intialize
                countermap[(long long)*it] = 1;
            }
            
            // return condition
            if (countermap[(long long)*it] == routersReportingErrors.size()){
                return *it;
            }
            
            // traverse back
            *it = (*it)->source;
        }
    }

    
}
 

 
 
 
 

//
/* problem 5 solution... */
