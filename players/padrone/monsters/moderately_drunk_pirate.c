inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("moderately drunk pirate");
    set_alias("pirate");
    set_level(4);
    set_female();
    set_al(-100);
    set_short("A moderately drunk pirate");
    set_long("She is moderately drunk.\n");
    set_aggressive(0);
    load_chat(5, ({
	"The moderately drunk pirate sings: And a bottle of rum!\n"
      }));
    add_money(2+random(10));
}
