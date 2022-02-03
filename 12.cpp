#include <vector>
#include <iostream>

using namespace std;

int itc_len(string str) {
    int a = 0;
    while (str[a] != '\0') a++;
    return a;
}

int pow(int n, int i) {
    if (i == 0) return 1;
    else return n * pow(n, i - 1);
}

int string_to_int(string str){
    int ste = int(itc_len(str));
    int ans = 0;
    for (int i = 0; i < itc_len(str); i++) {
        ans += (str[i] - 48) * pow(10, ste - 1);
        ste--;
    }
    return ans;
}


bool is_sorted(vector<int> &v) {
    if (v.size() > 1) {
        for (int i = 0; i < v.size() - 1; i++) if (v[i + 1] < v[i]) return false;
    }
    return true;
}

void s(vector<int> &v) {
    if(v.size() > 1) {
        int tmp = v[0];
        v[0] = v[1];
        v[1] = tmp;
    }
}

void rr(vector <int> &v) {
    if (v.size() > 1) {
        int tmp = v[v.size() - 1];
        for (int i = int(v.size()) - 1; i > 0; i--) {
            v[i] = v[i - 1];
        }
        v[0] = tmp;
    }
}

void r(vector <int> &v) {
    if (v.size() > 1) {
        int tmp = v[0];
        for (int i = 0; i < v.size() - 1; i++) {
            v[i] = v[i + 1];
        }
        v[v.size() - 1] = tmp;
    }
}

void p(vector <int> &v_to, vector <int> &v_from) {
    if (!v_from.empty()) {
        v_to.push_back(v_from[0]);
        rr(v_to);
        r(v_from);
        v_from.pop_back();
    }
}

void initialize_a(vector<int> &a, string nums) {
    string n = "";
    for (int i = 0; nums[i] != '\0'; i++) {
        if (nums[i] != ' ') {
            n += nums[i];
        }
        else {
            a.push_back(string_to_int(n));
            n = "";
        }
    }
    a.push_back(string_to_int(n));
}

vector<string> commands_to_mass(int argc, char *argv[]) {
    vector<string> commands;
    string command = "";
    if (argc < 3) {
        getline(cin, command);
    }
    else command = argv[2];
    string c = "";
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] != ' ') {
            c += command[i];
        }
        else {
            commands.push_back(c);
            c = "";
        }
    }
    commands.push_back(c);
    return commands;
}

void start(vector<int> &a, vector<int> &b, vector<string> commands) {
    for (int j = 0; j < commands.size(); j++) {
        if (commands[j] == "sa") s(a);
        if (commands[j] == "sb") s(b);
        if (commands[j] == "ss") {
            s(a);
            s(b);}
        if (commands[j] == "ra") r(a);
        if (commands[j] == "rb") r(b);
        if (commands[j] == "rr") {
            r(a);
            r(b);}
        if (commands[j] == "rra") rr(a);
        if (commands[j] == "rrb") rr(b);
        if (commands[j] == "rrr") {
            rr(a);
            rr(b);}
        if (commands[j] == "pa") p(a, b);
        if (commands[j] == "pb") p(b, a);
    }
}


void out(vector<int> &a, vector<int> &b) {

    if (is_sorted(a) && b.empty()) {
        cout << "OK";
    }
    else if (!b.empty()) {
        cout << "KO" << endl;
    }
    else {
        cout << "KO" << endl;

    }
}


int main(int argc, char *argv[]) {
    vector<int> a;
    vector<int> b;
    string nums;
    getline(cin, nums);
    if (argc == 1) initialize_a(a, nums);
    else initialize_a(a, argv[1]);
    start(a, b, commands_to_mass(argc, argv));
    out(a, b);
    return 0;
}
