/*
//A C++ programme to delete keys from btree

#include<bits/stdc++.h>

using namespace std;

// A class to create btree node

class btreenode

{

int *key;

int t;

btreenode **c; // A child pointer's Array

int n;

bool leaf; // returns true, if node is leaf

public:

btreenode(int _t, bool _leaf); //A btreenode class constructor

// A function to traverse btree

void traverse();

btreenode *search(int k); // if k is not present return false

int findkey(int k);// a function to find a key in the btree

// A function to split the child y of this node.

void splitchild(int i, btreenode *y);

void remove(int k);

//A function to delete a key at idx index which is leaf

void removefromleaf(int idx);

// A function to delete a key at idx index which is leaf non-leaf

void removefromnonleaf(int idx);

int getpred(int idx);

int getsucc(int idx);

// A function for filling the child node in the idx index.

void fill(int idx);

void borrowfromprev(int idx);

void borrowfromnext(int idx);

// A function to merge idx child of the node next node

void merge(int idx);

// we will make BTree friend of btreenode

friend class btree;

};

class btree

{

btreenode *root; //root node's pointer

int t;

public:

//btree class Constructor

btree(int _t)

{

root = NULL;

t = _t;

}

void traverse()

{

if (root != NULL)

root->traverse();

}

//A function to search a key in this tree

btreenode* search(int k)

{

if(root == NULL)

return NULL;

else

root->search(k);

}

// A function that removes a new key in the BTree

void remove(int k);

};

btreenode::btreenode(int t1, bool l1)

{

t = t1;

leaf = l1;

// Allocate memory for max possible keys and child pointers

key = new int[2*t-1];

c = new btreenode *[2*t];

n = 0;

}

int btreenode::findkey(int k)

{

int idx=0;

while (idx<n && key[idx] < k)

++idx;

return idx;

}

// A function to remove the key k

void btreenode::remove(int k)

{

int idx = findkey(k);

// check if the key to be removed is present in this node

if (idx < n && key[idx] == k)

{

if (leaf)

removefromleaf(idx);

else

removefromnonleaf(idx);

}

else

{

if (leaf)

{

cout << "The key "<< k <<" is not found in the tree\n";

return;

}

bool flag = ( (idx==n)? true : false );

//If there are less than t keys in the child where the key is expected to exist

if (c[idx]->n < t)

fill(idx);

//We recurse on the (idx-1)th child if the last child has been merged,

//as it must have merged with the preceding child.

//If not, we go back to the (idx)th child, which now contains at least t keys.

if (flag && idx > n)

c[idx-1]->remove(k);

else

c[idx]->remove(k);

}

return;

}

void btreenode::removefromleaf (int idx)

{

// a loop to shift key back

for (int j=idx+1; j<n; ++j)

key[j-1] = key[j];

n--;

return;

}

void btreenode::removefromnonleaf(int idx)

{

int k = key[idx];

//In the subtree rooted at c[idx], look for k's predecessor 'pred'.

//if the child preceding k (C[idx]) contains at least t keys.

//Pred should be substituted for k.

//Delete pred in C[idx] in a recursive manner.

if (c[idx]->n >= t)

{

int pred = getpred(idx);

key[idx] = pred;

c[idx]->remove(pred);

}

//Examine c[idx+1] if the child C[idx] contains less than t keys.

//Find the k's successor 'succ' in the subtree rooted at C[idx+1]

//and replace k with succ if C[idx+1] has at least t keys.

//Delete succ in C[idx+1] in a recursive manner.

else if (c[idx+1]->n >= t)

{

// this getsucc function returns the successor at idx

int succ = getsucc(idx);

key[idx] = succ;

c[idx+1]->remove(succ);

}

//we will merge k and all of c[idx+1] into c[idx]

//if both c[idx] and c[idx+1] have fewer than t keys.

//2t-1 keys now reside in c[idx].

//Remove k from c[idx] by freeing c[idx+1].

else

{

merge(idx);

c[idx]->remove(k);

}

return;

}

// A function to get predecessor of key[idx]

int btreenode::getpred(int idx)

{

// Move to the rightmost node until we get to a leaf.

btreenode *cur=c[idx];

while (!cur->leaf)

cur = cur->c[cur->n];

return cur->key[cur->n-1];

}

int btreenode::getsucc(int idx)

{

btreenode *cur = c[idx+1];

while (!cur->leaf)

cur = cur->c[0];

// Return the first key of the leaf

return cur->key[0];

}

void btreenode::fill(int idx)

{

if (idx!=0 && c[idx-1]->n>=t)

// a function to borrow key from previous node

borrowfromprev(idx);

else if (idx!=n && c[idx+1]->n>=t)

borrowfromnext(idx);

else

{

if (idx != n)

merge(idx);

else

merge(idx-1);

}

return;

}

void btreenode::borrowfromprev(int idx)

{

btreenode *child=c[idx];

btreenode *sibling=c[idx-1];

//The parent receives the final key from C[idx-1], and key[idx-1] from

//parent is placed as the first key in C[idx]. As a result, the sibling

//loses one key, and the child receives one.

for (int i=child->n-1; i>=0; --i)

child->key[i+1] = child->key[i];

//All keys in C[idx] are moved one step forward.

//If c[idx] isn't a leaf, advance all of its child pointers one step.

if (!child->leaf)

{

for(int i=child->n; i>=0; --i)

child->c[i+1] = child->c[i];

}

child->key[0] = key[idx-1];

if(!child->leaf)

child->c[0] = sibling->c[sibling->n];

//Shifting the key from a sibling to a parent.

//The number of keys in the sibling is reduced as a result.

key[idx-1] = sibling->key[sibling->n-1];

child->n += 1;

sibling->n -= 1;

return;

}

//A function that takes a key from C[idx+1] and stores it in C[idx].

void btreenode::borrowfromnext(int idx)

{

btreenode *child=c[idx];

btreenode *sibling=c[idx+1];

child->key[(child->n)] = key[idx];

//check if child node has a leaf node

if (!(child->leaf))

child->c[(child->n)+1] = sibling->c[0];

key[idx] = sibling->key[0];

for (int j=1; j<sibling->n; ++j)

sibling->key[j-1] = sibling->key[j];

if (!sibling->leaf)

{

for(int j=1; j<=sibling->n; ++j)

sibling->c[j-1] = sibling->c[j];

}

child->n ++;

sibling->n--;

return;

}

//C[idx] and C[idx+1] are merged with this function.

//After merging, C[idx+1] is freed.

void btreenode::merge(int idx)

{

btreenode *child = c[idx];

btreenode *sibling = c[idx+1];

child->key[t-1] = key[idx];

for (int j=0; j<sibling->n; ++j)

child->key[j+t] = sibling->key[j];

// Copying the child pointers from C[idx+1] to C[idx]

if (!child->leaf)

{

for(int j=0; j<=sibling->n; ++j)

child->c[j+t] = sibling->c[j];

}

//To fill the gap created by shifting keys[idx] to C[idx],

//move all keys following idx in the current node one step before.

for (int i=idx+1; i<n; ++i)

key[i-1] = key[i];

//Moving the child pointers one step

//before (idx+1) in the current node

for (int j=idx+2; j<=n; ++j)

c[j-1] = c[j];

//Updating the current node's key count

//and the child's key count

child->n += sibling->n+1;

n--;

delete(sibling);

return;

}

//A function to separate this node's child y

void btreenode::splitchild(int i, btreenode *y)

{

//Create a new node that will store the keys

btreenode *z = new btreenode(y->t, y->leaf);

z->n = t - 1;

for (int j = 0; j < t-1; j++)

z->key[j] = y->key[j+t];

if (y->leaf == false)

{

for (int j = 0; j < t; j++)

z->c[j] = y->c[j+t];

}

y->n = t - 1;

//Create a new child space for this node

//since it will have a new child.

for (int j = n; j >= i+1; j--)

c[j+1] = c[j];

c[i+1] = z;

//This node will be moved with a key of y.

//Locate the new key and

//move all larger keys one place forward.

for (int j = n-1; j >= i; j--)

key[j+1] = key[j];

//To this node, copy y's middle key.

key[i] = y->key[t-1];

n++;

}

// A Function to traverse all nodes

void btreenode::traverse()

{

int i;

for (i = 0; i < n; i++)

{

//If this is not a leaf, traverse the subtree rooted

//with child C[i] before printing key[i].

if (leaf == false)

c[i]->traverse();

cout << " " << key[i];

}

// Print the subtree rooted with last child

if (leaf == false)

c[i]->traverse();

}

//A function to search key k in btree

btreenode *btreenode::search(int k)

{

//Find the first key with a value higher or equal to k.

int i = 0;

while (i < n && k > key[i])

i++;

//Return this node if the detected key is equal to k.

if (key[i] == k)

return this;

//If the key isn't found here and the node is a leaf,

if (leaf == true)

return NULL;

// Go to the appropriate child

return c[i]->search(k);

}

void btree::remove(int k)

{

if (!root)

{

cout << "The tree is empty\n";

return;

}

// A function Call to remove function

root->remove(k);

// Make the first child of the root node the new root

//if the root node has no keys.

//If it has a child, set root to NULL otherwise.

if (root->n==0)

{

btreenode *tmp = root;

//check if root has leaf

if (root->leaf)

root = NULL;

else

root = root->c[0];

delete tmp;

}

return;

}

int main()

{

btree p(3); // A B-Tree with minimum degree 3

p.insert(1);

p.insert(13);

p.insert(7);

p.insert(10);

p.insert(11);

p.insert(6);

p.insert(14);

p.insert(15);

cout << "Traversal of tree constructed is\n";

p.traverse();

cout << endl;

p.remove(6);

cout << "Traversal of tree after deleting 6\n";

p.traverse();

cout << endl;

p.remove(13);

cout << "Traversal of tree after deleting 13\n";

p.traverse();

cout << endl;

return 0;

}
*/