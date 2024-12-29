1. Using std::weak_ptr in C++
	std::weak_ptr is one of the smart pointer types in the STL (Standard Template Library). It is used to solve the problem of cyclic references, which can lead to memory leaks when using std::shared_ptr.

2. What is std::weak_ptr?
	std::weak_ptr does not share ownership of the object it points to with std::shared_ptr. Instead:

	It acts as a weak reference to the object managed by std::shared_ptr, without affecting its reference count.

	It prevents memory leaks in cases of cyclic references.

3. Why Do We Need std::weak_ptr?
	The Core Problem: Cyclic References
	When two or more objects refer to each other using std::shared_ptr, their reference counts never drop to zero, resulting in memory leaks.

4. The Solution: std::weak_ptr
	By using std::weak_ptr, the reference count of the managed object is not increased.

	You can check if the managed object is still valid using expired().

	To access the object, you can convert the std::weak_ptr to std::shared_ptr using lock().

5. Best Scenarios to Use std::weak_ptr
	When There Are Cyclic References: If two (or more) objects are connected and use std::shared_ptr, you should use std::weak_ptr to break the cycle.

	To Reference an Object Without Affecting Its Lifetime: Use std::weak_ptr when you need a temporary reference to an object managed by std::shared_ptr.

	For Complex Data Structures: Such as trees or graphs, where nodes are interconnected.
