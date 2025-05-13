inherit "obj/treasure";

string type;
int no;

reset(arg) {
  if(arg) return;
  set_id("seeds");
  set_short("Some seeds");
  set_long("These are some plant seeds. Maybe you could plant them somewhere.\n");
  set_no(5);
  set_weight(1);
}

init() { add_action("plant", "plant"); }

set_no(arg) { no=arg; }

query_value() { return no*8; }

plant(str) {
  int loop;
  object plant;
  if(!id(str)) return;
  write("You plant the seeds.\n");
  say(this_player()->query_name() + " plants some seeds.\n");
  move_object(plant=clone_object("players/moonchild/plants/appletree"),
	environment(this_player()));
  plant->set_no(no);
  plant->start_growing();
  destruct(this_object());
  return 1;
}
