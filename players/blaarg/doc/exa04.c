inherit "/room/room";
 
// This include file provides automatic line wrap for very long
// strings. One is used in monster_died function.
#include "/obj/lw.h"
 
void reset(int arg) {
// This version of clone_list is for those who want a special monster
// or weapon. In this example, the weapon has a mweapon_hit and the
// monster has a set_dead_ob, which is called when the monster dies.
  clone_list = ({
    1, 1, "giant hunter", "obj/monster", ({
      "set_name", "giant hunter",
      "set_short", "A Giant Hunter",
      "set_race", "human",
      "set_alias_list", ({"hunter"}),
      "set_level", 18,
      "set_long", "A man who has devoted his entire life to "+
        "slaughtering giants. He's gotten himself a very good "+
        "weapon for doing such a thing too.\n",
      "set_gender", 1,
      "set_ac", 8,
      "set_wc", 10,
      "set_hp", 1000,
      "set_dead_ob", this_object(),
    }),
    -1, 1, "giant slayer", "obj/weapon", ({
      "set_name", "longsword",
      "set_short", "A giant slayer",
      "set_alt_name", "sword",
      "set_alias", "giant slayer",
      "set_class", 19,
      "set_value", 4000,
      "set_weight", 4,
      "set_long", "This is a very big longsword which looks like it "+
        "has slain many an enemy. There are pictures of giants on "+
        "the blade.\n",
      "set_hit_func", this_object(),
    }),
  });
 
// Note that since there are other functions besides reset() in
// the file, replace_program cannot be used. Instead ::reset()
// is called followed by if(arg) return.
  ::reset(arg);
  if(arg) return;
 
  set_light(1);
  short_desc = "A forest";
  long_desc =
    "You are in a deep forest. Trees stand all around you, hiding the sun.\n";
 
  dest_dir = ({
    "/doc/examples/exa05", "north",
    "/doc/examples/exa03", "east",
  });
 
  items = ({
    "trees", "There are trees everywhere",
  });
}
 
// This function gets called when a monster dies. It must return
// 0 or the monster stays alive.
monster_died(ob) {
  object money;

  if(ob->id("giant slayer")) {
    money = clone_object("obj/money");
    money->set_money(2000+random(1000));
    writelw("As you kill the famous giant slayer, you bust open "+
            "his purse, and a hoarde of money flies everywhere!\n");
    move_object(money, this_object());
  }
  return 0;
}
 
// The weapon hit function allows the weapon to do more damage
// on a hit. Should be directed toward a specific thing though.
weapon_hit(ob) {
  if(ob->id("giant")) {
    write("The blade hacks deeply into the giantish foe!\n");
        /* Give a message for attacking giants */
    return 10;
  }
 
  if(ob->id("dwarf"))
    return -2;
 
  return 0; /* Otherwise unchanged */
}
