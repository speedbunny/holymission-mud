/* Changed by Ethereal Cashimor, 260393, smell for linkdeads! */
inherit "room/room";

reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_light(1);
     property = ({ "no_teleport", "no_clean_up" });
     short_desc="Purgatory";
     long_desc="You are in the purgatory. This is the room where all link "
             + "dead players are thrown in. They look like they are dead... "
             + "you can see no life upon their pale faces.\n";
     dest_dir=({"room/church","church"});
     smell="It sure is dusty here.";
  }
}
 
init() {
  ::init();
  this_player()->set_smell("Very dusty. Probably has been stored in the "
                         + "purgatory for some time.");
}
