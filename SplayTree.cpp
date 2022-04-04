using namespace std;

template <typename T>
class SplayTree {
private:

    struct SplayTreeNode {
        SplayTreeNode* left;
        SplayTreeNode* right;
        SplayTreeNode* parent;
        T               data;

        SplayTreeNode(T data = T()) {
            this->left(nullptr);
            this->right(nullptr);
            this->parent(nullptr);
            this->data(data);
        }

        SplayTreeNode(SplayTreeNode* node) {
            this->left(node->left);
            this->right(node->right);
            this->parent(node->parent);
            this->data(node->data);
        }

        SplayTreeNode(SplayTreeNode* left, SplayTreeNode* right, T data) {
            this->left(left);
            this->right(right);
            this->parent(nullptr);
            this->data(data);
        }

        ~SplayTreeNode() {
            delete left;
            delete right;
        }

    } *root;

protected:

    void setParent(SplayTreeNode* child, SplayTreeNode* parent) {
        if (child)
            child->parent = parent;
    }

    void rotate(SplayTreeNode* child, SplayTreeNode* parent) {
        SplayTreeNode* grandparent = parent->parent;

        if (grandparent && grandparent->left == parent)
            grandparent->left = child;
        else if (grandparent && grandparent->right == parent)
            grandparent->right = child;

        if (parent->left == child) {
            parent->left = child->right;
            child->right = parent;
        }
        else {
            parent->right = child->left;
            child->left = parent;
        }

        setParent(child->left, child);
        setParent(child->right, child);
        setParent(parent->left, parent);
        setParent(parent->right, parent);
        child->parent = grandparent;
        if (!child->parent)
            this->root = child;
    }

    SplayTreeNode* splay(SplayTreeNode* vertex) {
        if (!vertex->parent) {
            this->root = vertex;
            return (vertex);
        }

        SplayTreeNode* parent = vertex->parent;
        SplayTreeNode* grandparent = parent->parent;

        if (!grandparent) {
            rotate(vertex, parent);
            this->root = vertex;
            return (vertex);
        }

        if ((grandparent->left == parent && parent->left == vertex) ||
            (grandparent->right == parent && parent->right == vertex)) {
            rotate(parent, grandparent);
            rotate(vertex, parent);
        }
        else {
            rotate(vertex, parent);
            rotate(vertex, grandparent);
        }
        return (splay(vertex));
    }

    SplayTreeNode* find(SplayTreeNode* vertex, T data)
    {
        if (!vertex)
            return (nullptr);
        if (vertex->data < data && vertex->left)
            return (find(vertex->left, data));
        else if (vertex->data > data && vertex->right)
            return (find(vertex->right, data));
        return (splay(vertex));
    }

    SplayTreeNode** split(SplayTreeNode* vertex, T data) {
        SplayTreeNode** splitted = new SplayTreeNode * [2];

        if (!vertex) {
            splitted[0] = splitted[1] = nullptr;
            return (splitted);
        }

        vertex = find(vertex, data);

        if (vertex->data < data) {
            splitted[0] = vertex;
            splitted[1] = vertex->right;
            setParent(vertex->right, nullptr);
            vertex->right = nullptr;
        }
        else {
            splitted[0] = vertex->left;
            splitted[1] = vertex;
            setParent(vertex->left, nullptr);
            vertex->left = nullptr;
        }
        return (splitted);
    }

    SplayTreeNode* insert(SplayTreeNode* vertex, T data) {
        SplayTreeNode** splitted = split(vertex, data);
        SplayTreeNode* root = new SplayTreeNode(splitted[0], splitted[1], data);
        setParent(root->left, root);
        setParent(root->right, root);
        this->root = root;
        return (root);
    }

    SplayTreeNode* merge(SplayTreeNode* treeRoot, SplayTreeNode* root = this->root) {
        if (treeRoot == nullptr)
            return (root);
        if (root == nullptr)
            return (treeRoot);
        SplayTreeNode* right = find(root, treeRoot);
        right->left = treeRoot;
        treeRoot->parent = right;
        treeRoot = right;
        root = right;
        return (root);
    }

    SplayTreeNode* remove(SplayTreeNode* vertex, T data) {
        vertex = find(vertex, data);
        setParent(vertex->left, nullptr);
        setParent(vertex->right, nullptr);
        SplayTreeNode* merged = merge(vertex->left, vertex->right);
        vertex->left = vertex->right = nullptr;
        delete(vertex);
        return (merged);
    }
};

void main() {

}