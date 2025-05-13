#define PPATH ("/players/patience/eastMonst/")
inherit "obj/monster";

reset(arg)
{
   int rnd;
   object wep;  /* whisky */
   string wep_name;

   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "shikome" );
    set_level( 10);
   set_size( 2 );
   set_short( "a shikome" );
   set_long( "A shikome is a goblin-like being dwelling in the wild parts of nihon.\n" +
             "It lives in caves and under the earth. It envies and hates all humans\n" +
             "who have mostly supplanted it in Nihon, taking the best land for their own.\n"
             "Many have migrated to the remote island of Ishikawa where they continue their hatred.\n");

   move_object( clone_object( PPATH + "shikome_blood" ), this_object() );

   rnd = random( 50 );
   switch( rnd ) {
      case 0..10:
         transfer( wep=clone_object( "/players/patience/guild/nweap/nstick" ), 
                   this_object() );
         break;
      case 11..21:
         transfer( wep=clone_object( "/players/patience/guild/nweap/yari" ),    
                   this_object() );
         break;
      case 22..27:
         transfer( wep=clone_object( "/players/patience/guild/nweap/bisento" ),
                  this_object() );
         break;
      case 28..40:
         transfer( wep=clone_object( "/players/patience/guild/nweap/naginata" ),
                  this_object() );
         break;
      case 41..49:
         transfer( wep=clone_object( "/players/patience/guild/nweap/sa-tja-koen"),
                  this_object() );
         break;
      default: 
         break;
   }

   /* whisky wields now again */
    if (objectp(wep))
    {
      wep_name = wep->query_name();
   command("wield "+wep_name);
    }
   set_dead_ob( "/players/patience/eastMonst/monst_died" );
}

/* removed whisky.. newbiekiller on the way to the guild
init( )
{
   ::init();

   if ( this_player() && this_player()->query_race() == "human" )
      set_aggressive( 1 );
}
  end comment */
