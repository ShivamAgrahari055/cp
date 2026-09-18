//133 clone the graph as it is
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp ;
    Node* cloneGraph(Node* node) {
            if(node == nullptr){
                return nullptr; 
            }
            if(mp.count(node)){
                return mp[node] ;
            }
            Node* copy = new Node(node->val);

            mp[node] = copy;
            for(Node* nei : node->neighbors){
                copy->neighbors.push_back(cloneGraph(nei)) ;
            }
            return copy ;

    }
};
//365 You are given two jugs with capacities x liters and y liters. You have an infinite water supply. Return whether the total amount of water in both jugs may reach target using the following operations:

// Fill either jug completely with water.
// Completely empty either jug.
// Pour water from one jug into another until the receiving jug is full, or the transferring jug is empty.
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y)
            return false;

        return target % gcd(x, y) == 0;
    }
};