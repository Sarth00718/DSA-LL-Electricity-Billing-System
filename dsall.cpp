#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct bill {
    int month;
    int year;
    int no_of_unit;
    float amount;
    bill* next;
};

struct consumer {
    int no_of_consumer;
    string name_of_consumer;
    string address_of_consumer;
    string phone_no_of_consumer;
    bill* bhead;
    consumer* next;
};

// /-------------------------------------------------------------------------------------/

consumer* createNodeForConsumer(int consumerNo, string consumerName, string consumerAddress, string consumerPhoneNo) {
    consumer* newNode = new consumer();
    newNode->no_of_consumer = consumerNo;
    newNode->name_of_consumer = consumerName;
    newNode->address_of_consumer = consumerAddress;
    newNode->phone_no_of_consumer = consumerPhoneNo;
    newNode->bhead = NULL;
    newNode->next = NULL;
    return newNode;
}

void add_New_Consumers(consumer* &head, int no_of_consumer, string name_of_consumer, string address_of_consumer, string phone_no_of_consumer) {
    consumer* newNode_Consumer = createNodeForConsumer(no_of_consumer, name_of_consumer, address_of_consumer, phone_no_of_consumer);
    newNode_Consumer->next = head;
    head = newNode_Consumer;
}

// /---------------------------------------------------------------------------------------/

void addBills_wrt_DiffConsumers(consumer* head, int no_of_consumer, int month, int year, int no_of_unit, float RPU) {
    consumer* c = head;
    while (c != NULL) {
        if (c->no_of_consumer == no_of_consumer) {
            float amount = no_of_unit * RPU;
            bill* newNode_bill = new bill();
            newNode_bill->month = month;
            newNode_bill->year = year;
            newNode_bill->no_of_unit = no_of_unit;
            newNode_bill->amount = amount;
            newNode_bill->next = c->bhead;
            c->bhead = newNode_bill;

            cout << "Consumer no. " << no_of_consumer << "'s bill added..." << endl;
            return;
        }
        c = c->next;
    }
    cout << "Consumer no. " << no_of_consumer << " does not exist..." << endl;
}

// /-----------------------------------------------------------------------------------------/

void Generate_Display_Bill(consumer* head, int no_of_consumer, int month, int year) {
    consumer* c = head;
    while (c != NULL) {
        if (c->no_of_consumer == no_of_consumer) {
            bill* temp = c->bhead;
            bool billFound = false;

            cout << "\nBill Details" << endl;
            cout << "Name: " << c->name_of_consumer << endl;
            cout << "Address: " << c->address_of_consumer << endl;
            cout << "Phone No.: " << c->phone_no_of_consumer << endl;

            cout << "\n" << setw(10) << "Bill No." << setw(10) << "Month" << setw(10) << "Year" 
                 << setw(15) << "Units" << setw(15) << "Amount" << endl;
            cout << string(70, '-') << endl;

            // Display the bill details
            while (temp != NULL) {
                if (temp->month == month && temp->year == year) {
                    cout << setw(10) << "1" << setw(10) << temp->month << setw(10) << temp->year 
                         << setw(15) << temp->no_of_unit << setw(15) << fixed << setprecision(2) << temp->amount << endl;
                    billFound = true;
                    break;
                }
                temp = temp->next;
            }

            if (!billFound) {
                cout << "Bill for " << month << "/" << year << " not found..." << endl;
                return;
            }

            // Display last 3 months' bills
            cout << "\nLast 3 months' bills:" << endl;
            cout << setw(10) << "Bill No." << setw(10) << "Month" << setw(10) << "Year" << setw(15) << "Units" 
                 << setw(15) << "Amount" << endl;
            cout << string(70, '-') << endl;

            int lastMonths[3] = {(month == 1 ? 12 : month - 1), (month <= 2 ? 12 : month - 2), (month <= 3 ? 12 : month - 3),};
            int lastYears[3] = {(month == 1 ? year - 1 : year), (month <= 2 ? year - 1 : year), (month <= 3 ? year - 1 : year)};
            
            for (int i = 0; i < 3; i++) {
                temp = c->bhead;
                bool billFoundForMonth = false;
                while (temp != NULL) {
                    if (temp->month == lastMonths[i] && temp->year == lastYears[i]) {
                        cout << setw(10) << (i + 1) << setw(10) << temp->month 
                             << setw(10) << temp->year << setw(15) << temp->no_of_unit 
                             << setw(15) << fixed << setprecision(2) << temp->amount << endl;
                        billFoundForMonth = true;
                        break;
                    }
                    temp = temp->next;
                }

                if (!billFoundForMonth) {
                    cout << "Bill for " << lastMonths[i] << "/" << lastYears[i] << " not found..." << endl;
                }
            }

            return;
        }
        c = c->next;
    }
    cout << "Consumer no. " << no_of_consumer << " does not exist..." << endl;
}

// /-----------------------------------------------------------------------------------------/

void displayConsumers(consumer* head) {
    consumer* temp = head;
    cout << "\nRegistered Consumers:" << endl;
    cout << setw(15) << "Consumer No." << setw(20) << "Name" << setw(20) << "Address" 
         << setw(15) << "Phone No." << endl;
    cout << string(70, '-') << endl;

    while (temp != NULL) {
        cout << setw(15) << temp->no_of_consumer << setw(20) << temp->name_of_consumer 
             << setw(20) << temp->address_of_consumer << setw(15) << temp->phone_no_of_consumer << endl;
        temp = temp->next;
    }
}

// /-----------------------------------------------------------------------------------------/

int main() {
    consumer* temphead = NULL;
    int choice;

    while (true) {
        cout << string(30, '-') << endl;
        cout << "| " << setw(24) << left << "Torrent Power Billing System" << " |" << endl;
        cout << string(30, '-') << endl;
        cout << setw(20) << "Features:" << endl;
        cout << string(30, '-') << endl;
        cout << setw(10) << "1. Add new consumer" << endl;
        cout << setw(10) << "2. Add bill to consumer" << endl;
        cout << setw(10) << "3. Generate and Display bill" << endl;
        cout << setw(10) << "4. Display all consumers" << endl;
        cout << setw(10) << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int no_of_consumer;
                string name_of_consumer;
                string address_of_consumer;
                string phone_no_of_consumer;
                cout << "Enter consumer number: ";
                cin >> no_of_consumer;
                cout << "Enter consumer name: ";
                cin.ignore();
                getline(cin, name_of_consumer);
                cout << "Enter consumer address: ";
                getline(cin, address_of_consumer);
                cout << "Enter consumer phone number: ";
                getline(cin, phone_no_of_consumer);
                add_New_Consumers(temphead, no_of_consumer, name_of_consumer, address_of_consumer, phone_no_of_consumer);
                cout << "Consumer " << name_of_consumer << " added..." << endl;
                break;
            }
            case 2: {
                int no_of_consumer;
                int month;
                int year;
                int no_of_unit;
                float RPU;
                cout << "Enter consumer number: ";
                cin >> no_of_consumer;
                cout << "Enter month: ";
                cin >> month;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter number of units: ";
                cin >> no_of_unit;
                cout << "Enter rate per unit: ";
                cin >> RPU;
                addBills_wrt_DiffConsumers(temphead, no_of_consumer, month, year, no_of_unit, RPU);
                break;
            }
            case 3: {
                int no_of_consumer;
                int month;
                int year;
                cout << "Enter consumer number: ";
                cin >> no_of_consumer;
                cout << "Enter month: ";
                cin >> month;
                cout << "Enter year: ";
                cin >> year;
                Generate_Display_Bill(temphead, no_of_consumer, month, year);
                break;
            }
            case 4: {
                displayConsumers(temphead);
                break;
            }
            case 5: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }
    return 0;
}
