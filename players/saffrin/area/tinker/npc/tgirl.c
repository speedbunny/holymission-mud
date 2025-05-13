inherit "obj/monster";
#include "/players/saffrin/defs.h"

object tamborine, wreath, talisman, earring, tarot;

reset(){

  ::reset();
    set_name("A tinker girl");
    set_race("human");
    set_short("A tinker girl");
    set_wc(0);
    set_alias("girl");
    set_long("A young girl dressed in a patched dress.  She is wearing no shoes.\n");
    set_level(4);
    set_size(3);
    set_hp(90);
    add_money(121);
    set_ac(6);

    load_chat(4,({
        "The tinker girl says: I am great at telling fortunes.\n",
        "The tinker girl blushes.\n",
      }));

    MOVE(CLONE(TINK+"obj/tarot"),TO);
        init_command("wield tarot");
    MOVE(CLONE(TINK+"obj/twreath"),TO);
        init_command("wear wreath");
    MOVE(CLONE(TINK+"obj/ttalisma"),TO);
        init_command("wear talisman");
    MOVE(CLONE(TINK+"obj/tearring"),TO);
        init_command("wear earring");
    MOVE(CLONE(TINK+"obj/tamborin"),TO);
}
