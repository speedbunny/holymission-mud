

inherit "room/room";
object o1;

reset(arg) {

  if (!o1) {
     o1=clone_object("/obj/monster");
     o1->set_name("guard");
     o1->set_short("Sorceror Guard");
     o1->set_long("This guard is here to make sure that all obey the rules"+
              " of the MUD.\n");
     o1->set_level(10);
     o1->set_al(100);
     o1->set_hp(500);
     o1->set_wc(25);
     o1->set_ac(10);
     o1->set_aggressive(0);
     move_object(o1,this_object());
     }
     
    if (arg) return;
    set_light(1);
    short_desc = "In a bright room";
    long_desc = 
         " You have entered a very bright and beautiful room. There are \n"
         +" pictures of great warriors and dragons lining the walls.\n";
    
    items = 
        ({
         "pictures","You see great warriors and dragons",
         "walls","You see a high wall surrounding you",
        });

    dest_dir = 
        ({
        "players/warlord/rooms/fut2", "west",
        "players/warlord/rooms/fut3", "east",
        "players/warlord/rooms/futent", "north",
        "players/warlord/rooms/fut4", "south"
        });
}



