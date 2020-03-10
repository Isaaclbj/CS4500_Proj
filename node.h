class Node
{
public:
	bool leader();
	KVStore kvs;
	Node() {};
	~Node() {};

	int communicate(Node* other);

	KVStore getKVStore();

	void run();
};

