/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF7
*/

inherit "/players/kbl/cpower/cry_node";

reset(arg)
{
  if(!arg)
   set_up();
}

set_up()
{
  set_light(1);
  set_name("Blue White Surface");
  node_dest=({
               "BRUPR","/players/kbl/matrix/SURF9",
               "BRUPR","/players/kbl/matrix/SURF8",
             });
  set_density(5);
  set_type(4);
  set_conn(2);
  set_access(5);
}

init()
{
  ::init();
}
