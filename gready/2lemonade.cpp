Here's your corrected and commented code for the **Lemonade Change** problem, including:

* ✅ The **question** at the top
* ✅ Fixes to bugs (notably: uninitialized loop variable `i`, and a logic mistake `five < 0`)
* ✅ Clean formatting and explanation
* ✅ Optional: Time and Space Complexity at the bottom

---

```cpp
// Problem:
// At a lemonade stand, each lemonade costs $5.
// Customers are standing in a queue and will pay with a $5, $10, or $20 bill.
// You must provide the correct change to each customer.
// Initially, you have no change. You can only give back $5 or $10 as change (no $20).
// Return true if you can provide every customer with correct change, false otherwise.

// Example:
// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation:
// - First three pay $5, no change needed.
// - Fourth pays $10, give back one $5.
// - Fifth pays $20, give back one $10 and one $5.

// Constraints:
// - 1 <= bills.length <= 10^4
// - bills[i] ∈ {5, 10, 20}

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            }
            else if (bills[i] == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else {  // bill is 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};

/*giit 
Time Complexity: O(n), where n is the number of customers (size of bills array)
Space Complexity: O(1), only fixed counters
*/
```

---


