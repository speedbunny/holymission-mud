inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
if(arg) return;
    set_name("boss");
    set_race("orc");
    set_gender(1);
    set_alias("orc","boss");
    set_short("Orc boss");
    set_long(
"The orc boss, whose face is proudly covered in festering wounds.  He is "+
"easily seven feet tall.  His massive hands are curled into fists.  His "+
"face is locked in a perpetual sneer.  A terrible stench rolls of off him.\n");
    set_level(7);
    set_hp(150);
    set_al(-40);
    set_ac(2);
    set_aggressive(1);
    set_wc(9);
    move_object(clone_object(si+"/sceptero.c"),TP);
    init_command("wield scepter");
}
