inherit "room/room";

#include "/players/tamina/defs.h"

object hell_hound;

void reset(int arg) 
{
  int i;
  ::reset(arg);
  if (!arg) 
  {
    set_light(1);
    short_desc = "An Unusual Passageway";
    long_desc =
"This stone passageway has small iron gates set flush with\n"+
"the ground. Right now all of them are open, letting the\n"+
"hell hounds they contain roam free!\n";

    dest_dir = ({
     TFIRE + "throne", "north",
     TFIRE + "ante_room", "south"
    });
  }
  if (!present("hell hound")) 
  {
    i = 0;
    while(i <= 4) 
    {
      i ++;
      hell_hound = clone_object("obj/monster");

      hell_hound->set_name("hell hound");
      hell_hound->set_alias("hound");
      hell_hound->set_race("hound");
      hell_hound->set_gender(1);
      hell_hound->set_short("A Large Hound from Hell");
      hell_hound->set_long(
        "This is a large black hound.  Its jaws are very powerful.\n"+
        "You can also see wisps of smoke curl up from its maw, and nostrils...\n");
      hell_hound->set_level(15);
      hell_hound->set_wc(25);
      hell_hound->set_ac(8);
      hell_hound->set_al(-750);
      hell_hound->set_aggressive(1);
      hell_hound->set_spell_mess1("The Hound lets loose a blast of hell fire.\n");
      hell_hound->set_spell_mess2("The Hound blasts you with Hell fire.\n");
      hell_hound->set_spell_dam(35);
      hell_hound->set_chance(80);

      move_object(hell_hound, this_object());
    }
  }
}

void init() 
{
  ::init();
  add_action("do_north", "north");
}

int do_north() 
{
  if (present("hell hound")) 
  {
    write("The Hell Hound blocks your way!\n");
    return 1;
  }
}
