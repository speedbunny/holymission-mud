/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF10
*/

inherit "/players/kbl/cpower/cry_node";

reset(arg)
{
  if(!arg)
   set_up();
}

set_up()
{
  set_long("Tube of bluewhite crystaline energy flows all around. There\n"+
           "is a seeming peace and chaos to it all.\n");
  set_light(1);
  set_name("Blue White Surface");
  node_dest=({
                "BRR","/players/kbl/matrix/SURF13",
                "BRDR","/players/kbl/matrix/SURF6",
             });
  set_density(3);
  set_type(4);
  set_conn(3);
  set_access(3);
}

init()
{
  ::init();
}
