
/* ################################################################
   #								  #
   #    		NINJA SPELL                               #
   #                                          		          #
   ###############################################(C) Pat########## */

#include "ninja.h"

#define SPELL_COST 50

speed(lev)
{
   return( 3 );
}

level() {   return 10; }
help () {   return HDIR+"scry"; }
cost () {   return SPELL_COST; }

do_spell(arg,skill)
{

   write( "TESTING OK" )
   return( 1 );
}

query_name()
{
   return( "shadow gate" );
}

query_command()
{
   return( "cast 'shadow gate' [target]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'flodak noky'" }) +
      ({ 0 })
   );
}
