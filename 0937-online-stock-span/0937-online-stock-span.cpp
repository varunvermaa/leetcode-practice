class StockSpanner {
public:
    stack<pair<int, int>> s;

    StockSpanner() {}

    int next(int p) {

        int span = 1;

        while (!s.empty() && s.top().first <= p) {
            span += s.top().second;
            s.pop();
        }
        s.push({p, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */