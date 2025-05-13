/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF5
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
  set_long("A reddish drain exists here. Seems to be a connection to\n"+
           "deeper into the matrix crystal.\n");
  node_dest=({
             "AXTIUM","/players/kbl/matrix/AXTM7",
             "BRU","/players/kbl/matrix/SURF11",
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
