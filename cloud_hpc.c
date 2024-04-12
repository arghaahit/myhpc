#include <stdio.h>
#include <stdbool.h>

#define ONSITE_NODE_COST 1000              // Cost of one onsite compute node ($)
#define ONSITE_NETWORK_COST_PER_GB 0.1     // Cost of network transfer per GB for onsite HPC ($)
#define ONSITE_ENERGY_COST_PER_HOUR 0.2    // Cost of energy per hour for onsite HPC ($)
#define ONSITE_STORAGE_COST_PER_TB 100     // Cost of onsite storage per TB ($)
#define CLOUD_CPU_COST_PER_HOUR 0.1        // Cost of CPU time per hour in the cloud ($)
#define CLOUD_STORAGE_COST_PER_TB 20       // Cost of storage per TB in the cloud ($)
#define CLOUD_NETWORK_COST_PER_GB 0.2      // Cost of network transfer per GB for cloud HPC ($)

double calculateOnsiteCost(int numNodes, int hours, int storageTB, int dataTransferGB);
double calculateCloudCost(int numNodes, int hours, int storageTB, int dataTransferGB);
bool validateInput(int numNodes, int hours, int storageTB, int dataTransferGB);

int main() {
    int numNodes, hours;
    double storageTB, dataTransferGB;

    printf("Enter the number of compute nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of hours for processing: ");
    scanf("%d", &hours);

    printf("Enter the storage requirement in TB: ");
    scanf("%lf", &storageTB);

    printf("Enter the data transfer requirement in GB: ");
    scanf("%lf", &dataTransferGB);

    if (!validateInput(numNodes, hours, storageTB, dataTransferGB)) {
        printf("Invalid input. Please enter non-negative numbers.\n");
        return 1;
    }

    double onsiteCost = calculateOnsiteCost(numNodes, hours, storageTB, dataTransferGB);
    double cloudCost = calculateCloudCost(numNodes, hours, storageTB, dataTransferGB);

    printf("Total onsite cost: $%.2f\n", onsiteCost);
    printf("Total cloud cost: $%.2f\n", cloudCost);

    if (onsiteCost < cloudCost) {
        printf("Recommendation: Onsite HPC is cheaper.\n");
    } else if (cloudCost < onsiteCost) {
        printf("Recommendation: Cloud HPC is cheaper.\n");
    } else {
        printf("Costs are equal. Consider other factors for decision making.\n");
    }

    printf("\nDetailed Cost Breakdown:\n");
    printf("Onsite Cost Breakdown:\n");
    printf("- Node Cost: $%.2f\n", ONSITE_NODE_COST * numNodes);
    printf("- Energy Cost: $%.2f\n", ONSITE_ENERGY_COST_PER_HOUR * hours);
    printf("- Storage Cost: $%.2f\n", ONSITE_STORAGE_COST_PER_TB * storageTB);
    printf("- Network Cost: $%.2f\n", ONSITE_NETWORK_COST_PER_GB * dataTransferGB);

    printf("\nCloud Cost Breakdown:\n");
    printf("- CPU Cost: $%.2f\n", CLOUD_CPU_COST_PER_HOUR * numNodes * hours);
    printf("- Storage Cost: $%.2f\n", CLOUD_STORAGE_COST_PER_TB * storageTB);
    printf("- Network Cost: $%.2f\n", CLOUD_NETWORK_COST_PER_GB * dataTransferGB);

    return 0;
}

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

bool validateInput(int numNodes, int hours, double storageTB, double dataTransferGB) {
    return (numNodes >= 0 && hours >= 0 && storageTB >= 0 && dataTransferGB >= 0);
}
