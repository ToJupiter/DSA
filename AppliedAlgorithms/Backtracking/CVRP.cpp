#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
const int INF = 1e9;

int numClients, numRoutes, maxLoad, totalDistance = 0, bestDistance = INF;
int demand[MAX], distanceMap[MAX][MAX], visited[MAX], load[MAX];
vector<int> nextPoint(MAX), startPoint(MAX);
int segmentCount = 0, routeCount = 0, minDistance;

void readInput() {
    cin >> numClients >> numRoutes >> maxLoad;
    for (int i = 1; i <= numClients; i++) 
        cin >> demand[i];
    
    demand[0] = 0;
    minDistance = INF;
    for (int i = 0; i <= numClients; i++) {
        for (int j = 0; j <= numClients; j++) {
            cin >> distanceMap[i][j];
            if (i != j) minDistance = min(minDistance, distanceMap[i][j]);
        }
    }
}

void findRoutes(int current, int routeIndex, bool isStartPoint = false) {
    if (isStartPoint) {
        for (int v = (startPoint[routeIndex-1] == 0 ? 0 : startPoint[routeIndex-1] + 1); v <= numClients; v++) {
            if (v == 0 || (!visited[v] && load[routeIndex] + demand[v] <= maxLoad)) {
                startPoint[routeIndex] = v;
                if (v > 0) {
                    visited[v] = 1;
                    totalDistance += distanceMap[0][v];
                    load[routeIndex] += demand[v];
                    segmentCount++;
                }
                
                if (routeIndex < numRoutes) {
                    findRoutes(0, routeIndex + 1, true);
                } else {
                    routeCount = numRoutes;  
                    findRoutes(startPoint[1], 1);
                }
                
                if (v > 0) {
                    segmentCount--;
                    load[routeIndex] -= demand[v];
                    totalDistance -= distanceMap[0][v];
                    visited[v] = 0;
                }
            }
        }
        return;
    }

    if (current == 0) {
        if (routeIndex < numRoutes) {
            findRoutes(startPoint[routeIndex + 1], routeIndex + 1);
        }
        return;
    }

    for (int v = 0; v <= numClients; v++) {
        if ((v == 0 || !visited[v]) && load[routeIndex] + demand[v] <= maxLoad) {
            nextPoint[current] = v;
            totalDistance += distanceMap[current][v];
            if (v > 0) {
                visited[v] = 1;
                load[routeIndex] += demand[v];
                segmentCount++;
            }

            if (v == 0) {
                if (routeIndex == numRoutes) {
                    if (segmentCount == numClients) 
                        bestDistance = min(bestDistance, totalDistance);
                } else if (totalDistance + (numClients - segmentCount) * minDistance < bestDistance)
                    findRoutes(startPoint[routeIndex + 1], routeIndex + 1);
            } else if (totalDistance + (numClients - segmentCount) * minDistance < bestDistance) {
                findRoutes(v, routeIndex);
            }

            if (v > 0) {
                segmentCount--;
                load[routeIndex] -= demand[v];
                visited[v] = 0;
            }
            totalDistance -= distanceMap[current][v];
        }
    }
}

int main() {
    readInput(); ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(visited, visited + MAX, 0);
    fill(load, load + MAX, 0);
    startPoint[0] = 0;
    findRoutes(0, 1, true);
    cout << (bestDistance == INF ? -1 : bestDistance) << endl;
    return 0;
}
