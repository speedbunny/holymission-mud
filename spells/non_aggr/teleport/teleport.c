
/* ################################################################
   #								  #
   #    		Mage teleport                             #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
    if (lev < 20) return 2;
    if (lev < 25) return 1;
    return 0;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "teleport" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'teleport' <destination>" );
   set_guild_allowed( 5, 13 );
   set_save_vs( NO_SAVE );
   set_cost( 30 );
   set_player_help(
"This spell will only work if you have used the 'memorize' command \n"+
"previously and stored the room to be teleported to.\n\n"+
"The number of rooms you can memorize depends on your level and int.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, sh;
   string oppo_name;
   mapping mem;
   string dest;
   object destr;
   int cost;

   if(!arg) {
       write("To which memorized site would you like to teleport to ??\n");
       return;
   };
   if(!(mem=TP->queryenv("MEMORIZE"))) {
       write("You have nothing memorized at all!\n");
       return;
   };
   if(!(dest=mem[arg])) {
       write("You didn't memorize this site ("+arg+") !\n");
       return;
   };
   if(catch(call_other(dest,"???",0))) {
       write("It seems that you are unable to reach that place at the moment.\n");
       return;
   };
   destr = find_object(dest);
 
   if (environment(TP)->query_property("no_teleport") ||
       destr->query_property("no_teleport"))
   {
       write("Ancient magic bars your way!\n");
       return;
   };

   if ( check_success( act_skill, max_skill ) )
   {
      TP->move_player("disappears in a puff of smoke", destr, 1,
                      "arrives out of thin air");
   }
}
