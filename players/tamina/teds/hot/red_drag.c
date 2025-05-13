inherit "room/room";

#include "/players/tamina/defs.h"

object dragon;

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(1);
    short_desc = "Volcanic Cave";
    long_desc =
	"This is a large cave where part of the volcano\n"+
	"cracked. It is very hot, sweat begins to form\n"+
	"on your brow. A strange sound can be heard comming\n"+
	"from an opening to the east.\n";

    dest_dir = ({
	  THOT + "volcano","west",
	  THOT + "earth_drag","east",
	});
    
    }
    if (!present("red dragon")) 
    {
      dragon = clone_object("obj/monster");

      dragon->set_name("red dragon");
      dragon->set_race("dragon");
      dragon->set_gender(1);
      dragon->set_long("A Flame Red Dragon.\n");
      dragon->set_level(19);
      dragon->set_wc(15);
      dragon->set_ac(10);
      dragon->set_spell_mess1("The Dragon breathes Fire.\n");
      dragon->set_spell_mess2("The Dragon blasts you with Fire !!\n");
      dragon->set_spell_dam(45);
      dragon->set_chance(25);

      call_other("/players/tamina/teds/random_treasure", "make_item", dragon, 19);
      call_other("/players/tamina/teds/random_magic", "make_item", dragon, 15);
      move_object(dragon, this_object());
    }
}

void init() 
{
    ::init();
    add_action("_east", "east");
}

int _east() 
{
  if (present("red dragon")) 
  {
    write("The Red Dragon blocks your way.\n");
    dragon->attack_object(TP);
    return 1;
  }
  write("You pass through a small opening in the wall, east.\n");
  MPL("east#/players/tamina/teds/hot/earth_drag");
  return 1;
}
