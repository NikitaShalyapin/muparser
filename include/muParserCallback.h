
#ifndef MU_PARSER_CALLBACK_H
#define MU_PARSER_CALLBACK_H

#include "muParserDef.h"


namespace mu
{


class API_EXPORT_CXX ParserCallback
{
public:
    ParserCallback(fun_type0  a_pFun, bool a_bAllowOpti);
    ParserCallback(fun_type1  a_pFun, bool a_bAllowOpti, int a_iPrec = -1, ECmdCode a_iCode=cmFUNC);
    ParserCallback(fun_type2  a_pFun, bool a_bAllowOpti, int a_iPrec, EOprtAssociativity a_eAssociativity);
    ParserCallback(fun_type2  a_pFun, bool a_bAllowOpti);
    ParserCallback(fun_type3  a_pFun, bool a_bAllowOpti);
    ParserCallback(fun_type4  a_pFun, bool a_bAllowOpti);
    ParserCallback(fun_type5  a_pFun, bool a_bAllowOpti);
    ParserCallback(fun_type6  a_pFun, bool a_bAllowOpti);
    ParserCallback(fun_type7  a_pFun, bool a_bAllowOpti);
    ParserCallback(fun_type8  a_pFun, bool a_bAllowOpti);
    ParserCallback(fun_type9  a_pFun, bool a_bAllowOpti);
    ParserCallback(fun_type10 a_pFun, bool a_bAllowOpti);

    ParserCallback(bulkfun_type0  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type1  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type2  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type3  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type4  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type5  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type6  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type7  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type8  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type9  a_pFun, bool a_bAllowOpti);
    ParserCallback(bulkfun_type10 a_pFun, bool a_bAllowOpti);

    ParserCallback(multfun_type a_pFun, bool a_bAllowOpti);
    ParserCallback(strfun_type1 a_pFun, bool a_bAllowOpti);
    ParserCallback(strfun_type2 a_pFun, bool a_bAllowOpti);
    ParserCallback(strfun_type3 a_pFun, bool a_bAllowOpti);
    ParserCallback();
    ParserCallback(const ParserCallback &a_Fun);
    
    ParserCallback* Clone() const;

    bool  IsOptimizable() const;
    void* GetAddr() const;
    ECmdCode  GetCode() const;
    ETypeCode GetType() const;
    int GetPri()  const;
    EOprtAssociativity GetAssociativity() const;
    int GetArgc() const;

private:
    void *m_pFun;                   ///< Pointer to the callback function, casted to void
    
    /** \brief Number of numeric function arguments
    
        This number is negative for functions with variable number of arguments. in this cases
        they represent the actual number of arguments found.
    */
    int   m_iArgc;      
    int   m_iPri;                   ///< Valid only for binary and infix operators; Operator precedence.
    EOprtAssociativity m_eOprtAsct; ///< Operator associativity; Valid only for binary operators 
    ECmdCode  m_iCode;
    ETypeCode m_iType;
    bool  m_bAllowOpti;             ///< Flag indication optimizeability 
};

//------------------------------------------------------------------------------
/** \brief Container for Callback objects. */
typedef std::map<string_type, ParserCallback> funmap_type; 

} // namespace mu

#endif

