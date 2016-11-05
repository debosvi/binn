
// TO ENABLE INLINE FUNCTIONS:
//   ON MSVC: enable the 'Inline Function Expansion' (/Ob2) compiler option, and maybe the
//            'Whole Program Optimitazion' (/GL), that requires the
//            'Link Time Code Generation' (/LTCG) linker option to be enabled too

#ifndef BINN_TYPES_H
#define BINN_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

    
#include <stdint.h>

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef BOOL
typedef int BOOL;
#endif

#ifndef BINN_PRIVATE
#   ifdef DEBUG
#       define BINN_PRIVATE
#   else
#       define BINN_PRIVATE  static
#   endif
#endif

#ifdef _MSC_VER
#   define INLINE         __inline
#   define ALWAYS_INLINE  __forceinline
#else
  // you can change to 'extern inline' if using the gcc option -flto
#   define INLINE         static inline
#   define ALWAYS_INLINE  static inline __attribute__((always_inline))
#endif

#ifdef _WIN32
#   define INT64_FORMAT  "I64i"
#   define UINT64_FORMAT "I64u"
#   define INT64_HEX_FORMAT  "I64x"
#else
#   define INT64_FORMAT  "lli"
#   define UINT64_FORMAT "llu"
#   define INT64_HEX_FORMAT  "llx"
#endif

extern int64_t atoi64(char *str);

#ifdef __cplusplus
}
#endif

#endif //BINN_TYPES_H
