#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
  if(arg) return;
    set_name("orc");
    set_race("orc");
    set_gender(1);
    set_alias("warrior");
    set_short("Orc Warrior");
    set_long(
"A massive orc with long, tusk-like teeth.  He stands with his hands on his "+
"hips and chortles to himself.  His huge feet are spread to about shoulders "+
"width.  His muscles ripple as he unconsciously flexes.\n");
    set_level(11);
    set_hp(270);
    set_al(-40);
    set_ac(4);
    set_wc(13);
move_object(clone_object(si+"/mace.c"),TO);
    init_command("wield mace");

