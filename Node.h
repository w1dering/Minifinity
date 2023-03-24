#include <vector>
#include <iostream>

using namespace std;

class Node
{
private:
    string word;

public:
    char letter = '#';
    bool isEndNode = false;
    vector<Node> children;

    bool addChild(Node n);
    string getWord();
    bool setWord(string s);
    vector<string> retrieve(string s);

    Node(char c, bool endNode)
    {
        letter = c;
        isEndNode = endNode;
        if (!isEndNode)
        {
            children = {Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node(), Node()};
        }
    }

    Node()
    {
        letter = '#';
        isEndNode = false;
    }
};