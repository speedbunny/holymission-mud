

inherit "room/room";
    object mon0;

reset(arg) {

    if (!arg) {

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
   "A room.exa founta\n"
   + "\n";
    dest_dir = ({
        });
    items = ({
     });
   }
   if (!mon0 || !living(mon0)) {
    mon0=clone_object("/players/arthur/area/items/sword");
    transfer(mon0,this_object());
   }
}

