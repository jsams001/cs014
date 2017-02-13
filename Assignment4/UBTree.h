#ifndef UBTREE_H
#define UBTREE_H

#include "dsexceptions.h"
#include <iostream>    // For NULL
using namespace std;     

ofstream outfile;

// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class UBTree
{
  public:
    UBTree( ) :root( NULL )
    {
    }

    UBTree( const UBTree & rhs ) : root( NULL )
    {
        *this = rhs;
    }

    /**
     * Destructor for the tree
     */
    ~UBTree( )
    {
        makeEmpty( );
    }

    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == NULL;
    }

    /**
     * Print the tree contents in sorted order.
     */
    // void printTree( ostream & out = cout ) const
    // {
    //     if( isEmpty( ) )
    //         out << "Empty tree" << endl;
    //     else
    //         printTree( root, out );
    // }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
     
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }

    /**
     * Deep copy.
     */
    const UBTree & operator=( const UBTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }
    /**
     * Helper function for prettyPrint found in main
     */
    void prettyPrint() {
        
        string p2 = "  ";
        string p3 = " <";
        prettyPrint(root, p2, p3);
    }

  private:
    struct HB_Node
    {
        Comparable element;
        HB_Node *left;
        HB_Node *right;

        HB_Node( const Comparable & theElement, HB_Node *lt, HB_Node *rt )
            : element( theElement ), left( lt ), right( rt ) { }
    };

    HB_Node *root;
  public:
    /**
     * My implemented function. Used to print out the tree 
     */
    void prettyPrint(HB_Node *t, string linePrefix, string nodeTag) {
        
        if(t == NULL) //was nullptr
            return;
        
        if(t == root) {
            nodeTag = " <";
            prettyPrint(t->right, linePrefix + "  ", " /");
            outfile << linePrefix << nodeTag << t->element << endl;
            prettyPrint(t->left, linePrefix + " ", " \\");
        }
        else if(nodeTag == " /") {
            prettyPrint(t->right, linePrefix + "  ", " /");
            outfile << linePrefix << nodeTag << t->element << endl;
            prettyPrint(t->left, linePrefix + "| ", " \\");
        }
        else if(nodeTag == " \\") {
            prettyPrint(t->right, linePrefix + "|  ", " /");
            outfile << linePrefix << nodeTag << t->element << endl;
            prettyPrint(t->left, linePrefix + "  ", " \\");
        }
        
        return;
    }


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, HB_Node * & t )
    {
        if( t == NULL )
            t = new HB_Node( x, NULL, NULL );
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, HB_Node * & t )
    {
        if( t == NULL )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != NULL && t->right != NULL ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            HB_Node *oldNode = t;
            t = ( t->left != NULL ) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    HB_Node * findMin( HB_Node *t ) const
    {
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    HB_Node * findMax( HB_Node *t ) const
    {
        if( t != NULL )
            while( t->right != NULL )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, HB_Node *t ) const
    {
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, HB_Node *t ) const
    {
        while( t != NULL )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( HB_Node * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( HB_Node *t, ostream & out ) const
    {
        if( t != NULL )
        {
            printTree( t->left, out );
            out << t->element << endl;
            printTree( t->right, out );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    HB_Node * clone( HB_Node *t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new HB_Node( t->element, clone( t->left ), clone( t->right ) );
    }
};

#endif