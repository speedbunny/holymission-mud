inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
   ::reset();
    set_name("thelgar");
    set_race("dwarf");
    set_gender(1);
    set_alias("thelgar");
    set_alt_name("dwarf");
    set_short("Thelgar");
            set_long(
"Thelgar is anything but a typical dwarf.  He stands in front of the\n"+
"forge wielding a small hammer.  He stands nearly six feet tall and\n"+
"is very thin.  However his thick beard and large nose betray him as\n"+
"a dwarf.  He makes his living forging items for the castle.\n")+
    set_level(20);
    set_hp(1500);
    set_al(330);
    set_ac(11);
    set_wc(30);
    load_chat(5, ({
"Thelgar hammers a sword into shape.\n",
"Chink, Chink.\n",
"Thelgar says: I miss my brother.\n",
"Thelgar shoves a sword into the cooling trough.\n",
"Thelgar grabs something from his work bench.\n",
}));
move_object((clone_object(bi+"/hammer.c")),this_object());
init_command("wield hammer");
    }
