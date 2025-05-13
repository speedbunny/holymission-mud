inherit "room/room";
int find_treasure();
int find;


void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A banquet hallin Jabba's palace";     
        long_desc = "\
You stand at the western side of a giant banquet hall, where Jabba comes to enjoy his \
favourite pastime of eating.  The grand table stretches the full length of the hall \
and 8 huge chairs are spaced evenly on this side of the room.  The wooden floor is covered \
with tidbits of food, and it is obvious the cleaners haven't had a chance to tidy up \
after the last meal. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/10",  "south",
            "/players/redsexy/jedi/areas/palace/12",  "east",
        });


         items = ({
             "floor", "The floor is made of wood, and covered with morsels of food",            
             "table", "This table is enormous, stretching the full legnth of the hall",
             "chairs", "The seats are massive, big enough to seat the most obese of the \
Huttese family",
             "hall",  "This is a grand banquet hall, where Jabba holds his feasts",
             "food",  "Bits of snailshell and toadspittle lie around on the floor",
        });
    }
    ::reset(arg);
}

void init() {
   ::init();


   add_action("_search","search");

   }

int _search(string str) {

  switch(str) {
    case "table" :
      {
        write("There doesn't seem to be anything on top of the table...\n");
        return 1;
       }
    case "under table" :
    case "underneath table" :
        write("You look left and right and down and up...\n");
               find_treasure();
               return 1;       
    default :
      notify_fail("Where do you want to search?\n");
      return 0;
  }
}



find_treasure() {
    object ob;
      
  if(present("potion",this_player())) {
    write("You search under the table, but there's nothing there.\n");
    return;
    find=1;
}
  
  if(find) {
    write("You search the room thoroughly but find nothing.\n");
    return;
}
    write ("You find some loose change and a potion discarded under the table\n");
        ob=clone_object("/players/redsexy/jedi/objects/knock");
        transfer(ob,this_player());
        this_player()->add_money(542);
        find=1;
        return 1;
}





