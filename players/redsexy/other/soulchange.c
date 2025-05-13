inherit "/obj/thing";

reset(arg) {
  ::reset(arg);
  set_name("/soul changer");
  set_short("Soul changer");
  set_long("A changer of souls");
  set_alias("/guild-changer");
  set_alt_name("changer");
}

init() {
  ::init();
  add_action("change", "change");
}

change(arg) {
   object vagsoul, sumsoul, guildsoul;

  if(arg == "vagabond") {
      write("You change your guild to test the spiffy new Vag soul!\n");
      guildsoul=this_player()->query_guild_soul();
      destruct (guildsoul);
      vagsoul=clone_object("/players/nae/guild/new/soul.c");
      transfer(vagsoul,this_player());
      return 1;
    }

    if(arg == "summoner") {
      write("You change your guild to test the spiffy new Summoner soul!\n");
      guildsoul=this_player()->query_guild_soul();
      destruct (guildsoul);
      sumsoul=clone_object("/players/redsexy/guild/soul.c");
      transfer(sumsoul,this_player());
    }

    write("That is not a valid guild soul to test!\n");
    return 1;
  }

