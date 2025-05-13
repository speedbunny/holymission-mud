/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF3
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
             "SURFL","/players/kbl/matrix/SURF2",
             "SURFR","/players/kbl/matrix/SURF9",
             });
  set_density(3);
  set_type(4);
  set_conn(3);
  set_access(3);
  set_long("Continuing tunnel of bluewhite swirling energy. Random patterns\n"+
           "dance about as you move through this area...\n");
}

init()
{
  ::init();
}
