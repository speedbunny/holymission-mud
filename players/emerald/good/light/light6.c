#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";
int passage_open;

int move(string str) {
  if(!str)
    str=query_verb();
  switch(str) {
    case "down" :
      if(present("mystic")) {
        write("The mystic waves his arms wildly and you freeze!\n");
        return 1;
      }
      if(!passage_open) {
        write("There is no where to go down!\n");
        return 1;
      }
  }
  return ::move(str);
}

void reset(int arg) {

passage_open=0;

  if(arg) return;

  set_light(1);

  long_desc="You have entered the cave of an old wizard.  He is usually " +
            "sitting at his table reading a book.  The cave itself is " +
            "very neat and tidy, with few extraneous oddments cluttering " +
            "up the corners.  The place probably wouldn't be worth "+
            "searching@@extralong@@.\n";

  short_desc="The Mystic's cave";

  dest_dir=({"players/emerald/good/light/light4","south",
           });

  hidden_dir=({"/players/emerald/good/cave/1","down",});

  items=({"table","This table is old and covered with magic books",
          "book","The book is unreadable",
          "cave","A natural, water-formed cave",
          "place","Well, you could search the cave if you wanted to",
          "oddments","A little of this, a little of that",
          "corners","They are clean, for the most part",
        });


  clone_list=({
    1,1,"mystic","/players/emerald/good/obj/mystic",0,
    -1,1,"staff","/players/emerald/good/obj/staff",0,
  });

  ::reset();

}
extralong() {
  if(passage_open==1) return ".  There is an open trap door leading down";
  return "";
}
    
void init() {
  ::init();
  add_action("_search","search");
}



_search(str){
  if(!str) str="cave";
  if(str=="cave") {
    write("A careful search reveals a trap door in the floor!\n");
    say(TPN+" finds a trap door leading down.\n");
    passage_open=1;
    return 1;
  }
}

