#define NIN_WEAP_PATH "/players/tatsuo/guild/nweap/"
#define NIN_WEAP_LIST \
                ({ "nstick","yari","nagimaki","bisento","naginata","gama",\
                   "kama","nunchaku","sa-tja-koen","shogi","sai" })

#define PPATH ("/players/tatsuo/eastMonst/")
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
   set_level( 6 );
   set_size( 2 );
   set_short( "a shikome" );
   set_long( "A shikome is a goblin-like being dwelling in the wild parts of nihon.\n" +
             "It lives in caves and under the earth. It envies and hates all humans\n" +
             "who have mostly supplanted it in Nihon, taking the best land for their own.\n" );

   move_object( clone_object( PPATH + "shikome_blood" ), this_object() );

   if ( !random(5) )
      transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),
               this_object() );
   if ( !random(8) )
      transfer(clone_object("/players/tatsuo/guild/nother/white_pepper"),
               this_object() );

   transfer( clone_object(NIN_WEAP_PATH+
             NIN_WEAP_LIST[random(sizeof(NIN_WEAP_LIST))]), this_object() );

   /* whisky wields now again */
    if (objectp(wep))
    {
      wep_name = wep->query_name();
      command("wield "+wep_name, this_object());
    }
   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}

/* removed whisky.. newbiekiller on the way to the guild
init( )
{
   ::init();

   if ( this_player() && this_player()->query_race() == "human" )
      set_aggressive( 1 );
}
  end comment */
