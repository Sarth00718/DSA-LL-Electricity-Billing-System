# ⚡ Torrent Power Billing System (DSA Project)

This is a C++ console application for managing consumer electricity billing, developed using core Data Structures like Linked Lists. It allows for maintaining consumer records, adding monthly electricity bills, and generating bills with history.

## 📌 Project Features

1. ➕ **Add New Consumer**  
   Store new consumer details like name, address, and contact number.

2. 📄 **Add Bill for a Consumer**  
   Add monthly electricity bill data (month, year, units used) and automatically calculate total amount.

3. 📊 **Generate and Display Bill**  
   Display bill for a specific month and year, along with previous 3 months' bill data.

4. 👥 **Display All Consumers**  
   View list of all registered consumers with their details.

5. ❌ **Exit**  
   Close the application safely.

---

## 🧠 Data Structures Used

- **Singly Linked List**:  
  - To manage consumers.  
  - Each consumer has a separate linked list of bills (nested structure).

---

## 🛠️ How It Works

- The program runs in a loop offering a menu-based system.
- For each consumer, the bills are stored in a separate linked list (`bill* bhead`).
- Bills are added to the front (most recent first).
- While generating a bill, the last 3 bills are found by traversing this list.

---
