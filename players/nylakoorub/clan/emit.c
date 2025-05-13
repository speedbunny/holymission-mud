/* Emit, Guild NPC
*
*
*/

inherit "/obj/npc";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("emit");
    set_short("Emit Ecaps");
    set_long("This is Emit Ecaps, the Elder Timelord.\n"+
      "\n");
    set_race("human");
    set_level(60);
    set_hp(2000);
    set_ac(25);
    set_gender(1);
    set_ep(1);
    set_wimpy();


}

