inherit "obj/monster";
void reset(int arg){
    ::reset();

    set_name("dog");
    set_race("dog");
    set_alt_name("doberman");
    set_gender(1);
    set_alias("dog");
    set_short("Doberman");
    set_long(
"This doberman's face is pulled back in a smile.  He sits quietly in the "+
"corner of the room.  However his eyes follow you wherever you walk in "+
"the room.  His shiny black hide is marked with brown and red high-lights "+
"and shines from the constant attention the groomers pay to it.\n");
    set_level(15);
    set_hp(200);
    set_al(40);
    set_ac(6);
    set_wc(15);
}
