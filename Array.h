
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          // for size_t definition

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
class Array
{
public:
  // Default constructor.
  Array (void);

  /**
   * Initializing parameterized constructor.
   */
  Array (size_t length);

  /**
   * Initializing constructor with multiple parameters
   */
  Array (size_t length, char fill);

  /**
   * Copy constructor
   */
  Array (const Array & arr);

  // Destructor.
  ~Array (void);

  /**
   * Assignment operation
   */
  const Array & operator = (const Array & rhs);

  /**
   * Retrieve the current size of the array.
   */
  size_t size (void) const;

  /**
   * Retrieve the maximum size of the array.
   */
  size_t max_size (void) const;

  /**
   * Get the character at the specified index. Also throw exception error If the index is not
   * within the range of the array
   */
  char & operator [] (size_t index);

  /**
   * @overload
   *
   * The returned character is not modifiable.
   */
  const char & operator [] (size_t index) const;

  /**
   * Get the character at the specified index. If the \a index is not within
   * the range of the array, then std::out_of_range exception is thrown.
   */
  char get (size_t index) const;

  /**
   * Set the character at the specified \a index. If the \a index is not
   * within range of the array, then std::out_of_range exception is
   * thrown.
   */
  void set (size_t index, char value);

  /**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the
   * array's size is either increased or decreased.
   */
  void resize (size_t new_size);

  /// Shrink the array to reclaim unused space.
  void shrink ();

  /**
   * Locate the specified character in the array. The index of the first
   * occurrence of the character is returned. If the character is not
   * found in the array, then -1 is returned.
   */
  int find (char ch) const;

  /**
   * @overload
   *
   * This version allows you to specify the start index of the search. If
   * the start index is not within the range of the array, then the
   * std::out_of_range exception is thrown.
   */
  int find (char ch, size_t start) const;

  /**
   * Test the array for equality.
   */
  bool operator == (const Array & rhs) const;

  /**
   * Test the array for inequality.
   */
  bool operator != (const Array & rhs) const;

  /**
   * Fill the contents of the array.
   */
  void fill (char ch);

  /// Reverse the contents of the array such that the first element is now
  /// the last element and the last element is the first element.
  void reverse (void);

private:


  void assign(const Array &rhs);


  /// Pointer to the actual data.
  char * data_;

  /// Current size of the array.
  size_t cur_size_;

  /// Maximum size of the array.
  size_t max_size_;
};

#include "Array.inl"

#endif   // !defined _ARRAY_H_
