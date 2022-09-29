#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

string Print(const vector<int> &numbers)
{
  string output;
  for (int num : numbers)
  {
    output += std::to_string(num) + ",";
  }
  if (output.size() > 0)
    output.pop_back();
  return "[" + output + "]";
}

string Print(const vector<vector<int>> &input)
{
  string output;
  for (const auto &v1 : input)
  {
    output = output + Print(v1) + ",";
  }
  if (output.size() > 0)
    output.pop_back();
  return "[" + output + "]";
}

vector<int> ParseLineToVector(const string &input)
{
  vector<int> output;
  string str = input;
  str.erase(std::remove(str.begin(), str.end(), '['), str.end());
  str.erase(std::remove(str.begin(), str.end(), ']'), str.end());
  char_separator<char> sep(",");
  tokenizer<char_separator<char>> tokens(str, sep);
  for (const auto &token : tokens)
  {
    output.push_back(stoi(token));
  }
  return output;
}

vector<string> SplitLineIntoVectors(const string &input)
{
  stack<char> st;
  string curr;
  vector<string> output;
  for (char ch : input)
  {
    if (ch == '[')
    {
      st.push(ch);
    }
    else if (ch == ']')
    {
      st.pop();
      if (st.empty())
      {
        output.push_back(curr);
        curr = "";
      }
    }
    else if (st.size() > 0)
    {
      curr.append(1, ch);
    }
  }
  return output;
}

vector<vector<int>> ParseLineToVectorOfVectors(const string &input)
{
  vector<vector<int>> output;
  string in_norm = input;
  in_norm.pop_back();
  in_norm = in_norm.substr(1);
  vector<string> lines = SplitLineIntoVectors(in_norm);
  for (string line : lines)
  {
    output.push_back(ParseLineToVector(line));
  }
  return output;
}

unordered_set<string> BuildSet(const vector<vector<int>> &v1)
{
  unordered_set<string> s;
  for (auto vec : v1)
  {
    vector<int> tmp = vec;
    sort(tmp.begin(), tmp.end());
    s.insert(Print(tmp));
  }
  return s;
}

bool Compare(const vector<vector<int>> &v1, const vector<vector<int>> &v2)
{
  unordered_set<string> s1 = BuildSet(v1);
  unordered_set<string> s2 = BuildSet(v2);
  return s1 == s2;
}

bool Compare(const vector<int> &v1, const vector<int> &v2)
{
  return v1 == v2;
}

void Success()
{
  cout << "Result: Success" << endl;
}

// input: string
// output: string

bool checkOuputString(string expected_output, string actual_output, string input1)
{
  if (expected_output != actual_output)
  {
    cout << "Result: Failed" << endl;
    cout << "Input: " << input1 << endl;
    cout << "Expected Output: " << expected_output << endl;
    cout << "Actual Output: " << actual_output << endl;
    return true;
  }
  return false;
}

// input: string
// output: int

bool checkOuputInt(int expected_output, int actual_output, string input1)
{
  if (expected_output != actual_output)
  {
    cout << "Result: Failed" << endl;
    cout << "Input: " << input1 << endl;
    cout << "Expected Output: " << expected_output << endl;
    cout << "Actual Output: " << actual_output << endl;
    return true;
  }
  return false;
}

// input: string
// output: vector<int>

bool checkOuputIntVec(vector<int> expected_output, vector<int> actual_output, string input1)
{
  if (expected_output != actual_output)
  {
    cout << "Result: Failed" << endl;
    cout << "Input: " << input1 << endl;
    cout << "Expected Output: ";
    for (auto x : expected_output)
    {
      cout << x << " ";
    }
    cout << "\nActual Output: ";
    for (auto x : actual_output)
    {
      cout << x << " ";
    }
    return true;
  }
  return false;
}

// input: string
// output: vector<char>

bool checkOuputCharVec(vector<char> expected_output, vector<char> actual_output, string input1)
{
  if (expected_output != actual_output)
  {
    cout << "Result: Failed" << endl;
    cout << "Input: " << input1 << endl;
    cout << "Expected Output: ";
    for (auto x : expected_output)
    {
      cout << x << " ";
    }
    cout << "\nActual Output: ";
    for (auto x : actual_output)
    {
      cout << x << " ";
    }
    return true;
  }
  return false;
}

// input: string
// output: vector<string>

bool checkOuputCharVec(vector<string> expected_output, vector<string> actual_output, string input1)
{
  if (expected_output != actual_output)
  {
    cout << "Result: Failed" << endl;
    cout << "Input: " << input1 << endl;
    cout << "Expected Output: ";
    for (auto x : expected_output)
    {
      cout << x << " ";
    }
    cout << "\nActual Output: ";
    for (auto x : actual_output)
    {
      cout << x << " ";
    }
    return true;
  }
  return false;
}

// input: string
// output: vector<string>

bool checkOuputStringVec(vector<string> expected_output, vector<string> actual_output, string input1)
{
  if (expected_output != actual_output)
  {
    cout << "Result: Failed" << endl;
    cout << "Input: " << input1 << endl;
    cout << "Expected Output: ";
    for (auto x : expected_output)
    {
      cout << x << " ";
    }
    cout << "\nActual Output: ";
    for (auto x : actual_output)
    {
      cout << x << " ";
    }
    return true;
  }
  return false;
}

// To Remove all comma's from a string

void RemoveAllCommas(string &line)
{
  for (int i = 0, len = line.size(); i < len; i++)
  {
    if (line[i] == ',')
    {
      line.erase(i--, 1);
      len = line.size();
    }
  }
}

// To Remove double quotes from string
void RemoveDoubleQuotes(string &line)
{
  line.erase(remove(line.begin(), line.end(), '\"'), line.end());
}

// To Remove all punctuations from a string
void RemoveAllPunctInString(string &line)
{
  for (int i = 0, len = line.size(); i < len; i++)
  {
    if (ispunct(line[i]))
    {
      line.erase(i--, 1);
      len = line.size();
    }
  }
}

// To Remove all punctuations from a array
string RemoveAllPunctInArray(string line)
{
  for (int i = 0, len = line.size(); i < len; i++)
  {
    if (line[i] == '-')
      continue;
    if (ispunct(line[i]))
    {
      line[i] = ' ';
    }
  }
  return line;
}

void RemoveAllPunctInStringArray(string &line)
{
  for (int i = 0, len = line.size(); i < len; i++)
  {
    if (ispunct(line[i]))
    {
      line[i] = ' ';
    }
  }
}

string convertInttoBool(bool res)
{
  if (res)
  {
    return "true";
  }
  else
  {
    return "false";
  }
}

// Input: int, vector<vector<int>>
void parseIntAndVectorOfVector(string &line, int &s, vector<vector<int>> &nums)
{
  vector<int> temp1;
  replace(line.begin(), line.end(), ',', ' ');
  int index;
  string sub_str = " [";
  string sub_str1 = "] ";
  while ((index = line.find("[[")) != string::npos)
  {
    line.replace(index, sub_str.length(), sub_str);
  }
  while ((index = line.find("]]")) != string::npos)
  {
    line.replace(index, sub_str1.length(), sub_str1);
  }
  int start = 0, end = 0;
  for (int i = 0; i < line.size(); i++)
  {
    if (line[i] == '[')
    {
      start = i;
      stringstream ss(line.substr(0, i - 1));
      ss >> s;
    }
    if (line[i] == ']')
    {
      end = i - 1 - start;
      stringstream ss(line.substr(start + 1, end));
      int v;
      while (ss >> v)
      {
        temp1.push_back(v);
      }
      nums.push_back(temp1);
      temp1.clear();
    }
  }
}

// Input: vector<vector<int>>
void parseVectorOfVector(string &line, vector<vector<int>> &nums)
{
  vector<int> temp1;
  replace(line.begin(), line.end(), ',', ' ');
  int index;
  string sub_str = " [";
  string sub_str1 = "] ";
  while ((index = line.find("[[")) != string::npos)
  {
    line.replace(index, sub_str.length(), sub_str);
  }
  while ((index = line.find("]]")) != string::npos)
  {
    line.replace(index, sub_str1.length(), sub_str1);
  }
  int start = 0, end = 0;
  for (int i = 0; i < line.size(); i++)
  {
    if (line[i] == '[')
    {
      start = i;
    }
    if (line[i] == ']')
    {
      end = i - 1 - start;
      stringstream ss(line.substr(start + 1, end));
      int v;
      while (ss >> v)
      {
        temp1.push_back(v);
      }
      nums.push_back(temp1);
      temp1.clear();
    }
  }
}

// Input: string1, string2
void parseTwoStrings(string &line, string &s1, string &s2)
{
  vector<string> temp;
  string temp1 = "";
  stack<char> stk;
  replace(line.begin(), line.end(), ',', ' ');
  int start = 0, end = 0;
  for (int i = 0; i < line.size(); i++)
  {
    if (line[i] == '"' && stk.empty())
    {
      stk.push(line[i]);
      continue;
    }
    else if (line[i] == '"')
    {
      stk.pop();
      end = i - 1 - start;
      temp.push_back(temp1);
      temp1 = "";
    }
    else
    {
      temp1 += line[i];
    }
  }
  s1 = temp[0];
  s2 = temp[1];
  s2 = s2.substr(2);
}

// Input: vector<string sentence>
vector<string> parseVectorOfStringSentence(string line)
{
  vector<string> s1;
  string temp1 = "";
  stack<char> stk;
  line.erase(remove(line.begin(), line.end(), ','), line.end());
  line.erase(remove(line.begin(), line.end(), '['), line.end());
  line.erase(remove(line.begin(), line.end(), ']'), line.end());
  int start = 0, end = 0;
  for (int i = 0; i < line.size(); i++)
  {
    if (line[i] == '"' && stk.empty())
    {
      stk.push(line[i]);
      continue;
    }
    else if (line[i] == '"')
    {
      stk.pop();
      end = i - 1 - start;
      s1.push_back(temp1);
      temp1 = "";
    }
    else
    {
      temp1 += line[i];
    }
  }
  return s1;
}
