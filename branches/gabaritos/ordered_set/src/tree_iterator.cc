// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_set/src/tree_iterator.h"

#include <stdlib.h>

#include "ordered_set/src/tree_node.h"

TreeIterator::TreeIterator(TreeNode* p) {
  ptr_ = p;
}

type TreeIterator::Key() {
  return ptr_->key;
}

bool TreeIterator::Nil() {
  return ptr_ == NULL;
}

TreeIterator TreeIterator::Minimum() {

}

TreeIterator TreeIterator::Maximum() {

}

TreeIterator TreeIterator::Search(type k) {
  if (Nil() || k == Key()) {
    return (*this);
  } else if (k < Key()) {
    return TreeIterator(ptr_->left).Search(k);
  } else {
    return TreeIterator(ptr_->right).Search(k);
  }
}

TreeIterator TreeIterator::Succerssor(TreeIterator& x) {

}

TreeIterator TreeIterator::Predecerssor(TreeIterator& x) {

}
