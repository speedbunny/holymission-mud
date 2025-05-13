/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF4
*/

inherit "/players/kbl/cpower/cry_node";

reset(arg)
{
  if(!arg)
   set_up();
}

set_up()
{
  object ob;

  set_light(1);
  set_name("Blue White Surface");
  node_dest=({
             "BRML","/players/kbl/matrix/SURF13",
             "BRR","/players/kbl/matrix/SURF11",
             "BRL","/players/kbl/matrix/SURF10",
             });
  add_cmd=({"read","Read the crystal object", 
           });
  set_density(3);
  set_type(4);
  set_conn(3);
  set_access(3);
  ob = clone_object("/players/kbl/cpower/decrystal");
  ob->set_place("Main Pub");
  ob->set_trans_to("/room/pub2");
  ob->set_color("red");
  ob->set_descrip("Shiny Blueball");
  transfer(ob,this_object());
}

init()
{
  ::init();
}
