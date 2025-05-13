inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  no_castle_flag = 0;
  short_desc = "Kelly's workroom";
  long_desc =
  "You're in Kelly's workroom.\n";
  dest_dir =({
   "players/wolfi/workroom","wolfi",
   "players/herp/workroom","herp",
   "players/llort/workroom","llort",
   "players/kelly/guild/room", "guild",
   "room/church","church",
   "players/kelly/rooms/training","up", 
   "players/kelly/rooms/vill/eastroad6","down",
   "players/kelly/rooms/castle/tower21bureau","buro",
   "players/kelly/store","west", 
   "obj/tick","north",
 });
}
 
#define TP this_player()
init() {
::init();
  if(TP->query_wizard()) {
    add_action("gifts","tool");
    add_action("gifts","watch");
    add_action("gifts","sword");
  }
}

gifts() {
  object obj;
  string str;
  switch (query_verb()) {
    case "watch": { str="/players/kelly/obj/watch"; break; }
    case "tool" : { str="/tools/tool"; break; }
    case "sword": { str="/players/kelly/guild/lightsaber"; break; }

  } 
  obj=clone_object(str);
  move_object(obj,TP);
  return 1;
}
