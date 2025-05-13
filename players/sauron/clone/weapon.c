/*--------------------------------------------------------------------------*/
/* FILE: /obj/weapon.c                                                      */
/*                                                                          */
/* DESC: This file contains the generic weapon object that should be        */
/*       inherited when you code a weapon.                                  */
/*       DO NOT COPY THIS FILE!                                             */
/*--------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 3 1997   Kryll        Cleaned up this file. Removed extraneous comments,
                          added full USERDOCs, and added functionality for
                          easy enchanted and weapon decay.
Mar 4 1997   Sauron       Rewritten into 'include' format for ease of
                          debugging and editing.
*/

#include "weapon/action.c"
#include "weapon/class.c"
#include "weapon/condition.c"
#include "weapon/general.c"
#include "weapon/hit.c"
#include "weapon/log.c"
#include "weapon/name.c"
#include "weapon/magic.c"
#include "weapon/size.c"
