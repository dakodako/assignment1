# assignment1
Introduction: Summary of data structure and inputs
The abstract data type dictionary was used to store key and value pairs in the database.
The underlying structure of the dictionaries in both stage 1 and stage 2 are binary search trees (without any balancing operations).
The difference between stage 1 and stage 2 is in the method of locating the duplicated keys. 
In stage 1, when doing insertions, if the key is <= (smaller than or equal to) the key of the previous node, a new node will be created at its left and when the key is > (larger), a new node will be inserted to its right. When we search a key in the tree, every time when a duplicated key is encountered, it will be put into a link list and print out the whole list at the end. 
In stage 2, there are three conditions when doing insertions. Same as in stage 1, when the key is larger than the one of its previous node, the new node will be put to its right, and when the key is smaller, it will be put to the left of its parent node. While when the key equals to the one in the previous node, it will be put into a link list following the the previous node. 
In each node in the binary search tree, there are a key value which is an key-value pair in the dictionary, a pointer to its left child and a pointer to its right child. In stage 1, the key-value pair is implemented by a data type called "Entry" which means a single entry in the dictionary. It has a field for name and another one for the information about the name. In stage 2, the key-value pair is implemented by link list whose elements consist of "Entry". When there is a duplicated key found when inserting a new node, the new node will directly be put into the link list which belongs to the node which has the same key as that of the new one. It saves a great by number of comparisons in insertion operation and search operation if there are a great number of duplicated keys in the database because when once the key is found, all the duplicated items are available without any further key comparisons.

Because there are two sets of input data files are provided (yelp_academic_dataset_business.csv and yelp_academic_dataset_user.csv), each stage are tested four times using a sorted version and a shuffled version of each data file.

Using UNIX command sort <filename> > <filename>, four different input data files are created: <br>
  
  yelp_academic_dataset_business.csv (77445 lines, 53.9 MB)
  yelp_academic_dataset_business_sorted.csv (sorted version of yelp_academic_dataset_user.csv)
  yelp_academic_dataset_user.csv (552275 lines, 94 MB)
  yelp_academic_dataset_user_sorted.csv (sorted version of yelp_academic_dataset_user.csv).
</br>
Also, using UNIX command cat filename.csv | awk -F ’;’ ’{print $1}’ and sort commands, input files which contain search keys are created.
