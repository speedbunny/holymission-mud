inherit "room/room";

#include "/players/tamina/defs.h"

object king, crown, mace;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc = "Petrified Forest";
    long_desc =
"You enter the dreaded Petrified Forest.\n"+
"Darkness surrounds you, and paths lead in all directions,\n"+
"deeper into the forest.\n";

    dest_dir = ({
    TFOREST + "rmU", "north",
    TFOREST + "rmI", "south",
    });

  king = present("goblin king");
  if (!king)
  {
    king = clone_object("obj/monster");

    king->set_name("goblin king");
    king->set_alias("king");
    king->set_race("goblin");
    king->set_short("Goblin King");
    king->set_long(
  "This is a larger goblin than most.  He seems to have some semblence\n"+
  "of intelligence about him.\n");
    king->set_level(29);
    king->set_hp(2750);
    king->set_wc(21);
    king->set_ac(16);
    king->set_aggressive(1);
    king->set_spell_mess1("The Goblin King kicks his foe.\n");
    king->set_spell_mess2("The Goblin King kicks you fiercely !!\n");
    king->set_spell_dam(20 + random(11));
    king->set_chance(27);

    crown = clone_object("obj/armour");

    crown->set_name("crown");
    crown->set_short("Goblin King's Crown");
    crown->set_long(
  "This is an ugly looking headpiece that can only be worn by\n"+
  "someone of incredibly bad taste.\n");
    crown->set_ac(1);
    crown->set_type("helmet");
    crown->set_value(1000);

    mace = clone_object(TWP + "gob_mace");

    "/players/tamina/teds/random_treasure"->make_item(king, 29);
    "/players/tamina/teds/random_armor"->make_item(king, 28);

    TR(crown, king);
    TR(mace, king);
    command("wear crown", king);
    command("wield mace", king);

    move_object(king, this_object());
  }
 }
}
