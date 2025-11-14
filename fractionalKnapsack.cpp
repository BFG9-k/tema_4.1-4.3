#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    double weight;
    double value;
};

bool compare(const Item& a, const Item& b) {
    return a.value / a.weight > b.value / b.weight;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (auto& item : items) {
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
        }
        else {
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n; // Количество предметов
    cout << "Введите количество предметов: ";
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cout << "Введите вес и стоимость предмета №" << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    int capacity;
    cout << "Введите вместимость рюкзака: ";
    cin >> capacity;
    double max_value = fractionalKnapsack(items, capacity);
    cout << "Максимальная стоимость набора предметов: " << max_value << endl;
    return 0;
}