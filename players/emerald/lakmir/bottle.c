inherit "/obj/thing";
#define TP    this_player()
#define TPN   TP->query_name()
#define ENV   environment

static int is_filled = 0;

int query_has_water() {

  return is_filled;
}

void set_descs() {

  set_long("");
  set_short("");
}

void set_short(string sh) {

  if(is_filled)
    short_desc = "A bottle full of water";
  else
    short_desc = "An empty bottle";
}

void set_long(string long) {

  if(is_filled)
    long_desc="A bottle which is filled with water.\n";
  else
    long_desc="An empty bottle.\n";
}

void reset(int arg) {
  ::reset(arg);

  if(arg) return;

  set_name("water bottle");
  set_alias("bottle");
  set_descs();
  set_can_get(1);
  set_weight(1);
  set_value(10);
}

void init() {
  ::init();

  add_action("_fill","fill");
  add_action("_drink","drink");
  add_action("_empty","pour");
}

int _fill(string str) {

  switch(str) {
    case "bottle with water" :
      if(is_filled) {
        write("But the bottle is already full.\n");
        return 1;
      }
      if(ENV(TP)->query_property("has_water")) {
        is_filled = 1;
        write("You fill the bottle with water.\n");
        say(TPN + " dips the bottle into the water and fills it up.\n");
        set_descs();
        return 1;
      }
      write("There is no water here to fill the bottle with.\n");
      say(TPN + " waves the bottle through the air.\n");
      return 1;
    case "bottle with" :
    case "bottle" :
      notify_fail("Fill bottle with what?\n");
      return 0;
    default :
      notify_fail("Fill what?\n");
      return 0;
  }
}

int _drink(string str) {

  switch(str) {
    case "water in bottle" :
    case "water from bottle" :
      if(is_filled) {
        write("You start drinking the water from the bottle, and soon it is "+
              "empty.\n");
        say(TPN + " drinks all the water from the bottle.\n");
        is_filled = 0;
        set_descs();
        return 1;
      }
      else {
        write("But the bottle is emptly.\n");
        return 1;
      }
    default :
      notify_fail("Drink what?\n");
      return 0;
  }
}

int _empty(string str) {
  object bottle, kettle;

  switch(str) {
    case "water in kettle" :
      bottle=this_object();
      kettle=present("kettle",environment(this_player()));
      if(!kettle) {
        write ("You'd spill the water on the floor if you did that.\n");
        return 1;
      }
      if(!is_filled) {
        write("The bottle is empty.\n");
        return 1;
      }
      write("Glug...glug...glug.\n");
      say(TPN + " pours water into the kettle.\n");

      move_object(clone_object("players/emerald/lakmir/water"),kettle);;
        is_filled=0;
        set_descs();
      return 1;
    case "water" :
      notify_fail("Pour the water where?\n");
      return 0;
    default :
      notify_fail("Pour what?\n");
      return 0;
  }
}
