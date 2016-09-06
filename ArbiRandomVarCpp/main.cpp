#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void show_vec(vector<double> x) {
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

vector<double> arbirand(vector<string> symbol, vector<double>P, int n) {
    auto dist = cumsum(P);
    auto gen = nrand(n);
    auto res = nzeros(n);
    for (int k = 0; k < n; ++k) {
        size_t idx = n - 1;
        while (dist[idx]) {

        }
        
    }
}
int main() {
    double a[] = { 1,2,3,4,5 };
    vector<double> vec;
    vec.reserve(5);
    vec.insert(vec.begin(), &(a[0]), &(a[5]));
    show_vec(vec);
    //auto cvec=cumsum(vec);
    auto cvec = nrand(5);
    show_vec(cvec);
}