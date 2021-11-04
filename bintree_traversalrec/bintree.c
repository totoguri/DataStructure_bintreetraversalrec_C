#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode) {
	BinTree* pReturn = NULL;
	pReturn = (BinTree*)malloc(sizeof(BinTree));
	if (pReturn != NULL) {
		pReturn->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		if (pReturn->pRootNode != NULL) {
			*(pReturn->pRootNode) = rootNode;
			pReturn->pRootNode->pLeftChild = NULL;
			pReturn->pRootNode->pRightChild = NULL;
		}
		else {
			printf("Memory Error for makeBinTree()\n");
		}
	}
	else {
		printf("Memory Error for makeBinTree()\n");
	}
	return pReturn;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
	BinTreeNode* pReturn = NULL;
	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == NULL) {
			pParentNode->pLeftChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));
			if (pParentNode->pLeftChild != NULL) {
				*(pParentNode->pLeftChild) = element;
				pParentNode->pLeftChild->pLeftChild = NULL;
				pParentNode->pLeftChild->pRightChild = NULL;
				pReturn = pParentNode->pLeftChild;
			}
			else {
				printf("Memory Error for insertLeftChildNodeBT()\n");
			}
		}
		else {
			printf("Error. Node already exists for insertLeftChildNodeBT()\n");
		}
	}
	return pReturn;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
	BinTreeNode* pReturn = NULL;
	if (pParentNode != NULL) {
		if (pParentNode->pRightChild == NULL) {
			pParentNode->pRightChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));
			if (pParentNode->pRightChild != NULL) {
				*(pParentNode->pRightChild) = element;
				pParentNode->pRightChild->pLeftChild = NULL;
				pParentNode->pRightChild->pRightChild = NULL;
				pReturn = pParentNode->pRightChild;
			}
			else {
				printf("Memory Error for insertRightChildNodeBT()\n");
			}
		}
		else {
			printf("Error. Node already exists for insertRightChildNodeBT()\n");
		}
	}
	return pReturn;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree) {
	BinTreeNode* pReturn = NULL;

	if (pBinTree != NULL) {
		pReturn = pBinTree->pRootNode;
	}

	return pReturn;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode) {
	BinTreeNode* pReturn = NULL;

	if (pNode != NULL) {
		pReturn = pNode->pLeftChild;
	}

	return pReturn;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode) {
	BinTreeNode* pReturn = NULL;

	if (pNode != NULL) {
		pReturn = pNode->pRightChild;
	}

	return pReturn;
}

void deleteBinTree(BinTree* pBinTree) {
	if (pBinTree != NULL) {
		deleteBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
	}
}

void deleteBinTreeNode(BinTreeNode* pNode) {
	if (pNode != NULL) {
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free(pNode);
	}
}