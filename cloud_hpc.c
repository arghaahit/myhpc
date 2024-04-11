#include <stdio.h>

// Define constants for prices
#define ONSITE_NODE_COST 1000           // Cost of one onsite compute node
#define ONSITE_NETWORK_COST_PER_GB 0.1  // Cost of network transfer per GB for onsite HPC
#define ONSITE_ENERGY_COST_PER_HOUR 0.2 // Cost of energy per hour for onsite HPC
#define ONSITE_STORAGE_COST_PER_TB 100  // Cost of onsite storage per TB
#define CLOUD_CPU_COST_PER_HOUR 0.1     // Cost of CPU time per hour in the cloud
#define CLOUD_STORAGE_COST_PER_TB 20    // Cost of storage per TB in the cloud
#define CLOUD_NETWORK_COST_PER_GB 0.2   // Cost of network transfer per GB for cloud HPC

// Function to calculate total onsite cost
double calculateOnsiteCost(int numNodes, int hours, int storageTB, int dataTransferGB) {
    double nodeCost = ONSITE_NODE_COST * numNodes;
    double energyCost = ONSITE_ENERGY_COST_PER_HOUR * hours;
    double storageCost = ONSITE_STORAGE_COST_PER_TB * storageTB;
    double networkCost = ONSITE_NETWORK_COST_PER_GB * dataTransferGB;
    return nodeCost + energyCost + storageCost + networkCost;
}

// Function to calculate total cloud cost
double calculateCloudCost(int numNodes, int hours, int storageTB, int dataTransferGB) {
    double cpuCost = CLOUD_CPU_COST_PER_HOUR * numNodes * hours;
    double storageCost = CLOUD_STORAGE_COST_PER_TB * storageTB;
    double networkCost = CLOUD_NETWORK_COST_PER_GB * dataTransferGB;
    return cpuCost + storageCost + networkCost;
}

int main() {
    // Input parameters
    int numNodes, hours, storageTB, dataTransferGB;

    // Get input values from user
    printf("Enter the number of compute nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of hours for processing: ");
    scanf("%d", &hours);

    printf("Enter the storage requirement in TB: ");
    scanf("%d", &storageTB);

    printf("Enter the data transfer requirement in GB: ");
    scanf("%d", &dataTransferGB);

    // Calculate costs
    double onsiteCost = calculateOnsiteCost(numNodes, hours, storageTB, dataTransferGB);
    double cloudCost = calculateCloudCost(numNodes, hours, storageTB, dataTransferGB);

    // Output results
    printf("Total onsite cost: $%.2f\n", onsiteCost);
    printf("Total cloud cost: $%.2f\n", cloudCost);

    if (onsiteCost < cloudCost) {
        printf("Recommendation: Onsite HPC is cheaper.\n");
    } else {
        printf("Recommendation: Cloud HPC is cheaper.\n");
    }

    return 0;
}
