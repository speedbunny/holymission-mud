inherit "room/room";

#include "/players/matt/definitions"

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
    "players/matt/rooms/forestb/b19", "north",
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

commands(arg) {
  switch(arg) {
    case "wake up":
      write("You force yourself awake.\n");
      say(TP->SNAME + " wakes up.\n");
      return 1;
      break;
    case "quit":
      command("quit", TP);
      return 1;
      break;
    default:
      write("You feel too drowsy to do that.\n");
      input_to("commands");
      return 1;
      break;
              }
              }

dream() {
  write("You have a strange dream.\n");
  write("Before you, you see four pyramid-shaped Prisms made of diamond.\n");
  write("They are empty at first, but then, one by one, they each draw\n");
  write("in a substance. The first draws water from a quickly-flowing\n");
  write("river...then the next draws in wind from a dark forest grove.\n");
  write("The third draws mud from a slimy mud-hole. And the fourth draws\n");
  write("flames up from a hole in the middle of a vast desert.\n\n");
  write("You feel like waking up now.\n");
        }
