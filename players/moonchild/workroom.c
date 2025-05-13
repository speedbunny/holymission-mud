inherit "players/moonchild/std/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  set("short", "Moonchild's workroom");
  set("long",
    "This is Moonchild's workroom. There is a large portrait on the wall.\n");
  set("exits",
    ([  "church":  "room/church",
	"sanctum": "players/moonchild/misc/sanctum",
	"post":    "room/post" ]));
  set("items",
    ([  "wall":    "A dirty wall.",
	"portrait":"@@pic_func@@" ]));
  move_object(clone_object("players/moonchild/misc/singer"), this_object());
}

string pic_func() {
  return "It's a picture of " + (string)this_player()->query_name()
    + ". Isn't " + (string)this_player()->query_pronoun() + " totally "
    + ({ "cute", "sexy", "adorable", "wonderful", "amazing" })[random(5)] + "?";
}
