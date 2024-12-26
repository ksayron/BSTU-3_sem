#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "Ru");
    const int numPrisoners = 100;
    const int numBoxes = 100;
    int randomSuccessCount = 0;
    int numberSuccessCount = 0;
    bool randomCheck = true;
    bool numberCheck = true;
    int count1 = 100;
    int count2 = 100;

    srand((time(0)));
    int boxes[numPrisoners];
    for (int i = 0; i < numPrisoners; ++i) {
        boxes[i] = i;
    }
    std::random_shuffle(boxes, boxes + numPrisoners);

   
    for (int i = 0; i < numPrisoners; ++i) {
        std::cout << boxes[i] << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl; 
        }
    }
    int rounds;
    std::cout << "Кол-во раундов сравнения\: ";
    std::cin >> rounds;

    for (int i = 0; i < rounds; i++) {
        bool randomSelection[numPrisoners] = { false };
        bool numberSelection[numPrisoners] = { false };

    
      
        for (int j = 0; j < numPrisoners; j++) {
            for (int k = 0;k < 50;k++) {
                int selectedBox = rand() % numBoxes; 
                if (boxes[selectedBox] == j) {
                    randomSelection[j] = true;
                    break;
                }
            }
        }

        for (int j = 0; j < numPrisoners; j++) {
            int selectedBox = j;
            for (int k = 0; k < 50; k++) {
                if (boxes[selectedBox] == j) {
                    numberSelection[j] = true;
                    break;
                }
                else {
                    selectedBox = boxes[selectedBox];
                }
            }
        }


        for (int j = 0; j < numPrisoners; j++) {
            if (!randomSelection[j]) {
                randomCheck = false;
                count1--;
            }
            if (!numberSelection[j]) {
                numberCheck = false;
                count2--;
            }
        }
        std::cout << i << ": " << count1 << " " << count2<<"\n";
        if (count1 == 100) {
            randomSuccessCount++;
        }
        if (count2 == 100) {
            numberSuccessCount++;
        }
        count1 = count2 = 100;
        
        std::random_shuffle(boxes, boxes + numPrisoners);
    }

    std::cout << "\nУспехов выбором наугад: " << randomSuccessCount << std::endl;
    std::cout << "\nУспехов выбором цепочкой: " << numberSuccessCount << std::endl;

    return 0;
}