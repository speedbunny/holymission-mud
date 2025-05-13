inherit "room/room";

#include "/players/tamina/defs.h"

object magi, glaive;

void reset(int arg) 
{
  magi = present("ogre magi");
  if (!magi) 
  {
    magi = clone_object("obj/monster");

    magi->set_name("ogre magi");
    magi->set_alias("magi");
    magi->set_race("ogre");
    magi->set_gender(1);
    magi->set_race("ogre");
    magi->set_long(
  "This is an oriental looking ogre dressed in a sari and a sash.\n");
    magi->set_level(21);
    magi->set_wc(21);
    magi->set_ac(6);
    magi->set_al(-150);
    magi->set_aggressive(1);
    magi->set_spell_mess1("The Ogre Magi begins a complex sutra.\n");
    magi->set_spell_mess2(
  "The Magi performs a delicate dance of magical death against you !!\n");
    magi->set_chance(30);
    magi->set_spell_dam(30 + random(15));

    glaive = clone_object("obj/weapon");

    glaive->set_name("Mithril Glaive");
    glaive->set_alias("glaive");
    glaive->set_short("A Mithril Glaive");
    glaive->set_long("This long pole arm is tipped with a mithril blade.\n");
    glaive->set_class(16);
    glaive->set_value(1500);
    glaive->set_weight(3);

    move_object(glaive, magi);
    command("wield glaive", magi);
    call_other("/players/tamina/teds/random_magic", "make item", magi, 21);

    move_object(magi, this_object());
  }
  if (arg) return 0;
  set_light(1);
  short_desc = "Dread Forest";
  long_desc =
"A crude lean to has been erected here. It is made\n"+
"of pine branches and covered with oak leaves. A\n"+
"fire pit has been dug in front of it and a roasting\n"+
"rack lies next to it.\n";

  dest_dir = ({
    TFOREST + "rm3", "north",
    TFOREST + "rmT", "south",
    TFOREST + "rmZ", "east"
    });
}
