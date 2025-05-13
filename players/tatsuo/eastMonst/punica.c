#define NIN_WEAP_PATH "/players/tatsuo/guild/nweap/"
#define NIN_WEAP_LIST \
                ({ "nstick","yari","nagimaki","bisento","naginata","gama",\
                   "kama","nunchaku","sa-tja-koen","shogi","sai" })

#define PPATH ("/players/tatsuo/eastMonst/")
inherit "obj/monster";

reset(arg)
{
   int rnd;
   string wep_name;

   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "punica" );
   set_level( 20 );
   set_size( 2 );
   set_short( "a juicy punica" );
   set_long( "ahhhh, refresshing !   You should drink it !\n" );

   set_n_wc(30 );

}
void init()
{
   add_action( "drink", "drink" );
   add_action( "drink", "get" );
}

void long()
{
   write( long_desc );
}

int drink( string arg )
{
   attack_object( this_player() );
   write( "oops !\n" );
   return( 1 );
}
