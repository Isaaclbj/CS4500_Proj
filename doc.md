Introduction: where we give a high-level description of the eau2 system.
    eau2 reads in tabular data that is only of the four supported data types. This data is read-only, and nodes will only be able to receive data (for now).

Architecture: where we describe the various part of eau2 at a high-level.
        Bottom layer: this is the KV store on each node.
        Middle layer: this is the concurrency control and networking between the nodes. (distributed array, data frame exchange).
        Top layer: the application layer, driver classes to initialize & call

Implementation: where we describe how the system is built, this can include a description of the classes and their API, but only the class you deem relevant and worth describing. (For example: do not describe the utility classes.)
    We will begin by building the system bottom-up; that is beginning with the KV storage system.
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

        class Key
        {
        public:
            String name;
            int val;

        };

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

        class Application : public Node
        {
        public:
            
            void run_();

            size_t this_node();

            void run_override();

            void producer();

            void counter();

            void summarizer();

        };




Use cases: examples of uses of the system. This could be in the form of code like the one above. It is okay to leave this section mostly empty if there is nothing to say. Maybe just an example of creating a dataframe would be enough.
    1. eau2 is called on multiple terminals, with one receiving an additional flag that designates that terminal's node to be the lead node.
    2. Each node runs run_, which initializes themselves and their KVStores
    3. Node A calls getAndWait on a key that does not exist in the network yet, and blocks.
    4. Node B puts a matching key into its KVStore. 
    5. Node A is in a blocking while loop, but discovers the key now exists in Node B's kvstore. It gets it and exists its blocking loop.

Open questions: where you list things that you are not sure of and would like the answer to.
    1. What are sample commands that customers will use other than get/put?

Status: where you describe what has been done and give an estimate of the work that remains.
    1. Design of the eau2 system layers and classes that will need to be implemented 
    2. Fixed segfaulting error linked_array header class, but we will transition to STL functions/classes.