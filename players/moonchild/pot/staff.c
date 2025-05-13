#define EP environment(this_player())
#define FN(x) file_name(x)
#define TPN this_player()->query_name()
inherit "obj/treasure";

status charged;

reset(arg) {
  string junk;
  if(arg) return;
  set_id("staff");
  set_short("A huge heavy oakenwood staff");
  set_weight(10);
  set_value(5000);
  charged=1;
}

long(str) {
  if(!id(str)) return;
  if(!charged) write("This staff appears strangely drained of power.\n");
  else write("The staff is glowing softly. You see runes on it.\n");
  return 1;
}

init() {
  ::init();
  add_action("wave", "wave");
  add_action("read", "read");
}

read(str) {
  if(str!="runes") return;
  write("The runes depict a magical bridge descending from the skies.\n");
  return 1;
}

drop() {
  if(query_ip_number(previous_object())) call_out("dest",1,0);
  return 0;
}

wave(str) {
  if(!id(str)) return;
  if(charged && FN(EP)=="room/south/sshore26") {
    if(!present("bridge"),EP) {
      move_object("players/moonchild/pot/bridge1",EP);
      write("You wave the staff.\n");
      say(TPN + " waves a staff.\n");
      tell_room(EP, "Suddenly, a magical bridge descends from the skies.\n");
      return 1;
    }
    return nothing();
  }
  if(charged && FN(EP)=="room/south/sislnd1") {
    if(!present("bridge"),EP) {
      move_object("players/moonchild/pot/bridge2",EP);
      write("You wave the staff.\n");
      say(TPN + " waves a staff.\n");
      tell_room(EP, "Suddenly, a magical bridge descends from the skies.\n");
      return 1;
    }
  }
  return nothing();
}

static nothing() {
  write("You wave the staff about. Nothing much happens.\n");
  say(TPN + " waves a staff about.\n");
  return 1;
}

dest() {
  tell_room(environment(this_object()),
	"The staff disintegrates into its primal elements.\n");
  destruct(this_object());
}
