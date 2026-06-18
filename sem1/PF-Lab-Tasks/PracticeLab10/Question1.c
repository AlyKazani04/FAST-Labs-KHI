#include <stdio.h>
#include <stdlib.h>

typedef struct Box {
	int weight;
	struct Box **nestedBox;
	int numofnestedBoxes;
} Box;

Box* createBox(int weight, int numofnestedBoxes) {
	Box *newBox = (Box*)malloc(sizeof(Box));
	if (!newBox) {
		printf("Memory allocation failed for box\n");
		exit(1);
	}
	newBox->weight = weight;
	newBox->numofnestedBoxes = numofnestedBoxes;
	if (numofnestedBoxes > 0) {
		newBox->nestedBox = (Box**)malloc(numofnestedBoxes * sizeof(Box*));
		if (!newBox->nestedBox) {
			printf("Memory allocation failed for nested boxes\n");
			free(newBox);
			exit(1);
		}
	} else {
		newBox->nestedBox = NULL;
	}
	return newBox;
}

int totalWeightHelper(Box *box, Box **visited, int *visitedCount) {
	int i;
	for ( i = 0; i < *visitedCount; i++) {
		if (visited[i] == box) {
			return 0; // Already visited, skip to avoid cycles
		}
	}
	visited[(*visitedCount)++] = box;

	int totalweight = box->weight;
	int j;
	for (j = 0; j < box->numofnestedBoxes; j++) {
		totalweight += totalWeightHelper(box->nestedBox[i], visited, visitedCount);
	}
	return totalweight;
}

int totalWeight(Box *box) {
	Box *visited[100]; // Arbitrary limit for visited boxes
	int visitedCount = 0;
	return totalWeightHelper(box, visited, &visitedCount);
}

int main() {
	Box *box1 = createBox(15, 0);
	Box *box2 = createBox(20, 1);
	Box *box3 = createBox(30, 2);

	box2->nestedBox[0] = box1;
	box3->nestedBox[0] = box1;
	box3->nestedBox[1] = box2;

	int weight = totalWeight(box3);
	printf("Total weight of the box is: %d\n", weight);

	if (box1->nestedBox) free(box1->nestedBox);
	free(box1);
	if (box2->nestedBox) free(box2->nestedBox);
	free(box2);
	if (box3->nestedBox) free(box3->nestedBox);
	free(box3);

	return 0;
}
