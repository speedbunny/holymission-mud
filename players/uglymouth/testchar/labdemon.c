/* Uglymouth's pet testmonster */
inherit "obj/monster";

void reset( int arg ) {
 ::reset( arg );
  if( arg ) return;

  set_name("labdemon");
  set_alias("demon");
  set_short("Uglymouth's labdemon");
  set_long(short() + ".\nIt's a green hairy ball with five human-like arms.\n"
      + "It floats in the air, turning around slowly.\n");
  set_race("vulgarian");
  set_level(4);
}
