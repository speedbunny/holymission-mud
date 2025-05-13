inherit "room/room";
reset(arg) {
  if(!arg) {

     short_desc = "A dark cavern";
     long_desc = "You almost turn around as soon as you walk into this\n" +
                 "part of the cave.\n" +
                 "The stench of death and decay is overwhelming.\n" +
                 "On the wall you notice a message scrawled in blood.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave1","north",
 
                     });

     items =({"message","It is written in blood.  Perhaps you could read it",
              "blood","There is a message written in it.  Maybe you should read it",
              "wall","There is a message written in blood on it",
              });
       set_light (1);
        smell = "It reeks of death in here.";
return 1; }}

init(){
  ::init();

        add_action("read", "read");
        }

read(str){
    if(!id(str)){
    write("Read what?\n");
    return 1;
}
    if(str=="message"){
    write("Sloppy letters spell out: Leave before they get you too!\n");
    return 1;
    }
}
