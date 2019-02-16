/*
 *  binarytree.cpp
 *
 *  Created by Daniel Dalquen on 29.11.10.
 *
 *  Beispiel-Aufruf des kompilierten Programms mit dem
 *  Baum aus der Übungsstunde:
 *  ./bintree 5 2 9 1 3 7 6 8
 *
 */
#include <iostream>

struct node {
	int value;
	node * left;
	node * right;
};

/* 
 * fuegt einen neuen Wert in den Baum ein. Dadurch, dass
 * der Pointer als Referenz übergeben wird, ist auch das
 * Einfuegen in den leeren Baum kein Problem.
 *
 * Wenn der Wert bereits im Baum gespeichert ist, wird
 * er nicht ein zweites Mal einefuegt.
 */
void insert(int v, node * &t) {
	if(t == NULL) {
		t = new node;
		t->value = v;
	} else {
		if(t->value > v) {
			insert(v, t->left);
		} else if(t->value < v) {
			insert(v, t->right);
		}
	}
}

/*
 * gibt die im Baum gespeicherten Werte in sortierter
 * Reihenfolge aus.
 */
void inorder(node * t) {
	if(t == NULL) return;
	
	inorder(t->left);
	std::cout << t->value << ' ';
	inorder(t->right);
}

/*
 * loescht den Baum rekursiv
 */
void clearTree(node * &t) {
	if(t->left != NULL)
		clearTree(t->left);
	if(t->right != NULL)
		clearTree(t->right);
	
	delete t;
	t = NULL;
}

int main(int argc, char ** argv) {
	int * vals = new int[argc];
	node * tree = NULL;
	
	// Werte in den Baum einfuegen
	for (int i = 1; i<argc; i++) {
		insert(atoi(argv[i]), tree);
	}
	// Werte ausgeben
	inorder(tree);
	std::cout << std::endl;
	
	// Baum loeschen
	clearTree(tree);
	
	delete[] vals;
	return 0;
}