#include <iostream>
#include <fstream>
using namespace std;

class item {
private:
    char *name, *uic;
    float *price;
    int *quant;
public:
    item() {
        name = new char[20];
        uic = new char[20];
        price = new float;
        quant = new int;
    }
    ~item() {
        delete[] name;
        delete[] uic;
        delete price;
        delete quant;
    }
    int getdata();
    int setdata();
    int packedfile();
    int freshfile();
    float calculateTotal();
};

int item::getdata() {
    cin.ignore();
    cout << "\nEnter the Name of a new product: ";     cin.getline(name, 20);
    cout << "Enter the UIC of a new product: ";        cin.getline(uic, 20);
    cout << "Enter the Price of new product: ";        cin >> *price;
    cout << "Enter the quantity of a new product: ";   cin >> *quant;
    return 0;
}

int item::setdata() {
    cout << "Name \t\t\t\tUIC\t\t\tPrice\t\tQuntity " << endl;
    cout << name << " \t\t\t\t" << uic << "\t\t\t" << *price << "\t\t" << *quant << endl;
    return 0;
}

int item::packedfile() {
    int count1 = 0;
    char arr1[100];
    cout << "Enter the no of products you want to add to cart: ";
    cin >> count1;

    fstream myfile("packed.txt", ios::out | ios::app);
    cin.ignore();

    if (myfile.is_open()) {
        while (count1 != 0) {
            cout << "\nEnter the Name of a new product: ";
            cin.getline(arr1, 100);
            myfile << "Name: " << arr1 << endl;

            cout << "Enter the UIC of a new product: ";
            cin.getline(arr1, 100);
            myfile << "UIC: " << arr1 << endl;

            cout << "Enter the Price of new product: ";
            cin.getline(arr1, 100);
            myfile << "Price: " << arr1 << endl;

            cout << "Enter the quantity of a new product: ";
            cin.getline(arr1, 100);
            myfile << "Quantity: " << arr1 << endl;

            count1--;
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }
    cout << "Data recorded successful" << endl;
    return 0;
}

int item::freshfile() {
    int count2 = 0;
    char arr2[100];
    cout << "Enter the no of products you want to add to cart: ";
    cin >> count2;

    fstream myfile("fresh.txt", ios::out | ios::app);
    cin.ignore();

    if (myfile.is_open()) {
        while (count2 != 0) {
            cout << "\nEnter the Name of a new product: ";
            cin.getline(arr2, 100);
            myfile << "Name: " << arr2 << endl;

            cout << "Enter the UIC of a new product: ";
            cin.getline(arr2, 100);
            myfile << "UIC: " << arr2 << endl;

            cout << "Enter the Price of new product: ";
            cin.getline(arr2, 100);
            myfile << "Price: " << arr2 << endl;

            cout << "Enter the quantity of a new product: ";
            cin.getline(arr2, 100);
            myfile << "Quantity: " << arr2 << endl;

            count2--;
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }
    cout << "Data recorded successful" << endl;
    return 0;
}

float item::calculateTotal() {
    return *price * *quant;
}

void writeBill(float totalBill) {
    ofstream billFile("bill.txt", ios::out | ios::trunc);
    if (billFile.is_open()) {
        billFile << "Total Bill: " << totalBill << endl;
        billFile.close();
        cout << "Total bill written to bill.txt successfully." << endl;
    }
    else {
        cout << "Unable to open bill.txt for writing." << endl;
    }
}

void displayBill() {
    string line;
    ifstream billFile("bill.txt");
    if (billFile.is_open()) {
        while (getline(billFile, line)) {
            cout << line << endl;
        }
        billFile.close();
    }
    else {
        cout << "Unable to open bill.txt for reading." << endl;
    }
}

int main() {
    item obj[20];
    int i = 0, choice1, choice2;
    float totalBill = 0.0;

    while (1) {
        cout << "--------------------------------------------" << endl;
        cout << "Main Menu:" << endl;
        cout << "1. List all products" << endl;
        cout << "2. Add Packed Groceries" << endl;
        cout << "3. Add Fresh Groceries" << endl;
        cout << "4. Purchase" << endl;
        cout << "Your Choice: ";
        cin >> choice1;

        switch (choice1) {
        case 1:
            cout << "--------------------------------------------" << endl;
            cout << "\tList of all products:\t\t\t\t" << endl;
            cout << "Name \t\t\t\tUIC\t\t\tPrice " << endl;
            cout << "List of PACKED GROCERIES " << endl;
            cout << "juice\t\t\t\tj\t\t\t50 " << endl;
            cout << "chocolate \t\t\tc\t\t\t45 " << endl;
            cout << "Biscuit \t\t\tbi\t\t\t45 " << endl;
            
            cout << "--------------------------------------------" << endl;
            cout << "List of FRESH GROCERIES " << endl;
            cout << "Name \t\t\t\tUIC\t\t\tPrice " << endl;
            cout << "apple \t\t\t\ta\t\t\t20" << endl;
            cout << "banana \t\t\t\tb\t\t\t30 " << endl;
            cout << "mango \t\t\t\tm\t\t\t30 " << endl;
            cout << "--------------------------------------------" << endl;
            break;

        case 2:
            obj[i].packedfile();
            break;

        case 3:
            obj[i].freshfile();
            break;

        case 4:
            cout << "------------------------------------" << endl;
            cout << "Second Main Menu" << endl;
            cout << "1. Go to Packed Groceries" << endl;
            cout << "2. Go to Fresh Groceries" << endl;
            cout << "3. BILL" << endl;
            cout << "0. Go Back" << endl;
            cout << "Your Choice: ";
            cin >> choice2;
            switch (choice2) {
            case 1:
                obj[i].getdata();
                obj[i].setdata();
                totalBill += obj[i].calculateTotal();
                i++;
                break;

            case 2:
                obj[i].getdata();
                obj[i].setdata();
                totalBill += obj[i].calculateTotal();
                i++;
                break;

            case 3:
                cout << "Your total bill is: " << totalBill << endl;
                writeBill(totalBill);
                cout << "------------------------------------" << endl;
                cout << "Do you want to pay the bill?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "3. Display Bill" << endl;
                cout << "Your Choice: ";
                int payChoice;
                cin >> payChoice;
                switch (payChoice) {
                case 1:
                    cout << "Thank you for your payment. Your bill has been cleared." << endl;
                    totalBill = 0.0;
                    break;

                case 2:
                    cout << "Your bill is still pending. Please pay your bill soon." << endl;
                    break;

                case 3:
                    displayBill();
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                break;

            case 0:
                continue;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}

