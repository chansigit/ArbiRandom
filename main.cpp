#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

template<typename T>
void show_vec(vector<T> x) {
    for (size_t i = 0; i != x.size(); ++i)
        cout << x[i] << " ";
    cout << endl;
}

vector<double> cumsum(vector<double> x) {
    vector<double> ret;
    double cum = 0.0;
    for (size_t i = 0; i != x.size(); ++i) {
        cum += x[i];
        ret.push_back(cum);
    }
    return ret;
}

vector<double> nrand(int size) {
    vector<double> ret;
    while (size--) {
        ret.push_back(rand() / double(RAND_MAX));
    }
    return ret;
}

vector<double> nzeros(int size) {
    vector<double> ret;
    while (size--)
        ret.push_back(0.0);
    return ret;
}

template<typename T>
vector<T> arbirand(vector<T> symbol, vector<double>P, int n) {
    auto dist = cumsum(P);
    auto genrand = nrand(n);
    vector<T> res;
    //show_vec(dist);
    //show_vec(genrand);
    for (int k = 0; k < n; ++k) {
        int idx = symbol.size() - 1;
        //cout << "generated["<<k<<"] =" << genrand[k] << endl;
        //cout << "dist[" << idx << "]=" << dist[idx] << endl;
        while (idx != -1 && genrand[k] < dist[idx] ) {
            idx--;
        }
        res.push_back(symbol[idx + 1]);
    }
    return res;
}


template<typename T>
void check_arr(const vector<T>& symbol, const vector<T>& res) {
    for (int i = 0; i != symbol.size(); ++i) {
        int cnt = 0;
        for (int j = 0; j != res.size(); ++j) {
            if (symbol[i] == res[j])
                cnt++;
        }
        cout << symbol[i] << ":  "<<(double)cnt / res.size() << endl;
    }
}

int main() {
    srand(time(0));
    vector<string> symb = { "A","G","C","T" };
    vector<double> prob = { 0.1,0.3,0.4,0.2 };
    auto res= arbirand(symb, prob, 10000);
    //show_vec(res);
    check_arr(symb, res);

}