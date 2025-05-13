inherit "room/room";
 
#define TP     this_player()
#define RNAME  query_real_name()
#define NAME   query_name()
 
string passage;
 
int move(string str) {
  if(!str)
    str=query_verb();
  switch(str) {
    case "down" :
      if(!passage) {
        return 0;
      }
      if(TP->query_size() !=passage) {
        write("The passage wasn't made by you, you don't fit into it!\n");
        return 1;
      }
  }
  return ::move(str);
}
 
void reset(int arg) {
  passage = 0;
 
  ::reset(arg);
  if(arg) return;
 
  set_light(1);
 
  short_desc="Cliff";
  long_desc="You have come to the base of a cliff rising out of the forest " +
            "floor. The cliff is extremely steep and it looks to be " +
            "impassable. At the base of the cliff, the dirt looks quite " +
            "soft@@extralong@@.\n";
 
  items=({"cliff","The cliff is very steep and looks frightening",
          "dirt","The dirt looks as if someone was digging in it",
          "floor","The forest and its shrubby vegetation",
          "base","The dirt is very soft here",
        });
 
  hidden_dir = ({
    "/players/emerald/good/light/light24", "down"
  });
 
  dest_dir=({"players/emerald/good/light/light22","east"
           });
 
  smell="The smell of freshly dug earth hangs in the air.";
}
 
 
extralong() {
  if(!passage) return "";
  return ".  There is a passage leading down here";
}
 
void init() {
  ::init();
  add_action("_dig","dig");
}
 
 
status _dig(string str) {
  object pickaxe;
 
  switch(str) {
    case "cliff" :
    case "at cliff base" :
    case "at base" :
    case "dirt" :
    case "under cliff" :
      pickaxe = present("pickaxe",TP);
      if(!pickaxe || !pickaxe->query_is_clean()) {
         write("You've got nothing to dig with!\n");
        return 1;
      }
      if(passage) {
        if(passage == TP->query_size()) {
          write("Why? There is already a passage there!\n");
          return 1;
      }
      write("You modify the passage leading down to fit someone like you.\n");
      say(TP->NAME+" modifies the passage leading down.\n");
      passage=TP->query_size();
      return 1;
      }
      if(random(100) < 35) {
        write("You dig at the base of the cliff with the axe and find a " +
              "passage leading down.\n");
        say(TP->NAME+" digs out a hidden path leading down with the axe.\n");
        passage=TP->query_size();
        return 1;
      }
      write("You dig, but find nothing.\n");
      say(TP->NAME + " digs in the dirt for fun and amusement.\n");
      return 1;
    default :
      notify_fail("Dig where?\n");
      return 0;
    }
}
