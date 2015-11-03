The ULIB is an efficient algorithm library for C and C++.
ULIB consists of components in multithreading, parallel computing, data indexing, numerical approximation, and cryptography.

Some building blocks are based on other open-source projects, such as the Linux kernel. Please refer to the copyright of the specific source code files.

###ULIB has been used in:
    TIBCO Spotfire - Business intelligence analytics software & data visualization. http://spotfire.tibco.com.
    ArangoDB - the multi-purpose NoSQL DB. https://www.arangodb.org.
    NXWEB - Ultra-fast and super-lightweight web server for applications written in C. https://bitbucket.org/yarosla/nxweb/wiki/Home.
    Bzing - Low-level Bitcoin database library. https://github.com/bitcoinjs/bzing.
    ECDSA Util - Tiny collection of programs used for ECDSA. https://github.com/tcatm/ecdsautils.
    Fast incremental JSON parser - https://github.com/bjouhier/i-json.
    jelly-hash - Low memory multithreaded hash table. https://github.com/noporpoise/jelly-hash.
    probing - Linear probing hash tables in Go. https://github.com/kho/probing.
    mrkcommon - Markiyan's library of "commonly used" functions. https://github.com/mkushnir/mrkcommon. 

###List of components:

####Basic Data Structures and Algorithms
        An extremely efficient open addressing hash table, comparable or even better performance than STL hashmap, Google sparse/dense hash, EASTL hashmap and RDESTL hashmap.
        A chaining hash table, corner stone for building concurrent hash tables.
        A concurrent hash table based on the chaining hash table. Significantly faster (~30%) than several popular ones, e.g., TBB(http://threadingbuildingblocks.org), nbds(http://code.google.com/p/nbds/) and Visual Studio 2012. LocksCanMakeSense provides some analysis.
        The fast-hash hash function http://fast-hash.googlecode.com. Efficient and robust general purpose hash function.
        A set of robust, efficient, and invertible integer hash functions.
        Heap and heapsort. Improved performance than STL.
        A text binary search algorithm.
        A robust O(n) median algorithm.
        Various random number generators, e.g. Zipf RNG, Normal RNG, and Gamma RNG.
        General AVL and Splay trees. Faster than Solaris Kernel AVL and libavl.
        Bit tricks.
        Cryptographic algorithms. 

####Parallel Computing
        MapReduce framework for multicores.
        A set of scalable locks.
        Atomic primitives for x86_64. 
