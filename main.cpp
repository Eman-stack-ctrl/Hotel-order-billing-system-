#include <iostream>
#include <fstream>
using namespace std;
struct Order {
    string customerName;
    int itemChoice;
    int quantity;
    float totalBill;
};
void calculateBill(Order *o, float prices[]) {
     o->totalBill += prices[o->itemChoice - 1] * o->quantity;
}
void saveToFile(Order O) {
    ofstream file("orders.txt", ios::app);
    file << "Customer Name: " << O.customerName << endl;
    file << "Total Bill: Rs " << O.totalBill << endl;
    file << "----------------------------" << endl;
    file.close();
}

int main() {

    string items[5] = {"Burger", "Pizza", "Pasta", "Fries", "Cold Drink"};
    float prices[5] = {250, 500, 350, 150, 100};

    Order ord;
    int menuChoice;

    cout << "===== RESTAURANT MANAGEMENT SYSTEM =====\n";

    cout << "Enter Customer Name: ";
    cin >> ord.customerName;

    do {
        cout << "\n1. View Menu";
        cout << "\n2. Place Order";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> menuChoice;

        switch (menuChoice) {

        case 1:
            cout << "\n--- MENU ---\n";
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << items[i]
                     << " - Rs " << prices[i] << endl;
            }
            break;

        case 2: {
            int totalItems;
            ord.totalBill = 0;

            cout << "\nHow many different items do you want to order? ";
            cin >> totalItems;

            for (int i = 0; i < totalItems; i++) {

                cout << "\nEnter item number (1-5): ";
                cin >> ord.itemChoice;

                if (ord.itemChoice < 1 || ord.itemChoice > 5) {
                    cout << "Invalid item! Skipped.\n";
                    continue;
                }

                cout << "Enter quantity: ";
                cin >> ord.quantity;

                calculateBill(&ord, prices);
            }

            cout << "\nTotawl Bill: Rs " << ord.totalBill << endl;

            int payment;
            cout << "Payment Method (1 = Cash, 2 = Online): ";
            cin >> payment;

            if (payment == 1)
                cout << "Cash Payment Selected.\n";
            else if (payment == 2)
                cout << "Online Payment Selected.\n";
            else
                cout << "Invalid Payment Option.\n";
            
            saveToFile(ord);
            cout << "Order saved successfully!\n";
            break;
        }

        case 3:
            cout << "Thank you for visiting!\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }

    } while (true);

    return 0;
}
