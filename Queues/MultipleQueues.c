// concept similar to multiple stacks

// use the queue with array code itself,
// queueA front = rear = -1
// queueB front = rear = MAX

// for queueA it is just like normal queue same code
// for queueB, while insertion we decrement rear and while deletion we decrement front
// if queueB gets empty, reset value for queueB is MAX