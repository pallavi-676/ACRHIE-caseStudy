#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <vector>

using namespace std;

// Artifact represents a discovered item
struct Artifact {
    int id;
    string name;
    string civilization;
    int age;
    int significanceScore; // 1 to 100
    string description;

    Artifact(int id = 0, string name = "", string civ = "", int age = 0, int score = 0, string desc = "")
        : id(id), name(name), civilization(civ), age(age), significanceScore(score), description(desc) {}
};

// ExcavationReport represents a report from a dig site
struct ExcavationReport {
    int reportId;
    string siteName;
    string date;
    int newArtifactsFound;
    string summary;

    ExcavationReport(int id = 0, string site = "", string d = "", int count = 0, string sum = "")
        : reportId(id), siteName(site), date(d), newArtifactsFound(count), summary(sum) {}
};

// TradeRoute represents a connection between two civilizations
struct TradeRoute {
    string fromCivilization;
    string toCivilization;
    int distance; // or travel time, represents weight

    TradeRoute(string from = "", string to = "", int dist = 0)
        : fromCivilization(from), toCivilization(to), distance(dist) {}
};

// PreviousClassification used for Stack Undo feature
struct PreviousClassification {
    int artifactId;
    string oldCivilization;
    string newCivilization;

    PreviousClassification(int id = 0, string oldCiv = "", string newCiv = "")
        : artifactId(id), oldCivilization(oldCiv), newCivilization(newCiv) {}
};

#endif
