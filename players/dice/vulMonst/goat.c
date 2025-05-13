inherit "/obj/monster";
object horn;

reset(arg) {
    ::reset(arg);
    if(!horn);
    if (arg) return 1;
    set_name("goat");
    set_alias("goat");
    set_alt_name("**");
    set_short("A goat");
    set_long("A mountain goat.\n"+
      "She climbs up and down on this mountain searching for food.\n"+
      "On her head are a pair of sharp horns.\n");
    set_race("goat");
    set_level(7);
    set_al(50);
    set_hp(150);
    set_ep(50);
    set_gender(2);
    set_aggressive(0);
    load_a_chat(15,({"The goat tried to bite you.\n",
	"The goat stings you with her horns.\n",}));
    set_whimpy(1);
transfer(clone_object("/players/dice/vulObj/horn"),this_object());
command("wield horn");
    return 1;
}


