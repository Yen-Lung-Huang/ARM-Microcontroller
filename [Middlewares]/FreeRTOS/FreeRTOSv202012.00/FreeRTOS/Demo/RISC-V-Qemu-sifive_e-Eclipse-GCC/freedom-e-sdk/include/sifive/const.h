<<<<<<< HEAD
// See LICENSE for license details.
/* Derived from <linux/const.h> */

#ifndef _SIFIVE_CONST_H
#define _SIFIVE_CONST_H

#ifdef __ASSEMBLER__
#define _AC(X,Y)        X
#define _AT(T,X)        X
#else
#define _AC(X,Y)        (X##Y)
#define _AT(T,X)        ((T)(X))
#endif /* !__ASSEMBLER__*/

#define _BITUL(x)       (_AC(1,UL) << (x))
#define _BITULL(x)      (_AC(1,ULL) << (x))

#endif /* _SIFIVE_CONST_H */
=======
// See LICENSE for license details.
/* Derived from <linux/const.h> */

#ifndef _SIFIVE_CONST_H
#define _SIFIVE_CONST_H

#ifdef __ASSEMBLER__
#define _AC(X,Y)        X
#define _AT(T,X)        X
#else
#define _AC(X,Y)        (X##Y)
#define _AT(T,X)        ((T)(X))
#endif /* !__ASSEMBLER__*/

#define _BITUL(x)       (_AC(1,UL) << (x))
#define _BITULL(x)      (_AC(1,ULL) << (x))

#endif /* _SIFIVE_CONST_H */
>>>>>>> 16c66438 (Upload from PC.)
