#include <stdio.h>
#include <stdbool.h>

#define ONSITE_NODE_COST 1000              // Cost of one onsite compute node ($)
#define ONSITE_NETWORK_COST_PER_GB 0.1     // Cost of network transfer per GB for onsite HPC ($)
#define ONSITE_ENERGY_COST_PER_HOUR 0.2    // Cost of energy per hour for onsite HPC ($)
#define ONSITE_STORAGE_COST_PER_TB 100     // Cost of onsite storage per TB ($)
#define CLOUD_CPU_COST_PER_HOUR 0.1        // Cost of CPU time per hour in the cloud ($)
#define CLOUD_STORAGE_COST_PER_TB 20       // Cost of storage per TB in the cloud ($)
#define CLOUD_NETWORK_COST_PER_GB 0.2      // Cost of network transfer per GB for cloud HPC ($)


double calculateOnsiteCost(int numNodes, int hours, int storageTB, int dataTransferGB) {
    double nodeCost = ONSITE_NODE_COST * numNodes;
    double energyCost = ONSITE_ENERGY_COST_PER_HOUR * hours;
    double storageCost = ONSITE_STORAGE_COST_PER_TB * storageTB;
    double networkCost = ONSITE_NETWORK_COST_PER_GB * dataTransferGB;
    return nodeCost + energyCost + storageCost + networkCost;
}

double calculateCloudCost(int numNodes, int hours, int storageTB, int dataTransferGB) {
    double cpuCost = CLOUD_CPU_COST_PER_HOUR * numNodes * hours;
    double storageCost = CLOUD_STORAGE_COST_PER_TB * storageTB;
    double networkCost = CLOUD_NETWORK_COST_PER_GB * dataTransferGB;
    return cpuCost + storageCost + networkCost;
}

bool validateInput(int numNodes, int hours, int storageTB, int dataTransferGB) {
    return (numNodes >= 0 && hours >= 0 && storageTB >= 0 && dataTransferGB >= 0);
}

int main() {
    const int numProcesses = 10; // Minimum number of processes
    int numNodes[10] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // Number of compute nodes for each 
    int hours[10] = {35, 40, 45, 50, 55, 60, 65, 70, 75, 80}; // Number of hours for processing 
    double storageTB = 1; // Assume 1 TB storage requirement for simplicity
    double dataTransferGB = 10; // Assume 10 GB data transfer requirement for simplicity

    

    for (int i = 0; i < numProcesses; i++) {
        printf("===========================================================");
        printf("Process %d:\n", i + 1);

        if (!validateInput(numNodes[i], hours[i], storageTB, dataTransferGB)) {
            printf("Invalid input for process %d. Skipping...", i + 1);
            continue;
        }

        double onsiteCost = calculateOnsiteCost(numNodes[i], hours[i], storageTB, dataTransferGB);
        double cloudCost = calculateCloudCost(numNodes[i], hours[i], storageTB, dataTransferGB);

        printf("Total onsite cost for process %d: $%.2f", i + 1, onsiteCost);
        printf("Total cloud cost for process %d: $%.2f", i + 1, cloudCost);

        if (onsiteCost < cloudCost) {
            printf("Recommendation for process %d: Onsite HPC is cheaper.", i + 1);
        } else if (cloudCost < onsiteCost) {
            printf("Recommendation for process %d: Cloud HPC is cheaper.", i + 1);
        } else {
            printf("Costs are equal for process %d. Consider other factors for decision making.\n", i + 1);
        }

        printf("\n");
    }

    // Calculate simulation times for each process
    double onsiteTimes[numProcesses];
    double cloudTimes[numProcesses];

    // You need to implement the logic to calculate simulation times for each process based on your application

    for (int i = 0; i < numProcesses; i++) {
        //  printf("===========================================================\n");
        printf("Process %d Simulation Times:", i + 1);
        printf("Onsite simulation time: %.2f seconds", onsiteTimes[i]);
        printf("Cloud simulation time: %.2f seconds", cloudTimes[i]);
        printf("\n");
    }

    return 0;
}
