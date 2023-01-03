#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    Node* left;
    Node* right;
};

Node* build_tree(int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<Node*> nodes;
    for (int i = 1; i <= n; i++) {
        Node* node = new Node;
        node->left = nullptr;
        node->right = nullptr;
        nodes.push_back(node);
    }

    for (auto edge : edges) {
        int parent = edge.first;
        int child = edge.second;
        if (nodes[parent - 1]->left == nullptr) {
            nodes[parent - 1]->left = nodes[child - 1];
        } else {
            nodes[parent - 1]->right = nodes[child - 1];
        }
    }

    return nodes[0];
}


std::vector<bool> children_bool_vector(Node* node1, Node* node2) {
    std::vector<bool> childs;
    if (node1->left != nullptr) {
        childs.push_back(true);
    } else {
        childs.push_back(false);
    }

    if (node1->right != nullptr) {
        childs.push_back(true);
    } else {
        childs.push_back(false);
    }

    if (node2->left != nullptr) {
        childs.push_back(true);
    } else {
        childs.push_back(false);
    }

    if (node2->right != nullptr) {
        childs.push_back(true);
    } else {
        childs.push_back(false);
    }

    return childs;
}

int dfs(Node* root1, Node* root2) {
    int vertices = 0;
    std::vector<bool> childs = children_bool_vector(root1, root2);

    if (!any_of(childs.begin(), childs.end(), [](bool x) { return x; })) {
        return vertices + 1;
    }

    if (all_of(childs.begin(), childs.end(), [](bool x) { return x; })) {
        vertices = std::max(
                dfs(root1->left, root2->left) +
                dfs(root1->right, root2->right),
                dfs(root1->left, root2->right) +
                dfs(root1->right, root2->left)
        );
    }

    if (childs == std::vector<bool>{false, true, true, true}) {
        vertices = std::max(
                dfs(root1->right, root2->left),
                dfs(root1->right, root2->right)
        );
    }

    if (childs == std::vector<bool>{true, false, true, true}) {
        vertices = std::max(
                dfs(root1->left, root2->left),
                dfs(root1->left, root2->right)
        );
    }

    if (childs == std::vector<bool>{true, true, false, true}) {
        vertices = std::max(
                dfs(root1->left, root2->right),
                dfs(root1->right, root2->right)
        );
    }

    if (childs == std::vector<bool>{true, true, true, false}) {
        vertices = std::max(
                dfs(root1->left, root2->left),
                dfs(root1->right, root2->left)
        );
    }

    if (childs == std::vector<bool>{true, false, true, false}) {
        vertices = dfs(root1->left, root2->left);
    }

    if (childs == std::vector<bool>{false, true, true, false}) {
        vertices = dfs(root1->right, root2->left);
    }

    if (childs == std::vector<bool>{false, true, false, true}) {
        vertices = dfs(root1->right, root2->right);
    }

    if (childs == std::vector<bool>{true, false, false, true}) {
        vertices = dfs(root1->left, root2->right);

    }

    return vertices + 1;

}


int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int parent, child;
        std::cin >> parent >> child;
        edges.emplace_back(std::make_pair(parent, child));
    }
    Node* root1 = build_tree(n, edges);

    std::cin >> n;
    edges.clear();
    for (int i = 0; i < n - 1; i++) {
        int parent, child;
        std::cin >> parent >> child;
        edges.emplace_back(std::make_pair(parent, child));
    }
    Node* root2 = build_tree(n, edges);

    std::cout << dfs(root1, root2) << std::endl;

    return 0;
}
