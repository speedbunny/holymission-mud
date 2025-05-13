
/* ################################################################
   #								  #
   #    		Mage continual light spell                #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev > 20) return 0;
   return 1;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "continual light" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'continual light' <object>" );
   set_guild_allowed( 5, 6);
   set_save_vs( NO_SAVE );
   set_cost( 100 );
   set_player_help(
"If cast on an item, that spell lightens it. The Spell can not be cast on\n"+
"item already lighted. You have to have the item in your inventory while\n"+
"casting. The effect of the spell is permanent.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object ob;
   int ll;

   if(!arg)
   {
       write("On which object whould you like to cast the spell?\n");
       return;
   }

   if(!ob=present(arg,TP))
   {
       write("You don't have such an item.\n");
       return;
   };
 
   if ( check_success( act_skill, max_skill ) )
   {
       ll=ob->_light_level();
       if(ll>0)
       {
          write("This item ("+ob->query_name()+") is already lighted.\n");
          return;
       };

       if(ll<0)
       {
          write("The "+ob->query_name()+" seems to be a bit less dark now.\n");
          ob->_set_light_level(ll+1);
       };

       ob->_set_light_level(1);
       if(!ob->_light_level())
       {
          write("The "+ob->query_name()+
                " withstood your attempt to brighten it!\n");
          return;
       }
   
       ob->set_short(ob->short()+"(glowing)");
       say(TPNT+"'s "+ob->query_name()+" glows brighter now.\n",0,TP,"");
       write("Your "+ob->query_name()+" starts emmitting bright light.\n");
   }
}
