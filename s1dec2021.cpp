#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> findMax(vector<pair<int, int>> vec)
{
    int max = INT_MIN;
    pair<int, int> maxIndex = make_pair(0, 0);
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i).first > max)
        {
            max = vec.at(i).first;
            maxIndex.first = i;
            maxIndex.second = 1;
        }
        if (vec.at(i).second > max)
        {
            max = vec.at(i).second;
            maxIndex.first = i;
            maxIndex.second = 2;
        }
    }
    return maxIndex;
}

int main()
{
    int k, m, n;
    scanf("%d %d %d", &k, &m, &n);
    vector<pair<int, int>> patches;
    vector<int> nhojCows;
    int max = INT_MIN;

    for (int i = 0; i < k; i++)
    {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        if (temp1 > max)
        {
            max = temp1;
        }
        patches.push_back(make_pair(temp1, temp2));
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        scanf("%d", &temp);
        nhojCows.push_back(temp);
    }

    sort(nhojCows.begin(), nhojCows.end());

    vector<pair<int, int>> line(max + 1);
    for (int i = 0; i < k; i++)
    {
        line[patches.at(i).first].first = 1;
        line[patches.at(i).first].second = patches.at(i).second;
    }

    vector<pair<vector<int>, vector<int>>> patchesLeftRight(m);
    vector<pair<int, int>> leftRightTastinessM(m, make_pair(0, 0));
    for (int i = 0; i < m; i++)
    {
        int pointer = nhojCows.at(i);
        if (i != m - 1)
        {
            int rightBound = nhojCows.at(i + 1);
            while (pointer < rightBound)
            {
                if (line.at(pointer).first == 1)
                {
                    leftRightTastinessM.at(i).second += line.at(pointer).second;
                    patchesLeftRight.at(i).second.push_back(pointer);
                }
                pointer++;
            }
        }
        else
        {
            int pointer = nhojCows.at(i);
            while (pointer <= max)
            {
                if (line.at(pointer).first == 1)
                {
                    leftRightTastinessM.at(i).second += line.at(pointer).second;
                    patchesLeftRight.at(i).second.push_back(pointer);
                }
                pointer++;
            }
        }
        if (i != 0)
        {
            int pointer = nhojCows.at(i);
            int leftBound = nhojCows.at(i - 1);
            while (pointer > leftBound)
            {
                if (line.at(pointer).first == 1)
                {
                    leftRightTastinessM.at(i).first += line.at(pointer).second;
                    patchesLeftRight.at(i).first.push_back(pointer);
                }
                pointer--;
            }
        }
        else
        {
            int pointer = nhojCows.at(i);
            while (pointer >= 0)
            {
                if (line.at(pointer).first == 1)
                {
                    leftRightTastinessM.at(i).first += line.at(pointer).second;
                    patchesLeftRight.at(i).first.push_back(pointer);
                }
                pointer--;
            }
        }
    }
    //DEBUG--------------------------------------------------------------------
    //PASSED
    // for (int i = 0; i < m; i ++) {
    //     cout << leftRightTastinessM.at(i).first << " " << leftRightTastinessM.at(i).second << " ";
    // }
    // cout << "\n";
    //DEBUG--------------------------------------------------------------------
    //PASSED
    // for (int i = 0; i < patchesLeftRight.size(); i++) {
    //     cout << "Patch " << i + 1 << ":\n";

    //     // Print elements in the first vector (left side)
    //     cout << "  Left: ";
    //     for (int j = 0; j < patchesLeftRight[i].first.size(); j++) {
    //         cout << patchesLeftRight[i].first[j] << " ";
    //     }
    //     cout << "\n";

    //     // Print elements in the second vector (right side)
    //     cout << "  Right: ";
    //     for (int j = 0; j < patchesLeftRight[i].second.size(); j++) {
    //         cout << patchesLeftRight[i].second[j] << " ";
    //     }
    //     cout << "\n";
    // }    

    cout << "\n";
    int sum = 0;
    vector<bool> taken(max + 1);
    int counter = 0;
    while (counter < n)
    {
        pair<int, int> lol = findMax(leftRightTastinessM);
        bool sec = false;
        if (lol.second == 2)
        {
            sec = true;
        }
        bool proceed = true;
        if (sec)
        {
            for (int j = 0; j < patchesLeftRight.at(lol.first).second.size(); j++)
            {
                if (taken.at(patchesLeftRight.at(lol.first).second.at(j)) == true)
                {
                    proceed = false;
                    break;
                }
            }
            if (proceed)
            {
                for (int j = 0; j < patchesLeftRight.at(lol.first).second.size(); j++)
                {
                    taken.at(patchesLeftRight.at(lol.first).second.at(j)) = true;
                }
                //DEBUG
                // for (int x = 0; x < max + 1; x++) {
                //     cout << taken.at(x) << " "; 
                // }
                // cout << "\n";
                // sum += leftRightTastinessM.at(lol.first).second;
                // cout << leftRightTastinessM.at(lol.first).second << "\n";
                // cout << "lol" << "\n";
                leftRightTastinessM.at(lol.first).second = INT_MIN;
                counter++;
            }
        }
        else
        {
            for (int j = 0; j < patchesLeftRight.at(lol.first).first.size(); j++)
            {
                if (taken.at(patchesLeftRight.at(lol.first).first.at(j)) == true)
                {
                    proceed = false;
                    break;
                }
                if (proceed)
                {
                    for (int j = 0; j < patchesLeftRight.at(lol.first).first.size(); j++)
                    {
                        taken.at(patchesLeftRight.at(lol.first).first.at(j)) = true;
                    }
                    sum += leftRightTastinessM.at(lol.first).first;
                    // for (int x = 0; x < max + 1; x++) {
                    //     cout << taken.at(x) << " "; 
                    // }
                    // cout << leftRightTastinessM.at(lol.first).second << "\n";
                    // cout << "zs" << "\n";
                    leftRightTastinessM.at(lol.first).first = INT_MIN;
                    counter++;
                }
            }
        }
       
    }
    printf("%d", sum);
}