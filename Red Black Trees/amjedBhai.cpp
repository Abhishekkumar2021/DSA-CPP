#include<iostream>

using namespace std;

class rbtree
{

  public:
  int data;
  bool colour;
  rbtree *left;
  rbtree *right;
  rbtree *par;
  
  rbtree(int d)
  {
    data  = d;
    left  = NULL;
    right = NULL;
    colour = 0;
  }
};
rbtree *pseudo_insertelement(int x,rbtree *t)
{
  if(t == NULL)
  {
    t = new rbtree(x);
  }
  else if(x < t->data)
    t->left = pseudo_insertelement(x,t->left);
  else if(x > t->data)
    t->right = pseudo_insertelement(x,t->right);
  return t;
}
void rotateleft(rbtree *root, rbtree *pt)
{
  rbtree *pt_right = pt->right;
  pt->right = pt_right->left;
  if (pt->right != NULL)
        pt->right->par = pt;
 
    pt_right->par = pt->par;
 
    if (pt->par == NULL)
        root = pt_right;
 
    else if (pt == pt->par->left)
        pt->par->left = pt_right;
 
    else
        pt->par->right = pt_right;
 
    pt_right->left = pt;
    pt->par = pt_right;
}
void rotateRight(rbtree *root, rbtree *pt)
{
    rbtree *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->par = pt;
 
    pt_left->par = pt->par;
 
    if (pt->par == NULL)
        root = pt_left;
 
    else if (pt == pt->par->left)
        pt->par->left = pt_left;
 
    else
        pt->par->right = pt_left;
 
    pt_left->right = pt;
    pt->par = pt_left;
}
rbtree *fixing_colour(rbtree *root,rbtree *pt)
{
  rbtree *par_pt = NULL;
  rbtree *grand_par_pt = NULL;
 
    while ((pt != root) && (pt->colour != 0) &&
           (pt->par->colour == 1))
    {
 
        par_pt = pt->par;
        grand_par_pt = pt->par->par;
 
        /*  Case : A
            Parent of pt is left child
            of Grand-parent of pt */
        if (par_pt == grand_par_pt->left)
        {
 
            rbtree *uncle_pt = grand_par_pt->right;

            /* Case : 1
               The uncle of pt is also red
               Only Recolouring required */
            if (uncle_pt != NULL && uncle_pt->colour ==
                                                   1)
            {
                grand_par_pt->colour = 1;
                par_pt->colour = 0;
                uncle_pt->colour = 0;
                pt = grand_par_pt;
            }

            else
            {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == par_pt->right)
                {
                    rotateleft(root, par_pt);
                    pt = par_pt;
                    par_pt = pt->par;
                }
 
                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_par_pt);
                swap(par_pt->colour,
                           grand_par_pt->colour);
                pt = par_pt;
            }
        }
 
        /* Case : B
           Parent of pt is right child
           of Grand-parent of pt */
        else
        {
            rbtree *uncle_pt = grand_par_pt->left;
 
            /*  Case : 1
                The uncle of pt is also red
                Only Recolouring required */
            if ((uncle_pt != NULL) && (uncle_pt->colour ==
                                                    1))
            {
                grand_par_pt->colour = 1;
                par_pt->colour = 0;
                uncle_pt->colour = 0;
                pt = grand_par_pt;
            }

            else
            {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == par_pt->left)
                {
                    rotateRight(root, par_pt);
                    pt = par_pt;
                    par_pt = pt->par;
                }
 
                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateleft(root, grand_par_pt);
                swap(par_pt->colour,
                         grand_par_pt->colour);
                pt = par_pt;
            }
        }
    }

    root->colour = 0;
}

rbtree *insertelement(int data)
{
  rbtree *pt = new rbtree(data);
  int x= pt->data;
  rbtree *root = pseudo_insertelement(x,root);
  fixing_colour(root,pt);
}
  
void printPreorder(rbtree* root)
{
    if (root == NULL)
        return;
 
    /* first print data of node */
    cout << root->data << " ";
 
    /* then recur on left subtree */
    printPreorder(root->left);
 
    /* now recur on right subtree */
    printPreorder(root->right);
}

int main()
{
  rbtree *root = NULL;
  int n;
  cin>>n;
  for( int i=0; i<n ;i++)
  {
     int value;
     cin>>value;
     root = insertelement(value);
  }
  
  printPreorder(root);
  
  return 0;
}