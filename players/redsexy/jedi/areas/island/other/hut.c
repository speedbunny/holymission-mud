inherit "obj/std_shop"; 

void reset(int arg) 
{
  ::reset(arg);
 

    set_light(1); 
    smell="The room smells of polish";
short_desc="A trader's hut on the Island of Carkoon"; 
    long_desc="You have entered one of the Jawa's stores "+
              "where creatures who have been banished to "+
              "live on this island pick up their everyday "+
              "goods and accessories.  You notice a sign " +
              "on the wall, and there is a Jawa here, " +
              "eager to do trade with you.\n\n";

store = "/players/redsexy/jedi/areas/island/other/hutstore";
keeper = "Jawa";
items =  ({"walls","The walls are made of sand and straw",
            "desk","It's a wooden desk",
            "floor","The floor has been swept, and everything is tidy",
            "lat","They are spruce wooden",
            "jawa","He is eager to sell you some of his goods.",
            "sign","The sign is written in Basic so you understand it!  It says: Type 'list' to see what I have on offer."
            });

move_object(clone_object("/obj/torch"),query_store());
move_object(clone_object("/players/redsexy/jedi/objects/jspear"),query_store());
move_object(clone_object("/players/redsexy/jedi/objects/watch"),query_store());


}

void init() {
   ::init();
   add_action("leave","leave");
   }

int leave(string str) {
   if(str!="hut") return 0;
   write("The Jawa shouts after you: I look forward to seeing you again! \n");
   this_player()->move_player("out of the small hut.#players/redsexy/jedi/areas/island/4");
   return 1;
   }
