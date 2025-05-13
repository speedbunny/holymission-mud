inherit "/room/room";
int counter;

void reset(int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The edge of the plain";
  long_desc="The ancient trees of the thick Ilkin Forest form the edge of " +
            "the plain.  Their branches grow together thickly, blocking " +
            "entrance to that evil place from this area.  Towering grey " +
            "mountains rise in the north, across a short section of " +
            "golden grassland.  A stand of dark green leaved plants grows " +
            "in a little hollow by the edge of the woods.\n";

  dest_dir=({"/players/emerald/plain/p20","north",
             "/players/emerald/plain/p12","east",
             "/players/emerald/plain/p10","west",
             "/players/emerald/plain/p21","northeast",
             "/players/emerald/plain/p19","northwest",
           });

  items=({"trees","Giant specimens of oak and ash",
          "forest","It is rumoured to be a dangerous place",
          "branches","They weave between one another",
          "area","A section of the grassy plain",
          "mountains","High, craggy mountains",
          "grassland","The grass ripens in the sunlight",
          "plants","A stand of stinging nettles, a beneficial herb.  " +
                   "You could pick some",
          "hollow","A slightly sunken patch of ground",
          "edge","The border of the plain and the woods",
          "woods","The dark Ilkin Forest",
        });

  clone_list=({
    1,1,"vole","obj/monster", ({
      "set_name","vole",
      "set_race","rodent",
      "set_short","A frightened vole",
      "set_long","A cute little brown vole, searching for some food.\n",
      "set_level",4,
      "add_money",10,
    }),
  });

  ::reset();

}
void init() {

  ::init();

  add_action("_pick","pick");

}

_pick(str) {
object nettle;

  switch(str) {
    case "nettles" :
    case "nettle" :
    case "plant" :
    case "herb" :
    if (counter >=3) {
      write ("Sorry, but there are no more nettles left to be picked.\n");
      return 1;
    }
      write("OUCH!  Those nettles sting!\n");
      say(this_player()->query_name() + " picks a stinging nettle.\n");
      counter++;
      move_object(clone_object("/players/emerald/plain/nettle"),this_player());
      return 1;

    default :
      notify_fail("Pick what?\n");
      return 0;
  }
}

