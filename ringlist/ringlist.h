#ifndef TKK_AS_C_RINGLIST_H
#define TKK_AS_C_RINGLIST_H

#include <stddef.h>

// Required variables:
// - data: array of 101 characters (max. 100 + terminating NUL)
// - prev and next: pointers to previous/next nodes
struct {
	char data[101];
	struct RingNode_s* prev;
	struct RingNode_s* next;
} RingNode_s;

typedef struct RingNode_s RingNode;

/** Construct a new node.
 * @param pos if NULL, a new ring is created, otherwise the new node is inserted after node pos.
 * @param data a C string used to initialize the data (undefined behavior for strings longer than 100 characters).
 * @return the new node (connected to the old ring if pos was provided).
 **/
RingNode* ringAdd(RingNode* pos, char const* data);

/** Calculates the size of the ring given. O(n).
 * @return the number of nodes, 0 if node was NULL.
 **/
size_t ringSize(RingNode* node);

/** Move forward by count nodes. O(count). **/
RingNode* ringAdvance(RingNode* node, size_t count);

/** Erase a node, connecting the nodes around it to each-other. O(1).
 * @param node the node to erase (not NULL).
 * @return the node next to the one removed, NULL if there are none left.
 **/
RingNode* ringEraseNode(RingNode* node);

/** Erase all nodes of a ring. O(n).
 * @param node any node of the ring (if NULL, the function does nothing).
**/
void ringEraseAll(RingNode* node);

/** Move a set of nodes to another position. O(1).
 * Takes a range of nodes [first, last] and moves them to a new position. The new
 * position may be within another ring or in the same ring as the range, but the
 * behavior is undefined if the destination is within the range to be moved.
 * @param first the first node to move.
 * @param last the last node to move.
 * @param pos the destination: the moved nodes are inserted after node pos.
 * @return first
 **/
RingNode* ringMove(RingNode* first, RingNode* last, RingNode* pos);

#endif
