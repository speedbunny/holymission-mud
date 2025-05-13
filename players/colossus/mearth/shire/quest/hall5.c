/* 971031, Uglymouth: removed MAKE_KEY macro, added replace_program().
 */
inherit "room/room";

void reset( int arg ) {
  clone_list = ({
    1, 1, "shiriff", "/players/colossus/mearth/shire/shiriff", 0,
   -1, 1, "metal key", "/obj/thing", ({
      "set_name", "metal key",
      "set_alias", "key",
      "set_alt_name", "iron",
      "set_short", "A metal key",
      "set_long", "A metal key. You wonder where it fits.\n",
      "set_value", 10,
    }),
  });

  set_light( 1 );
  short_desc = "Stairway to cells";
  long_desc = "A short hallway that ends at a set of stairs leading down "
    + "to the east. Set on the walls are scones for holding torches and "
    + "the main entrance hall lies at the other end of the hall to the "
    + "northwest.\n";
  dest_dir = ({
    "/players/colossus/mearth/shire/quest/hall", "northwest",
    "/players/colossus/mearth/shire/quest/hall10", "stairs",
  });
  items = ({
    "stairs", "Stone stairs that lead down to the cells",
    "walls", "The walls look stone cold",
    "scones", "These are metal rings sticking out of walls to hold torches",
  });

  ::reset(arg);
  replace_program( "room/room" );
}
