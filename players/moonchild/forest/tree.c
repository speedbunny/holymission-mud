#define TREETOP "players/moonchild/forest/tree_top"

string type;
object top;

void reset(int arg) {
  if(type)
    return;
  type=({ "oak", "ash", "cedar", "alder" })[random(4)];
}

void init() {
  add_action("climb", "climb");
}

void long() {
  write((type=="cedar" ? "A" : "An") + " " + type
	+ " tree. It's looks as if you might be able to climb it.\n");
}

string query_name() {
  return type + " tree";
}

int id(string str) {
  return str=="tree" || str==type + " tree";
}

int climb(string str) {
  if(!id(str)) {
    notify_fail("Climb what ??\n");
    return 0;
  }
  if(!top) {
    top=clone_object(TREETOP);
    top->set_type(type);
  }
  this_player()->move_player("up the tree", top);
  return 1;
}
