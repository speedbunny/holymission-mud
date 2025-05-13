#define TP    (this_player())
#define TPN   this_player()->query_name()

inherit "obj/monster";

#define SKILL_PATH "/players/tatsuo/skill/skill_rout"

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "hudriwudri" );
   set_alias( "priest" );
   set_short( "Hudriwudri" );
   set_long("This is Hudriwudri, a very powerful priest of the amida cult.\n" +
             "Maybe he will help you if you ask him.\n");
   set_level( 50 );
   set_size( 2 );
   set_gender( 1 );
}

init()
{
   ::init();

   add_action( "do_show", "show" );
}

do_cost()
{
   return( SKILL_PATH->cost_it() );
}

do_raise( arg )
{
   return( SKILL_PATH->raise_it() );
}

do_help( arg )
{
   return( SKILL_PATH->help_it() );
}

catch_tell( arg )
{
   string who, what, *arr;

   if ( arg ) {
/*
      sscanf( arg, "%s says: %s", who, what );
      if ( !what || !strlen( what ) )
         what = arg;
      arr = explode( what, " " );
      if ( member_array("help",arr)>-1 || member_array("help\n",arr)>-1 ) 
         return( SKILL_PATH->help_it() );
      else if ( member_array("raise",arr)>-1 || member_array("raise\n",arr)>-1 )
         return( SKILL_PATH->raise_it(what) );
      else if ( member_array("cost",arr)>-1 || member_array("cost\n",arr)>-1 ) 
         return( SKILL_PATH->cost_it() );
*/    ;
   }
}

attack()
{
   if ( random( 100 ) < 7 )
      "/players/tatsuo/guild/sorcerer_spells/freeze"->do_freeze();
   return( ::attack() );
}

get_skill( str )
{
   if ( !stringp( str ) )
      return;

   return( ({100,100,-1}) );
}

do_show( string arg )
{
   object parch;

   if ( !arg ) {
      write( "Show what to whom ?\n" );
   }
   else if ( !(arg == "parchment to hudriwudri-san" || 
        arg == "parchment to Hudriwudri-san") )
   {
       write( "Hudriwudri-san ignores you. Have you used the right title ?\n" );
   }
   else {
      if ( this_player()->query_guild() != 8 ) {
         write( "Hudriwudri-san yells: GO AWAY, UNTRUSTWORTHY !\n" );
         return( 1 );
      }
      if ( this_player()->query_level() < 20 ) {
         write( "Hudriwudri-san says: I won't decipher this for you, lad.\n"+
                "   Give the parchment to a more experienced ninja.\n" );
         return( 1 );
      }
      parch = present( "unreadable_ninja_parch", this_player() );
      if ( parch ) {
         write( "Hudriwudri-san studies the scroll intently, then whispers to you:\n"+
     "Ahh, this scroll is very old indeed. It is said there, that there is\n"+
     "a secret tunnel connecting Ezo with the main-island. But in the\n"+
     "parchment is only described, how you can go from Ezo to the mainland.\n"+
     "There must be crack somewhere in the connecting-way between the guild\n"+
     "and the torii. You have to enter it and you are in a huge tunneling-\n"+
     "system. But beware, it is also said here, that the tunnels are very\n"+
     "dangerous, even deadly. They are full of traps and unsafe room.\n"+
     "And I guess, because it wasn't used for such a long time, there might\n"+
     "have some vicious monsters settled down in the abandoned caves.\n"+
     "You need a password somewhere within the cave to open a gate,\n"+
     "but for ill sake the password is encrypted an not even I can solve it.\n"+
     "So beware, fellow, and uncover the lost secret for the guild again.\n"+
     "\nBut, "+TPN+", under no circumstances this secret information may\n"+
     "fall into the hands of unworthy!!! So consider well, with whom thee\n"+
     "will share thy secret, or you will feel the wrath of the guild !!!\n"+
     "\nYoshihiro-san points with a finger at the parchment, which crumbles\n"+
     "to ashes ....\n" );
      destruct( parch );
      }
      else {
         write( "Hudriwudri-san ignores you. Have you used the right title ?\n" );
      }
   }
   return( 1 );
}
