inherit "obj/monster";
void reset(int arg){
    ::reset();

    set_name("dog");
    set_race("dog");
    set_alt_name("rottweiler");
    set_gender(1);
    set_alias("dog");
    set_short("Rottweiler");
    set_long(
"A massive rottweiler, its lips pulled back over its teeth.  The dogs fur "+
"glistens as his muscles flow smoothly onder his skin.  His golden eyebrows "+
"are raised expressively as he looks around the room.\n");
    set_level(15);
    set_hp(200);
    set_al(40);
    set_ac(6);
    set_wc(15);
}
