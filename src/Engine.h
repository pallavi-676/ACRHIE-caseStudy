#ifndef ENGINE_H
#define ENGINE_H

#include "models.h"
#include "DataStructures.h"
#include "Algorithms.h"
#include <vector>

class HistoricalIntelligenceEngine {
private:
    ArtifactHashTable artifactHash;
    ClassificationStack classificationUndoStack;
    ReportQueue reportQueue;
    ArtifactBST artifactTree;
    CivilizationGraph tradeNetwork;
    vector<Artifact> allArtifacts; // For sorting and searching

public:
    HistoricalIntelligenceEngine();

    // Data Management
    void addArtifact(Artifact a);
    void reclassifyArtifact(int artifactId, string newCivilization);
    void undoReclassification();
    
    // Excavation Reports
    void submitReport(ExcavationReport r);
    void processNextReport();

    // Queries
    void displayTopSignificantArtifacts();
    void displayArtifactsByAge();
    void findArtifactById(int id);
    void findArtifactByIdBinarySearch(int id);

    // Trade Routes
    void addTradeRoute(string civ1, string civ2, int distance);
    void analyzeCivilizationConnections(string startCiv);
    void analyzeCivilizationConnectionsDFS(string startCiv);
    void findShortestTradeRoute(string civ1, string civ2);
};

#endif
