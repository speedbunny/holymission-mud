inherit "obj/monster";

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_short("A dumb monster.");
    set_name("monster");
    set_alias("mon");
    set_level(1);
    set_hp(1);
    set_dead_ob(this_object());
}
monster_died(ob){
    shout("Evil laughter is heard as a stupid monster is taken from this world.\n");
}
