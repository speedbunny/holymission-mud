inherit "obj/food";

static int is_pressed=0;

int query_is_pressed() {
  return is_pressed;
}

void set_descs(){
  if(is_pressed) {
    set_short("A pressed olive");
    set_long("A large, dry, pressed olive.\n");
  }
  else {
    set_short("A juicy olive");
    set_long("A large olive.  Farmers press them to extract their oil.\n");
  }
}

void reset(int arg) {
  is_pressed=0;
  set_descs();
  ::reset(arg);
  if(arg) return;
  set_name("olive");
  set_value(2);
  set_weight(1);
  set_eater_mess("It's a little bitter, and very oily.\n");
  set_strength(5);
}
void init() {
 ::init();
  add_action("_press","press");
 
}

_press(str) {
  if(str!="olive") {
    notify_fail("Press what?\n");
    return 1;
  }
  write("As you press the olive a drop of oil comes out of it.\n");
  say(this_player()->query_name()+" presses the olive.\n");
  move_object(clone_object("players/emerald/island/obj/drop"),this_player());
  is_pressed=1;
  set_descs();
 return 1;
} 
query_quest_item() { return 1; }

drop() {
  write("You can't drop your olive, its too sticky !\n");
  return 1;
  }
