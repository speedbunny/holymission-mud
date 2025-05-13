inherit "room/room";
object human, human, human, human;
reset(arg){
    if(arg)return;
    set_light(1);
    short_desc = "The Stage";
    long_desc = "You are standing on a stage.  There is scenery and\n"+
    "props around you.  If you are daring, try your hand a a bit of\n"+
    "acting.  There is a ladder leading down.\n";
    dest_dir=({
      "/players/saffrin/area/room/droom14", "north",
      "/players/saffrin/area/room/passage1", "down",
    });
    items=({
      "scenery", "The old and torn scenery is impossilbe to identify",
      "ladder", "A wooden ladder that goes down",
      "props", "A pile of swords, wigs, and candles",
      "floor", "It is very messy",
    });
    move_object((clone_object("/players/saffrin/area/monster/player_king")),
      this_object());
    move_object((clone_object("/players/saffrin/area/monster/player")),
      this_object());
    move_object((clone_object("/players/saffrin/area/monster/player")),
      this_object());
    move_object((clone_object("/players/saffrin/area/monster/player")),
      this_object());
}

init()
{
  ::init();
  add_action("_act","act");
  return 1;
  }

_act()
{
  write("You stand in the centre of the stage and orate the famous\n");
  write("lines from Hamlet.\n");
  write("You orate:\n");
  write("  To be or not to be\n");
  write("  That is the question\n");
  write("  Whether tis nobler in the mind\n");
  write("  To suffer the slings and arrows of outrageous fortune\n");
  write("  Or to take arms against a sea of troubles\n");
  write("\nYou take a deep bow to the sound of thunderous applause\n");
  return 1;
  }
