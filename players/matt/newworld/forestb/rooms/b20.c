inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Sleepy Copse";
  long_desc =
    "    You feel an overwhelming desire to rest your bones as you\n" +
    "look around this place. Something about it, perhaps the air,\n" +
    "perhaps the soothing sounds or the tranquility, makes you want\n" +
    "to sit down and relax, just for a moment.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b19", "north",
  });
}

init() {
  ::init();
  call_out("sleep", 10);
}
     
sleep() {
  if(present(TP, TO)) {
    write("You sink down to the ground and fall into a deep sleep,\n");
    write("though somehow you are still aware of what is going on\n");
    write("around you.\n");
    say(TP->SNAME + " sinks to the ground and falls asleep.\n");
    call_out("dream", 10);
    input_to("commands");
    return 1;
  }
}

dream() {
  if(ENV(TP) == TO) {
    write("You have a strange dream...\n");
    write("You are floating up out of your body, drifting up above the\n");
    write("world, gazing down on the landscape below. You drift down\n");
    write("towards a beautiful forest, your ghost-like form soaring\n");
    write("through trees and foliage...\n");
    write("You pass over a huge fallen tree, over a gnarled tree-stump,\n");
    write("through a tree split open by lightning... and finally come\n");
    write("to a huge Oak. A woman is there, beckoning towards you,\n");
    write("pleading with you to help her...\n");
    write("...you then see the shattered shards of a prism fill the air\n");
    write("with pure blue water, raining down on a circle of light...\n");
    return 1;
  }
}

commands(arg) {
  switch(arg) {
    case "wake up":
      write("You force yourself awake.\n");
      say(TP->SNAME + " wakes up.\n");
      remove_call_out("dream");
      return 1;
      break;
    case "wake":
      write("You force yourself awake.\n");
      say(TP->SNAME + " wakes up.\n");
      remove_call_out("dream");
      return 1;
      break;
    case "quit":
      command("quit", TP);
      return 1;
      break;
    default:
      write("You can't do that while you're asleep.\n");
      input_to("commands");
      return 1;
      break;
  }
}
