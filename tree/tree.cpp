/*1, Дано корені двох бінарних дерев p і q, напишіть функцію, щоб перевірити, чи вони однакові.*/





/*


#include <iostream>
#include <queue>

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Функція для перевірки, чи два бінарних дерева однакові
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;  // Обидва дерева порожні, тому вони однакові
    }
    if (!p || !q) {
        return false;  // Одне з дерев порожнє, а інше ні - вони не однакові
    }

    // Обхід дерев в ширину (BFS) для порівняння вузлів
    std::queue<TreeNode*> queueP, queueQ;
    queueP.push(p);
    queueQ.push(q);

    while (!queueP.empty() && !queueQ.empty()) {
        TreeNode* nodeP = queueP.front();
        TreeNode* nodeQ = queueQ.front();
        queueP.pop();
        queueQ.pop();

        if (nodeP->val != nodeQ->val) {
            return false;  // Значення вузлів не однакові
        }

        // Додавання лівих та правих дітей в чергу для подальшого порівняння
        if (nodeP->left) {
            queueP.push(nodeP->left);
        }
        if (nodeQ->left) {
            queueQ.push(nodeQ->left);
        }
        if (nodeP->right) {
            queueP.push(nodeP->right);
        }
        if (nodeQ->right) {
            queueQ.push(nodeQ->right);
        }
    }

    // Перевірка, чи обидва дерева оброблені повністю
    return queueP.empty() && queueQ.empty();
}

int main() {
    // Створення тестових дерев
    TreeNode* treeP = new TreeNode(1);
    treeP->left = new TreeNode(2);
    treeP->right = new TreeNode(3);

    TreeNode* treeQ = new TreeNode(1);
    treeQ->left = new TreeNode(2);
    treeQ->right = new TreeNode(3);

    // Виклик функції та вивід результату
    bool result = isSameTree(treeP, treeQ);
    std::cout << "Output: " << (result ? "true" : "false") << std::endl;

    // Звільнення пам'яті
    delete treeP->left;
    delete treeP->right;
    delete treeP;

    delete treeQ->left;
    delete treeQ->right;
    delete treeQ;

    return 0;
}


*/





/*2, Дано root бінарного дерева, перевірте, чи є він дзеркалом самого себе 
(тобто симетричним відносно свого центру).*/




/*

#include <iostream>
#include <queue>

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Допоміжна функція для перевірки, чи два піддерева є дзеркальними
bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
    if (!leftSubtree && !rightSubtree) {
        return true;  // Обидва піддерева порожні, тому вони дзеркальні
    }
    if (!leftSubtree || !rightSubtree) {
        return false;  // Одне з піддерев порожнє, а інше ні - вони не дзеркальні
    }
    // Перевірка, чи значення вузлів однакові, а також дзеркальність їхніх лівих і правих піддерев
    return (leftSubtree->val == rightSubtree->val) &&
           isMirror(leftSubtree->left, rightSubtree->right) &&
           isMirror(leftSubtree->right, rightSubtree->left);
}

// Функція для перевірки, чи дерево є дзеркальним
bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;  // Порожнє дерево вважається дзеркальним
    }
    return isMirror(root->left, root->right);
}

int main() {
    // Створення тестового дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Виклик функції та вивід результату
    bool result = isSymmetric(root);
    std::cout << "Output: " << (result ? "true" : "false") << std::endl;

    // Звільнення пам'яті
    delete root->left->left;
    delete root->left->right;
    delete root->left;

    delete root->right->left;
    delete root->right->right;
    delete root->right;

    delete root;

    return 0;
}


*/






/*3, Маючи корінь бінарного дерева, інвертувати дерево та повернути його корінь.*/



/*

#include <iostream>

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Функція для інверсії бінарного дерева
TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;  // Порожнє дерево
    }

    // Обміняти ліве і праве піддерева
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Рекурсивно інвертувати ліве і праве піддерева
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Функція для виведення значень вузлів бінарного дерева (обхід у порядку "вглибину")
void printTree(TreeNode* root) {
    if (root) {
        std::cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
    // Створення тестового дерева
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Виклик функції для інверсії та вивід результату
    TreeNode* invertedRoot = invertTree(root);
    std::cout << "Output: ";
    printTree(invertedRoot);

    // Звільнення пам'яті
    delete root->left->left;
    delete root->left->right;
    delete root->left;

    delete root->right->left;
    delete root->right->right;
    delete root->right;

    delete root;

    return 0;
}



*/





/*4, Враховуючи корінь бінарного дерева пошуку та ціле число k, 
поверніть k-те найменше значення (з індексом 1) усіх значень вузлів у дереві.*/





/*


#include <iostream>
#include <vector>
#include <stack>

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> s;
    TreeNode* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        k--;

        if (k == 0) {
            return current->val;
        }

        current = current->right;
    }

    return -1; // Якщо BST містить менше, ніж k вузлів
}

// Допоміжна функція для створення BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) {
        return new TreeNode(key);
    }

    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }

    return root;
}

int main() {
    // Створення BST
    TreeNode* root = nullptr;
    std::vector<int> values = {5, 3, 6, 2, 4, 1};

    for (int value : values) {
        root = insert(root, value);
    }

    // Знаходження k-того найменшого значення
    int k = 3;
    int result = kthSmallest(root, k);

    // Вивід результату
    std::cout << "Output: " << result << std::endl;

    // Звільнення пам'яті (рекурсивне видалення вузлів)
    delete root->left->left;
    delete root->left->right;
    delete root->left;

    delete root->right->left;
    delete root->right->right;
    delete root->right;

    delete root;

    return 0;
}


*/






/*7, Вам надано корінь бінарного дерева. Ми встановлюємо камери на вузлах дерева, 
де кожна камера на вузлі може стежити за своїм батьком, 
собою та своїми безпосередніми дочірніми елементами.*/





/*


#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        std::pair<int, int> result = dfs(root);
        return std::min({result.first, result.second + 1});
    }

private:
    // Повертає пару (кількість камер, чи вузол моніторяться)
    std::pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int minCameras = left.second + right.second + 1;
        int monitored = std::min({left.first + std::min(right.first, right.second),
                                  right.first + std::min(left.first, left.second),
                                  minCameras});

        return {minCameras, monitored};
    }
};

int main() {
    // Створення прикладового дерева
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = nullptr;
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);

    // Створення об'єкту розв'язання
    Solution solution;

    // Знаходження мінімальної кількості камер
    int result = solution.minCameraCover(root);

    // Вивід результату
    std::cout << "Output: " << result << std::endl;

    // Звільнення пам'яті (рекурсивне видалення вузлів)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root;

    return 0;
}


*/