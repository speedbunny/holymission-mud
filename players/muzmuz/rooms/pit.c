inherit "room/room";
reset(arg) {
  if(!arg) {
short_desc = "pit";
 long_desc = "This is Muzmuz's test pit. BEWARE !";
set_light (1);
}
return 1; }
init()
{

   write (this_player()->query_property("fighter_legend"));
}
