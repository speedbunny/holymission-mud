inherit "room/room";

object pike;
int found;

reset(arg) {
  found=0;
  if(!pike) {
    pike=clone_object("obj/monster");
    pike->set_name("pike");
    pike->set_short("A vicious-looking pike");
    pike->set_level(13);
    pike->set_whimpy(-1);
    pike->set_aggressive(1);
    pike->set_wc(26);
    pike->set_al(-50);
    move_object(pike,this_object());
  }
  if(arg) return;
  set_light(1);
  short_desc="The bottom of a lake";
  long_desc="You are swimming at the bottom of a lake. There are weeds growing everywhere.\n"
	+ "The murky water flows all about you, and it makes you dirty, cold and wet.\n";
  dest_dir=({ "players/moonchild/trollslayer/lake", "up", });
  items=({ "lake", "A damp, still lake",
	"weeds", "There are weeds at the bottom of the lake. They might be hiding something",
	"water", "Dark, murky water", });
}

init() {
  ::init();
  add_action("search", "search");
  add_action("up", "up");
  call_out("no_air",10,0);
}

up() { if(this_player()->query_npc()) return 1; }

search(str) {
  object stone;
  if(!id(str)) {
    write("Search what?\n");
    return 1;
  }
  if(present("pike")) {
    write("You can't get past the pike!\n");
    return 1;
  }
  if(str=="weeds" && !found) {
    write("You search the weeds and find a strange stone!\n");
    say(this_player()->query_name() + " searches the weeds and finds something.\n");
    log_file("moonchild.quest", ctime(time()) + ": " +
	this_player()->query_name() + " (level " + this_player()->query_level()
	+ ") (" + capitalize(this_player()->query_real_name()) + ")\n\t\t\t  "
	+ "got the magic stone.\n");
    stone=clone_object("players/moonchild/puzzle/stone");
    move_object(stone,this_object());
    stone->set_finder(this_player()->query_real_name());
    found=1;
    return 1;
  }
  say(this_player()->query_name() + " searches the " + str + " and finds nothing.\n");
  write("You search the " + str + " and find nothing.\n");
  return 1;
}

no_air() {
  if(environment(this_player())!=this_object()) return;
  write("Your lungs are gasping for air, and you surface.\n");
  command("up",this_player());
}
