inherit "room/room";
 
#define TO (this_object())
 
reset(arg) {
    if(!arg) {
 
    short_desc="Jewel's Storage Room";
 
    long_desc="This is Jewel's Storage Room! \n" +
              "Here is where Jewel stores all her neat monsters  \n" +
              "and objects for Jewel's Crystal Caverns.\n";
 
    set_light(1);
 
    dest_dir=({"players/jewel/workroom","out"});
     }
}
 
 
init()
 
{
  ::init();
}
 

