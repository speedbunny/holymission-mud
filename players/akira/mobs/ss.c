inherit "obj/monster";
reset(arg){
    ::reset(arg);
    set_name("German Soldier");
    set_alias("soldier");
    set_short("German Soldier");
    set_long("This is a German SS trooper. His unifore is very clean and\n"+
      "his boots are as black as night. He looks at you and gives\n"+
      "you a look like he is going to kill you!\n");
    set_level(20);
    set_ac(10);
    set_wc(12);
    set_aggressive(1);
}
