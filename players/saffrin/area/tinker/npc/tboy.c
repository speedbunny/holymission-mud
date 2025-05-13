inherit "obj/monster";
#include "/players/saffrin/defs.h"

object horseshoe, talisman, foot, earring;

reset(){

  ::reset();
    set_name("A tinker boy");
    set_race("human");
    set_short("A tinker boy");
    set_wc(0);
    set_alias("boy");
    set_long("A young boy dressed in colorful patched clothes.  He has a smile on his face\n");
    set_size(3);
    set_level(4);
    set_hp(90);
    add_money(121);
    set_ac(6);

    load_chat(4,({
        "The tinker boy says: Some stones can be carried for good luck.\n",
        "The tinker boy smiles.\n",
    }));

    MOVE(CLONE(TINK+"obj/horsesho"),TO);
        init_command("wield horseshoe");
    MOVE(CLONE(TINK+"obj/harefoot"),TO);
        init_command("wear foot");
    MOVE(CLONE(TINK+"obj/ttalisma"),TO);
        init_command("wear talisman");
    MOVE(CLONE(TINK+"obj/tearring"),TO);
        init_command("wear earring"); 
}
