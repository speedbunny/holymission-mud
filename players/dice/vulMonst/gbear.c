inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return 1;
    set_name("grizzly bear");
    set_alias("grizzly bear");
  set_alt_name("bear");
    set_short("A grizzly bear");
    set_long("A brown grizzly bear.\n"+
      "It lives here on the mountain.\n");
    set_race("grizzly bear");
    set_level(12);
    set_al(-20);
    set_hp(300);
    set_ep(300);
    set_aggressive(1);
    load_chat(10,({"The grizzly bear growls a little.\n",
	"The grizzly bear searches for something to eat.\n",
      }));
    load_a_chat(15,({"The grizzly bear bites you.\n",
          "The grizzly bear tries to crunch you with its power.\n",
	"The grizzly bear slammed you with it's claw.\n",}));
    set_whimpy();
    return 1;
}


