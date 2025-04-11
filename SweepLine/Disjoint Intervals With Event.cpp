/*
[GOOGLE]
You are given a list of worker shifts, where each shift is
represented as a list [name, start, end]. The name is a string
representing the worker's name, start is an integer representing the
start time of the shift, and end is an integer representing the end
time of the shift. The goal is to generate a schedule that shows the
intervals of time and the workers present during each interval.
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void printActiveIntervals(vector<vector<int>>& events) {
    map<int, vector<int>> timeline;
    
    // Populate the timeline with event start and end days
    for (int i = 0; i < events.size(); ++i) {
        timeline[events[i][0]].push_back(i + 1);  // Event starts (1-based index)
        timeline[events[i][1] + 1].push_back(-(i + 1)); // Event ends (1-based index)
    }
    
    set<int> activeEvents;
    int prevDay = -1;
    
    for (auto it = timeline.begin(); it != timeline.end(); ++it) {
        int currentDay = it->first;
        
        // Print the interval if there were active events in the previous segment
        if (!activeEvents.empty() && prevDay != -1) {
            cout << "[" << prevDay << ", " << currentDay - 1 << "] : { ";
            for (int event : activeEvents) {
                cout << event << " ";
            }
            cout << "}\n";
        }
        
        // Update active events
        for (int event : it->second) {
            if (event >= 0)
                activeEvents.insert(event); // Add event
            else
                activeEvents.erase(-event); // Remove event
        }
        
        prevDay = currentDay;
    }
}

int main() {
    vector<vector<int>> events = {{1, 3}, {2, 5}, {4, 6}};
    printActiveIntervals(events);
    return 0;
}