inherit "room/room";
reset(tick){
if(tick)return;
set_light(1);
short_desc= "In a Pocket Dimension";
long_desc= "This part of the prison seems to be a living area for Ryu. "+
           "The mist is a lot thicker here, and the smell is making you "+
           "sick. There are huge claw marks on the floor and some of the "+
           "walls. You don't think it would be a good idea to stay here "+
           "much longer.\n";
items= ({ "mist", "This mist is a thick green color.",
          "walls", "The walls are clawed to shit." });
move_object(clone_object("/players/akira/mobs/ryu"),this_object());
dest_dir = ({ "players/akira/area/ryu8", "north",
              "players/akira/area/ryu2", "south",
              "players/akira/area/ryu6", "east",
              "players/akira/area/ryu4", "west",
              "players/akira/area/ryu9", "northeast",
              "players/akira/area/ryu7", "northwest",
              "players/akira/area/ryu3", "southeast",
              "players/akira/area/ryu1", "southwest" });
}
