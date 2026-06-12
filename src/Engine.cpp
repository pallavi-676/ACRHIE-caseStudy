#include "Engine.h"
#include <iostream>
#include <algorithm>

HistoricalIntelligenceEngine::HistoricalIntelligenceEngine() {}

void HistoricalIntelligenceEngine::addArtifact(Artifact a) {
    artifactHash.insert(a);
    artifactTree.insert(a);
    allArtifacts.push_back(a);
    cout << "Artifact added: " << a.name << " (ID: " << a.id << ")" << endl;
}

void HistoricalIntelligenceEngine::reclassifyArtifact(int artifactId, string newCivilization) {
    Artifact* a = artifactHash.search(artifactId);
    if (a) {
        string oldCiv = a->civilization;
        a->civilization = newCivilization;
        classificationUndoStack.push(PreviousClassification(artifactId, oldCiv, newCivilization));
        cout << "Artifact " << artifactId << " reclassified to " << newCivilization << endl;
        
        // Also update in vector
        for (auto& art : allArtifacts) {
            if (art.id == artifactId) {
                art.civilization = newCivilization;
                break;
            }
        }
    } else {
        cout << "Artifact ID not found!" << endl;
    }
}

void HistoricalIntelligenceEngine::undoReclassification() {
    PreviousClassification prev;
    if (classificationUndoStack.pop(prev)) {
        Artifact* a = artifactHash.search(prev.artifactId);
        if (a) {
            a->civilization = prev.oldCivilization;
            cout << "Undo successful: Artifact " << prev.artifactId << " restored to " << prev.oldCivilization << endl;
            // update in vector
            for (auto& art : allArtifacts) {
                if (art.id == prev.artifactId) {
                    art.civilization = prev.oldCivilization;
                    break;
                }
            }
        }
    } else {
        cout << "No actions to undo." << endl;
    }
}

void HistoricalIntelligenceEngine::submitReport(ExcavationReport r) {
    reportQueue.enqueue(r);
    cout << "Report " << r.reportId << " added to queue." << endl;
}

void HistoricalIntelligenceEngine::processNextReport() {
    ExcavationReport r;
    if (reportQueue.dequeue(r)) {
        cout << "Processing Report ID: " << r.reportId << endl;
        cout << "Site: " << r.siteName << " | Date: " << r.date << endl;
        cout << "Summary: " << r.summary << " (" << r.newArtifactsFound << " artifacts)" << endl;
    } else {
        cout << "No reports to process." << endl;
    }
}

void HistoricalIntelligenceEngine::displayTopSignificantArtifacts() {
    if (allArtifacts.empty()) {
        cout << "No artifacts available." << endl;
        return;
    }
    vector<Artifact> copy = allArtifacts;
    Sorter::quickSort(copy, 0, copy.size() - 1);
    
    cout << "--- Top Artifacts by Significance ---" << endl;
    for (size_t i = 0; i < copy.size(); i++) {
        cout << i + 1 << ". " << copy[i].name << " (Score: " << copy[i].significanceScore << ") - " << copy[i].civilization << endl;
    }
}

void HistoricalIntelligenceEngine::displayArtifactsByAge() {
    vector<Artifact> sorted = artifactTree.getInorder();
    cout << "--- Artifacts Sorted by Age (Oldest to Newest) ---" << endl;
    for (const auto& a : sorted) {
        cout << "Age: " << a.age << " | Name: " << a.name << " | Civ: " << a.civilization << endl;
    }
}

void HistoricalIntelligenceEngine::findArtifactById(int id) {
    Artifact* a = artifactHash.search(id);
    if (a) {
        cout << "Found Artifact via Hash Table: " << a->name << " (Civ: " << a->civilization << ")" << endl;
    } else {
        cout << "Artifact not found." << endl;
    }
}

void HistoricalIntelligenceEngine::addTradeRoute(string civ1, string civ2, int distance) {
    tradeNetwork.addRoute(civ1, civ2, distance);
    cout << "Trade route added between " << civ1 << " and " << civ2 << " (Dist: " << distance << ")" << endl;
}

void HistoricalIntelligenceEngine::analyzeCivilizationConnections(string startCiv) {
    cout << "Analyzing connections for " << startCiv << "..." << endl;
    tradeNetwork.BFS(startCiv);
}

void HistoricalIntelligenceEngine::findShortestTradeRoute(string civ1, string civ2) {
    tradeNetwork.Dijkstra(civ1, civ2);
}

void HistoricalIntelligenceEngine::findArtifactByIdBinarySearch(int id) {
    if (allArtifacts.empty()) {
        cout << "No artifacts available." << endl;
        return;
    }
    
    // Sort a copy of the artifacts array by ID
    vector<Artifact> copy = allArtifacts;
    sort(copy.begin(), copy.end(), [](const Artifact& a, const Artifact& b) {
        return a.id < b.id;
    });

    // Use binary search from Algorithms.h
    int index = Searcher::binarySearchById(copy, 0, copy.size() - 1, id);
    if (index != -1) {
        cout << "Found Artifact via Binary Search: " << copy[index].name 
             << " (Civ: " << copy[index].civilization << ")" << endl;
    } else {
        cout << "Artifact not found." << endl;
    }
}

void HistoricalIntelligenceEngine::analyzeCivilizationConnectionsDFS(string startCiv) {
    cout << "Analyzing connections for " << startCiv << " using DFS..." << endl;
    tradeNetwork.DFS(startCiv);
}
