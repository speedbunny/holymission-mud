inherit "/obj/monster";

reset(str) {
    ::reset(str);
    if(str) return;
    set_name("squirrel");
    set_short("A brown squirrel");
    set_long("The squirrel is working hard to accumulate nuts for the hard winter.\n");
    set_race("rodent");
    set_level(1);
    set_al(50);
    set_wc(2);
    set_ac(2);

}
