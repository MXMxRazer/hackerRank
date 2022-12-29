// 4 3
// <tag1 value = "HelloWorld">
// <tag2 name = "Name1">
// </tag2>
// </tag1>
// tag1.tag2~name
// tag1~name
// tag1~value

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> splitter(string s, string delimitter)
{
    int start = 0, end = -1 * delimitter.size();
    string res;
    vector<string> tagList;
    do
    {
        start = delimitter.size() + end;
        end = s.find(delimitter, start);
        res = s.substr(start, end - start);
        tagList.push_back(res);
    } while (end != -1);

    return tagList;
}

int main()
{
    int HTML, HRML;

    cout << "Enter for HTML: " << endl;
    cin >> HTML;
    cout << "Enter for HRML: " << endl;
    cin >> HRML;

    string whole, temp;

    cout << "Enter HTML: " << endl;
    for (int i = 0; i < HTML + 1; i++)
    {
        getline(cin, temp);
        whole += temp + "\n";
    }

    string whole2, temp2;

    cout << "Enter HRML: " << endl;
    for (int i = 0; i < HRML; i++)
    {
        getline(cin, temp2);
        whole2 += temp2 + "\n";
    }

    int HRMLArray[HRML];
    vector<string> tagList = splitter(whole2, "\n");
    int i = 0;

    unordered_map<string, string> attrMap;

    while (i != tagList.size() - 1)
    {
        cout << tagList[i] << endl;
        cout << "-----------------------------" << endl;
        vector<string> vect = splitter(tagList[i], "~");
        vector<string> vect2 = splitter(vect[0], ".");
        const auto key = vect2[vect2.size() - 1];
        const auto value = vect[vect.size() - 1];
        attrMap.insert(make_pair(key, value));

        i++;
    }

    return 0;
}