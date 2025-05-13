#include "/players/tamina/defs.h"

inherit "room/room";

object horn;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

  set_light(1);
  short_desc = "Red Pavilion";
  long_desc =
    "A blood red pavilion sits in a clearing to one side\n"+
    "of the path here. A large oak is adorned with the trophies\n"+
    "collected by the occupant of the pavilion.\n";

  dest_dir = ({
      TPATH + "path8","north",
      TPATH + "path7","south",
    });

  items = ({
      "pavilion",
"A large, blood red tent, usualy used by Knights and nobles",
      "oak",
"The bloodied armor and remains of human corpses hang from the branches"
    });
  horn = present("Red Horn");
  if (!horn)
  {
    horn = CLO("obj/thing");

    horn->set_name("Red Horn");
    horn->set_alias("horn");
    horn->set_short("A Blood Red Horn");
    horn->set_long(
"This massive horn was carved from the skull of a red dragon.\n\n"+
"A small plaque reads:\n\n         Blow horn to challenge Knight\n");
    horn->set_can_get(0);
  
    MO(horn, TO);
  }
}

void init()
{
  ::init();
  AA("_blow", "blow");
}

int _blow(string str)
{
  object knight, knife, steak;

  if (str == "horn" && present("Red Horn") && !present("Red Knight")) 
  {
    write("The Red Knight bounds out of his pavilion !!\n");
    say(TPN+" blows the Red Horn.\n"+
        "The Red Knight comes out of his pavilion.\n");
 
    knight = CLO("obj/monster");

    knight->set_name("Red Knight");
    knight->set_alt_name("red");
    knight->set_alias("knight");
    knight->set_race("human");
    knight->set_gender(1);
    knight->set_long(
 "This Knight is clad in blood red armor and carrys a Blood red shield.\n"+
 "He looks very dangerous, and menacing in his eerie armour...\n");
    knight->set_level(16);
    knight->set_wc(25);
    knight->set_ac(9);
    knight->set_al(-200);
    knight->set_aggressive(1);
    knight->load_a_chat(33,
   ({"The Red Knight draws a puddle of blood from you!\n",
     "The Red Knight says: Why do you bother, weakling?\n",
     "The Red Knight says: Beware, foolish follower of the idiot, Arthur!\n",
     "The Red Knight says: Beware the castle known as Camelot!\n"+
     "                     You will not survive there!!\n",
     }) );
    knight->add_money(50 + random(150));

    call_other("/players/tamina/teds/random_armor", "make_item", knight, 16);
 
    steak = CLO("/players/tamina/teds/foodstuffs/steak");
    knife = CLO(COBJ + "sac_knife2");

    TR(steak, knight);
    TR(knife, knight);
    command("wield knife", knight);
    MO(knight, E(TP));

    knight->attack_object(TP);
    destruct(horn);
    return 1;
  }
  else
  {
    NFAIL("Blow what?\n");
    return 0;
  }
}
