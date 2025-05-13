inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Figley");
    set_alias("figley");
    set_alt_name("young figley");
    set_race("human");
    set_short("Young Figley the human");
    set_long("This is Young Figley.\n" +
             "Please be nice to him, he isn't very happy at the moment.\n");
    set_aggressive(0);
    set_level(10);
    set_wc(12);
    set_ac(3);
    set_al(500);
    set_hp(230);
load_chat(20,({
        "Figley mopes.\n",
        "Figley pouts.\n",
        "Figley says: I got everything on my list, but I dropped them.\n",
        "Figley says: I just took a shortcut through the woods and got lost.\n",
}));
  }
  return 1;
}
