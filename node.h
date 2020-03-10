class Node
{
public:
	KVStore kvs;
	Node() {};
	~Node() {};

	int communicate(Node* other);

	KVStore getKVStore();

	void run();
};

