#define COLOURS ({ "blue", "red", "pink", "green", "turquoise" })
#define SHAPES ({ "prism", "cube", "sphere", "diamond", "cylinder" })

inherit "obj/treasure";

int type;
status got;

reset(arg) {
  if(arg) return;
  if(file_name()!="players/moonchild/gnome/crystal" && test_invalid())
	destruct(this_object());
  type=-1;
}

query_quest_item() { return "moonchild_gnome_crystal"; }

set_type(arg) {
  if(test_invalid() || type!=-1 || arg<0 || arg>4) destruct(this_object());
  type="players/moonchild/gnome/temple"->query_crystal_colour(arg);
}

test_invalid() {
  if(!previous_object() || !this_player()) return;
  return (creator(previous_object())!="moonchild"
	&& this_player()->query_real_name()!="moonchild"
        && this_player()->query_level()<33)
	|| (!interactive(this_player())
	&& creator(this_player())!="moonchild");
}

short() { return "A " + COLOURS[type] + " crystal"; }

long() {
  write(short() + ", shaped like a " + SHAPES[type] + ". It looks magical.\n");
  return;
}

id(str) { return str=="crystal" || str==COLOURS[type] + " crystal"; }

query_value() { return 250; }
