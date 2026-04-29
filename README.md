# AuraOS Smart Kiosk System (Path A)

---

## 🧠 System Overview

The AuraOS Smart Kiosk System is a modular, object-oriented application designed to simulate a real-world automated vending kiosk. It enables users to browse products, add balance, and purchase items while dynamically adapting system behavior based on operational states.

The system is built using multiple Object-Oriented Design Patterns to ensure scalability, flexibility, and maintainability. It follows a clean modular architecture where each subsystem is responsible for a specific functionality such as inventory management, payment processing, user management, and persistence.

The kiosk operates under multiple system states such as Active, Emergency, Maintenance, and Power Saving. Instead of completely blocking operations, each state enforces specific purchase limits, making the system more realistic and user-friendly.

The system also ensures persistence by storing data in CSV files, allowing it to retain inventory, user balance, transactions, and configuration even after restart.

---

## ✨ Key Features

- Inventory Management System
- User Balance Management (Persistent)
- Transaction History Tracking
- Multiple System States with Purchase Limits
- Dynamic Pricing Strategies
- File-based Data Persistence (CSV)
- Modular Architecture using Design Patterns
- Command-based Operation Execution
- Event Monitoring using Observer Pattern

---

## 📂 Project Structure


```bash
AuraOS/
│
├── main.cpp
├── build.bat / build.ps1
├── inventory.csv
├── user.csv
├── transactions.csv
├── config.csv
│
├── command/
├── core/
├── factory/
├── failure/
├── inventory/
├── models/
├── observer/
├── payment/
├── pricing/
├── registry/
├── state/
```


---

## ⚙️ How to Run the Program

### 📌 Prerequisites

- `C++ Compiler (g++)`
- `Windows Command Prompt / Terminal`

---

### 🔨 Step 1: Build the Project

Run:


```bash
build
```



This compiles all `.cpp` files and generates:


```bash
kiosk.exe
```


---

### ▶️ Step 2: Run the Program


```bash
kiosk.exe
```


---

## 🧪 Basic Usage Flow

1. Add products to inventory  
2. Add balance to user  
3. View products  
4. Purchase items  
5. View transaction history  
6. Change system state  

---

## 🧩 Implemented Design Patterns

---

### 🔹 1. State Pattern

**Location:** `state/`

Controls kiosk behavior based on operational mode.

**States Implemented:**
- `ActiveState`  
- `EmergencyState`  
- `MaintenanceState`  
- `PowerSavingState`  

Each state defines purchase limits dynamically.

---

### 🔹 2. Strategy Pattern

**Location:** `pricing/`

Implements dynamic pricing logic.

**Strategies:**
- `StandardPricing`  
- `DiscountPricing`  
- `EmergencyPricing`  

---

### 🔹 3. Command Pattern

**Location:** `command/`

Encapsulates user actions as objects.

**Commands:**
- `PurchaseCommand`  
- `RefundCommand`  

---

### 🔹 4. Observer Pattern

**Location:** `observer/`

Enables event-driven system monitoring.

**Components:**
- `EventManager`  
- `Subscriber`  
- `MonitoringSystem`  

---

### 🔹 5. Factory Pattern

**Location:** `factory/`

Responsible for object creation.

**Component:**
- `KioskFactory`  

---

### 🔹 6. Failure Handling (Strategy-Based)

**Location:** `failure/`

Handles system failures using different recovery strategies.

**Handlers:**
- `RetryHandler` 
- `RecalibrationHandler`  
- `AlertHandler`  

---

### 🔹 7. Central Registry (Singleton Concept)

**Location:** `registry/`

Maintains global configuration and system state.

**Components:**
- `CentralRegistry`  
- `SystemConfig`  

---

## 💾 Data Persistence

The system stores data in CSV files:

- `inventory.csv` → Product data  
- `user.csv` → User balance  
- `transactions.csv` → Transaction history  
- `config.csv` → System configuration  

This ensures that data is retained across program restarts.

---

## 📸 Simulation Demonstration

---

### 🔹 Step 1: Start Program   

📸 Screenshot: 

<img width="875" height="747" alt="image" src="https://github.com/user-attachments/assets/4d9435a9-f45b-4394-95ef-4cce61b6d356" />

---

### 🔹 Step 2: Show Products    

📸 Screenshot: 

<img width="791" height="280" alt="image" src="https://github.com/user-attachments/assets/27832730-9f8b-4d07-b5ce-6c177c9e7de5" />

---

### 🔹 Step 3: Buy Product(in normal mode)    

📸 Screenshot:

<img width="739" height="436" alt="image" src="https://github.com/user-attachments/assets/2e0d7b36-383a-4bed-9419-95da06670304" />

---

### 🔹 Step 4: Activate Emergency Mode  

📸 Screenshot: 

<img width="606" height="164" alt="image" src="https://github.com/user-attachments/assets/1432ea7b-ede0-4d68-95aa-91c95ce302ff" />

---

### 🔹 Purchase Product(in emergency mode for dynamic pricing)  

📸 Screenshot:  

<img width="656" height="420" alt="image" src="https://github.com/user-attachments/assets/6c327e7b-4789-4427-877b-06bb3524084b" />

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

## 🏁 Conclusion

The AuraOS Smart Kiosk System demonstrates a well-structured and scalable software design using Object-Oriented Programming principles and multiple design patterns. It effectively simulates a real-world kiosk system with dynamic behavior, persistence, and modular architecture.

The project highlights strong design thinking, separation of concerns, and real-world applicability, making it a robust and extensible system.

---
