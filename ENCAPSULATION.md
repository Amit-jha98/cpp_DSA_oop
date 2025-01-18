# Encapsulation in C++: Complete Guide

## 1. What is Encapsulation?

Encapsulation is one of the four fundamental OOP concepts that:
- Bundles data and methods that work on that data within a single unit (class)
- Restricts direct access to some object's components
- Implements information hiding
- Controls how data is accessed or modified

## 2. Benefits of Encapsulation

1. **Data Hiding**
   - Protects internal state of objects
   - Prevents unauthorized access
   - Reduces system complexity

2. **Modularity**
   - Classes can be developed and updated independently
   - Changes in internal implementation don't affect other code

3. **Security**
   - Controlled access through public interface
   - Data validation before modification
   - Prevention of invalid state

## 3. Implementation Examples

### 3.1 Basic Encapsulation
```cpp
class BankAccount {
private:
    double balance;
    string accountNumber;
    string accountHolder;

public:
    // Constructor with validation
    BankAccount(string holder, string accNum, double initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
        accountHolder = holder;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Public interface methods
    double getBalance() const { return balance; }
    string getAccountHolder() const { return accountHolder; }
    
    // Controlled modification with validation
    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
};
```

### 3.2 Advanced Encapsulation Patterns

#### Data Validation Layer
```cpp
class UserProfile {
private:
    string email;
    string password;
    
    bool isValidEmail(const string& email) const {
        // Email validation logic
        return email.find('@') != string::npos;
    }
    
    bool isStrongPassword(const string& pwd) const {
        // Password strength check
        return pwd.length() >= 8;
    }

public:
    bool setEmail(const string& newEmail) {
        if (isValidEmail(newEmail)) {
            email = newEmail;
            return true;
        }
        return false;
    }
    
    bool setPassword(const string& newPassword) {
        if (isStrongPassword(newPassword)) {
            password = newPassword;
            return true;
        }
        return false;
    }
};
```

### 3.3 Nested Encapsulation
```cpp
class Library {
private:
    class Book {
    private:
        string isbn;
        bool isCheckedOut;
        
    public:
        Book(string id) : isbn(id), isCheckedOut(false) {}
        bool checkOut() {
            if (!isCheckedOut) {
                isCheckedOut = true;
                return true;
            }
            return false;
        }
    };
    
    vector<Book> books;
    
public:
    void addBook(string isbn) {
        books.emplace_back(isbn);
    }
    
    bool lendBook(int index) {
        if (index < books.size()) {
            return books[index].checkOut();
        }
        return false;
    }
};
```

## 4. Best Practices

### 4.1 Access Level Guidelines
1. Make data members private by default
2. Use protected only when inheritance requires access
3. Make public interface as minimal as possible

### 4.2 Getter/Setter Design
```cpp
class Employee {
private:
    string name;
    double salary;
    
public:
    // Const getter - read-only access
    const string& getName() const { return name; }
    
    // Setter with validation
    bool setSalary(double newSalary) {
        if (newSalary >= 0) {
            salary = newSalary;
            return true;
        }
        return false;
    }
};
```

### 4.3 Immutable Data Protection
```cpp
class Configuration {
private:
    const string SERVER_URL;
    const int MAX_CONNECTIONS;
    
public:
    Configuration(string url, int max) 
        : SERVER_URL(url), MAX_CONNECTIONS(max) {}
        
    string getServerUrl() const { return SERVER_URL; }
    int getMaxConnections() const { return MAX_CONNECTIONS; }
};
```

## 5. Common Patterns

### 5.1 Facade Pattern with Encapsulation
```cpp
class ComputerFacade {
private:
    class CPU {
        void freeze() {}
        void jump(long position) {}
        void execute() {}
    };
    
    class Memory {
        void load(long position, string data) {}
    };
    
    CPU cpu;
    Memory memory;
    
public:
    void start() {
        cpu.freeze();
        memory.load(0, "boot data");
        cpu.jump(0);
        cpu.execute();
    }
};
```

### 5.2 Builder Pattern with Encapsulation
```cpp
class Computer {
private:
    string cpu;
    int ram;
    string storage;
    
    // Private constructor enforces use of builder
    Computer() {}
    
    friend class ComputerBuilder;
    
public:
    class ComputerBuilder {
    private:
        Computer* computer;
        
    public:
        ComputerBuilder() { computer = new Computer(); }
        
        ComputerBuilder& setCPU(const string& cpu) {
            computer->cpu = cpu;
            return *this;
        }
        
        // More builder methods...
        
        Computer* build() { return computer; }
    };
};
```

## 6. Troubleshooting Common Issues

1. **Over-encapsulation**
   - Don't make everything private
   - Consider what really needs protection
   
2. **Under-encapsulation**
   - Avoid public data members
   - Don't expose internal implementation

3. **Performance Considerations**
   - Use references for getters of large objects
   - Consider inline functions for simple accessors

## Additional Resources
1. [C++ Encapsulation](https://en.cppreference.com/w/cpp/language/access)
2. [Design Patterns](https://refactoring.guru/design-patterns)
