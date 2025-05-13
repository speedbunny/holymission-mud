inherit "/room/inherit/std_pub";

void reset(int arg) {

  if(arg) return;
  set_light( 1);

  short_desc="In the Zombie bar";
  long_desc="You are in a strange cavern of the volcano.  It's really hot "+
            "in here, but the smell of cool drinks makes your mouth water.  "+
            "An old sailor is standing behind a counter and waiting for "+
            "you to order.  There is a wooden sign hanging on the wall.\n";

  dest_dir=({"/players/emerald/island/room/i17","south",
            });

  items=({"cavern","It has been turned into a little bar",
          "volcano","Yes, the island is volcanic",
          "sailor","Kunigunde",
          "counter","A wooden counter for serving drinks",
          "sign","You might try reading it",
          "wall","There is a sign on it",
        });

  set_waiter("Kunigunde");
  set_header("Kunigunde's Inn");

  add_item("dragon killer", 500, 20, "alco", 75, "A dragon killer");
  add_item("monkey's breath", 25, 4, "alco", 20, "A monkey's breath");
  add_item("pizza", 50, 4, "food", 30, "A pizza");
  add_item("chocolate milk", 15, 2, "soft", 15, "A chocolate milk");
 
  ::reset(arg);
  replace_program("/room/inherit/std_pub");

}
