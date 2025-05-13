inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("very drunk pirate");
    set_alias("pirate");
    set_level(5);
    set_female();
    set_al(-100);
    set_short("A very drunk pirate");
    set_long("She is very drunk.\n");
    set_aggressive(0);
    load_chat(5, ({
	"The very drunk pirate sings: And a chest of rum!  Yeah!\n"
      }));
    add_money(2+random(10));
}
