inherit "/room/room";
 
#include "/room/room_defs.h"

void reset(int arg) {
  clone_list = ({
    1, 2, "baby fox", "obj/monster", ({
      "set_name", "baby fox",
      "set_alias_list", ({"fox"}),
      "set_short", "A smart baby fox",
      "set_long", "It's looking at you like it's searching "+
        "for someone to play with.\n",
      "set_level", 2,
      "set_size", 2,
      "set_al", 20,
      "set_gender", 1,
      "set_wc", 3,
      "set_dead_ob", TO,
      "set_whimpy", 1,
    }),
    -1, 1, "jacket", "obj/armour", ({
      "set_name", "fox-fur jacket",
      "set_alias_list", ({"jacket","fox jacket","fur jacket"}),
      "set_short", "A fox-fur jacket",
      "set_size", 2, 
      "set_ac", 1,
      "set_long", "A beautiful red fur jacket from a baby fox.\n",
      "set_value", 40,
      "set_weight", 1,
      "seT_type", "armour",
    }),
  });

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In a beautiful garden";
  no_castle_flag = 0;

  long_desc =
    "The middle of Chantilly's garden is very green with "+
    "its beautifully pruned bushes around. The village walls "+
    "block travel south but the garden stretches in the other "+
    "three directions. Are those animal tracks in the dirt?\n";

  items = ({
    "tracks", "They look like fox tracks",
    "garden", "The middle of the garden has many bushes",
    "bushes", "There are quite a few of them, but they are "+
      "well tended to",
    "wall", "It protects the village from the evil of the "+
      "outside world",
  });

  property = ({ "no_teleport" });

  dest_dir = ({
    VILLAGE_GARDEN + "garden5","north",
    VILLAGE_GARDEN + "garden3", "east",
    VILLAGE_GARDEN + "garden1", "west",
  });
}

monster_died(object ob) {
  object mon, arm;

  arm = clone_object("obj/armour");
  arm->set_name("fox-fur jacket");
  arm->set_alias_list(({"jacket","fox jacket","fur jacket"}));
  arm->set_short("A fox-fur jacket");
  arm->set_long("A beautiful reddish-brown fur jacket from "+
                "an adult fox.\n");
  arm->set_ac(2);
  arm->set_weight(2);
  arm->set_size(2);
  arm->set_value(80);

  if(ob->id("baby_fox")) {
    mon = clone_object("obj/monster");
    mon->set_name("mother fox");
    mon->set_short("A mother fox");
    mon->set_long("A mother fox. It looks very angry after someone "+
                  "butchered her child.\n");
    mon->set_alias_list(({"fox","mother"}));
    mon->set_gender(2);
    mon->set_level(3);
    mon->set_wc(5);
    mon->set_aggressive(1);
    mon->set_size(2);
    mon->set_al(20);
    mon->set_dead_ob(TO);
    move_object(arm, mon);
    command("wear jacket", mon);
    move_object(mon, TO);
    TELLR(TO, "Suddenly a mother fox arrives looking angry.\n");
  }
  else if(ob->id("mother fox")) {
    mon = clone_object("obj/monster");
    mon->set_name("father fox");
    mon->set_short("A father fox");
    mon->set_long("A father fox. It looks very angry after someone "+
                  "butchered his mate and child.\n");
    mon->set_alias_list(({"fox","father"}));
    mon->set_gender(1);
    mon->set_level(4);
    mon->set_wc(7);
    mon->set_aggressive(1);
    mon->set_size(2);
    mon->set_al(20);
    mon->set_dead_ob(TO);
    move_object(arm, mon);
    command("wear jacket", mon);
    move_object(mon, TO);
    TELLR(TO, "An angry father fox jumps from the bushes.\n");
  }
  return 0;
}

