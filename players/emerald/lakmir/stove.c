// 051197: Sauron: Recoded branch check to give correct msgs.

inherit "/obj/container";
#define TP    this_player()
#define TPN   TP->query_name()
#define ENV   environment

static int is_lighted = 0;

int query_is_lighted() {

  return is_lighted;
}

void set_descs() {

  set_long("");
  set_short("");
}

void set_short(string sh) {

  if(is_lighted)
    short_desc="A hot stove";
  else
    short_desc = "A stove";
}

void set_long(string long) {

  if(is_lighted)
    long_desc="A lighted black cooking stove.\n";
  else
    long_desc="A black cooking stove.\n";
}

void reset(int arg) {
  ::reset(arg);

  if(arg) return;

  set_name("stove");
  set_max_weight(7);
  set_descs();
  set_can_get(0);
}

void init() {
  ::init();

  add_action("_light","light");
}

int _light(string str) {
  object item1, item2, item3, torch, stove;

  stove = this_object();
  if(stove) {
    item1 = present("branch",stove);
    item2 = present("branch 2", stove);
    item3 = present("branch 3", stove);
  }
  if(!item1 || !item2 || !item3) {
    write("The stove needs some branches to burn.\n");
    return 1;
  }

  switch(str) {
    case "stove with torch" :
      if(is_lighted) {
        write("But the stove is already lighted.\n");
        return 1;
      }
      if (torch=present("torch",this_player())) {
        if(!torch->id("lighted_torch")) {
          write("Maybe you should light the torch?\n");
          say(TPN + " needs to light the torch.\n");
          return 1;
        }
      } 
      if(item1 && item2 && item3) {
        is_lighted = 1;
        write("You light the stove with the torch.\n");
        say(TPN + " lights the stove with a torch.\n");
        set_descs();
        return 1;
      }
    case "stove with" :
    case "stove" :
      if (!torch=present("torch",this_player())) {
        write("Perhaps you ought to get a torch?\n");
        say(TPN + " needs a torch to light the stove.\n");
        return 1;
      }
      notify_fail("Light the stove with what?\n");
      return 0;
    default :
      notify_fail("Light what?\n");
      return 0;
  }
}
