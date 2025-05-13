inherit "obj/monster";
#include "/players/saffrin/defs.h"

object staff, talisman, earring;

reset(){

  ::reset();
    set_name("A tinker woman");
    set_race("human");
    set_short("A tinker woman");
    set_wc(0);
    set_alias("woman");
    set_long("A beautiful, mysterious tinker woman.  As you look at her, her dark\n"+
                   "eyes peer up at you from under her long eyelashes.\n");
    set_size(3);
    set_level(6);
    set_hp(110);
    add_money(234);
    set_ac(8);

    load_chat(4,({
        "The tinker woman says: I can make you smile.\n",
        "The tinker woman flutters her eyelashes.\n",
      }));

    MOVE(CLONE(TINK+"obj/tstaff"),TO);
        init_command("wield staff");
    MOVE(CLONE(TINK+"obj/ttalisma"),TO);
        init_command("wear talisman");
    MOVE(CLONE(TINK+"obj/mearring"),TO);
        init_command("wear earring");
}
