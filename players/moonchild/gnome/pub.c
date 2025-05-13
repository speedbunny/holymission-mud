inherit "room/room";

int p_no;

catch_tell(str) {
  string who,ans;
  if(p_no==3 || !present("player")) return;
  if(sscanf(str,"%s says: play %s\n",who,ans)!=2) return;
  if("players/moonchild/gnome/problem"->check_answer(ans)) {
    this_player()->add_exp(50+random(50));
    write("Chess player says: That's right!\nYou feel more experienced.\n");
    "players/moonchild/gnome/problem"->new_problem(++p_no);
    if(p_no==3) {
      object c;
      tell_room(this_object(),"Chess player says: Thanks a lot, "
        + this_player()->query_name() + ".\nChess player says: Take this as a "
        + "token of thanks.\n");
      c=clone_object("players/moonchild/gnome/crystal");
      c->set_type(1);
      if(transfer(c,this_player())) {
        move_object(c,this_object());
        tell_room(environment(this_player()),
                "Chess player drops the crystal.\n");
      } else {
        write("Chess player gives crystal to you.\n");
        say("Chess player gives crystal to " + this_player()->query_name()
                + ".\n", this_player());
        c->get();
      }
    }
    else tell_room(this_object(),"He immediately plays out a new problem.\n");
  }
  else tell_room(this_object(),"Chess player says: No, that can't work.\n");
  return;
}

reset(arg) {
  p_no=0;
  if(!present("list"))
    move_object(clone_object("obj/level_list"),this_object());
  if(!present("box"))
    move_object(clone_object("players/moonchild/misc/singer"),this_object());
  call_other("players/moonchild/gnome/problem","???");
  if(!present("player")) {
    object p;
    move_object(p=clone_object("obj/monster"),this_object());
    p->set_name("player");
    p->set_alias("chess player");
    p->set_short("Chess player");
    p->set_race("gnome");
    p->set_male();
    p->set_long("A small gnome, studying a chess problem intently.\n"
        + "He seems harmless enough, why don't you help him?\n");
    p->set_level(4);
    p->set_chance(0);
  }
  if(arg) return;
  set_light(1);
  short_desc="Gnomes' Pub";
  long_desc="This is the Gnomes' local pub.\n"
	+ "Drinks available are:\n\n"
	+ "        Gnomish ale:       10 gold coins\n"
	+ "        Apple cider:       40 gold coins\n"
	+ "        Gnomish whisky:   100 gold coins\n"
	+ "        Potato spirit:    400 gold coins\n\n";
  dest_dir=({ "players/moonchild/gnome/alley2", "west" });
  property=({ "no_teleport" });
  enable_commands();
}

init() {
  ::init();
  add_action("_buy", "buy");
}

_buy(str) {
  int cost,heal,stre;
  string mess,saymess;
  switch(str) {
    case "ale":
	cost=10;
	heal=2;
	stre=3;
	mess="A fairly salty ale";
	saymess="orders an ale";
	break;
    case "cider":
	cost=40;
	heal=12;
	stre=6;
	mess="Not too bad, actually";
	saymess="drinks a glass of cider";
	break;
    case "whisky":
	cost=100;
	heal=25;
	stre=9;
	mess="Powerful stuff";
	saymess="gulps down some gnomish whisky";
	break;
    case "spirit":
	cost=400;
	heal=80;
	stre=12;
	mess="Tastes disgusting, but makes your body gasp";
	saymess="drinks some raw potato spirit, and looks rather ill";
	break;
    default:
	write("Buy what?\n");
	return 1;
	break;
  }
  if(this_player()->query_money()<cost) {
    write("You don't have enough money to buy that!\n");
    return 1;
  }
  this_player()->add_money(-cost);
  if((stre>11 && this_player()->query_level()<10)
	|| (stre>7 && this_player()->query_level()<5)) {
    write("You try to drink a " + str + ", but throw it up!\n");
    say(this_player()->query_name() + " tries to drink a " + str
	+ ", but throws it all up!\n");
    return 1;
  }
  if(!this_player()->drink_alcohol(stre)) {
    this_player()->add_money(cost);
    return 1;
  }
  write(mess + ".\n");
  say(this_player()->query_name() + " " + saymess + ".\n", this_player());
  this_player()->heal_self(heal);
  return 1;
}
