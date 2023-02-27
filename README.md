# ProjetAlgo

## Goal
 *The goal of this project is to use binary search trees to index a given text file.*

This tree contains the different words of the text file with the occurrences of the word in the file
(position of the word in the sentences of the file).
That is to say, these words of the text will be the indexes, and for each word it is associated with the list of
occurrences of the word in the file (the number of the sentences where these words appear). If a word is present
several times in a sentence, it is counted only once, the sentence is considered only once.
Searching for a phrase in a text (in the text file) is the intersection of the list of
positions of the words of the sentence in the binary search tree.
- Create this structure,
- Build the search tree, (search for a word, insert a word if it doesn't exist, ...)
- Create the list of positions.
- Add positions to it.
- Make the intersection of two lists, a common list, which checks if an element exists in this list.
- Find a sentence in the text.
