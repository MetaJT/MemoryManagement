#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

void translateAddress(int logicalAddress, std::vector<int> pageTable) {
    int pageNumber = (logicalAddress >> 8) & 0xFF; // Logic shift left 8 times to grab the last 8 bits
    int offset = logicalAddress & 0xFF; // Grab the first 8 bits

    if (pageTable[pageNumber] == -1) { // If the position is map the new pageNumber
        std::cout << "Page fault occurred for Logical Address: 0x" << std::hex << logicalAddress << "\n";
        pageTable[pageNumber] = pageNumber;
    }

    std::cout << "Logical Address: 0x" << std::hex << logicalAddress;
    std::cout << " => Page Number: 0x" << std::setw(2) << std::setfill('0') << pageTable[pageNumber];
    std::cout << ", Offset: 0x" << std::setw(2) << std::setfill('0') << offset << "\n";
}

int main() {
    std::vector<int> pageFrameTable(0xFF, -1); // Initialize the page/frame table will -1
    std::vector<int> logicalAddresses = {0x3A7F, 0xABCD, 0x5678};

    pageFrameTable[0x3A] = 0x0D; // Insert physical page number data
    pageFrameTable[0xAB] = 0x2B;
    pageFrameTable[0x56] = 0x15;

    
    for (int i = 0; i < logicalAddresses.size(); ++i) {
        translateAddress(logicalAddresses[i], pageFrameTable); // Translate the logical address to physical address
    }

    return 0;
}
