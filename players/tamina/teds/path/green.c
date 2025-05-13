inherit "room/room";

#include "/players/tamina/defs.h"

object horn;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

    set_light(1);
    short_desc = "Green pavilion";
    long_desc =
    "An olive green pavilion sits in a clearing to one side of\n"+
    "the path. A large oak nearby holds the remains of the challengers\n"+
    "to the owner of the pavilion.\n";

    dest_dir = ({
      TPATH + "path9","north",
      TPATH + "path8","south",
      TFOREST + "rm1", "east",
      TFOREST + "rmZ", "west",
    });

    items = ({
  "pavilion",
"A large round tent. It's bright green colour looks sinister",
  "oak",
"This massive oak has the rotting corpses of many knights "+
"skewered on it's mighty branches",
    });
  horn = present("Green Horn");
  if (!horn)
  {
    horn = CLO ("obj/thing");

    horn->set_name("Green Horn");
    horn->set_alias("horn");
    horn->set_short("An Olive Green Horn");
    horn->set_long(
    "A beautifully carved horn, made from a green dragon's skull.\n"+
    "A small plaque reads:\n\nBlow horn to challenge Knight\n");
    horn->set_weight(25);
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
  object knight, mail;

  if (str == "horn" && present("Green Horn") && !present("green knight")) 
  {
    write("\nThe Green Knight jumps out of his pavilion !!\n");
    say(TPN+" blows the horn.\n"+
        "The Green Knight comes out of his pavilion\n");
 
    knight = CLO("obj/monster");

    knight->set_name("green knight");
    knight->set_alias("knight");
    knight->set_alt_name("green");
    knight->set_race("human");
    knight->set_gender(1);
    knight->set_long(
      "This Knight is clad in green and wears green platemail.\n"+
      "He looks very well protected, and very competent in armed combat.\n");
    knight->set_level(17);
    knight->set_wc(25);
    knight->set_ac(9);
    knight->set_al(-350);
    knight->set_aggressive(1);
    knight->add_money(150 + random(301));
    knight->load_a_chat(30,
     ({"The Green Knight says: Thou canst not defeat me!!\n",
       "The Green Knight says: Avast, ye swine!!\n",
       "Your swipe rebounds of the Green Knight's Platemail!!\n",
       "The Green Knight nimbly avoids your poor attempts to attack him.\n",
       "The Green Knight laughs scornfully at your inability to hurt him.\n"}) );
 
    mail = clone_object("obj/armour");
 
    mail->set_id("olive green platemail");
    mail->set_name("Olive Green Platemail");
    mail->set_alias("platemail");
    mail->set_type("armour");
    mail->set_short("Olive Green Platemail");
    mail->set_long(
      "This is a fine set of beautifully crafted armour.\n"+
      "It is made out of some strange, but very rigid material.\n"+
      "You think it is very protective.\n");
    mail->set_value(2000);
    mail->set_weight(6);
    mail->set_ac(4);
 
    transfer(mail, knight);
    command("wear platemail", knight);

    call_other("/players/tamina/teds/random_magic","make_item", knight, 19);
 
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

