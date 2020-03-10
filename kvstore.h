class KVStore
{
public:
	DataFrame kv;
	KVStore() {};
	~KVStore() {};

	void put(Key k, void* v);

	void* get(Key k);

	void* getAndWait(Key k);
};



