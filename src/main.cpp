#include "Engine.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu() {
    cout << "\n=======================================================\n";
    cout << "  Ancient Civilization Reconstruction Engine (ACRHIE)  \n";
    cout << "=======================================================\n";
    cout << "1. View Top Significant Artifacts (Sorting)\n";
    cout << "2. View Artifacts Timeline (BST)\n";
    cout << "3. Search Artifact by ID (Hashing)\n";
    cout << "4. Search Artifact by ID (Binary Search)\n";
    cout << "5. Reclassify Artifact\n";
    cout << "6. Undo Reclassification (Stack)\n";
    cout << "7. Process Excavation Report (Queue)\n";
    cout << "8. Analyze Civilization Trade Network (BFS)\n";
    cout << "9. Analyze Civilization Trade Network (DFS)\n";
    cout << "10. Find Shortest Trade Route (Dijkstra's)\n";
    cout << "11. Exit\n";
    cout << "Select an option: ";
}

void loadSampleData(HistoricalIntelligenceEngine& engine) {
    ifstream file("data/sample_input.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open data/sample_input.txt. Please check the file path." << endl;
        return;
    }

    string line;
    string section = "";

    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line == "Artifacts:") {
            section = "Artifacts";
            continue;
        } else if (line == "TradeRoutes:") {
            section = "TradeRoutes";
            continue;
        } else if (line == "Reports:") {
            section = "Reports";
            continue;
        }

        stringstream ss(line);
        string token;
        
        if (section == "Artifacts") {
            int id, age, score;
            string name, civ, desc;
            
            getline(ss, token, ','); id = stoi(token);
            getline(ss, name, ',');
            getline(ss, civ, ',');
            getline(ss, token, ','); age = stoi(token);
            getline(ss, token, ','); score = stoi(token);
            getline(ss, desc); // Optional
            
            engine.addArtifact(Artifact(id, name, civ, age, score, desc));
        } else if (section == "TradeRoutes") {
            string from, to;
            int dist;
            
            getline(ss, from, ',');
            getline(ss, to, ',');
            getline(ss, token, ','); dist = stoi(token);
            
            engine.addTradeRoute(from, to, dist);
        } else if (section == "Reports") {
            int id, count;
            string site, date, sum;
            
            getline(ss, token, ','); id = stoi(token);
            getline(ss, site, ',');
            getline(ss, date, ',');
            getline(ss, token, ','); count = stoi(token);
            getline(ss, sum);
            
            engine.submitReport(ExcavationReport(id, site, date, count, sum));
        }
    }
    file.close();
    cout << "Data successfully loaded from data/sample_input.txt" << endl;
}

int main() {
    HistoricalIntelligenceEngine engine;
    
    cout << "Loading Data...\n";
    loadSampleData(engine);
    
    int choice;
    do {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                engine.displayTopSignificantArtifacts();
                break;
            case 2:
                engine.displayArtifactsByAge();
                break;
            case 3: {
                int id;
                cout << "Enter Artifact ID: ";
                cin >> id;
                engine.findArtifactById(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Artifact ID: ";
                cin >> id;
                engine.findArtifactByIdBinarySearch(id);
                break;
            }
            case 5: {
                int id;
                string newCiv;
                cout << "Enter Artifact ID to reclassify: ";
                cin >> id;
                cout << "Enter new civilization: ";
                cin >> newCiv;
                engine.reclassifyArtifact(id, newCiv);
                break;
            }
            case 6:
                engine.undoReclassification();
                break;
            case 7:
                engine.processNextReport();
                break;
            case 8: {
                string civ;
                cout << "Enter Civilization Name (e.g., Egyptian): ";
                cin >> civ;
                engine.analyzeCivilizationConnections(civ);
                break;
            }
            case 9: {
                string civ;
                cout << "Enter Civilization Name (e.g., Egyptian): ";
                cin >> civ;
                engine.analyzeCivilizationConnectionsDFS(civ);
                break;
            }
            case 10: {
                string civ1, civ2;
                cout << "Enter Start Civilization: ";
                cin >> civ1;
                cout << "Enter Destination Civilization: ";
                cin >> civ2;
                engine.findShortestTradeRoute(civ1, civ2);
                break;
            }
            case 11:
                cout << "Exiting system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 11);

    return 0;
}
