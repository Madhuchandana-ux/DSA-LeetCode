#include <stack>
#include <utility>

class StockSpanner {
private:
    // Stack stores pairs of {price, span}
    std::stack<std::pair<int, int>> st;

public:
    StockSpanner() {
        // Initialization if needed
    }
    
    int next(int price) {
        int span = 1;
        
        // Collapse all previous prices that are <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push the accumulated span for the current price
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */