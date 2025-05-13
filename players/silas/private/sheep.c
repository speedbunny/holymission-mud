inherit"/obj/monster";

object owner;
string owner_name;
int ear_mode;

reset(arg) {
  if (arg)
    return;
  ::reset();
  set_name("sheep");
  set_alias("daisy");
  set_short("Daisy the sheep");
  set_long("This is the most beautiful sheep that you've ever seen, but she's already taken - so buzz off. DO NOT ATTACK HER UNLESS YOU'RE SUICIDAL!\n");
  set_level(30);
  set_gender(2);
  set_wc(100);
  set_ac(100);
  ear_mode = 0;
  owner_name = "silas";
  owner = find_living(owner_name);
  call_out("look_for_owner",10);
}

long(str) {
  ::long(str);
   if (present("silas"))
    write("She is eagerly nibbling at Silas' zipper.\n");
  else
    write("Daisy stares at you blankly.\n");
  if ((str == "sheep") && (this_player()->query_real_name() == "silas")) {
    write("Commands:\n"+
	"\tsay Daisy, go home.\t\tsay Daisy, greet <player>.\n"+
	"\tsay Daisy, [stay/come].\t\ttell Daisy [stay/come]\n"+
	"\ttell Daisy [yes/no/maybe]\t\ttell Daisy [listen/quiet]\n");
  }
}

greeting(ob) {
  if (present(ob)) {
    say("Daisy zooms over to greet "+ob->query_name(),ob);
    if (present("silas"))
	say(" then returns to Silas.\n",ob);
    else
        say(" then continues nibbling at Silas' zipper.\n",ob);
    tell_object(ob,"Daisy zooms over to you and licks your hand in greeting.\n");
  }
}

catch_tell(str) {
  object ob;
  string answer, extra, who, what;

  if (ear_mode) {
    if (!owner) {
	tell_room(environment(this_object()),
    "Daisy is engulfed in an explosion which spews her remains all over the plae.\n");
	destruct(this_object());
	return 1;
    }
    else
      tell_object(owner, "DAISY: "+str);
  }

/* Greet new arrivals */

  if (sscanf(str, "%s arrives.", what) == 1) {
    who = lower_case(what);
    ob = find_player(who);
    if (!ob) {
      return;
    } else {
      call_out("greeting",5, ob);
    }
  }

/* Obey tell commands */
  sscanf(str, "Silas tells you: %s\n", what);
  if (what == "no") {
    tell_room(environment(this_object()),
        "Daisy shakes her head.\n");
  }
  if (what == "yes") {
    tell_room(environment(this_object()),
        "Daisy nods.\n");
  }
  if (what == "maybe") {
    tell_room(environment(this_object()), "Daisy looks uncertain.\n");
  }
  if (what == "stay") {
    remove_call_out("look_for_owner");
    return 1;
  }
  if (what == "come") {
    remove_call_out("look_for_owner");
    call_out("look_for_owner", 2);
    return 1;
  }
  if (what == "listen") {
    ear_mode = 1;
    tell_object(owner,"Listening mode enabled.\n");
    return 1;
  }
  if (what == "quiet") {
    ear_mode = 0;
    tell_object(owner,"Listening mode disabled.\n");
    return 1;
  }

/* Copy actions and says */
  if (sscanf(str, "Silas %s.\n", what) != 1) return;
  if (what == "left the game") {
    tell_room(environment(this_object()),
      "Daisy is engulfed in an explosion which spews her remains all over the place.\n");
    destruct(this_object());
  }
  if (what == "says: Daisy, go home") {
    tell_room(environment(this_object()),
        "Daisy flies off into the skies.\n");
    move_object(this_object(),"players/silas/workroom");
    remove_call_out("look_for_owner");
    call_out("look_for_owner",3600);
    return 1;
  }
  if (what == "says: Daisy, stay") {
    tell_room(environment(this_object()),
        "Daisy assumes a solid stance in the middle of the room.\n");
    remove_call_out("look_for_owner");
    return 1;
  }
  if (what == "says: Daisy, come") {
    tell_room(environment(this_object()),
        "Daisy hears Silas calling her and happily trots out of the room.\n");
    call_out("look_for_owner",2);
    return 1;
  }
  if (sscanf(what, "says: Daisy, greet %s", who) == 1) {
    who = lower_case(who);
    ob = find_player(who);
    if (!ob) {
      tell_room(environment(this_object()),
        "Daisy races around the room, looking for "+capitalize(who)+".\n");
      return;
    } else {
      call_out("greeting",2, ob);
    }
  }
  if (what == "smiles happily" || what == "falls down laughing" ||
	what == "giggles inanely" || what == "snickers" ||
	what == "chuckles politely") {
    tell_room(environment(this_object()),
        "Daisy bleats happily.\n");
  }
  if (what == "grins evilly" || what == "growls") {
    tell_room(environment(this_object()),
        "Daisy growls angrily.\n");
  }
  if (what == "frowns" || what == "sighs deeply") {
    tell_room(environment(this_object()),
        "Daisy looks depressed.\n");
  }
  if (what == "starts to think very deeply") {
    tell_room(environment(this_object()),
        "Daisy looks pensive.\n");
  }
}

look_for_owner() {
  object ob;

  ob = find_living(owner_name);
  if (!ob) {
    tell_room(environment(),"Daisy flies off into the skies.\n");
    move_object(this_object(),"/players/silas/workroom");
    call_out("look_for_owner",60);
    return;
  }
  if (!present(ob,environment())) {
    tell_room(environment(),"Daisy vanishes suddenly.\n");
    tell_room(environment(ob),"Daisy appears out of nowhere.\n");
    move_object(this_object(), environment(ob));
  }
  ob = find_living("ossi");
  if (ob) {
    if (present(ob, environment())) {
      tell_room(environment(),"Ossi disgusts Daisy.\n"+
        "She angrily rams into him with full force, killing him instantly.\n");
      destruct(ob);
    }
  }
  call_out("look_for_owner",2);
}

