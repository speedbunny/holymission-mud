inherit "room/room";  

reset(arg) {  
    if (arg) return;  
  ;:reset(arg); 
  if(!present("stormtrooper")) 
{ 
    move_object(clone_object("players/sargon/monster/storm.c"), this_object());
} 

    set_light(1);  
    short_desc = "A clean pure white room";  
    long_desc =  
    "You are on a smooth, flat and perfectly white square.To the north,\n"+  
    "south and east you see a brown boarder and in the distance you see\n"+  
    "a flat plane, it appears to be made up of black and white squares.\n"+ 
    "You also think you may see some imposing figures.  Maybe you should\n"+ 
    "go check it out.  To the west there is a brown boarder and a vast\n"+ 
    "void that appears to have no dimension.\n";  





    dest_dir = ({  
  

      "players/sargon/rooms/a3.c", "north",   
      "players/sargon/rooms/b2.c", "east", 
      "players/sargon/rooms/a1.c", "south", 
      "players/sargon/rooms/b3.c", "northeast",  
      "players/sargon/rooms/b1.c", "southeast", 
      "players/sargon/rooms/void.c", "west" 

    });  






}  
  
