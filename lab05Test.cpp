//lab05Test.cpp

#include <iostream>
#include <string>
#include "tddFuncs.h"
#include "WordCount.h"
using namespace std;

int main(){
	cout << "---Testing WordCount.cpp---" << endl;
	WordCount obj;
	string test1 = "dog";
	string test2 = "cat";
	string test3 = "fish";
	string test4 = "!3234c908at";
	string test5 = "fi-sh";
	string test6 = "-cat'";
	string test7 = "183?><,.14098";
	string test8 = "123!c43a56n66't@!#";
	string test9 = "F*&i-S?><h";
	string test10 = " c43 a 324t34?!'";

	ASSERT_EQUALS(1, obj.incrWordCount(test1));
	obj.incrWordCount(test2);
	obj.incrWordCount(test3);
	obj.incrWordCount("");

	ASSERT_EQUALS(3, obj.getTotalWords());

	obj.incrWordCount(test4);
	obj.incrWordCount(test5);
	obj.incrWordCount(test6);

	ASSERT_EQUALS(6, obj.getTotalWords());

	obj.incrWordCount(test7);

	ASSERT_EQUALS(6, obj.getTotalWords());

	obj.incrWordCount(test8);
	obj.incrWordCount(test9);


	ASSERT_EQUALS(3, obj.getWordCount("CAT"));
	ASSERT_EQUALS(0, obj.getWordCount(""));
	ASSERT_EQUALS(2, obj.getWordCount("13f234i0!@#-??s&^h!-"));
	ASSERT_EQUALS("clean", obj.stripWord(">cl32e?!an;'"));
	ASSERT_EQUALS(true, obj.isWordChar('d'));
	ASSERT_EQUALS(false, obj.isWordChar('!'));
	ASSERT_EQUALS(4, obj.incrWordCount("C89?a!T**&"));
	ASSERT_EQUALS("mOnkEYs", obj.stripWord("12mOnkEYs-$"));
	ASSERT_EQUALS("inline", obj.stripWord("--''$$-'in41lin123e''&&#$-"));
	ASSERT_EQUALS(5, obj.incrWordCount(test10));
	ASSERT_EQUALS(0, obj.incrWordCount(" "));
	ASSERT_EQUALS(5, obj.getNumUniqueWords());
	ASSERT_EQUALS(10, obj.getTotalWords());

	obj.addAllWords("-90932fast \nderrt   123t34rack?3!-$f   yo 323  ");
	ASSERT_EQUALS(14,obj.getTotalWords());
	obj.dumpWordsSortedByWord(cout);
	cout << "\n---------\n";
	obj.dumpWordsSortedByOccurence(cout);
	cout << "---------" << endl;

	WordCount tester;
	tester.addAllWords("Sentence is a sentence.");
	tester.dumpWordsSortedByWord(cout);
	cout << endl;
	tester.dumpWordsSortedByOccurence(cout);

	WordCount empty;
	empty.addAllWords("");
	empty.dumpWordsSortedByWord(cout);
	empty.dumpWordsSortedByOccurence(cout);

	return 0;
}
