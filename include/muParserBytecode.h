#ifndef MU_PARSER_BYTECODE_H
#define MU_PARSER_BYTECODE_H

#include <cassert>
#include <string>
#include <stack>
#include <vector>

#include "muParserDef.h"
#include "muParserError.h"
#include "muParserToken.h"


namespace mu
{
  struct SToken
  {
    ECmdCode Cmd;
    int StackPos;

    union
    {
      struct //SValData
      {
        value_type *ptr;
        value_type  data;
        value_type  data2;
      } Val;

      struct //SFunData
      {
        // Note: generic_fun_type is merely a placeholder. The real type could be 
        //       anything between gun_type1 and fun_type9. I can't use a void
        //       pointer due to constraints in the ANSI standard which allows
        //       data pointers and function pointers to differ in size.
        generic_fun_type ptr;
        int   argc;
        int   idx;
      } Fun;

      struct //SOprtData
      {
        value_type *ptr;
        int offset;
      } Oprt;
    };
  };
  

class ParserByteCode
{
private:

    /** \brief Token type for internal use only. */
    typedef ParserToken<value_type, string_type> token_type;

    /** \brief Token vector for storing the RPN. */
    typedef std::vector<SToken> rpn_type;

    /** \brief Position in the Calculation array. */
    unsigned m_iStackPos;

    /** \brief Maximum size needed for the stack. */
    std::size_t m_iMaxStackSize;
    
    /** \brief The actual rpn storage. */
    rpn_type  m_vRPN;

    bool m_bEnableOptimizer;

    void ConstantFolding(ECmdCode a_Oprt);

public:

    ParserByteCode();
    ParserByteCode(const ParserByteCode &a_ByteCode);
    ParserByteCode& operator=(const ParserByteCode &a_ByteCode);
    void Assign(const ParserByteCode &a_ByteCode);

    void AddVar(value_type *a_pVar);
    void AddVal(value_type a_fVal);
    void AddOp(ECmdCode a_Oprt);
    void AddIfElse(ECmdCode a_Oprt);
    void AddAssignOp(value_type *a_pVar);
    void AddFun(generic_fun_type a_pFun, int a_iArgc);
    void AddBulkFun(generic_fun_type a_pFun, int a_iArgc);
    void AddStrFun(generic_fun_type a_pFun, int a_iArgc, int a_iIdx);

    void EnableOptimizer(bool bStat);

    void Finalize();
    void clear();
    std::size_t GetMaxStackSize() const;
    std::size_t GetSize() const;

    const SToken* GetBase() const;
    void AsciiDump();
};

} // namespace mu

#endif


