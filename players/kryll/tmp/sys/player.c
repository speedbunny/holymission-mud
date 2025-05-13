/*--------------------------------------------------------------------------*/
/* FILE: player.c                                                           */
/*                                                                          */
/* DESC: This file contains the generic player object that should be        */
/*       inherited when a new player begins.                                */
/*       DO NOT COPY THIS FILE!                                             */
/*--------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 30 1997  Kryll        Cleaned up this file. Removed extraneous comments,
                          created bin commands, and made it into includes
                          for easier debugging, and editing.

*/

#include "player/condition.c"
#include "player/description.c"
#include "player/general.c"
#include "player/group.c"
#include "player/guild.c"
#include "player/heartbeat.c"
#include "player/level.c"
#include "player/misc.c"
#include "player/more.c"
#include "player/prompt.c"
#include "player/score.c"
#include "player/start.c"

nomask inherit "/secure/valid";
inherit "/sys/living";

