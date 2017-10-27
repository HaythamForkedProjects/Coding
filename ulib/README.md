ULIB is a C++ library providing fundamental functions/classes for high-performance computation. The components include building block data structures, numeric approximation and optimization routines, aligned hashing and fast synchronization locks for multi-threading, and parallel computing frameworks such as MapReduce over multicores. The goal of ULIB is to provide a flexible interface as well as state-of-the-art efficiency.

Some components of ULIB builds upon other open-source projects. Please refer to the copyright of the specific source code files.

### Why ULIB?

ULIB has been used in:

* TIBCO Spotfire - Business intelligence analytics software & data visualization. http://spotfire.tibco.com. Check out https://docs.tibco.com/pub/spotfire/6.0.3/license/TIB_sfire_6.0.3_license.pdf.
* Xfinity Open Source Software, see http://my.xfinity.com/terms/opensource.
* Yumpu.com, check out https://www.yumpu.com/en/document/view/41650370/read-this-end-user-license-agreement-carefully-tibco-product-/23.
* The EOS Project, a low-latency disk-based storage infrastructure. Check out http://eos.cern.ch/cgi-bin/cgit.cgi/eos/plain/common/ulib.
* ArangoDB - the multi-purpose NoSQL DB. https://www.arangodb.org.
* NXWEB - Ultra-fast and super-lightweight web server for applications written in C. https://bitbucket.org/yarosla/nxweb/wiki/Home.
* Bzing - Low-level Bitcoin database library. https://github.com/bitcoinjs/bzing.
* ECDSA Util - Tiny collection of programs used for ECDSA. https://github.com/tcatm/ecdsautils.
* Fast incremental JSON parser - https://github.com/bjouhier/i-json.
* jelly-hash - Low memory multithreaded hash table. https://github.com/noporpoise/jelly-hash.
* probing - Linear probing hash tables in Go. https://github.com/kho/probing.
* mrkcommon - Markiyan's library of "commonly used" functions. https://github.com/mkushnir/mrkcommon. 

### Component Categories

* Multicore MapReduce implementation as C++ containers.
* Efficient concurrent hashing routines which outperform several popular ones like Google SparseHash and Intel TBB hashing. 
* Fast bit operations.
* Low-latency locks for multi-threaded programming.
* Atomic primitives for x86_64.
* Cryptographic algorithms. 
