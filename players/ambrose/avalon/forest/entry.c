inherit "room/room";

object *g=({ 0,0 });

void reset(int arg) {
  if(!g[0])
   move_object(g[0]=clone_object("players/ambrose/avalon/monsters/julian"),
	this_object());
  if(!g[1])
    move_object(g[1]=clone_object("players/ambrose/avalon/monsters/eric"),
	this_object());
  g[0]->set_friend(g[1]);
  g[1]->set_friend(g[0]);
  if(arg)
    return;
  set_light(1);
  short_desc="Outside of the Unicorns Shrine";
  long_desc="You stand outside a large marble building rising out of the \n"+
            "the surrounding forest.  The front is held up by large marble\n"+
            "columns and you can tell that the building is a holy place.\n"+
            "There is a large sign which gives off a very erie glow, maybe\n"+
            "you should read it before venturing any farther.\n";
  dest_dir=({"players/ambrose/avalon/forest/inner","south",
             "players/ambrose/avalon/forest/shrine1","north"});
  items=({ "gates", "They are wide open",
	"tower", "The gates of the huge dark tower are wide open",
	"trees", "The huge trees of the dark forest are dwarfed by the tower",
	"forest", "The huge trees of the dark forest are dwarfed by the tower",
	"glowing", "It must be some kind of magical beacon, sometimes it is red, sometimes yellow",
	"sky", "It is black, and there no stars" });
}

int move(string str) {
  if(query_verb()=="south") {
    if(present("eric")) {
      tell_room(this_object(), "Eric says:  Don't even think we will let you descrate\n"+
                               "this shrine!\n");
      if(g[0])
	g[0]->hit_player(0);
      if(g[1])
	g[1]->hit_player(0);
    }
    else
      this_player()->move_player("into the tower#players/moonchild/deep_forest/tower_g");
    return 1;
  }
  return ::move(str);
}
