# Aura Retail OS – Path A

## Project Overview

This project is a partial implementation of **Aura Retail OS**, a smart kiosk system designed using Object-Oriented Programming principles and design patterns.

The system simulates an **autonomous retail kiosk** where users can:

* View available products
* Purchase items
* Switch kiosk modes (Active / Emergency)
* Apply different pricing strategies dynamically

This implementation focuses on **Path A: Adaptive Autonomous System**, where the kiosk adapts its behavior based on system conditions.

---

## Features Implemented

### 1. Interactive Kiosk System

* Menu-driven interface
* User can perform multiple operations
* Real-time interaction with system

### 2. Product & Inventory Management

* Add and manage products
* Track product quantity
* Check product availability

### 3. Dynamic Pricing (Strategy Pattern)

* Standard Pricing
* Emergency Pricing (1.5× increase)

### 4. Kiosk Modes (State Pattern)

* Active Mode → Allows purchases
* Emergency Mode → Restricts purchases

### 5. Transaction Handling (Command Pattern)

* Purchase operation encapsulated as a command
* Supports execution of user requests

---

## Design Patterns Used

### Strategy Pattern

* `PricingStrategy`
* `StandardPricing`
* `EmergencyPricing`

Used to dynamically change pricing logic at runtime.

---

### State Pattern

* `KioskState`
* `ActiveState`
* `EmergencyState`

Controls kiosk behavior based on current state.

---

### Command Pattern

* `Command`
* `PurchaseCommand`

Encapsulates purchase operation as an object.

---

## Class Structure (Implemented)

* Product
* Inventory
* Kiosk
* Payment
* PricingStrategy (Interface + Implementations)
* KioskState (Interface + Implementations)
* Command (Interface + PurchaseCommand)

---

## How to Run the Program

### Step 1: Compile

```bash
g++ main.cpp -o kiosk
```

### Step 2: Run

```bash
./kiosk
```

---

## Sample Menu

```
===== KIOSK MENU =====
1. Show Products
2. Buy Product
3. Set Active Mode
4. Set Emergency Mode
5. Use Standard Pricing
6. Use Emergency Pricing
0. Exit
```

---

## Sample Output

```
Kiosk is in ACTIVE mode
Using STANDARD pricing
Final Price: 100
Processing payment...
Item dispensed successfully!
```

---

## Limitations

* No database or file storage (in-memory only)
* Payment system is simulated
* Limited error handling
* Single-user interaction only

---

## Future Enhancements

* Add Observer Pattern (Event System)
* Add Failure Handling (Chain of Responsibility)
* Implement persistent storage (JSON/CSV)
* Support concurrent transactions
* Add GUI interface

---

## Author / Team

* Developed as part of **IT620 – Object Oriented Programming Project**
* Path A Implementated by team **PolymorphRangers**

|Name         | StudentID|
|- |- |
|Dhrumil Doshi | 202512088 |
|Harsh Rathod |202512086 |
|Rohit Peswani | 202512115 |
|Parshwa Jain | 202512096 |

---

## Notes

This is a **prototype implementation** for Subtask 2.
The final system will include more modules and advanced features.

---
