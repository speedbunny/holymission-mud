#define TPN this_player()->query_name()
inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="The treasure room",
  long_desc="This is the treasure room of the cats.  This room does not " +
            "look like there has ever been much treasure stored here.  " +
            "You wonder where could all the treasure be?  As you look " +
            "around, you notice a few things lying around.  There are " +
            "some broken weapons and some rusty armour, and there is also " +
            "a note.  You also see skeletons chained to the wall.  One of " +
            "the skeletons is grinning at you.\n";

  dest_dir=({"/players/emerald/good/evil/evil5","down",
           });

  items=({"room","The scene is rather bleak",
          "skeletons","One particular skeleton looks particularly strange",
          "weapons","Broken swords and daggers",
          "armour","Dented, rusty armour",
          "skeleton","You see a light coming from the head",
          "wall","The skeletons are chained to it",
          "head","The eye in the head resembles a peephole",
          "note","The note reads 'Manx, please do not allow anyone to " +
                 "bother me, especially mortals!'",
        });

  ::reset();

}
 
void init() {
  ::init();
  add_action("_look","look");
  add_action("_knock","knock");
}

_look(str) {

  if(str=="at peephole") {
    write("You look into the peephole and see another eye staring\n " +
          "back at you!\n" +
         "You are so startled that you run from the room.\n");
    say(TPN +" runs from the room screaming!\n");
    this_player()->move_player("down#/players/emerald/good/evil/evil5");
    return 1;
  }
}

_knock(str) {
   if (str == "three times") {
     write("You hear a loud growl from the north.\n" +
           "The wall slides open and a LARGE claw grabs you.\n" +
           "You are pulled into a secret room.\n");
     say("You hear a loud gowling coming from the north.\n" +
         TPN +" is grabbed by a claw.\n"
         "They are pulled from the room.\n");
     this_player()->move_player("in#players/emerald/good/evil/evil22");
     return 1;
   }
     return 0;
}
