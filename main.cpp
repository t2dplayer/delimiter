#include <iostream>
#include <locale>
#include <vector>

using std::cout, std::cin, std::locale;

struct Delimiter: std::ctype<char> {
    static const mask* make_table(std::string ds) {
        static std::vector<mask> v(classic_table(), classic_table() + table_size);
        for (auto mask: v) {
            mask &= ~space;
        }
        for (auto d: ds) {
            v[d] |= space;
        }
        return &v[0];
    }
    Delimiter(std::string ds, size_t refs = 0):
        ctype(make_table(ds), false, refs) {}
};


int main() {
    cin.tie(nullptr);
    cin.imbue(locale(cin.getloc(), new Delimiter(":")));
    std::string src, dst;
    int weight;
    while (cin >> src >> weight >> dst) {
        cout << src << " " << weight << " " << dst << '\n';
    }
    return 0;
}
