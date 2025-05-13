

inherit "room/room";

object sword;
object board;

reset(arg) {
    if(!board) {
       board=clone_object("obj/board");
       board->set_file("players/warlord/guild/board");
       board->set_name("clerics");
       board->set_short("The clerics board");
       move_object(board,this_object());
    }
    
    if (arg) return;
    set_light(1);
    short_desc = "Resting room.";
    long_desc = 
          "This is the cleric home.\n" 
        + "This room is only for clerics !!!\n";
    dest_dir = 
        ({
        "players/warlord/guild/room.c", "north"
        });
return;
}

query_property(arg)  {
  return arg == "no_fight";
}

try_attack(ob) {
  write("This is a peaceful place.\n");
return 1;
}

query_light() {
    return 1;
}
init() {
  ::init();
  add_action("west","west"); 
}

west() {
  this_player()->move_player("west#players/warlord/guild/cleric/entr");
  "players/capablanca/guild/fighter/entr"->check_guild();
  return 1;
}

