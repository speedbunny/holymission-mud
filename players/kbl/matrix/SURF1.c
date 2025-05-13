/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF1
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
              "BRNHD","/players/kbl/matrix/SURF8",
              "BRNHF","/players/kbl/matrix/SURF9",
              "BRNHR","/players/kbl/matrix/SURF2",
              "AXTM","/players/kbl/matrix/AXTM1",
             });
  set_density(3);
  set_type(4);
  set_conn(3);
  set_access(3);
  set_long("Continuing bluewhite tunnel of swirling energy and random\n"+
           "patterns that dance before your eyes...\n");
}

init()
{
  ::init();
}
