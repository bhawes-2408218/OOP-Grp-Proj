#pragma once
#include <iostream>
#include <string>
#include "Analytics.h"
#include"Metrics.h"

class Analytics {
private:
    Metrics metrics;
    std::vector<std::string> observations;

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
        std::cout << "----- Weekly Hospital Report -----\n";
        std::cout << "Total Appointments: " << metrics.getTotalAppts() << "\n";
        std::cout << "Conflicts: " << metrics.getTotalConflicts() << "\n";
        std::cout << "High Risk Patients: " << metrics.getHighRiskPats() << "\n";
        std::cout << "Avg Response Time: " << metrics.getAvgRespTime() << " mins\n\n";
        std::cout << "Observations:\n";
        for (const auto& o: observations) 
            std::cout << "- " << o << "\n";
    }
};
