/* 971011, Uglymouth: Recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  clone_list = ({
    1, 1, "police sergeant", "obj/monster", ({
      "set_name", "police sergeant",
      "set_alias", "sergeant",
      "set_short", "A police sergeant",
      "set_long", "This ugly brute makes you glad you are not a prisoner.\n",
      "set_level", 5,
      "set_hp", 200,
      "set_al", 50,
      "set_male", 0,
      "set_spell_mess1",
        "The police sergeant kicks his opponent with a dagger-tipped boot",
      "set_spell_mess2",
        "The police sergeant kicks you with a dagger-tipped boot",
      "set_chance", 20,
      "set_spell_dam", 10,
      "set_aggressive", 1,
    }),
    -1, 1, "membership", "players/padrone/secret_police/membership", 0,
    -1, 1, "short sword", "obj/weapon", ({
      "set_name", "short sword",
      "set_alias", "shortsword",
      "set_alt_name", "sword",
      "set_short","A short sword",
      "set_long", "The standard duty weapon of a police sergeant.\n",
      "set_class", 15,
      "set_value", 700,
      "set_weight", 2,
    }),
    -1, 1, "iron key", "obj/thing", ({
      "set_name", "steel key",
      "set_alias", "key",
      "set_alt_name", "cell key",
      "set_short", "An steel key",
      "set_long", "The steel key of a police cell.\n",
      "set_value", 10,
    }),
    2, 1, "policeman", "obj/monster", ({
      "set_name"," secret policeman",
      "set_alias","policeman",
      "set_short", "A policeman",
      "set_long", "The policeman stands alert upon inspection.\n",
      "set_level", 1,
      "set_al", 60,
      "set_male", 0,
      "set_spell_mess1", "The policeman throws a quick punch\n",
      "set_spell_mess2", "The policeman punches you",
      "set_chance", 10,
      "set_spell_dam", 10,
      "set_aggressive", 1,
    }),
    -2, 1, "membership", "players/padrone/secret_police/membership", 0,
    -2, 1, "billy club", "obj/weapon", ({
      "set_name", "billy club",
      "set_alias", "club",
      "set_short", "A billy club",
      "set_long", "The standard duty weapon of a policemen.\n",
      "set_class", 5,
      "set_value", 10,
      "set_weight", 2,
    }),
  });
  ::reset( arg );

  set_light(1);
  short_desc = "The Police Interrogation Room";
  long_desc = "The Police Interrogation Room.\n"
    + "A dim and barren, gray square cubicle, lacking any windows, "
    + "ideal for its purpose. An iron door leads east to freedom. The "
    + "cell door to the west leads to dark suffering.\n";
  dest_dir = ({
    "players/padrone/secret_police/cell", "west",
    "players/padrone/secret_police/hall", "east",
  });
  items = ({
    "door", "Choose the iron door or the cell door",
    "iron door", "dummy door description",
    "cell door", "dummy door description",
  });

  set_door( "cell door" );
  set_door_desc( "cell door", "This is a solid steel door with steel "
    + "hinges, a barred window and a steel lock" );
  set_door_direction( "cell door", "west" );
  set_lock_status( "cell door", DOOR_LOCKED );
  set_door_key( "cell door", "celldoor" );
  set_door_reset( "cell door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "cell door",
    "The police sergeant makes sure the cell door is properly locked.\n" );
  set_other_door( "cell door" );
  replace_program( DOOR_ROOM );
}

