/******************************************************************************/
/*                                                                            */
/*                 X r d S c i T o k e n s H e l p e r . h h                  */
/*                                                                            */
/******************************************************************************/
  
#include <string>
#include <vector>

//-----------------------------------------------------------------------------
//! This class defines the XrdAccSciTokens API to perform token validation as
//! well as getting the list of valid issuers. It requires that the SciTokens
//! authorization plugin be loaded and initialized. Upon successful loading
//! and initialization the symbol "SciTokensHelper" will contain the address
//! of an instance of this class.
//-----------------------------------------------------------------------------

class XrdSciTokensHelper
{
public:

//-----------------------------------------------------------------------------
//! Get the list of valid issuers.
//!
//! @result  A vector of valid issuers.  The list of issuers never changes.
//!          Only a reconfig of the scitokens plugin could cause the issuer
//!          list to change, which right now only happens in plugin 
//!          initialization.
//-----------------------------------------------------------------------------

struct   ValidIssuer
        {std::string issuer_name;
         std::string issuer_url;
        };
typedef std::vector<ValidIssuer> Issuers;

virtual  Issuers IssuerList() = 0;

//-----------------------------------------------------------------------------
//! Validate a scitoken.
//!
//! @param   token - Pointer to the token to validate.
//! @param   emsg  - Reference to a string to hold the reason for rejection
//!
//! @result  Return true if the token is valid; false otherwise with emsg set.
//-----------------------------------------------------------------------------

virtual  bool    Validate(const char *token, std::string &emsg) = 0;

//-----------------------------------------------------------------------------
//! Constructor and Destructor.
//-----------------------------------------------------------------------------

         XrdSciTokensHelper() {}
virtual ~XrdSciTokensHelper() {}
};
