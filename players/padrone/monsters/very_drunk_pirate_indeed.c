inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("very drunk pirate indeed");
    set_alias("pirate");
    set_level(6);
    set_male();
    set_al(-100);
    set_short("A very drunk pirate indeed");
    set_long("He is very drunk indeed.\n");
    set_aggressive(0);
    load_chat(5, ({
	"The very drunk pirate indeed sings: Andsch a rum of bottle chest! La-la-la!\n"
      }));
    add_money(2+random(10));
}
