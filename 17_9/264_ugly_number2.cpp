class Solution {
public:
    int nthUglyNumber(int n) {

        vector<long long> ugly(n);

        ugly[0] = 1;

        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        //each i produces one min numv=ber if one has already produced that increase its value

        for (int i = 1; i < n; i++) {

            long long a = ugly[i2] * 2;
            long long b = ugly[i3] * 3;
            long long c = ugly[i5] * 5;

            long long next = min({a, b, c});

            ugly[i] = next;

            if (next == a)
                i2++;

            if (next == b)
                i3++;

            if (next == c)
                i5++;
        }

        return ugly[n - 1];
    }
};
//METHOD 2
class Solution {
public:
    int nthUglyNumber(int n) {

        priority_queue<long long,
                       vector<long long>,
                       greater<long long>> pq;

        set<long long> st;

        pq.push(1);
        st.insert(1);

        long long num = 1;

        for (int i = 0; i < n; i++) {

            num = pq.top();
            pq.pop();

            long long a = num * 2;
            long long b = num * 3;
            long long c = num * 5;

            if (!st.count(a)) {
                pq.push(a);
                st.insert(a);
            }

            if (!st.count(b)) {
                pq.push(b);
                st.insert(b);
            }

            if (!st.count(c)) {
                pq.push(c);
                st.insert(c);
            }
        }

        return num;
    }
};