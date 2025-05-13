inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A narrow corridor in Jabba's palace.";     
        long_desc = "\
The smell of food reaches your senses as you stand here.  Just a narrow passageway, it \
is well lit by the large window in the ceiling above you.  The floor is wooden here, and the \
boards creak as you step onto them.\n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/1",  "north",
            "/players/redsexy/jedi/areas/palace/6", "south",

        });


         items = ({
             "window", "The window is embedded in the ceiling and lets the sunlight shine in from above",            
             "food", "You can smell food",
             "passageway", "This passageway is very narrow",       
             "floor", "The floorboards creak under your weight",
        });
    }
    ::reset(arg);
}

void init() {
   ::init();


   add_action("_search","search");

   }



int _search(string str) {
  object ob;


   if(str!="boards") return 0;
         write("You find a scroll!\n");
         say(this_player()->query_name()+" searches the boards.\n");
         ob=clone_object("/players/whisky/obj/recall_scroll");
         transfer(ob,this_player());
         return 1;
}

   


