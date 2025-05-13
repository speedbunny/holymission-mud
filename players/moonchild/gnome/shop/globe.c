inherit "obj/treasure";

string name,pro,msg;
status active;

reset(arg) {
  if(arg) return;
  set_id("globe");
  set_short("Glowing globe");
  set_long("This is a strange glowing globe. You feel you could say something into it.\n"
	+ "and it might magnify it. Usage: tellglobe <message>. Cost: 100 spell points.\n");
  set_value(100);
}

init() {
  ::init();
  add_action("hail", "tellglobe");
}

hail(str) {
  if(!str || environment()!=this_player()) return;
  if(active) write("The loudhailer is too hot to put near your lips.\n");
  else if(this_player()->query_spell_points()<100)
	write("You are not strong enough.\n");
  else if(present("shout_curse",this_player()))
	write("Oops. You appear to have been cursed by someone.\n");
  else {
    msg=str;
    this_player()->restore_spell_points(-100);
    name=capitalize(this_player()->query_real_name());
    pro=capitalize(this_player()->query_pronoun());
    write("You shout \"" + msg + "\" into the globe.\n");
    active=1;
    call_out("sh1",2,0);
  }
  return 1;
}

sh1() {
  shout("You hear a wailing and a shrieking in the distance.\n");
  call_out("sh2",2,0);
}

sh2() {
  shout("Gradually it resolves itself into the sound of " + name + "'s voice.\n");
  call_out("sh3",2,0);
}

sh3() {
  shout(pro + " appears to be ranting and raging in a loud voice.\n");
  call_out("sh4",2,0);
}

sh4() {
  shout(pro + " " + ({ "scream", "yell", "howl", "bawl" })[random(4)] +
	"s: \"" + msg + "\"\n");
  active=0;
  if(!random(5)) {
    write("The globe suddenly disintegrates!\n");
    destruct(this_object());
    return 1;
  }
}
