inherit "/obj/thing";
#define TP    this_player()
#define TPN   TP->query_name()
#define ENV   environment

static int is_clean = 0;

int query_is_clean() {

  return is_clean;
}

void set_descs() {

  set_long("");
  set_short("");
}

void set_short(string sh) {

  if(is_clean)
    short_desc="A fragile pickaxe";
      
  else
    short_desc="A rusty pickaxe";
}

void set_long(string long) {

  if(is_clean)
    long_desc="An old, fragile, but usable, pickaxe.\n";
  else
    long_desc="An extremely rusty, and very fragile, pickaxe.  As it is,\n"+
              "it is unusable.  If it were cleaned, however...\n";
}

void reset(int arg) {
  ::reset(arg);

  if(arg) return;

  set_name("pickaxe");
  set_alias("axe");
  set_descs();
  set_can_get(1);
  set_weight(2);
  set_value(10);
}

void init() {
  ::init();
  add_action("_clean","clean");
  add_action("_clean","oil");
}

int _clean(string str) {
object oil;

  switch(str) {
    case "axe with oil" :
    case "pickaxe with oil" :
      if(is_clean) {
        write("But the pickaxe is already clean.\n");
        return 1;
      }
      oil=present("oil",this_player());
      if(!oil) {
        write("Maybe you ought to acquire some oil from somewhere?\n");
        return 1;
      }
      is_clean = 1;
      write("You clean the pickaxe with the oil.\n");
      say(TPN + " cleans the rust off the pickaxe.\n");
      set_descs();
      return 1;
    case "axe with" :
    case "pickaxe" :
    case "pickaxe with" :
    case "axe" :
      if(!present("oil",TP)) {
        write("You need some oil in order to clean the pickaxe properly.\n");
        return 1;
      }
      notify_fail("Clean the pickaxe with what?\n");
      return 0;
    default :
      notify_fail("Clean what?\n");
      return 0;
  }
}


drop() {
  write("I TOLD you it was fragile! The axe breaks, and is gone.\n");
  say(TPN+" drops an axe. It breaks because it is an OLD axe.\n");
  destruct(this_object());
  return 1;
}
