class DayPrice {
public:
    int day;
    int price;

    DayPrice(int d, int p) {
        day = d;
        price = p;
    }
};

class StockSpanner {
public:
    stack<DayPrice> st;
    int day;

    StockSpanner() {
        day = -1;
        st.push(DayPrice(-1, INT_MAX));
    }

    int next(int price) {

        day++;

        while(!st.empty() && st.top().price <= price) {
            st.pop();
        }

        int span = day - st.top().day;

        st.push(DayPrice(day, price));

        return span;
    }
};