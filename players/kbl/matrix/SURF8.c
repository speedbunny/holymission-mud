/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF8
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
               "BRDWN","/players/kbl/matrix/SURF7",
                "BRUP","/players/kbl/matrix/SURF1",
             });
  set_density(3);
  set_type(4);
  set_conn(2);
  set_access(3);
}

init()
{
  ::init();
}
