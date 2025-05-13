inherit "room/room";

status door_open;

id(str) { return ::id(str) || str=="door" || str=="doors"; }

reset(arg) {
  call_other("players/moonchild/cave/box", "???");
  if(!present("troll")) {
    object t,o;
    move_object(t=clone_object("obj/monster"),this_object());
    t->set_name("troll");
    t->set_alias("large troll");
    t->set_short("A large troll stands here");
    t->set_long("A large troll stands here. He looks mean and nasty.\n");
    t->set_male();
    t->set_level(22);
    t->set_wc(22);
    t->set_al(-100);
    t->set_whimpy(-1);
    move_object(o=clone_object("obj/armour"),t);
    o->set_type("armour");
    o->set_name("platemail");
    o->set_short("Some trollish platemail");
    o->set_long("This is some trollish platemail.\n");
    o->set_ac(4);
    o->set_weight(4);
    o->set_value(1000);
    move_object(o=clone_object("obj/weapon"),t);
    o->set_name("longsword");
    o->set_alias("sword");
    o->set_short("A trollish longsword");
    o->set_long("This is a trollish longsword.\n");
    o->set_class(13);
    o->set_weight(7);
    o->set_value(600);
  }
  if(arg) return;
  short_desc="Beside two giant stone doors";
  long_desc="Here, the path of these natural underground tunnels is abruptly\n"
	+ "ended by two huge stone doors that bar any exit to the west.\n";
  dest_dir=({ "players/moonchild/cave/c23", "west",
/*
  "/players/gareth/evil/cave/new","north",
*/
	"room/mine/tunnel20", "east" });
  items=({ "writing", "Perhaps you should read it" });
  enable_commands();
}

long(str) {
  if(str=="door" || str=="doors") {
    write(door_open ? "The huge stone doors are open.\n" : 
	"The huge stone doors appear securely closed.\n"
	+ "However, you do notice some writing carved on them.\n");
    return;
  }
  return ::long(str);
}

init() {
  ::init();
  add_action("read", "read");
  add_action("west", "west");
}

read(str) {
  if(str!="writing") return;
  write("The writing reads \"Speak friend and enter\".");
  write("\n\nBelow it, a small sign has been affixed reading:\n\n");
  write("Enter here and die.\n\n   /Raourort, King of Gnomes\n");
  return 1;
}

west() {
  if(!door_open) write("The doors are closed.\n");
  else if(present("troll")) write("The troll bars your way.\n");
  else {
    this_player()->move_player("west#players/moonchild/cave/c23");
    toggle_door();
  }
  return 1;
}

catch_tell(str) {
  string junk;
  if(sscanf(lower_case(str),"%s says: frien%s",junk,junk)) toggle_door();
}

query_door_open() { return door_open; }

toggle_door() {
  string msg;
  object ob;
  door_open=!door_open;
  msg="The huge stone doors slide " + ({ "shut", "open" })[door_open] + "!\n";
  tell_room(this_object(),msg);
  if((ob=find_object("players/moonchild/cave/c23"))) tell_room(ob,msg);
}
