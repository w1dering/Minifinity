#include <iostream>
#include <vector>
#include <fstream>
#include "Node.h"

using namespace std;

vector<vector<char>> makeGrid();
void initialize(Node root);

vector<string> combine(vector<string> a, vector<string> b);

int main()
{
    // const int screenWidth = 500;
    // const int screenHeight = 500;
    Node root('!', false);
    // initialize(root);
    // InitWindow(screenWidth, screenHeight, "minifinity");

    // SetTargetFPS(60);
    // vector<vector<char>> grid = makeGrid();

    // while (WindowShouldClose() == false)
    // {
    //     BeginDrawing();
    //     ClearBackground(WHITE);
    //     EndDrawing();
    // }

    // CloseWindow();

    while (true)
    {
        string input;
        cin >> input;
        vector<string> v = root.retrieve(input);
        for (int i = 0; i < int(v.size()); i++)
        {
            cout << "printing v" << endl;
            cout << v[i] << endl;
        }
    }

    cout << "returned 0" << endl;
    return 0;
}

vector<vector<char>> makeGrid()
{
    int width = rand() % 3 + 4;
    int height = rand() % 3 + 4;
    vector<vector<char>> grid;
    for (int i = 0; i < height; i++) // initializes empty 2d vector of height rows and width cols
    {
        grid.push_back({}); // makes vectors
        for (int j = 0; j < width; j++)
        {
            if (rand() % 6 == 0)
            {
                grid[i].push_back('#'); // blocked square
            }
            else
            {
                grid[i].push_back(' '); // empty square
            }
        }
    }
    return {};
}

void initialize(Node root) // initializes tree to make for easier searching
{
    for (char c = 'A'; c <= 'Z'; c++)
    {
        ifstream wordFile;
        wordFile.open("words_" + string(1, c) + ".txt");
        string output;
        while (wordFile >> output)
        {
            Node currentNode = root;
            for (int i = 0; i < int(output.size()); i++)
            {
                bool isEnd = i == int(output.size()) - 1;
                Node tempNode(output[i], isEnd);
                if (isEnd)
                {
                    tempNode.setWord(output);
                }
                currentNode.addChild(tempNode);
                currentNode = tempNode;
            }
        }
    }
}

bool Node::addChild(Node n)
{
    if (n.isEndNode)
    {
        return false;
    }
    children[int(n.letter) - 65] = n;
    return true;
}

string Node::getWord()
{
    if (!isEndNode)
    {
        cout << "tried get wording a non-end node" << endl;
        return "";
    }
    return word;
}

bool Node::setWord(string s)
{
    if (!isEndNode)
    {
        cout << "tried set wording a non end node" << endl;
        return false;
    }
    word = s;
    return true;
}

vector<string> Node::retrieve(string s)
{
    cout << "on string " << s << endl;
    if (int(s.size()) == 0)
    {
        cout << "returning nothing" << endl;
        return {};
    }

    cout << "made it to candidates: s[0] is " << s[0] << endl;
    vector<string> candidates;
    cout << "past past candidates" << endl;
    if (s[0] == ' ') // open ended: check every child
    {
        cout << "space" << endl;
        for (int i = 0; i < 26; i++)
        {
            if (children[i].letter != '#')
            {
                cout << "not pound in space" << endl;
                if (children[i].isEndNode)
                {
                    cout << "pushed back" << endl;
                    candidates.push_back(children[i].getWord());
                }
                else
                {
                    cout << "delving deeper" << endl;
                    candidates = combine(candidates, children[i].retrieve(s.substr(1)));
                }
            }
        }
    }
    else if (children[s[0]].letter != '#')
    {
        cout << "not pound" << endl;
        if (children[s[0]].isEndNode)
        {
            cout << "returning getWord" << endl;
            return {children[s[0]].getWord()};
        }
        else
        {
            cout << "delving deeper not pound" << endl;
            candidates = combine(candidates, children[s[0]].retrieve(s.substr(1)));
        }
    }
    cout << "end return" << endl;
    return candidates;
}

vector<string> combine(vector<string> a, vector<string> b)
{
    for (int i = 0; i < int(b.size()); i++)
    {
        a.push_back(b[i]);
    }
    return a;
}