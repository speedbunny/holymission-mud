#pragma strict-types
#define path "/players/paris/waste/"
inherit "/room/room";
object ob;

int _translate(string str);
void reset(int arg) {
  int i;
  
  ::reset(arg);
  if (arg) 
    return;
  set_light(1);
  short_desc="Under the hill";
  long_desc=
    "A dark narrow passageway leads off into the darkness, the walls seem to "+
    "be made of large rectangular blocks almost grown together somehow. You "+
    "can feel something strange in the air. A large engraving covers most of "+
    "the northern wall.\n";
  dest_dir = ({ 
    path + "room/gw-b-6", "southwest" 
  });
  items = ({
    "blocks", "They almost look like they've been grown together",
    "walls", "Made from large sandstone blocks",
  });
  smell = "It smells strange in here.\n";
  items = ({ 
    "engraving", 
    "It appears to be some form of writing, maybe you can translate it somehow", 
    "wall", 
    "A large engraving covers one of the walls, perhaps you can look at it", 
  });
  /* create a pair of each type of monsters. */
  i=2;
  while(i--) {
    ob = clone_object(path+"monster/shaman");
    move_object(ob, this_object());
    ob = clone_object(path+"monster/cultist");
    move_object(ob, this_object());
  }
}

void init() {
  ::init();
  add_action("_translate", "translate");
}

int _translate(string str) {
  if (!str || !present("stone of ages", this_player())) {
		write("What are you trying to translate?\n");
		say(capitalize(this_player()->query_name())+" mutters to "+
		    "themselves, but seems to be puzzled.\n",this_player());
		return 1;
  }
  if (str != "engraving") {
    write("You don't think you can translate that.\n");
    return 1;
  }
  if (find_object("/players/paris/obj/floating_disk")) {
    write("You say the words, but they don't seem to make sense.\n");
    return 1;
  } else { 
    write("You manage to translate the engraving.\n");
    say(capitalize(this_player()->query_name())+" mutters to "+
	"themselves, unfortunately you don't catch what they say.\n",
	this_player());
    ob = clone_object("/players/paris/obj/floating_disk");
    ob->set_owner(this_player());
    move_object(ob, this_object());
    return 1;
  }
}
