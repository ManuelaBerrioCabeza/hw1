#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

 /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   * space available at back
   * no space available back
   * empty list
   */
  void ULListStr::push_back(const std::string& val){
    if(tail_==NULL){
      tail_= new Item();
      head_=tail_;
      tail_->val[0]=val;
      tail_->first=0;
      tail_->last=1;
    }
    else if(tail_->last<ARRSIZE){
      tail_->val[tail_->last]= val;
      tail_->last ++;

    }
    else{
      Item* addItem = new Item();
      addItem->val[0] =val;
      addItem->first=0;
      addItem->last=1;
      addItem->prev=tail_;
      tail_->next= addItem;
      tail_=addItem;

    }
    size_++;
  }

  

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
    if(tail_ == NULL){
      return;
    }

    tail_->last--;
    if(tail_->first == tail_->last){
      Item* temp = tail_;
      tail_= tail_->prev;
      if(tail_!=NULL){
        tail_->next =NULL;

      }
      else{
        head_=NULL;
      }
      delete temp;
    }
    size_--;


  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   * 1: space available at front 
   * 2: no space available at front
   * 3: empty list 
   */
  void ULListStr::push_front(const std::string& val){
    if(head_==NULL){
      head_= new Item();
      tail_=head_;
      head_->val[ARRSIZE-1]=val;
      head_->first=ARRSIZE-1;
      head_->last=ARRSIZE;
    }
    else if(head_->first>0){
      head_->first--;
      head_->val[head_->first]=val;

    }
    else{
      Item* addItem = new Item();
      addItem->val[ARRSIZE-1] =val;
      addItem->first=ARRSIZE-1;
      addItem->last=ARRSIZE;
      addItem->next=head_;
      head_->prev= addItem;
      head_=addItem;

    }
    
    size_++;

  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if(head_ == NULL){
      return;
    }

    head_->first++;
    if(head_->first == head_->last){
      Item* temp = head_;
      head_= head_->next;
      if(head_!=NULL){
        head_->prev =NULL;

      }
      else{
        tail_=NULL;
      }
      delete temp;
    }
    size_--;

  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   *  Assumes list is NOT empty 
   * (dont worry about handling case when list is empty)
   */
  std::string const & ULListStr::back() const{
    return tail_->val[tail_->last -1];

  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   *  Assumes list is NOT empty 
   * (dont worry about handling case when list is empty)
   */
  std::string const & ULListStr::front() const{
    return head_->val[head_->first];

  }

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *  Will return a pointer to the i-th value in the entire list 
   * (not just in a single Item’s array) 
   * If a non-existent location provided to getValAtLoc should cause it to return NULL.
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const{
    if(loc>=size_){
      return NULL;
    }
    Item* curr =head_;
    size_t i = loc;

    while(curr!=NULL){
      size_t total = curr->last-curr->first;
      if(i<total){
        return &curr->val[curr->first+i];
      }
      i -= total;
      curr=curr->next;
    }
    return NULL;

  }

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
