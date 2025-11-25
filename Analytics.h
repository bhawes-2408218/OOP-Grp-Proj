#pragma once
#include <iostream>
#include <string>
#include "Analytics.h"
#include"Metrics.h"
using namespace std;

class Analytics {
private:
    Metrics metrics;
    vector<string> observations;

public:
    Analytics() = default;

    void setMetrics(const Metrics& m) {
        metrics = m;
    }

    void trackHospitalPerformance() {
        observations.clear();
        if (metrics.getHighRiskPats() > 10)
            observations.push_back("High number of critical patients this week.");
        if (metrics.getTotalConflicts() > 5)
            observations.push_back("Appointment scheduling conflicts above normal.");
        if (metrics.getAvgRespTime() > 60.0f)
            observations.push_back("Average response time is high.");
    }

    void generateWeeklyReport() {
        trackHospitalPerformance();
        cout << "----- Weekly Hospital Report -----\n";
        cout << "Total Appointments: " << metrics.getTotalAppts() << "\n";
        cout << "Conflicts: " << metrics.getTotalConflicts() << "\n";
        cout << "High Risk Patients: " << metrics.getHighRiskPats() << "\n";
        cout << "Avg Response Time: " << metrics.getAvgRespTime() << " mins\n\n";
        cout << "Observations:\n";
        for (const auto& o: observations) 
            cout << "- " << o << "\n";
    }
};
