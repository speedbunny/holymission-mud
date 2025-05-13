inherit "obj/monster";
#include "/players/saffrin/defs.h"

object staff, talisman, earring;

reset(){

  ::reset();
    set_name("A tinker man");
    set_race("human");
    set_short("A tinker man");
    set_wc(0);
    set_alias("man");
    set_long("A handsome tinker man dressed in colorful patched clothes.  He looks\n"+
                   "friendly and kind.\n");
    set_size(3);
    set_level(6);
    set_hp(110);
    add_money(234);
    set_ac(8);

    load_chat(4,({
        "The tinker man says: You can tell a lot about someone by their smile.\n",
        "The tinker man smiles mysteriously.\n",
      }));

    MOVE(CLONE(TINK+"obj/tstaff"),TO);
        init_command("wield staff");
    MOVE(CLONE(TINK+"obj/ttalisma"),TO);
        init_command("wear talisman");
    MOVE(CLONE(TINK+"obj/tearring"),TO);
        init_command("wear earring");
}
