inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return 1;
    set_name("bear");
    set_alias("bear");
    set_alt_name("**");
    set_short("A bear");
    set_long("A brown bear.\n"+
      "It lives here on the mountain.\n");
    set_race("bear");
    set_level(10);
    set_al(5);
    set_hp(250);
    set_ep(250);
    set_aggressive(0);
    load_chat(10,({"The bear growls a little.\n",
	"The bear searches for something to eat.\n",
      }));
    load_a_chat(15,({"The bear bites you.\n",
	"The bear slammed you with it's claw.\n",}));
    set_whimpy();
    return 1;
}


