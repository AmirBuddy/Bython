#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calc (string str, vector <pair<string, int>> &var) {
    int res = 0;
    string var_str1 = "";
    string var_str2 = "";
    int var1 = 0;
    int var2 = 0;
    int helper1 = 0;
    int helper2 = 0;
    for (int i = 0; i < str.length();) {
        while (str[i] != ' ' && helper1 == 0) {
            var_str1 += str[i];
            i++;
        }
        if (str[i] == ' ') {
            helper1++;
            i++;
            continue;
        }
        if (helper1 == 2) {
            var_str2 += str[i];
            i++;
            continue;
        }
        i++;
    }
    helper1 = 0;
    for (int i = 0; i < var.size(); i++) {
        if (var[i].first == var_str1) {
            var1 = var[i].second;
            helper1 = 1;
        }
        if (var[i].first == var_str2) {
            var2 = var[i].second;
            helper2 = 1;
        }
    }
    if (helper1 == 0) {
        var1 = stoi(var_str1);
    }
    if (helper2 == 0) {
        var2 = stoi(var_str2);
    }

    if (str.find(" + ") != string::npos) {
        res = var1 + var2;
    }
    if (str.find(" - ") != string::npos) {
        res = var1 - var2;
    }
    return res;
}

void simple_assignment (string line, vector <pair<string, int>> &var) {
    string var_str1 = "";
    string var_str2 = "";
    int var2 = 0;
    int helper = 0;
    for (int i = 0; i < line.length();) {
        while (line[i] != ' ' && helper == 0) {
            var_str1 += line[i];
            i++;
        }
        if (line[i] == ' ') {
            helper++;
            i++;
            continue;
        }
        if (helper == 2) {
            var_str2 += line[i];
            i++;
            continue;
        }
        i++;
    }

    helper = 0;
    for (int i = 0; i < var.size(); i++) {
        if (var[i].first == var_str2) {
            var2 = var[i].second;
            helper = 1;
        }
    }
    if (helper == 0) {
        var2 = stoi(var_str2);
    }

    helper = 0;
    for (int i = 0; i < var.size(); i++) {
        if (var[i].first == var_str1) {
            var[i].second = var2;
            helper = 1;
        }
    }
    if (helper == 0) {
        var.push_back(make_pair(var_str1, var2));
    }
}

void calc_assignment (string line, vector <pair<string, int>> &var) {
    string var_str1 = "";
    string var_str2 = "";
    int helper = 0;
    for (int i = 0; i < line.length();) {
        while (line[i] != ' ' && helper == 0) {
            var_str1 += line[i];
            i++;
        }
        if (line[i] == ' ' && helper < 2) {
            helper++;
            i++;
            continue;
        }
        if (helper == 2) {
            var_str2 += line[i];
            i++;
            continue;
        }
        i++;
    }
    helper = 0;
    for (int i = 0; i < var.size(); i++) {
        if (var[i].first == var_str1) {
            var[i].second = calc(var_str2, var);
            helper = 1;
        }
    }
    if (helper == 0) {
        var.push_back(make_pair(var_str1, calc(var_str2, var)));
    }
}

void voroodi (string line, vector <pair<string, int>> &var, string input_line) {
    string var_str1 = "";
    int helper = 0;
    for (int i = 0; i < line.length();) {
        while (line[i] != ' ') {
            var_str1 += line[i];
            i++;
        }
        if (line[i] == ' ') {
            break;
        }
    }
    for (int i = 0; i < var.size(); i++) {
        if (var[i].first == var_str1) {
            var[i].second = stoi(input_line);
            helper = 1;
        }
    }
    if (helper == 0) {
        var.push_back(make_pair(var_str1, stoi(input_line)));
    }
}

void khorooji (string line, vector <pair<string, int>> &var) {
    string str = "";
    string elem = "";
    int helper = 0;
    for (int i = 10; i < line.length() - 1; i++) 
        str += line[i];
    vector <string> elements {};
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ',') {
            elem += str[i];
            if (i == str.length() - 1) {
                elements.push_back(elem);
                continue;
            }
            else {
                continue;
            }
        }
        if (str[i] == ',' && str[i + 1] == ' ') {
            elements.push_back(elem);
            elem = "";
            i++;
            continue;
        }
    }
    for (int i = 0; i < elements.size(); i++) {
        for (int j = 0; j < var.size(); j++) {
            if (elements[i] == var[j].first) {
                cout << var[j].second << " ";
                helper = 1;
                break;
            }
        }
        if (helper == 0) {
            cout << elements[i] << " ";
            continue;
        }
        helper = 0;
    }
    cout << endl;
}

bool condition (string str, vector <pair<string, int>> &var) {
    string var_str1 = "";
    string var_str2 = "";
    int var1 = 0;
    int var2 = 0;
    int helper1 = 0;
    int helper2 = 0;
    for (int i = 0; i < str.length();) {
        while (str[i] != ' ' && helper1 == 0) {
            var_str1 += str[i];
            i++;
        }
        if (str[i] == ' ') {
            helper1++;
            i++;
            continue;
        }
        if (helper1 == 2) {
            var_str2 += str[i];
            i++;
            continue;
        }
        i++;
    }
    helper1 = 0;
    for (int i = 0; i < var.size(); i++) {
        if (var[i].first == var_str1) {
            var1 = var[i].second;
            helper1 = 1;
        }
        if (var[i].first == var_str2) {
            var2 = var[i].second;
            helper2 = 1;
        }
    }
    if (helper1 == 0) {
        var1 = stoi(var_str1);
    }
    if (helper2 == 0) {
        var2 = stoi(var_str2);
    }
    if (var1 == var2)
        return true;
    else
        return false;
}

void check (string str, vector <pair<string, int>> &var) {
    if (!(str.find("voroodi()") != string::npos) && 
        !(str.find(" + ") != string::npos) && 
        !(str.find(" - ") != string::npos) && 
        !(str.find(" == ") != string::npos) &&
        (str.find(" = ") != string::npos)) 
    {
        simple_assignment(str, var);
    }
    else if ((str.find(" = ") != string::npos) && 
             ((str.find(" + ") != string::npos) || (str.find(" - ") != string::npos)) && 
             !(str.find(" == ") != string::npos)) 
    {
        calc_assignment(str, var);
    }
}

void agar (string line, vector <pair<string, int>> &var) {
    string str = "";
    string sub_str1 = "";
    string sub_srt2 = "";
    int helper = 0;
    for (int i = 5; i < line.length(); i++) 
        str += line[i];
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ')
            helper++;
        if (helper < 3) {
            sub_str1 += str[i];
            continue;
        }
        if (helper == 4 && str[i] == ' ')
            continue;
        if (helper >= 4) {
            sub_srt2 += str[i];
            continue;
        }
    }
    if (condition(sub_str1, var)) {
        check(sub_srt2, var);
    }
    else
        return;
}

int main () {
    vector <string> code_line {};
    string line;
    string input_line;
    int checkpoint = 0;
    int inputs = 0; bool flag = false;
    for (int i = 0; true; i++) {
        getline(cin, line);
        code_line.push_back(line);
        if (line.find("voroodi()") != string::npos) {
            inputs++;
        }
        if (line.find("--") != string::npos) {
            checkpoint = i;
            flag = true;
            if (inputs == 0)
                break;
            continue;
        }
        if (flag == true) {
            inputs--;
            if (inputs == 0)
                break;
        }
    }
    vector <pair<string, int>> var {};
    for (int i = 0; i < code_line.size(); i++) {
        line = code_line[i];
        if (!(line.find("voroodi()") != string::npos) && 
            !(line.find(" + ") != string::npos) && 
            !(line.find(" - ") != string::npos) && 
            !(line.find(" == ") != string::npos) &&
            (line.find(" = ") != string::npos)) 
        {
            simple_assignment(line, var);
        }
        else if (line.find("voroodi()") != string::npos) {
            inputs++;
            input_line = code_line[checkpoint + inputs];
            voroodi(line, var, input_line);
        }
        else if ((line.find(" = ") != string::npos) && 
                 ((line.find(" + ") != string::npos) || (line.find(" - ") != string::npos)) && 
                 !(line.find(" == ") != string::npos)) 
        {
            calc_assignment(line, var);
        }
        else if (line.find("khorooji") != string::npos) {
            khorooji(line, var);
        }
        else if (line.find("agar ") != string::npos) {
            agar(line, var);
        }
    }
    cout << var.size() << endl;
    // for (int i = 0; i < var.size(); i++)
    //     cout << var[i].first << " = " << var[i].second << endl;

    // for (int i = 0; i < code_line.size(); i++)
    //     cout << code_line[i] << endl;
    // system("pause");
    return 0;
}
