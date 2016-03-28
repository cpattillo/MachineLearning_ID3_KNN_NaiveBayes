# MachineLearning_ID3_KNN_NaiveBayes
This projects implements a KNN, Navie Bayes, and ID3 classifiers to predict different class attributes for data sets with nominal attributes

The output displays the accuracy rate and standard deviation for the data set soybean, using k fold cross validation, the holdout
method. Besides implementing the holdout and test set method in Evaluator, I also moved the accuracy and standard deviation
calculations to the Performance class. Now, after each fold, I store a vector of accuracy measures. I then create a new Performance
object and calculate the accuracy and standard deviation by passing in the vector of accuracy measures.

In my ID3 class, I overrided the classify and train methods from Classifier to build my decision tree. In my train method, I passed in
a pointer to a node and a DataSet object. As my base case, I check to see if the DataSet is homogeneous, meaning all the examples have
the same class labels. If this base case is true, I set the class label of the node and return. Else if, the DataSet is empty with no
examples, I output an error message that there are no examples. Else, I find the best attribute to split the data. In the DataSet
class I implemented four methods, bestAttribute(), entropySet(), gain(int attribute) and entropy(int attribute). In bestAttribute() I
loop through all the attributes and calculate the gains. I find the gain of an attribute by subtracting entropySet() – entropy(int
attribute). To find the entropy of the set, I create a vector that keeps track of all the observations for each class attribute. Then,
I calculate the proportions of each class attribute and find the summation of –(p*log2(p)). Next, in my recursive train algorithm, I
make a new node set to the best attribute and split the dataset into a dataset for each domain for the best attribute, stored in a
vector. I then iterate over the split vector and create a new child node. Next, I test to see if the DataSet is empty, which in that
case I call majority(). This function votes on the majority class attribute of the parent node. Else, I make a recursive call to the
child node. In the classify method, I test to see if the node is a leaf node by checking if the node has any children. If it is a
leaf, then I return the class label. If not, I recursively traverse the child nodes. 

For my Naive Bayes classifier, I implemented a 3D vector with the first layer as the attributes, second the domain of the attributes and third as the counts of democrats or republicans with those attributes. For examples myVector[0][0][0] finds the number of democrats or republicans that voted yes, no, or u on a certain issue. When loading the training data, I add a one to each of the positions in the vector, which implements the additive smoothing tactic. I also find the total number of class attributes in the load training set. In the classify method, I go through each element in an example, find the number of counts and then calculate a conditional probability. I then multiply the conditional probabilities together and then use Bayes’ Theorem. I calculate Bayes’ Theorem for all the class attributes and return the class attribute with the largest probability. My accuracy is extremely low because I was having an issue counting the total number of class attributes in the data set, which is throwing off my probability calculations. For KNN, I implement a set of parallel vectors, one holding the distances and the other holding the class attributes. I then store the “k” nearest neighbors, vote on the neighbors and return the class attribute.

