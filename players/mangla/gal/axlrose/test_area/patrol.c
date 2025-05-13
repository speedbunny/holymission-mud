inherit "/players/axlrose/inherit/patrol_monster";

void reset(int arg) {
    ::reset(arg);
    if(!arg) {
        set_name("man");
        set_race("human");
        set_short("Patrol man");
        set_long("A wandering test patrol man.\n");
        set_level(10);
        set_size(3);
        set_ac(5);
        set_wc(5);
    }
}
