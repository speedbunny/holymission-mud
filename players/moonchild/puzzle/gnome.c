inherit "obj/monster";

int count;
string walk;

reset(arg) {
  object paper;
  ::reset(arg);
  if(arg) return;
  count=0;
  set_name("gnome");
  set_short("A busy looking gnome");
  set_long("This gnome looks like he's busy doing something. He also looks quite happy\n"
	+ "to be busy doing it. Maybe you should leave just leave him alone as he doesn't\n"
	+ "seem to want to bother anyone.\n");
  load_chat(15, ({ "The gnome mutters something about lurking creatures.\n",
	"The gnome mutters something about what lies down below.\n" }));
  set_level(10);
  set_wc(20);
  set_whimpy(20);
  set_random_pick(20);
  set_heart_beat(1);
  walk=({ "north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest", "up", "down" });
  move_object(paper=clone_object("obj/treasure"),this_object());
  paper->set_id("paper");
  paper->set_alias("piece of paper");
  paper->set_short("A piece of paper");
  paper->set_long("A piece of paper with something strange drawn on it.\n");
  paper->set_value(5);
  paper->set_read(
          "       N\n\n"
	+ "       @\n"
	+ "       |\n"
	+ "       #\n"
	+ "       |\n"
	+ "       |\n"
	+ "W @-#--+--#-@ E\n"
	+ "       |\n"
	+ "       |\n"
	+ "       #\n"
	+ "       |\n"
	+ "       @\n\n"
	+ "       S\n");
}

heart_beat() {
  ::heart_beat();
  count++;
  if(count>4) {
    motivate();
    count=0;
  }
}

motivate() {
  int dir,ct,flag;
  while(!flag && ct<10) {
    ct++;
    dir=random(10);
    flag=command(walk[dir],this_object());
  }
}
