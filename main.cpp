#include <iostream>
#include <string>
#include <fstream>
#include <array>

using namespace std;


struct Node {
    array<array<int, 3>, 3> state;
    string action;
    int depth;
    Node* parent;
};

void parse_input(string file, array<array<int, 3>, 3>& state)
{
    // parse input files and return data in 2d array
    ifstream inputfile;
    inputfile.open(file);

    if (!inputfile.is_open())
    {
        cerr << "Error opening " << file << endl;
        return;
    }

    string line;
    int row = 0;
    int col = 0;

    while (getline(inputfile, line))
    {
        for (char c : line)
        {
            if (isdigit(c))
            {
                state[row][col] = c - '0';
                col += 1;

                if (col == 3)
                {
                    col = 0;
                    row += 1;
                }
            }
        }
    }
    return;
}




int main(int argc, char* argv[])
{
    //Extracting command line arguments
    string start_file = argv[1];
    string goal_file = argv[2];
    string method = "a*";
    bool dump_flag = false;

    for (int i = 3; i < argc; i++)
    {   
        string arg = argv[i];

        if (arg == "true")
        {   
            dump_flag = true;
        }
        else if (arg == "false")
        {
            dump_flag = false;
        }
        else
        {
            method = arg;
        }
    }

    array<array<int, 3>, 3> start_state;
    array<array<int, 3>, 3> goal_state;

    //parse input from given text files
    parse_input(start_file, start_state);
    parse_input(goal_file, goal_state);


    //Create start node
    Node start_node;
    start_node.state = start_state; 
    start_node.action = "Start";
    start_node.depth = 0;
    start_node.parent = nullptr;

    if (method == "bfs")
    { 
       // auto solution = conduct_bfs(start_node, goal_state, dump_flag);
       

    }

    else if (method == "a*")
    {
        //auto solution = conduct_astar(start_node, goal_state, dump_flag);
    }

    else if (method == "greedy")
    {
       // auto solution = conduct_greedy(start_node, goal_state, dump_flag);
    }
    


    return 0;
}