<<<<<<< HEAD
/* See LICENSE of license details. */

#include <errno.h>
#include "stub.h"
#include "weak_under_alias.h"

int __wrap_close(int fd)
{
  return _stub(EBADF);
}
weak_under_alias(close);
=======
/* See LICENSE of license details. */

#include <errno.h>
#include "stub.h"
#include "weak_under_alias.h"

int __wrap_close(int fd)
{
  return _stub(EBADF);
}
weak_under_alias(close);
>>>>>>> 16c66438 (Upload from PC.)
