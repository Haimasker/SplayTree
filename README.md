<h1 align="center">
	SplayTree
</h1>

<p align="center">
	this is the implementation of splay tree - self-balancing binary search tree.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/haimasker/SplayTree?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/haimasker/SplayTree?color=blue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/haimasker/SplayTree?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/haimasker/SplayTree?color=blue" />
</p>

<h3 align="center">
	<a href="#preamble">Preamble</a>
	<span> · </span>
	<a href="#operations">Operations</a>
	<span> · </span>
	<a href="#analysis">Amortized analysis</a>
</h3>

---

<a name="preamble"></a>
## Preamble

The purpose of this project is to implement SplayTree class and it's basic operations.

* Splay tree qualities

| Advantages                                                   | Disadvantages                                          |
| ------------------------------------------------------------ | ------------------------------------------------------ |
| Average-case performance is as efficient as other trees      | In some cases the height of a splay tree can be linear |
| Splay trees don't need to store any additional data in nodes |                                                        |

---

<a name="operations"></a>
## Operations

* rotate(child, parent) - rotates edge between child and parent node in splay tree

* splay(x) - moves node x to splay tree's root due to following operations:
  *  zig(x) - runs if there is no grandparent of target node
  
  ![zig](https://github.com/Haimasker/SplayTree/blob/master/images/zig.png)
  
  *  zig-zig(x) - runs if node and it's parent are both left or right childs of their parents

  ![zig-zig](https://github.com/Haimasker/SplayTree/blob/master/images/zig-zig.png)
  
  *  zig-zag(x) - runs if node and it's parent are not both left or right childs of their parents

  ![zig-zag](https://github.com/Haimasker/SplayTree/blob/master/images/zig-zag.png)
  
* find(vertex, x) - trying to find node with value `x` beginning from given node `vertex` (as in simple BST). <br>
Then runs `splay` of it's result. If there is no node with value `x` in the tree then runs `splay` from node with closest value to `x` <br>
(leaf-node that was last during find process)

* split(vertex x) - splits given by pointer `vertex` tree into two: in first all values are less than `x`, in second one all values are bigger or equal

* insert(vertex, x) - splits given by pointer `vertex` tree by value `x`. Then first subtree becomes left child and second subtree becomes right child of new node

* merge(root1, root2) - merges two trees into one. All values in first tree must be less than values in second tree

* remove(vertex, x) - removes from given by pointer `vertex` tree node with value `x`. Runs `find(vertex, tree)`. Then runs `merge` left and right childs of new root.

---

<a name="analysis"></a>
## Amortized analysis

* Amortized time of `m` operations is actually `O(m*log(n))`

* You can find proof [here](https://en.wikipedia.org/wiki/Splay_tree) 
