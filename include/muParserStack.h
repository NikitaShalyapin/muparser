#ifndef MU_PARSER_STACK_H
#define MU_PARSER_STACK_H

#include <cassert>
#include <string>
#include <stack>
#include <vector>

#include "muParserError.h"
#include "muParserToken.h"

/** \file 
    \brief This file defines the stack used by muparser.
*/

namespace mu
{

  template <typename TValueType>
  class ParserStack 
  {
    private:

      /** \brief Type of the underlying stack implementation. */
      typedef std::stack<TValueType, std::vector<TValueType> > impl_type;
      
      impl_type m_Stack;  ///< This is the actual stack.

    public:	
  	 
      //---------------------------------------------------------------------------
      ParserStack()
        :m_Stack()
      {}

      //---------------------------------------------------------------------------
      virtual ~ParserStack()
      {}

      //---------------------------------------------------------------------------
      /** \brief Pop a value from the stack.
       
        Unlike the standard implementation this function will return the value that
        is going to be taken from the stack.

        \throw ParserException in case the stack is empty.
        \sa pop(int &a_iErrc)
      */
	    TValueType pop()
      {
        if (empty())
          throw ParserError( _T("stack is empty.") );

        TValueType el = top();
        m_Stack.pop();
        return el;
      }

      /** \brief Push an object into the stack. 

          \param a_Val object to push into the stack.
          \throw nothrow
      */
      void push(const TValueType& a_Val) 
      { 
        m_Stack.push(a_Val); 
      }

      /** \brief Return the number of stored elements. */
      unsigned size() const
      { 
        return (unsigned)m_Stack.size(); 
      }

      /** \brief Returns true if stack is empty false otherwise. */
      bool empty() const
      {
        return m_Stack.empty(); 
      }
       
      /** \brief Return reference to the top object in the stack. 
       
          The top object is the one pushed most recently.
      */
      TValueType& top() 
      { 
        return m_Stack.top(); 
      }
  };
} // namespace MathUtils

#endif
