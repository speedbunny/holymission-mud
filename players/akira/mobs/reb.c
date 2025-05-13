inherit "obj/monster";
reset(arg){
    ::reset(arg);
    set_name("Rebel Soldier");
    set_alias("soldier");
    set_short("Rebel Soldier");
    set_long("This is a soldier of the Confederate army. His uniform\n"+
      "looks to be messed-up, and he has no shoes.\n");
    set_level(17);
    set_ac(7);
    set_wc(10);
    set_aggressive(1);
}
