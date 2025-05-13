/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF2
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
              "BRNHF","/players/kbl/matrix/SURF1",
              "BRNHL","/players/kbl/matrix/SURF3",
              "BRNH","/players/kbl/matrix/SURF13",
              "BRNHD","/players/kbl/matrix/SURF7",
             });
  set_density(3);
  set_type(4);
  set_conn(3);
  set_access(3);
  set_long("Continuing bluewhite tunnel of swirling energy and random\n"+
           "patterns. Somethings do look different here. Theres a exposed\n"+
           "portion of bluewhite crystal here.\n");
}

init()
{
  ::init();
}
