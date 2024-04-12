#include "pch.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <tuple>

using namespace std;

/// 1: walkable
/// 0: not walkable
///
/// S: start
/// G: goal

char map[7][5] = {
	{'G', '0', '1', '1', '1' },
	{'1', '0', '1', '0', '1' },
	{'1', '1', '1', '0', '1' },
	{'1', '1', '0', 'S', '1' },
	{'1', '1', '1', '1', '1' },
	{'1', '1', '0', '1', '1' },
	{'1', '1', '1', '1', '1' }
};

public:
ASNode *conn;
int row, col;
int g,h,f;
char nodeName;
char value;

public:
ASNode(int _x, int _y, char _v, int _i)
{
    row = _x;
    col = _y;
    value = _v;
    nodeName = _i;
    g = 0;
    h = 0;
    f = 0;
}

ASNode* GetChildNodes(int childInRow, int childInCol, ASNode* parentNode);
ASNode* CreateNodeByIndex(int rowIndex, int colIndex, ASNode* parentNode);

static char uniqueName = 'a';
list<ASNode*> openList;
list<ASNode*> closeList;

tuple<int,int> GetGoalIndex(){
    int maxMapSizeRow = sizeof(map) / sizeof(map[0]);
    int maxMapSizeCol = sizeof(map[0]);

    for (int i = 0; i < maxMapSizeRow; i++)
    {
        for(int j = 0; j < maxMapSizeCol; j++)
        {
            if (map[i][j] == 'G')
            return make_tuple(i,j);
        }
    }
}

void DebugPrintList(list<ASNode*>& nodelist, string name)
{
    cout << name.c_str() << ":" << "\n";
    for (auto& ele : nodelist)
    {
        cout << "(" << ele->row << "," << ele->col << ")";
    }
    cout << "\n";
}

void ShowMap()
{
    int maxMapSizeRow = sizeof(map) / sizeof(map[0]);
    int maxMapSizeCol = sizeof(map[0]);

    cout << "\n===================================================" << endl;
    for(int i = 0; i < maxMapSizeRow; i++)
    {
        for(int j = 0; j < maxMapSizeCol; j++)
            cout << map[i][j];
        cout << endl;
    }
    cout << "\n===================================================" << endl;
}

void FindPath()
{
    int maxMapSizeRow = sizeof(map) / sizeof(map[0]);
    int maxMapSizeCol = sizeof(map[0]);

    if(openList.size() == 0)
    {
        cout << "no path exists." << endl;
        return;
    }

    ASNode* openNode = nullptr;

    int smallest_f = 10000;
    for(auto& op : openList)
    {
        if(op->f < smallest_f)
        {
            smallest_f = op->f;
            openNode = op;
        }
    }

    if(openNode != nullptr)
    {
        if(openNode->nodeName == 'G')
        {
            cout << "< Optimal Path (row, column)>" << "\n";
            while(openNode != nullptr)
            {
                cout << "(" << openNode->row << "," << openNode->col << ")";

                int rowind = openNode->row;
                int colind = openNode->col;

                map[rowind][colind] = '*';

                openNode = openNode->conn;
                if(openNode != nullptr)
                    cout << "<==";
            }
            ShowMap();
        }
        else
        {
            int rowInd = openNode->row;
            int colInd = openNode->col;

            ASNode* childNode;
            if(openNode->row - 1 >= 0)
            {
                int childIndRow = openNode->row - 1;
                int chileIndCol = openNode->col;

                childNode = GetChildNodes(childIndRow, chileIndCol, openNode);
            }

            if(openNode->row + 1 < maxMapSizeRow)
            {
                int childIndRow = openNode->row + 1;
                int childIndCol = openNode->col;

                childNode = GetChildNodes(childIndRow, childIndCol, openNode);
            }

            if (openNode->col + 1 < maxMapSizeCol)
            {
                int childIndRow = openNode->row;
                int childIndCol = openNode->col + 1; 

                childNode = GetChildNodes(childIndRow, childIndCol, openNode);
            }

            if (openNode->col - 1 >= 0)
            {
                int childIndRow = openNode->row;
                int childIndCol = openNode->col - 1; 

                childNode = GetChildNodes(childIndRow, childIndCol, openNode);
            }

            openList.remove_if([&](ASNode* node)
            {
                if(node->row == rowInd && node->col == colInd)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            });

            closeList.push_back(openNode);

            FindPath();
        }
    }
}

ASNode* GetchildNodes(int childInRow, int childInCol, ASNode* parentNode)
{
    auto it_open = find_if(openList.begin(), openList.end(), [&](ASNode* node)
    {
        if(node->row == childInRow && node->col == childIndCol)
        {
            return true;
        }
        else
        {
            return false;
        }
    });

    auto it_close = find_if(closeList.begin(), closeList.end(), [&](ASNode* node)
    {
        if(node->row == childInRow && node->col == childIndCol)
        {
            return true;
        }
        else
        {
            return false;
        }
    });

    if(it_open != openList.end())
    {
        if((*it_open)->g < parentNode->g + 1)
        {
            (*it_open)->g = parentNode->g + 1;
            parentNode->conn = (*it_open);
            (*it_open)->f = (*it_open)->g + (*it_open)->h;
        }

        return *it_open;
    }
    else if(it_close != closeList.end())
    {
        if((*it_close)->g < parentNode->g + 1)
        {
            (*it_close)->g = parentNode->g + 1;
            parentNode->conn = (*it_close);
            (*it_close)->f = (*it_close)->g + (*it_close)->h;
        }

        return *it_close;
    }
    else
	{
		ASNode* newNode = CreateNodeByIndex(childIndRow, childIndCol, parentNode);
		
		if (newNode != nullptr)
		{
			openList.push_back(newNode);
		}
		return newNode;
	}

	return nullptr;

}

ASNode* CreateNodeByIndex(int rowIndex, int colIndex, ASNode* parentNode)
{
	char val = map[rowIndex][colIndex];

	if (val == '0')
		return nullptr;

	ASNode* node = nullptr;
	if (val == 'G')
	{
		node = new ASNode(rowIndex, colIndex, 'G', 'G');
		node->g = parentNode->g + 1;
		node->h = 0;
		node->f = node->g;
		node->conn = parentNode;
	}
	else
	{
		node = new ASNode(rowIndex, colIndex, val, uniqueName++);
		node->g = parentNode->g + 1;

		auto inds = GetGoalIndex();
		int goalRowInd = get<0>(inds);
		int goalColInd = get<1>(inds);

		int h = abs(goalRowInd - rowIndex) + abs(goalColInd - colIndex);
		node->h = h;
		node->f = node->g + h;
		node->conn = parentNode;
	}

	return node;
}

int main()
{
	ShowMap();

	int startRowInd = 3;
	int startColInd = 3;

	ASNode* startNode = new ASNode(startRowInd, startColInd, 'S', 'S');

	//put open list first
	openList.push_back(startNode);

	FindPath();
}