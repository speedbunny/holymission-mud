inherit "/obj/armour";

reset( arg )
{
    ::reset( arg );

    if ( arg )
	return;

   set_name( "o-yori");
  set_alias( "oyori" );
  set_type( "armor");
 set_ac(6);
    set_size(0);

  set_short( "O-yori battle armour");
    
    set_long( 
    "A complete set of nihonese O-yori armour, complete with mask and helmet.\n");
  set_weight(8);
}

query_ninja_wear( ) { return( 1 ); }
drop () { write("Never drop your O-yori!\n"); return 1; }
query_auto_load() {
  if(this_player()->query_guild() == 8 ){
   return "/players/tatsuo/guild/narmour/oyori:"; } }
