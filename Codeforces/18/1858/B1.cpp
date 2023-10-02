#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("B.in", "r", stdin);
    int tasks; cin >>tasks;
    while (tasks --) {
	    int n, m, d;
	    cin >> n >> m >> d;

	    vector<int> sellers(m);
	    for (int i = 0; i < m; ++i) {
	        cin >> sellers[i];
	    }

	    int min_cookies_eaten = n; // Initialize to a large value
	    int num_sellers_to_remove = 0;

	    for (int i = 0; i < m; ++i) {
	        int seller_position = sellers[i];
	        int prev_eaten = 0;
	        int cookies_eaten = 0;

	        for (int bench = 1; bench <= n; ++bench) {
	            int dist = abs(bench - seller_position);
	            if (bench == seller_position) {
	                cookies_eaten++;
	                prev_eaten = bench;
	            } else if (dist >= d && bench - prev_eaten >= d) {
	                cookies_eaten++;
	                prev_eaten = bench;
	            }
	        }

	        if (cookies_eaten < min_cookies_eaten) {
	            min_cookies_eaten = cookies_eaten;
	            num_sellers_to_remove = 1;
	        } else if (cookies_eaten == min_cookies_eaten) {
	            num_sellers_to_remove++;
	        }
	    }

	    cout << min_cookies_eaten << " " << num_sellers_to_remove << endl;
    }


    return 0;
}
