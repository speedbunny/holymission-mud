inherit "room/room";

status got;

reset(arg) {
  got=0;
  if(arg) return;
  short_desc="End of cavern";
  long_desc="A dead end in the underground cavern. There is a pile of wood here.\n";
  dest_dir=({ "players/moonchild/gnome/maze2",
	({ "north", "east", "south", "west" })[random(4)] });
  items=({ "wood", "Perhaps you should search it",
	"pile", "Perhaps you should search it",
	"pile of wood", "Perhaps you should search it" });
  property=({ "no_teleport" });
}

init() {
  ::init();
  add_action("search", "search");
}

search(str) {
  if(!id(str)) return;
  if(got) {
    write("You search and find nothing.\n");
    say(this_player()->query_name() + " searches in the " + str + ".\n");
  } else {
    object s;
    write("You search and find something.\n");
    say(this_player()->query_name() + " drags something out the " + str + ".\n");
    move_object(s=clone_object("obj/weapon"),this_object());
    s->set_name("stake");
    s->set_short("A pointed wooden stake");
    s->set_long("This pointed wooden stake looks very sharp.\n");
    s->set_class(8);
    s->set_value(500);
    s->set_weight(2);
    s->set_hit_func(this_object());
    got=1;
  }
  return 1;
}

weapon_hit(ob) {
  if(ob->id("vampire lord") && creator(ob)=="moonchild") {
    switch(random(3)) {
	case 0:
	  write("You attempt to stab Vampire lord in the stomach, but fail.\n");
	  return 0;
	  break;
	case 1:
	  write("You catch Vampire lord a glancing blow in the chest.\n");
	  return 10;
	  break;
	case 2:
	  write("You stab Vampire lord right in the heart!\n");
	  return 50;
	  break;
    }
  }
}
