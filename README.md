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

*(Insert screenshots in your report for each step below)*

---

### 🔹 Step 1: Start Program  
Display main menu  

📸 Screenshot: Main Menu  

---

### 🔹 Step 2: Add Product  
Add product details  

📸 Screenshot: Product Added  

---

### 🔹 Step 3: Add Balance  
Update user balance  

📸 Screenshot: Balance Updated  

---

### 🔹 Step 4: View Products  
Display inventory  

📸 Screenshot: Product List  

---

### 🔹 Step 5: Purchase Product  
Perform purchase with validations  

📸 Screenshot: Purchase Successful  

---

### 🔹 Step 6: View Transactions  
Display transaction history  

📸 Screenshot: Transaction History  

---

### 🔹 Step 7: Change State  
Switch system mode  

📸 Screenshot: State Change  

---

### 🔹 Step 8: Restart System  
Verify persistence  

📸 Screenshot: Persistent Data  

---

## 🏁 Conclusion

The AuraOS Smart Kiosk System demonstrates a well-structured and scalable software design using Object-Oriented Programming principles and multiple design patterns. It effectively simulates a real-world kiosk system with dynamic behavior, persistence, and modular architecture.

The project highlights strong design thinking, separation of concerns, and real-world applicability, making it a robust and extensible system.

---