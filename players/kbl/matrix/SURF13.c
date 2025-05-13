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
                "BRL","/players/kbl/matrix/SURF9",
                "BRU","/players/kbl/matrix/SURF10",
                "BRDR","/players/kbl/matrix/SURF11",
                "BRR","/players/kbl/matrix/SURF12",
                "BRMRD","/players/kbl/matrix/SURF6",
                "BRUR","/players/kbl/matrix/SURF4",
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
