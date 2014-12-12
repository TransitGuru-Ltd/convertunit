#ifndef __DEBUG_H__
#define __DEBUG_H__

#define _CONU_ERR_MSG_BUFFER_SZ 512

enum conu_err_codes
{
  CONU_SUCCESS,
  CONU_UNDEF_ERR,
  CONU_MALLOC_ERR
};

struct conu_err_t
{
  uint code;
  char msg[_CONU_ERR_MSG_BUFFER_SZ];
};

#define _CHECK_MEM_ALLOC(palloc, pcuz_err, finally_block)                   \
  if ( (palloc) == NULL )                                                   \
  {                                                                         \
    (pcuz_err)->code = CONU_MALLOC_ERR;                                     \
    snprintf ((pcuz_err)->msg, _CONU_ERR_MSG_BUFFER_SZ,                     \
      "Memory allocation error in line %d of file %s (function %s)\n",      \
      __LINE__, __FILE__, __func__);                                        \
    finally_block                                                           \
  }

#endif
