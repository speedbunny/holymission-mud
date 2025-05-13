inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("The Hall of Records.\n");
long_desc=("This is the hall of recoreds. It is covered from wall to wall\n"+
           "with books and tables. A think layer of dust seems to have\n"+
           "covered the entirer room. High along the tops of all the walls\n"+
           "you can see some strange writing.\n");
items=({"walls", "They are lined with books, and some strange writing.",
        "tables", "There are a great many of them",
        "books", "The books tell the strory of this Temple. They tell "+
                 "how the walls were covered in magic script that prevents "+
                 "anyone from teleporting in or out of the Temple. They "+
                 "also tell of objects of great power that are stored in "+
                 "the temple. It goes on to mention a ring that the god "+
                 "Crom once wore, a Fan made by another god, a piece of "+
                 "the great summoner power crystal, and a sphere that can "+
                 "can control time itself! There are also other things "+
                 "that are hinted at but not mentioned." });
dest_dir=({"/players/akira/area/up", "down" });
   clone_list=({ 1, 1, "guardian", "/players/akira/mobs/guardian", 0});
   ::reset(tick);
   replace_program("room/room");
property=({"no_teleport"});
}
