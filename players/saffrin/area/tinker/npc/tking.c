inherit "obj/monster";
#include "/players/saffrin/defs.h"

object staff, cloak, amulet, earring, foot;

reset(){

  ::reset();
    set_name("The tinker king");
    set_race("human");
    set_short("The tinker king");
    set_wc(0);
    set_alias("king");
    set_long("The most handsome man you have ever set eyes on.  His dark, smoldering eyes\n"+
                   "draw you to him.  His stance is proud but relaxed.  He seems very friendly.\n");
    set_level(10);
    set_size(3);
    set_hp(165);
    add_money(411);
    set_ac(12);

    load_chat(4,({
        "The tinker king says: My friend, have you come for a love potion.\n",
        "The tinker king says: Master the arts of the tinkers and lovers will fall at your feet.\n",
        "The tinker king throws back his head and releases out his rich laughter.\n",
      }));

    MOVE(CLONE(TINK+"obj/tkstaff"),TO);
        init_command("wield staff");
    MOVE(CLONE(TINK+"obj/tkamulet"),TO);
        init_command("wear amulet");
    MOVE(CLONE(TINK+"obj/tkcloak"),TO);
        init_command("wear cloak");
    MOVE(CLONE(TINK+"obj/badfoot"),TO);
        init_command("wear foot");
    MOVE(CLONE(TINK+"obj/learring"),TO);
        init_command("wear earring");
}
