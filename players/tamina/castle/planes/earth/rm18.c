inherit "/room/room";

#include "/players/tamina/defs.h"

status here;

void reset(int arg)
{
  ::reset(arg);
  here = 0;
  if (arg) return 0;

    property = ({ "has_earth", "no_teleport" });
    smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(1);
	short_desc = "A small Alcove";
	long_desc = 
"    You are in a small, oval chamber.\n"+
"    It is lighted by the same unknown source of light that\n"+
"    permeates the whole system of tunnels down here.\n"+
"    There is very little to see, but your own reflection in \n"+
"    the glass walls...\n";

     	dest_dir = ({
      EARTH + "rm17", "east",
	});
}

void init()
{
  ::init();
  AA("my_look", "look");
  AA("my_look", "exa");
}

int my_look(string str)
{
  object me, ring;

  if (str == "at walls" || str == "walls" || str == " at wall" || 
                  str == "wall" || str == "glass")
  {
    if (here)
    {
      write("You see nothing but your reflection in the walls.\n");
      return 1;
    }
    write("As your eyes gaze at the glassy surface, you notice that\n"+
          "your own reflection seems to be moving independantly of\n"+
          "itself...\n");
    say(TPN+" looks at the walls...\n");

    me = CLO("obj/monster");

    me->set_name("A Reflection of "+CAP(TPRN));
    me->set_alias("reflection");
    me->set_alt_name(TPRN);
    me->set_race(TP->query_race());
    me->set_gender(TP->query_gender());
    me->set_level(5 + TP->LVL);
    me->set_wc(TP->query_wc() + 5);
    me->set_ac(TP->query_ac() + 3);
    me->set_hp(TP->MAXHP*3);
    me->set_aggressive(1);
    me->set_whimpy(24);
    me->set_al(-500);
    me->set_spell_mess2("The Reflection splinters you with glass.\n");
    me->set_spell_mess1("The Reflection cuts deely into its image.\n");
    me->set_spell_dam(45);
    me->set_chance(TP->LVL);
    me->set_own_env("earth");

    TRM(TO,
      "A reflected image of "+TPN+" suddenly appears in the room.\n");

    MO(me, TO);
    me->attack_object(TP);
    here = 1;
    return 1;
  }
}
