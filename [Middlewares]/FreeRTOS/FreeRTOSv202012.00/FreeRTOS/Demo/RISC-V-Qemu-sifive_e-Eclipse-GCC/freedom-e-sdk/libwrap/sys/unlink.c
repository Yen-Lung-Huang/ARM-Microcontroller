<<<<<<< HEAD
/* See LICENSE of license details. */

#include <errno.h>
#include "stub.h"
#include "weak_under_alias.h"

int __wrap_unlink(const char* name)
{
  return _stub(ENOENT);
}
weak_under_alias(unlink);
=======
/* See LICENSE of license details. */

#include <errno.h>
#include "stub.h"
#include "weak_under_alias.h"

int __wrap_unlink(const char* name)
{
  return _stub(ENOENT);
}
weak_under_alias(unlink);
>>>>>>> 16c66438 (Upload from PC.)
