#define TPN   this_player()->query_name()
#define TO this_object();
inherit "obj/thing";


reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("paper");
    set_alias("piece of paper");
    set_short("A tattered piece of paper");
    set_long("This is a tattered and torn piece of paper.\n" +
             "It appears to be a list of some sort.\n");
    set_value(0);
  }
}

void init() {
  ::init();
  add_action("_read","read");
}

status _read(string str){

  if(str == "paper"){
    write("To turn lead into gold.\n\n"+
          "The mighty sapphire alone is not enough to transform this\n"+
          "humble metal into gold.  No, yet another is needed, and\n"+
          "the magical properties of emeralds are well known in this\n"
          "matter.  But in solid form they will not suffice; the\n"+
          "liquid only reacts.\n\n"+
          "Yet another precious metal must needs be sacrificed\n"
          "if the gold is to be obtained.  And yet a fourth ingredient\n"
          "is needed.  What it is has yet to be determined.\n");
    say(TPN + " reads a piece of paper.\n");
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}
