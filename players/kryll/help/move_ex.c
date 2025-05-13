#define TO this_object()
#define TP this_player()
#define NAME query_name()
#define INV query_invis()
inherit "/room/room";
 
// the normal move function is within room.c so if you "overwrite"
// the function in your room, it gets called first...the ::move(str)
// allows the function to be called in the object that this room inherits,
// which is room.c ...it only needs to be called if the player is
// allowed to pass...
int move(string str) {
  if(!str)
    str = query_verb();
  switch(str) {
    case "north" :
// the invis check isn't necessary, just in some places when you
// want the room to let invis people pass...might want to use
// query_sneak() sometimes too
      if(present("cat", TO) && !TP->INV) {
        write("The cat prevents you from going further in.\n");
        say(TP->NAME+" tries to go north, but is stopped by the cat.\n");
        return 1;
      }
  }
  return ::move(str);
}
 
void reset(int arg) {
  if(arg) return;
 
  set_light(1);
  short_desc = "A move example...";
  long_desc =
   "This room contains a cat to block people's way. If you want to "+
   "go north you have to either be invisible or kill the cat.\n";
  dest_dir = ({
    "/players/emerald/workroom", "north",
  });
  clone_list = ({
    1, 4, "cat", "/obj/monster", ({
      "set_level", 2,
      "set_name", "cat",
      "set_short", "A guardcat",
      "set_long", "This cat guards. Watch it guard well.\n",
    })
  });
  ::reset(arg);
}

