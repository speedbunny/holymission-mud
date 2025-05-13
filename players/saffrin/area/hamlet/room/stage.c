inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The Stage";
  long_desc = 
      "You have walked onto the stage of the theatre.  From where you are"+
      " you can see chairs for the audience members for a performance.  There "+
      "is dust all over the floor.  The scenery and props from an old play are scattered"+
      " around you.  If you are daring, perhaps you can try to perform and get the ghosts"+
      " of audiences past to cheer for you.  There is a ladder leading down off to stage"+
      "left.\n";
  dest_dir=({
      HAM+"room/droom14", "north",
      HAM+"room/pass1", "down",
  });
  items=({
      "scenery", "The old and torn scenery is impossilbe to identify",
      "ladder", "A wooden ladder that goes down",
      "props", "A pile of swords, wigs, and candles",
      "chairs", "Broken wooden chairs that paying audiences members sat on",
      "floor", "It is covered in dust",
  });
  clone_list=({
      1, 3, "player", HAM+"npc/player", 0,
      1, 1, "king", HAM+"npc/pking", 0,
  });
  ::reset();
}

init(){

  ::init();
      AA("_perform","perform");
  return 1;
}

_perform(){

      ME("You stand in the center of the stage and orate the famous\n");
      ME("lines from 'Hamlet'.\n");
      ME("You orate:\n");
      ME("\tTo be or not to be\n");
      ME("\tThat is the question\n");
      ME("\tWhether tis nobler in the mind\n");
      ME("\tTo suffer the slings and arrows of outrageous fortune\n");
      ME("\tOr to take arms against a sea of troubles\n");
      ME("\nYou take a deep bow to the sound of thunderous applause!\n");

      say(CQN+" orates:\n");
      say("\tTo be or not to be\n");
      say("\tThat is the question\n");
      say("\tWhether tis nobler in the mind\n");
      say("\tTo suffer the slings and arrows of outrageous fortune\n");
      say("\tOr to take arms against a sea of troubles\n\n");
      say(CQN+" takes a deep bow to the sound of thunderous applause!\n");

 return 1;
}
