inherit "obj/monster";
void reset(int arg){
    ::reset();

    set_name("badger");
    set_race("badger");
    set_gender(1);
    set_alias("voracious badger");
    set_short("A voracious badger");
    set_long(
"A huge badger with a half eaten corpse in his mouth.  His eyes glow red\n"+
"as he looks intently for his next victim.  Froth drips from the corner of\n"+
"his mouth.\n");
    set_aggressive(25);
    set_level(5);
    set_hp(110);
    set_al(-40);
    set_ac(1);
    set_wc(7);
    }
