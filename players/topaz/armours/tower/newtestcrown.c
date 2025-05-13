inherit "obj/weapon";

reset(arg) {
  if (arg) return;
  set_name("doomsgiver");
  set_alias("doomsgiver");
  set_alt_name("doomsgiver");
  set_short("Doomsgiver");
  set_long(
   "This is a very powerful sword. You feel a magic aura surrounding it.\n"+
   "There is something written on it.\n");
  set_read(
  "The language is very old. You can hardly understand it. But the\n"+
  "sword once seem to have been owned by Angmar himself.\n");
  set_class(20);
  set_value(5000);
  set_weight(4);
}

heart_beat() {
  object plr, al;
  if(!wielded) {
     set_heart_beat(0);
     return;
  }
  plr=environment();
  if(!living(plr)) {
    set_heart_beat(0);
    return;
  }

  al=plr->query_alignment();
  if(al>-200) {
    tell_object(plr, "Your Doomsgiver seems to come alive!\n");
    plr->drop_one_item(this_object());
    say("The Doomsgiver wriggles out of "+plr->query_name()+"'s hands.\n");
    set_heart_beat(0);
  }
}

wield(str) {
  if(!id(str)) return;
  if((this_player()->query_alignment() <= -200)) {
    set_heart_beat(1);
    ::wield(str); 
    return 1;
  }
  write("You can't wield Angmar's sword. Maybe you're not evil enough...\n");
  say(this_player()->query_name()+
      " failed to wield Doomsgiver\n");
    return 1;
}
