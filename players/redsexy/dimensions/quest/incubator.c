inherit "/obj/container";
#define TP    this_player()
#define TPN   TP->query_name()
#define ENV   environment

static int is_on = 0;

int query_is_on() {

  return is_on;
}

void set_descs() {

  set_long("");
  set_short("");
}

void set_short(string sh) {

  if(is_on)
    short_desc="A warm incubator";
  else
    short_desc = "";
}

void set_long(string long) {

  if(is_on)
    long_desc="A warm incubator, with demon cocoons inside.\n";
  else
    long_desc="The incubator has a lever on it, to switch it on and off.\n";
}

void reset(int arg) {
  ::reset(arg);

  if(arg) return;

  set_alias("incubator");
  set_max_weight(20);
  set_descs();
  set_can_get(0);
}

void init() {
  ::init();

  add_action("_switch","switch");
  add_action("_switch","pull");
  add_action("_switch","move");
  add_action("_switch","push");
  add_action("_switch","turn");
  add_action("_switch","adjust");
}

int _switch(string str) {
  object redcocoon, orangecocoon, yellowcocoon, greencocoon, bluecocoon, indigococoon, violetcocoon, incubator, scroll, prize;

  incubator = this_object();
  if(incubator) {
    redcocoon = present("red cocoon", incubator);
    orangecocoon = present("orange cocoon", incubator);
    yellowcocoon = present("yellow cocoon", incubator);
    greencocoon = present("green cocoon", incubator);
    bluecocoon = present("blue cocoon", incubator);
    indigococoon = present("indigo cocoon", incubator);
    violetcocoon = present("violet cocoon", incubator);
  }
  if(!redcocoon || !orangecocoon || !yellowcocoon || !greencocoon || !bluecocoon || !indigococoon || !violetcocoon) {
    write("There is something missing.\n");
    return 1;
  }

  switch(str) {
    case "lever" :
    case "lever down" :
    case "lever to on" :
    case "incubator on" :
   
      if(is_on) {
        write("But the incubator is already working.\n");
        return 1;
      }

 if(redcocoon && orangecocoon && yellowcocoon && greencocoon && bluecocoon && indigococoon && violetcocoon) {
    scroll = present("red_quest_scroll", TP);
    if(scroll) {
        is_on = 1;
        write("You turn the incubator on.\n");
        say(TPN + " turns on the incubator.\n");
        set_descs();
        destruct(redcocoon);
        destruct(orangecocoon);
        destruct(yellowcocoon);
        destruct(greencocoon);
        destruct(indigococoon);
        destruct(bluecocoon);
        destruct(violetcocoon);
        write("A voice from above echoes: Well done, you are now the Master of the Domains!\n");
        prize=clone_object("/players/redsexy/dimensions/quest/rainbow");
        transfer(prize,this_player());
        write("A voice from above echoes: Take the rainbowstick as a token of my gratitude!\n");
        write("A voice from above echoes: Now all you have to do is find your way back home!\n");
        write("You hear distant laughter.\n");
        shout(this_player()->query_name()+" is the new Master of the Domains.\n");
        write_file("/players/redsexy/logfiles/QUEST", ctime(time()) + ": " +
        this_player()->query_name() + " (level " + this_player()->query_level()
	  + ") (" + capitalize(this_player()->query_real_name()) + ")\n\t\t\t  "
        + "solved the quest!\n");
        TP->set_quest("dimension_quest");
        return 1;
      }
        write("A voice echoes: You have no scroll and therefore are not worthy of this task!\n");
      }
   case "incubator" :
      write("What do you want to do with the incubator?\n");
      return 1;
    default :
      write("Try wording that differently?\n");
      return 1;
  }
}

