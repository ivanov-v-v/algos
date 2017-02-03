typedef LeftistNode* pnode;
unsigned getRank(pnode T) {
    return T ? T->rank : 0;
}
void update(pnode T) {
    if (!T) return;
    T->rank = min(getRank(T->tl), getRank(T->tr)) + 1;
}

pnode merge(pnode& L, pnode& R) {
    if (!L || !R) {
        return L ? L : R;
    }
    if (L->key > R->key) {
        swap(L, R);
    }
    L->tr = merge(L->tr, R);
    if (getRank(L->tl) < getRank(R->tr)) {
        swap(L->tl, L->tr);
    }
    L->pr = nullptr;
    if (L->tl) { L->tl->pr = L; }
    if (L->tr) { L->tr->pr = L; }
    update(L);
    return L;
}

void insert(pnode& root, const int& key) {
    pnode T0 = new LeftistNode(key);
    root = merge(root, T0);
}
int getMin(pnode root) {
    if (!getRank(root)) {
        throw logic_error("Empty heap");
    }
    return root->key;
}
int extractMin(pnode& root) {
    if (!getRank(root)) {
        throw logic_error("Empty heap");
    }
    int result = root->key;
    root = merge(root->tl, root->tr);
    return result;
}
void deleteNode(pnode& node) {
    pnode backLink = node->pr;
    node = merge(node->tl, node->tr);
    node->pr = backLink;
    pnode currNode = node;
    while (currNode->pr) {
        update(currNode->pr);
        currNode = currNode->pr;
    }
}
void decreaseKey(pnode node, int delta) {
    if (delta <= 0) {
        return;
    }
    node->key -= delta;
    while (node->pr && node->key < node->pr->key) {
        swap(node->key, node->pr->key);
        node = node->pr;
    }
}
bool empty(pnode T) {
    return !getRank(T);
}