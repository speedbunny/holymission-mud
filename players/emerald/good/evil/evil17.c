inherit "room/room";

void reset(int arg) {

  if(arg) return;

  long_desc="You have entered a small room.  The walls here all look " +
            "ridden with holes. You notice mice scurrying into the " +
            "shadows and the walls to avoid the light.  Mouse droppings "+
            "are everywhere.  You stop into a rather large one and hear "+
            "a SQUISH!\n";

  short_desc = "Small room";

  dest_dir=({"/players/emerald/good/evil/evil11","south",
             "/players/emerald/good/evil/evil18","east"
            });

  items=({"wall","You see a small hole in the wall",
          "hole","You look in the hole and see a note",
          "walls","There are mouse holes in the walls",
          "shadows","Wavering shadows offering refuge for scared mice",
          "note","You can barely make out part of one word '.noc.'",
          "holes","Oodles of holes in the wall",
          "mice","Small grey furry rodents",
          "droppings","The by-products of mouse-existence",
        });

  ::reset();
  replace_program("/room/room");

}
