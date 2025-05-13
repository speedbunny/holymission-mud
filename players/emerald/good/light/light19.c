inherit "room/room";

int passage;

#define TPN capitalize(this_player()->query_name())

int move(string str) { 
  if(!str)
    str=query_verb();
  if(str=="west" && !passage) {
    write("What ?\n");
    return 1;
  }
  return ::move(str);
}  
 
void reset(int arg) {

  if(arg) return;

  passage=0;

  set_light(1);

  short_desc="Ring of trees";

  long_desc="You have came to a clearing in the forest. There is a small " +
            "ring of trees surrounding the clearing to the west.  You do " +
            "not feel scared, but the trees seem to emanate an aura of " +
            "some hidden power@@extralong@@.\n";

  dest_dir=({"/players/emerald/good/light/light10", "east"
           });

  hidden_dir=({"/players/emerald/good/light/light22", "west"
           });

  items=({"clearing","A place of low-growing vegetation",
          "forest","A place of tall woody vegetation, like trees",
          "ring","A ring of strange trees",
          "ring of trees","They look like they are hiding something",
          "trees","You might want to search the ring of trees",
        });
  ::reset();

}

extralong() {
  if(passage==1) return ". There is now a secret path leading west";
  return "";
}

void init() {
  ::init();
  add_action("_search","search");
}


_search(str) {

  switch (str) {
    case "ring" :
    case "ring of trees" :
    case "trees" :
    if(random(100) <35) {
      write("You search through the trees and find a path leading west.\n");
      say(TPN + " finds a hidden path leading west.\n");
      passage = 1;
      call_out("refresh", 6);
      return 1;
    }
    write("You find nothing unusual.\n");
    say(TPN + " searches the room.\n");
    return 1;
    default :
      notify_fail("Search what?\n");
      return 0;
  }
}


refresh() {
     say("The trees cover the passage back up again.\n");
     passage = 0;
}
