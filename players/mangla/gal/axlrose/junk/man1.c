inherit "obj/mon";

reset(){
    ::reset();
    set_name("man");
    set_race("human");
    set_short("Patrol man");
    set_long("A wandering test patrol man.\n");
set_level(24);
    set_size(3);
    set_ac(5);
    set_wc(5);
    set_walk_chance(10);
    set_walk_limit("/players/axlrose/junk/room/");
    set_al(250);
set_sp(175);
set_int(15);
}
