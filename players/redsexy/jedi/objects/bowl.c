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
    short_desc = "A wooden bowl full of water";
  else
    short_desc = "An empty wooden bowl";
}

void set_long(string long) {

  if(is_filled)
    long_desc="A wooden bowl filled with water.\n";
  else
    long_desc="A wooden bowl.\n";
}

void reset(int arg) {
  ::reset(arg);

  if(arg) return;

  set_name("bowl");
  set_alias("bowl");
  set_descs();
  set_can_get(1);
  set_weight(1);
  set_value(100);
}

void init() {
  ::init();

  add_action("_fill","fill");
  add_action("_drink","drink");
  add_action("_empty","empty");
}

int _fill(string str) {

  switch(str) {
    case "bowl with water" :
      if(is_filled) {
        write("But the bowl is already full.\n");
        return 1;
      }
      if(ENV(TP)->query_property("has_water")) {
        is_filled = 1;
        write("You fill the bowl with water.\n");
        say(TPN + " dips the bucket into and water and fills it up.\n");
        set_descs();
        return 1;
      }
      write("There is no water here to fill the bowl with.\n");
      say(TPN + " tries to fill the bowl with air.\n");
      return 1;
    case "bowl with" :
    case "bowl" :
      notify_fail("Fill bowl with what?\n");
      return 0;
    default :
      notify_fail("Fill what?\n");
      return 0;
  }
}

int _drink(string str) {

  switch(str) {
    case "water in bowl" :
    case "water from bowl" :
      if(is_filled) {
        write("You drink the water from the bowl... refreshing!\n");
        say(TPN + " drinks all the water from the bowl.\n");
        is_filled = 0;
        set_descs();
        return 1;
      }
      else {
        write("But the bowl is empty.\m");
        return 1;
      }
    default :
      notify_fail("Drink what?\n");
      return 0;
  }
}

int _empty(string str) {

  switch(str) {
    case "bucket" :
      if(!is_filled) {
        write("The bowl is already empty.\n");
        return 1;
      }
      is_filled = 0;
      write("You pour the water out of the bowl\n");
      say(TPN + " pours water out of the bowl.\n");
      set_descs();
      return 1;
    default :
      notify_fail("Empty what?\n");
      return 0;
  }
}

