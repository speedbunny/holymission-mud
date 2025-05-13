inherit "room/room";

#include "/players/topaz/defs.h"

int found;
reset(arg) {
object figley;
  found=0;
  if(!arg) {
    short_desc="Figley's house";
    long_desc="This is Figley's house.\n" +
              "It is sparsely decorated.  There is a table, a chair, some\n" +
              "cupboards and a trash can.\n";

    dest_dir=({ATTACH + "road8","north",
    });
    items=({"house","Figley lives here.  :)  It is cozy",
            "table","There is nothing on it",
            "cupboard","It is empty",
            "cupboards","They are empty",
            "chair","Figley rests his bones on it",
            "trash","There are a few scraps of paper",
            "trash can","There are a few scraps of paper in it",
            "can","There are a few scraps of paper in it",
    });
    set_light(1);
    move_object(figley=clone_object(MNST + "attach/figley"),this_object());
return 1;
  }
}

init() {

object qst;
object fig;

    ::init();
    if(fig=present("figley",this_object())) {
if(qst=present("bread",this_player()) && qst=present("milk",this_player()) && qst=present("candy",this_player()) && qst=present("butter",this_player()) && qst=present("yo-yo",this_player())) {
        call_out("quest_done",1);
    }
    }
    add_action("_search","search");
}

quest_done() {
object figley;
    write("Figley says: Thank you!  Thank you!\n");
    say("Figley says: Thank you!  Thank you!\n");
    write("Figley shouts: " + CAP(TPN) + " got my stuff for me!\n");
    say("Figley shouts: " + CAP(TPN) + " got my stuff for me!\n");
    write("Figley takes his stuff from you and puts it away.\n");
    say("Figley takes his stuff from " + CAP(TPN) + " and puts it away.\n");
    write("Figley says: Now I can go play!\n");
    say("Figley says: Now I can go play!\n");
    write("Figley leaves out the front door.\n");
    say("Figley leaves out the front door.\n");
    destruct(present("figley",TO));
    destruct(present("bread",TP));
    destruct(present("milk",TP));
    destruct(present("yo-yo",TP));
    destruct(present("candy",TP));
    destruct(present("butter",TP));
    return 1;
}

_search(str) {
     object slist;
     if(!id(str)) {
     write("Search what?\n");
     return 1;
}
    if((str=="can"||str=="trash"||str=="trash can")  && !found) {
    write("You search the trash can and find a shopping list.\n");
    say(this_player()->query_name() + " searches the trash can and finds something.\n");
 transfer(slist=clone_object(OBJS + "attach/slist"),TP);
    found=1;
    return 1; }
}
