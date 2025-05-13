/* 12.11.93 Airborne: change to room/room */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "By Great Lake";
  long_desc =
	"You are standing by Great Lake. You can hear the gulls crying.\n"+
	"If you go east, you will end up in a clump of reeds.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/crossing", "west",
         "players/topaz/angmar/fairyland/reeds", "east" });
}

init() {  
 ::init();
  add_action("east", "east");
}

east() {
  object boots;
  boots=present("waterproofed boots", this_player());
  if(boots) {
    if(boots->query_worn(0)) {
      this_player()->move_player(
              "east#players/topaz/angmar/fairyland/reeds");
      return 1;
    }
  }
  write("No! You wouldn't want to get your feet wet, would you?\n");
  write("You could use a pair of waterproofed boots.\n");
  say(this_player()->query_name(0));
  say(" was about to go into the reeds, but changed\n");
  say("his mind when he saw the cold water.\n");
  return 1;
}
