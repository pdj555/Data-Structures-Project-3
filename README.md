# Simple-Blockchain-Implementation

## Objective
The goal of this project is to create a single BlockChain using the given class structures with linked lists. [Blockchain-Network](https://github.com/pdj555/Blockchain-Network) will be an extension of this project.

## Description
Blockchain is a revolutionary technology that has gained widespread attention in recent years. It is a decentralized digital ledger that enables secure and transparent transactions without the need for intermediaries such as banks or governments. The underlying technology is based on a distributed network that is replicated across a network of computers/nodes. This makes blockchain ideal for applications that require transparency, security, and trust in a decentralized environment, such as cryptocurrency, supply chain management, and voting systems. The potential uses of blockchain are vast and have the potential to revolutionize various industries by creating a more secure, efficient, and transparent way of doing business.

In this project, we have three classes that you can see in the boilerplate code. The transaction class will hold information about one transaction. An array of transaction class objects will be present in the block class. This block class has a block number, the current number of transactions, and the maximum number of transactions that the block can hold. This maximum number of transactions per block is given in the input.

The blockchain class has a list (linked list) of blocks along with the number of blocks. The object of this blockchain class is what we declare in the main function.

For this project, you need not maintain the value of each person ID (fromID and toID). You will just read the transaction from the input and insert it into the data structure (blockchain). You need not worry about if the person ID has enough funds to make the transaction or not.

## Input explanation
The input file given is in the following format:

[Input file content]

The input file starts with the number of transactions per block and then the total number of transactions given in the input file. This is followed by the list of transactions.

Each transaction has the transaction ID, followed by the fromID, toID, amount to be transferred, and finally the timestamp. All these are integers except the last one, which is a string and will stay as a string throughout.

To get started, a boilerplate file is provided alongside this project. Keep up with the FAQ discussion for the project as more assumptions will be updated there. A sample output file will be released soon as well.

## Redirected input
Redirected input provides you a way to send a file to the standard input of a program without typing it using the keyboard. To use redirected input in the Visual Studio environment (on Windows), follow these steps: After you have opened or created a new project, go to project, project properties, expand configuration properties until you see Debugging, on the right you will see a set of options, and in the command arguments type `<input filename>`. The `<` sign is for redirected input, and the input filename is the name of the input file (including the path if not in the working directory).

If you use macOS or Linux (or Windows using PowerShell), you may use the terminal to compile and run your program using g++. Once you installed g++, you may compile your program using the following command:

        g++ project3.cpp -o p3

You may then run the program with the redirected input using the following command:

        ./p3 < input1.txt


Make sure your program and your input file are in the same folder.
