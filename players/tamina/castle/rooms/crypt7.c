/*  This is in the Crypt  */

#include "/players/tamina/defs.h"

inherit "room/room";
object tomb;
int counter, gotten;

reset(arg) {
  counter = 0;
  gotten = 0;
  if (arg) return ;

      	set_light(-1);
	short_desc = "A Crypt under Camelot";
	long_desc = 
"In the apse to the east of the central room, you can see a single \n"+ 
"limestone tomb standing magnificently in the centre of the room.\n"+
"Around it are strange artifacts that glint mysteriously in the \n"+
"darkness.\n";

	dest_dir = ({
          CROOMS + "crypt6","west",
        });

	items = ({
  "shadows",
"Deep, black, almost moving figures in the dimness",
  "artifacts",
"There seem to be a few of the valuable remnants of the King's hoarde "+
"still left strewn across the floor around the tomb"
     });

  tomb = CLO (COBJ + "tomb2");
  MO (tomb, TO);

}

init() {
  ::init();
  add_action("get",  "get");
  add_action("get",  "take");
}

int get (string str) 
{
  object ob, treasure;

  if (str == "artifacts" || str == "artifact")
  {
    if (gotten) 
    {
      write("There are no artifacts worth getting...\n");
      return 1;
    }
    if (counter < 3)
    {
      write("As you start to lift up a few of the valuable artifacts that\n"+
            "lie around the tomb, you instantly hear a grinding of rock\n"+
            "and stone.  You drop all the bright things you tried to steal\n"+
            "from the tomb, and look around in fear...\n");
      say(TPN+" starts to lift up a few of the valuable looking artifacts\n"+
          "that were littered around the tomb.  You suddenly hear a grinding\n"+
          "of rock and stone...\n");

    ob = CLO("obj/monster");

    ob->set_name("watcher");
    ob->set_short("A Watcher");
    ob->set_long(
"A supernatural being, intended to watch over the tomb of its master.\n");
    ob->set_level(35);
    ob->set_wc(33);
    ob->set_ac(17);
    ob->set_aggressive(1);
    ob->set_al(-250);
    ob->set_spell_mess2(
"The Watcher's eyes glow with an eerie, powerful light, and boil your flesh!\n");
    ob->set_spell_mess1(
"The Watcher's eyes glow with an eerie, powerful light!\n");
    ob->set_spell_dam(30 + random(26));
    ob->set_chance(5);

      MO (ob, TO);

      counter++;

      return 1;
    }
    if (!present("watcher", TO))
    {
      write("You manage to take a few of the valuable artifacts from around the \n"+
            "tomb.\n");
      say(TPN+" takes a few of the artifacts from the tomb.\n");

        treasure = CLO ("obj/treasure");

        treasure->set_name("artifact");
        treasure->set_short("Valuable Artifact");
        treasure->set_long("This looks like it is an old relic from when ancient Kings ruled the land.\n");
        treasure->set_value(1000);
        treasure->set_weight(2);

      TR (treasure, TP);
      gotten = 1;
      return 1;
    }
  }
}
