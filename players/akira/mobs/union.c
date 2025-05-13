inherit "obj/monster";
reset(arg){
    ::reset(arg);
    set_name("Union Soldier");
    set_alias("soldier");
    set_short("Union Soldier");
    set_long("This is a soldier for the union army. His uniform looks\n"+
      "well kept and is a navy blue.\n");
    set_level(15);
    set_ac(7);
    set_wc(7);
    set_aggressive(1);
}
