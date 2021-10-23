#include <iostream>
#include <stdlib.h>

using namespace std;
template<class  T>class Item
{
public:
    T data;
    Item *right, *left;
//    int height;

    Item()
    {
        right = left = NULL;
    }

};

//Высота считается рекурсивно, выбирается максимальное значение у корней и + 1
template<class  T>
int height(Item<T>* tr) {
    int height1 = 0;
    if (tr != NULL) {
        int l_height = height(tr->left);
        int r_height = height(tr->right);
        int max_height = max(l_height, r_height);
        height1 = max_height + 1;
    }
    return height1;
}


// Считается разность высот левого и правого поддерева, +1 - левое больше -1 - правое больше
template<class  T>
int difference(const Item<T>* tr) {
    int leftHeight = height(tr->left);
    int rightHeight = height(tr->right);
    int balanceFactor = leftHeight - rightHeight;
    return balanceFactor;
}

//вставка
//template<class  T> void node_add(Item<T>*& tr, T val){
//    if(tr == NULL){
//        tr = new Item<T>();
//        tr->data = val;
//    } else {
//        Item<T> *p = tr;
//        Item<T> *p_prev = tr;
//        while(p != NULL){
//            p_prev = p;
//            if(val < p->data)
//                p = p->left;
//            else if(val > p->data)
//                p = p->right;
//            else
//                return;
//        }
//
//        p = new Item<T>();
//        if(p == NULL)
//            return;
//        p->data  = val;
//        if (p_prev->data > val) {
//            p_prev->left = p;
//        } else if(p_prev->data < val) {
//            p_prev->right = p;
//        }
//    }
//
//
//
//}

template<class  T>
Item<T> *insert(Item<T> *node, int value) {
    if (node == NULL) {
        node = new Item<T>();
        node->data = value;
        return node;
    } else if (value< node->data) {
        node->left = insert(node->left, value);
        node = balance(node);
    } else if (value >= node->data) {
        node->right = insert(node->right, value);
        node = balance(node);
    } return node;
}

//template<class  T>
//void nodePrint(const Item<T>* tr){
//    if(tr != NULL){
//        node_print(tr->left);
//        cout << "Root: "<< tr->data << ' ';
//        node_print(tr->right);
//
//    }
//}
//template<class  T>
//void node_print(const Item<T>* tr){
//    if(tr != NULL){
//        node_print(tr->left);
//        node_print(tr->right);
//        cout << tr->data << ' ';
//    }
//}
template<class  T>
void LNR(Item<T> **node)
{
    if( *node != nullptr)
    {
        LNR( &( (*node)->left ) );
        cout << "data : " << (*node)->data << endl;

        LNR( &( (*node)->right) );
    }
}


template<class  T>
Item<T> *balance (Item<T>* node) {
    int bal_factor = difference(node);
    if (bal_factor > 1) {
        if (difference(node->left) > 0)
            node = ll_rotate(node);
        else
            node = lr_rotate(node);
    } else if (bal_factor < -1) {
        if (difference(node->right) > 0)
            node = rl_rotate(node);
        else
            node = rr_rotate(node);
    }
    return node;
}

//14 слайд презентации, но наоборот
template<class  T>
Item<T>* rr_rotate(Item<T>* parent) {
    Item<T> *tree;
    tree = parent->right;
    parent->right = tree->left;
    tree->left = parent;
    return tree;
}

//14 слайд презентации
template<class  T>
Item<T>* ll_rotate(Item<T>* parent) {
    Item<T>* tree;
    tree = parent->left;
    parent->left = tree->right;
    tree->right = parent;
    return tree;
}


// корнем становится левый элемент правого поддерева
template<class  T>
Item<T>*  lr_rotate(Item<T>* parent) {
    Item<T> *tree;
    tree = parent->left;
    parent->left = rr_rotate(tree);
    return ll_rotate(parent);
}


// корнем становится правый элемент левого поддерева
template<class  T>
Item<T>*rl_rotate(Item<T>* parent) {
    Item<T> *tree;
    tree = parent->right;
    parent->right = ll_rotate(tree);
    return rr_rotate(parent);
}

template<class  T>
Item<T>* deleteOne(Item<T>* node, int key)
{
    Item<T>* curr = node;
    Item<T>* parent = NULL;
    while (curr && curr->data != key)
    {
        parent = curr;
        if (curr->data > key)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (!curr)
        return node;
    if (curr->left == NULL)
    {
        // Вместо curr подвешивается его правое поддерево
        if (parent && parent->left == curr)
            parent->left = curr->right;
        if (parent && parent->right == curr)
            parent->right = curr->right;
        delete curr;
        return balance(node);
    }
    if (curr->right == NULL)
    {
        // Вместо curr подвешивается его левое поддерево
        if (parent && parent->left == curr)
            parent->left = curr->left;
        if (parent && parent->right == curr)
            parent->right = curr->left;
        delete curr;
        return balance(node);
    }
    // У элемента есть два потомка, тогда на место элемента поставим
    // наименьший элемент из его правого поддерева
    Item<T>* replace = curr->right;
    while (replace->left)
        replace = replace->left;
    int replace_value = replace->data;
    deleteOne(node ,replace_value);
    curr->data = replace_value;
    return balance(node);
}

//template<class  T>
//Item<T>* DeleteOne(Item<T>* node, int val){
//    if(node == NULL)
//        return node;
//
//    if(val == node->data){
//
//        Item<T>* tmp;
//        if(node->right == NULL)
//            tmp = node->left;
//        else {
//
//            Item<T>* ptr = node->right;
//            if(ptr->left == NULL){
//                ptr->left = node->left;
//                tmp = ptr;
//            } else {
//
//                Item<T>* pmin = ptr->left;
//                while(pmin->left != NULL){
//                    ptr  = pmin;
//                    pmin = ptr->left;
//                }
//                ptr->left   = pmin->right;
//                pmin->left  = node->left;
//                pmin->right = node->right;
//                tmp = pmin;
//            }
//        }
//
//        delete node;
//        return tmp;
//    } else if(val < node->data)
//        node->left  = DeleteOne(node->left, val);
//    else
//        node->right = DeleteOne(node->right, val);
//    return node;
//}
// Написать тесты
// Является ли дерево бинарным деревом поска

int main() {
    Item<int> *node = NULL;
//    for (int i = 0; i < 10; ++i) {
//        node = insert(node, rand() % 100 + 1);
//    }
    node = insert(node, 10);
    node =insert(node, 3);
    node =insert(node, 20);
    node =insert(node, 1);
    node = insert(node, 15);
    node =insert(node, 30);
    node =insert(node, 17);
    LNR(&node);
    deleteOne(node, 10);
    LNR(&node);
//    deleteOne(node, 36);
//    deleteOne(node, 87);
//    cout << "Удалили 16 36 87" << endl;
//    LNR(&node);

    return 0;
}
// Удаление элементов из дерева 
