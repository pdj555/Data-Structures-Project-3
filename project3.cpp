// Project 3
// CS 2413 Data Structures
// Spring 2023

#include <iostream>
#include <vector> // for array of transactions
#include <list> // for blockchain

using namespace std;

class transaction
{
    int tID; // transaction id
    int fromID; // source ID
    int toID; // target ID
    int tAmount; // how much is being transfered
    string timeStamp; // time of the transaction read from the input file

    public:
        transaction(); // default constructor
        transaction(int temptID, int tempfromID, int temptoID, int temptAmount, string temptimeStamp); // non default constructor - default 100 for values
        
        // all setters
        void setTranID(int tranID); // sets transaction ID
        void setFromID(int fID); // sets from ID
        void setToID(int targetID); // sets to ID
        void setTranAmount(int tranAmount); // sets transaction amount
        void setTimeStamp(string tS); // sets time stamp
        
        //all getters
        int getTranID(); // gets transaction ID
        int getFromID(); // gets from ID
        int getToID(); // gets to ID
        int getTranAmount(); // gets transaction amount
        string getTimeStamp(); // gets time stamp

};

// Constructors
// Default contructor for transaction class
transaction::transaction() {
    tID = 100;
    fromID = 100;
    toID = 100;
    tAmount = 100;
    timeStamp = "100";
}

// Non-Default Contructor for transaction class
transaction::transaction(int temptID, int tempfromID, int temptoID, int temptAmount, string temptimeStamp) {
    tID = temptID;
    fromID = tempfromID;
    toID = temptoID;
    tAmount = temptAmount;
    timeStamp = temptimeStamp;
}

// Setters
// Sets transaction ID
void transaction::setTranID(int tranID) {
    tID = tranID;
}

// Sets source ID
void transaction::setFromID(int fID) {
    fromID = fID;
}

// Sets target ID
void transaction::setToID(int targetID) {
    toID = targetID;
}

// Sets how much is being transfered
void transaction::setTranAmount(int tranAmount) {
    tAmount = tranAmount;
}

// Sets time of the transaction read from the input file
void transaction::setTimeStamp(string tS) {
    timeStamp = tS;
}

// Getters
// Gets transaction ID
int transaction::getTranID() {
    return tID;
}

// Gets source ID
int transaction::getFromID() {
    return fromID;
}

// Gets target ID
int transaction::getToID() {
    return toID;
}

// Gets amount being transfered
int transaction::getTranAmount() {
    return tAmount;
}

// Gets time of the transaction read from the input file
string transaction::getTimeStamp() {
    return timeStamp;
}


class block
{
    int blockNumber; // block number of the current block
    int currentNumTransactions; // how many transactions are currently in the block
    int maxNumTransactions; // how many maximum transactions can be in the block
    vector<transaction> bTransactions; // vector of transaction objects
    block* nextBlock; // keeps up with the previous block in the list

    public:
        block(); // default constructor
        block(int bNumber, int maxTransactions); // non default constructor
    
        bool searchTrans(transaction t); // search method for searching through array of transactions
        void inseartTran(transaction t); // insert method to insert a new transaction
        
        // setters
        void setBlockNumber(int bN); // sets block number
        void setCurrNumTran(int cnt); // sets current number of transactions
        void setMaxNumTran(int mnt); // sets maximum number of tranactions 
        void setNextBlock(block* bA); // sets pointer to next block in blockchain
        
        // getters
        int getBlockNumber(); // gets block number
        int getCurrNumTran(); // gets current number of transactions
        int getMaxNumTran(); // gets maximum number of transactions
        block* getNextBlock(); // gets pointer to next block in blockchain
        
        void displayTransctions(); // displays the transactions that the block holds
};

// Constructors
// Default constructor for block class
block::block() {
    blockNumber = 0;
    maxNumTransactions = 10;
    currentNumTransactions = 0;
}

// Non-Default Constructor for block class
block::block(int bNumber, int maxTransactions) {
    blockNumber = bNumber;
    maxNumTransactions = maxTransactions;
    currentNumTransactions = 0;
}

// Functions
bool block::searchTrans(transaction t) {
    bool find = false;
    for (int i = 0; i < bTransactions.size(); i++) {
        if (bTransactions[i].getTranID() == t.getTranID()) {
            find = true;
        }
    }
    return find;
}

// Insearts transaction into block's vector
void block::inseartTran(transaction t) {
    bTransactions.push_back(t);
    currentNumTransactions++;
}

// Setters
// Sets block number
void block::setBlockNumber(int bN) {
    blockNumber = bN;
}

// Sets current number of transactions
void block::setCurrNumTran(int cnt) {
    currentNumTransactions = cnt;
}

// Sets maximum number of transactions
void block::setMaxNumTran(int mnt) {
    maxNumTransactions = mnt;
}

// Sets pointer to next block in blockchain
void block::setNextBlock(block* bA) {
    nextBlock = bA;
}

// Getters
// Gets block number
int block::getBlockNumber() {
    return blockNumber;
}

// Gets current number of transactions
int block::getCurrNumTran() {
    return currentNumTransactions;
}

// Gets maximum number of transactions
int block::getMaxNumTran() {
    return maxNumTransactions;
}

// Gets pointer to next block in blockchain
block* block::getNextBlock() {
    return nextBlock;
}

// Displays the transactions stored in the block's vector
void block::displayTransctions() {
    cout << "Block Number: " << blockNumber+1 << " -- Number of Transaction: " << currentNumTransactions << endl;

    for (int i = 0; i < bTransactions.size(); i++) {
        cout << bTransactions[i].getTranID() << " " << bTransactions[i].getFromID() <<  " " << bTransactions[i].getToID() <<  " " 
        << bTransactions[i].getTranAmount() <<  " " << bTransactions[i].getTimeStamp() << endl;
    }
}


class blockChain
{
    int currentNumBlocks; // maintain the size of the list/block chain list
    list<block> bChain; // blockchain as a linked list

    public:
        blockChain(); // default constructor
        blockChain(int tPerB); // non default constructor
        
        void insertTran(transaction* t); // insert method to insert new transaction into the block chain - add new block if existing block is full
        void insertBlockFront(block b); // while inserting new block into list, insert front
        
        // Setters
        void setCurrNumBlocks(int cnb); // sets the current number of blocks in the blockchain
        
        // Getters
        int getCurrNumBlocks(); // gets the current number of blocks in the blockchain
        void displayTrans(int bNum); // displays the transactions that are held in the blocks in the blockchain
};

// Default constructor for blockChain class
blockChain::blockChain() {
    currentNumBlocks = 0;
}

// Non-Default Constructor for blockChain class
blockChain::blockChain(int tPerB) {
    bChain.push_front(block(currentNumBlocks, tPerB));
    currentNumBlocks = 1;
    cout << "Adding block #" << currentNumBlocks << endl;
}

// Functions
// Inserts a transaction into the front-most block in the blockchain. If the front block has reached it's maximum number of 
// trasactions, a new block is added to the front of the blockchain
void blockChain::insertTran(transaction* t) {
    if (bChain.empty() || bChain.front().getCurrNumTran() == bChain.front().getMaxNumTran()) {
        block nB(bChain.size(), bChain.front().getMaxNumTran());
        nB.inseartTran(*t);
        insertBlockFront(nB);
        cout << "Inserting transaction to block #" << currentNumBlocks << endl;

        
    }
    else {
        bChain.front().inseartTran(*t);
        cout << "Inserting transaction to block #" << currentNumBlocks << endl;
    }
}

// Inserts a new block at the front of the blockchain
void blockChain::insertBlockFront(block b) {
    b.setNextBlock(&bChain.front());
    bChain.push_front(b);
    currentNumBlocks++;
    cout << "Adding block #" << currentNumBlocks << endl;
}

// Setters
// Sets the current number of blocks in the blockchain
void blockChain::setCurrNumBlocks(int cnb) {
    currentNumBlocks = cnb;
}

// Getters
// Gets the current number of blocks in the blockchain
int blockChain::getCurrNumBlocks() {
    return currentNumBlocks;
}

// Displays the transactions in each block of the blockchain
void blockChain::displayTrans(int bNum) {
    if (bChain.front().getBlockNumber() == bNum) {
        bChain.front().displayTransctions();
    }
    else if (bChain.back().getBlockNumber() == bNum) {
        bChain.back().displayTransctions();
    }
    else {
        block* curr = bChain.front().getNextBlock();

        for (int i = 0; i < bChain.size(); i++) {
            if (curr->getBlockNumber() == bNum) {
                curr->displayTransctions();
                break;
            }
            else {
                curr = curr->getNextBlock();
            }
        }
    }
}


int main()
{
    int numTransactionsPerBlock; // max transactions per block

    cin >> numTransactionsPerBlock;
    cout << "Number of transactions per block: " << numTransactionsPerBlock << endl;

    int totalNumTransactions; // total transactions to be read from the input file

    cin >> totalNumTransactions;
    cout << "Total number of transactions: " << totalNumTransactions << endl;

    // Object of block chain
    blockChain* b1 = new blockChain(numTransactionsPerBlock);

    // Insert transactions into the blockchain
    int transactionID;
    int fromID;
    int toID;
    int amountTrans;
    string timeStamp;

    while (cin >> transactionID >> fromID >> toID >> amountTrans >> timeStamp) {
        transaction* t = new transaction(transactionID, fromID, toID, amountTrans, timeStamp);
        b1 -> insertTran(t);
    }

    // Display number of blocks in the block chain
    int numBCBlocks = b1 -> getCurrNumBlocks();
    cout << "Current number of blocks: " << numBCBlocks << endl;

    // Display contents of each block in the blockchain
    for (int i = 0; i < numBCBlocks; i++) {
        b1 -> displayTrans(i);
    }

    return 0;
}

