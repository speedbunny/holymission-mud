inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("completely drunk pirate");
    set_alias("pirate");
    set_level(7);
    set_male();
    set_al(-100);
    set_short("A completely drunk pirate");
    set_long("He is completely drunk.\n");
    set_aggressive(0);
    load_chat(5, ({
	"The completely drunk pirate tries to sing, but falls down and pukes.\n"
      }));
    add_money(100+random(100));
}
