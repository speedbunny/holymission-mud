inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("more drunk pirate");
    set_alias("pirate");
    set_level(4);
    set_male();
    set_al(-100);
    set_short("A more drunk pirate");
    set_long("He is more drunk.\n");
    set_aggressive(0);
    load_chat(5, ({
	"The more drunk pirate sings: And a bott-(hick)-bottle of rum!\n"
      }));
    add_money(2+random(10));
}
