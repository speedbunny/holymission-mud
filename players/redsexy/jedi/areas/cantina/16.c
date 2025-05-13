/*This room may well be a quest room eventually!*/
inherit "room/room";
int find_treasure();
int find;

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="Wuntar's Office in the Mos Eisley Cantina";
  long_desc="This room is obviously an office of some kind, and there is a wooden desk "+
            "with a chair pushed under the table here.  Unlike the rest of the Cantina "+
            "this room is carpeted, and by looking at the plaque on the open door, you "+
            "realize this is none other than the office of the great Wuntar himself! "+
            "Here is where he concocts his special recipes for the cocktails that will "+
            "please the almighty Jabba and get him out of this dead end job. \n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/11","north",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "desk","There seems to be something on the chair by the table",
          "table","There seems to be something on the chair by the table",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "office","You can tell it is an office from all the pieces of paper lying around!",
          "chair","A sturdy chair, covered with leather.  Something is glimmering on it, perhaps you should try and move it?",
          "carpet","A royal blue carpet covers the floor",
          "plaque","It is in gold, with 'Wuntar's Office' engraved on it",
         });

  smell="This room smells fresh and clean.\n";
 
  ::reset();
}

void init() {
  ::init();

  add_action("_move", "move");
}

int _move(string str) {

   if(str!="chair") return 0;
   say(this_player()->query_name()+" moves the leather chair.\n");
   find_treasure();
   return 1;
   }
   

find_treasure() {
object flask;
      
  if(present("flask",this_player())) {
    write("You move the chair, but there's nothing there.\n");
    return;
    find=1;
  }
  
  if(find) {
    write("You haven't even got the strength to move the chair at the moment!\n");
    return;
  }

  write("A glass flask rolls off the chair as you move it...\n" +
        "You skillfully catch it before it hits the ground!\n");
  flask=clone_object("players/redsexy/jedi/objects/flask");
  transfer(flask,this_player());
  find=1;
  return;
}
