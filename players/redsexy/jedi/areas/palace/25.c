inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "An elegant stairway in Jabba's Palace.";     
        long_desc = "\
This swooping elegant staircase is decorated in the finest of fabrics, and it is \
obvious that Jabba wants to impress all who venture here.  Busts and ornaments \
miraculously stand on a diagonal shelf and the bannister is made from pure gold.  \
Never before have you seen such extravagence. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/19", "down",
            "/players/redsexy/jedi/areas/palace/35", "up",
        });

         items = ({
             "staircase", "An elegant swooping staircase.",
             "shelf", "The shelf climbs at 45 degrees and you wonder how the statues \
stay put",            
             "fabrics", "Chiffons and velvets line the walls and the pure white marble \
steps have golden paintings of each sign of the Hut-si-dah",
             "steps", "White marble steps on the staircase",       
             "busts", "Busts of Jabba's family and historical figures",
             "ornaments", "Twisted pieces of metal and fine gems add to the ornament display",
             "bannister", "The banister is made from the purest of gold",
             "extravagence","The place is luxiourious",
             
       });

}
    ::reset(arg);
    replace_program("room/room");
}




