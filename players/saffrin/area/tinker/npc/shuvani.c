inherit "obj/monster";
#include "/players/saffrin/defs.h"

object staff, amulet, earring;

reset(){
  ::reset();
    set_name("shuvani");
    set_race("human");
    set_short("Shuvani");
    set_wc(0);
    set_alias("woman");
    set_long("The old, wise woman of the tinker band.  She is sitting around the fire\n"+
               "telling tales to all who will listen.\n");
    set_level(8);
    set_size(3);
    set_hp(135);
    add_money(357);
    set_ac(10);

    load_chat(4,({
        "Shuvani says: A person wishing to draw love to them, should chew on carroway seeds.\n",
        "Shuvani says: To frown, a person uses 183 muscles.  Ahh, but to smile they use only 5.  So smile!\n",
        "Shuvani smiles brightly.\n",
        "Shuvani says: By looking into a person's eyes, you can peer into their soul.\n",
    }));

    MOVE(CLONE(TINK+"obj/shstaff"),TO);
        init_command("wield staff");
    MOVE(CLONE(TINK+"obj/shamulet"),TO);
        init_command("wear amulet");
    MOVE(CLONE(TINK+"obj/qearring"),TO);
        init_command("wear earring");
}
