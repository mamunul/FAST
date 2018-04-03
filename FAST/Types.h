//
//  Types.h
//  FAST
//
//  Created by Mamunul on 4/3/18.
//  Copyright © 2018 Mamunul. All rights reserved.
//

#ifndef Types_h
#define Types_h
#include <stdint.h>
#include <string>

using namespace std;

struct corner{
	uint64_t count;
	bool is_corner;
};

////////////////////////////////////////////////////////////////////////////////
//
// Tree buliding
//

///This class represents a decision tree.
///Each leaf node contains a class, being Corner or NonCorner.
///Each decision node contains a feature about which to make a ternary decision.
///Additionally, each node records how many datapoints were tested.
///The generated tree structure is not mutable.
struct tree{
	///The class of the leaf, and a sentinal to indacate that the node is
	///not a leaf. Now that I come back to this, it looks suspiciously like
	///an instance of http://thedailywtf.com/Articles/What_Is_Truth_0x3f_.aspx
	///Oh well.
	enum IsCorner
	{
		Corner,
		NonCorner,
		NonTerminal
	};
	
	const shared_ptr<tree> brighter;                  ///<Subtrees
	const shared_ptr<tree> darker;                    ///<Subtrees
	const shared_ptr<tree> similar;                   ///<Subtrees
	const IsCorner is_a_corner;                       ///<Class of this node (if its a leaf)
	const int feature_to_test;                        ///<Feature (ie pixel) to test if this  is a non-leaf.
	const uint64_t num_datapoints;	   				  ///<Number of datapoints passing through this node.
	
	///Convert the tree to a simple string representation.
	///This is allows comparison of two trees to see if they are the same.
	///It's probably rather inefficient to hammer the string class compared
	///to using an ostringstream, but this is not the slowest part of the program.
	///@return a stringified tree representation
	string stringify()
	{
		if(is_a_corner == NonTerminal)
			return "(" + brighter->stringify() + darker->stringify() + similar->stringify() + ")";
		else
			return string("(") + (is_a_corner == Corner?"1":"0")  +  ")";
	}
	
	///Create a leaf node which is a corner
	///This special constructor function makes it impossible to
	///construct a leaf with the NonTerminal class.
	///@param n number of datapoints reaching this node.
	static shared_ptr<tree> CornerLeaf(uint64_t n)
	{
		return shared_ptr<tree>(new tree(Corner, n));
	}
	
	///Creat a leaf node which is a non-corner
	///This special constructor function makes it impossible to
	///construct a leaf with the NonTerminal class.
	///@param n number of datapoints reaching this node.
	static shared_ptr<tree> NonCornerLeaf(uint64_t n)
	{
		return shared_ptr<tree>(new tree(NonCorner, n));
	}
	
	///Create a non-leaf node
	///@param b The brighter subtree
	///@param d The darker subtree
	///@param s The similar subtree
	///@param n Feature number to test
	///@param num Number of datapoints reaching this node.
	tree(shared_ptr<tree> b, shared_ptr<tree> d, shared_ptr<tree> s, int n, uint64_t num)
	:brighter(b), darker(d), similar(s), is_a_corner(NonTerminal), feature_to_test(n), num_datapoints(num)
	{}
	
private:
	///The leaf node constructor is private to prevent a tree
	///being constructed with invalid values.
	///see also CornerLeaf and NonCornerLeaf.
	///@param c Class of the node
	///@param n Number of datapoints which this node represents
	tree(IsCorner c, uint64_t n)
	:is_a_corner(c),feature_to_test(-1),num_datapoints(n)
	{}
};

#endif /* Types_h */
