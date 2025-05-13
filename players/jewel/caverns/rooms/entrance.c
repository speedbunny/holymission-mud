inherit "room/room";
 
 
reset(arg) 
{
    if (arg) return;
 
 
    set_light(1);
    short_desc = "Entrance to underground caverns";
    no_castle_flag = 0;
    long_desc = "This is a big limestone cavern.\n"+ 
    "The air pressure in this room is higher than normal, "+
     "which keeps water out\n"+ 
    "of the caverns.  There is some moss growing on the walls. "+
     "The ceiling is so\n"+
    "high it is lost in the darkness\n";
    dest_dir = 
        ({ "players/jewel/caverns/rooms/central", "west",
           "room/sea", "out" 
        });
    items=({ 
     "moss","Glowing green moss growing on the cavern walls near "+
            "the water's edge",
   "water","Salty ocean water, which leads out of the caverns",
   "wall","A concave wall made of limestone covered with glowing green moss",
   "walls","Concave walls made of limestone covered with glowing green moss",
   "ceiling","You tilt your head back as far as you can, "+
             "and you still can't see anything",
     "floor","A limestone floor.  Watch out for that moss!",
          });
}
 
 
query_light() {
    return 1;
}
 
 

