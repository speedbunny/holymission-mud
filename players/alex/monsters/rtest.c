#define ME this_object()
 
inherit "room/room";
reset(arg) {
 if (arg) return;
 
 
    set_light(0);
 short_desc = "tomb";
long_desc = "The Dark tomb of Shal~Manthues.  The very air is decayed by a evil presence.\n"+
            "In the corner you see a throne is there some one on it?\n";
dest_dir = ({"players/alex/area/df/df20","out",});
 
items=({
        "throne",
        "The throne is empty at the moment, but who knows what\n"+
         "might happen if an amulet of summoning is placed on to it.",});
 
  }
 
init()
{
add_action("place","place");
::init();
}
 
 
 
int place(string str) {
        switch(str){
        case "amulet on throne":
 if (present("bamulet",this_player()))     {
     move_object(clone_object("/players/alex/monsters/dknight"),ME);
     destruct(present("bamulet",this_player()));
     write("As you place the amulet on the throne it vanishes.\n"+
           "A mist forms in front of you, it colalesses into the shape of a Death knight.\n");
        return 1;
                                           }
else{
     write("You have nothing to place on the throne.\n");
     return 0;
    }
     
                  }
 
                     }
