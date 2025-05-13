inherit "obj/treasure";

string type;
int no;

reset(arg) {
  if(arg) return;
  set_id("seeds");
  set_short("Some seeds");
  set_long("These are some rose seeds. Maybe you could plant them somewhere?\n");
  set_type(({ "beautiful red", "deeply-scented yellow",
	"plain white", "flaming orange" })[random(4)]);
  set_no(3+random(5));
  set_weight(1);
}

init() { add_action("plant", "plant"); }

set_type(str) { type=str; }

set_no(arg) { no=arg; }

query_value() { return no*5; }

plant(str) {
  int loop;
  object plant;
  if(!id(str)) return;
  write("You plant the seeds.\n");
  say(this_player()->query_name() + " plants some seeds.\n");
  move_object(plant=clone_object("players/moonchild/plants/rosebush"),
	environment(this_player()));
  plant->set_type(type);
  plant->set_no(no);
  destruct(this_object());
  return 1;
}
