#pragma once
#include <iostream>
#include <string>
#include "Metrics.h"

class Metrics {
private:
    int totalAppts;
    int totalConflicts;
    int highRiskPats;
    float avgRespTime; 

		/*--------Constructors--------*/
public:
    Metrics() : totalAppts(0), totalConflicts(0), highRiskPats(0), avgRespTime(0.0f) {}
	
/*--------Collecting patient's data--------*/

    void collectData(int appts, int conflicts, int highRisk, float respTime) {
        totalAppts += appts;
        totalConflicts += conflicts;
        highRiskPats += highRisk;
        avgRespTime = respTime;
    }

    void updateMetrics(int apptDelta, bool conflict, bool highRisk) {
        totalAppts += apptDelta;
        if (conflict) totalConflicts++;
        if (highRisk) highRiskPats++;
    }
		/*--------Getter Functions--------*/

    int getTotalAppts() const { return totalAppts; }
    int getTotalConflicts() const { return totalConflicts; }
    int getHighRiskPats() const { return highRiskPats; }
    float getAvgRespTime() const { return avgRespTime; }
};
