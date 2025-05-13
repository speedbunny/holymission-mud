
#define TP	this_player()

inherit "/players/llort/bars";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Demo Bar";
  long_desc="It's Llort's Demo bar.\n" +
	    "There is a sign on the wall, just type menu to read it.\n";
  dest_dir=({ "players/llort/guild/tower/hallway","north" });
  menu_title="The card of Llorts test bar:\n"+
             "-----------------------------\n";
  menu_desc=explode(read_file("players/kelly/shitbox/bar.stock"),"!");

}

init() {
  ::init();
  add_action("menu","menu");
}
