inherit "room/room";
int find_treasure();
int find;

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A banquet hallin Jabba's palace";     
        long_desc = "\
You stand at the eastern side of a giant banquet hall, where Jabba comes to enjoy his \
favourite pastime of eating.  The grand table stretches the full length of the hall \
and 8 huge chairs are spaced evenly on this side of the room.  The wooden floor is covered \
with tidbits of food, and it is obvious the cleaners haven't had a chance to tidy up \
after the last meal. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/13",  "south",
            "/players/redsexy/jedi/areas/palace/11",  "west",
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
  object ob;

  switch(str) {
    case "table" :
    case "underneath table" :
    case "under table" : 
      {
        write("There doesn't seem to be anything here...\n");
        return 1;
       }
    case "chair" :
    case "underneath chair" :
    case "on chair":
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
      
  if(present("tie",this_player())) {
    write("You search the chair, but there's nothing there.\n");
    return;
    find=1;
}
  
  if(find) {
    write("You search the room thoroughly but find nothing.\n");
    return;
}
    write ("You have found a tie belonging to one of Jabba's dinner guests!\n");
        ob=clone_object("/players/redsexy/jedi/objects/tie");
        transfer(ob,this_player());
        find=1;
        return 1;
}
    


  
  
