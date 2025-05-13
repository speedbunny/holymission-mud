inherit "room/room";

#include "/players/tamina/defs.h"

object lady, bottle, crown;
int got_box;

void reset(int arg) 
{
  got_box = 0;
  ::reset(arg);
  if (!arg) 
  {
    set_light(1);
    short_desc = "Bed Room";
    long_desc =
"This is obviously a ladies bedroom. A large canopy bed takes up\n"+
"the entire northern wall, while a huge dresser and mirror fill\n"+
"the western and southwestern portions of the room. The smell\n"+
"of perfume still lingers in the air......\n";

    dest_dir = ({
      TFROST + "cave10", "southeast"
    });

    items = ({
"bed","This is a large canopy bed. The frame is carved rose wood and\n"+
      "the sheets are made of silk. It looks very comfortable",
"canopy","This canopy acts like a second ceiling to give the bed a\n"+
         "cozy feeling. The side drapes can also be drawn to give\n"+
         "added privacy",
"mirror","You see someone looking back at you!!!!!\n"+
         "\n\nYou realize it is yourself.....",
"drawers", "They seem to be full of clothes and stuff",
"cabinets", "They seem to be full of clothes and stuff",
"stand", "It is just a stand made of wood"
    });

  }
  if (!present("frost giant queen")) 
  {
    lady = clone_object("players/ted/monsters/frost_giant_queen");

    lady->set_name("Frost Giant Queen");
    lady->set_alias("queen");
    lady->set_race("giant");
    lady->set_gender(2);
    lady->set_short("A Frost Giant Queen");
    lady->set_long(
      "This is the wife of the FRost Giant King.\n"+
      "She looks very elegant, and quite beautiful.\n");
    lady->set_level(11);
    lady->set_wc(15);
    lady->set_ac(2);
    lady->set_al(250);

    move_object(lady, this_object());

    crown = clone_object("obj/armour");
    crown->set_name("the Frost Giant Queen's Crown");
    crown->set_alias("crown");
    crown->set_type("helmet");
    crown->set_short("The Frost Giant Queen's Crown");
    crown->set_long(
"This is a pearl and platinum crown. It is very light and very expensive\n"+
"looking. It is also much too large for you to wear properly.\n");
    crown->set_ac(1);
    crown->set_weight(3);
    crown->set_value(3000);
    move_object(crown, lady);

    bottle = clone_object("obj/treasure");
    bottle->set_id("perfume bottle");
    bottle->set_alias("bottle");
    bottle->set_short("A Massive Bottle of Perfume");
    bottle->set_long(
"This huge bottle of perfume is almost full. It also smells so strong\n"+
"monsters should be able to smell you coming a mile away.\n");
    bottle->set_weight(3);
    bottle->set_value(1250);
    move_object(bottle, lady);

    call_other("players/tamina/teds/random_magic", "make_item", lady, 19);

    command("wear crown", lady);
  }
}

void init() 
{
  ::init();
  add_action("do_get", "take");
  add_action("do_get", "get");
}

int id(string str) 
{
  if(::id(str)) return 1;
  return (str=="box" || str == "dresser");
}

int long(string str) 
{
  ::long(str);
  if (str == "dresser") 
  {
    write("This is a huge teakwood dresser, covered with perfume bottles\n");
    write("makeup and other knick-knacks. There must be 30 or 40 drawers\n");
    write("and just as many cabinets. All in all it must weight at least\n");
    write("4000 pounds or more.\n");
    if (!got_box) 
      write("There is a box sitting on a stand on the dresser.\n");
  }
  if (str == "box" && !got_box) 
  {
    write("This small gold box is sitting all alone on a kind of\n");
    write("stand in the middle of the dresser.\n");
  }
}

int do_get(string str) 
{
  object box_obj, jewel, note;
  if (str == "box" && !got_box) 
  {
    box_obj = clone_object("obj/container");
    box_obj->set_name("jeweled box");
    box_obj->set_alias("box");
    box_obj->set_short("A Jeweled Box");
    box_obj->set_long(
"This gold inlayed box is set with gems and precious stones.\n");
    box_obj->set_value(750);
    box_obj->set_weight(2);
    box_obj->set_max_weight(4);
    box_obj->set_can_open(1);
    if (transfer(box_obj, this_player())) 
    {
      write("You are carrying too much.\n");
      destruct(box_obj);
      return 1;
    }
    write("The box rattles as you lift it from the stand.\n");
    say(TPN+" takes the box from the dresser\n");
    got_box = 1;

    jewel = clone_object("obj/treasure");
    jewel->set_id("Jewels");
    jewel->set_alias("jewels");
    jewel->set_short("The Frost Giant Queen's Jewels");
    jewel->set_long(
"This set of jewels is fit to grace the neck and wrist of only\n"+
"the most elegant and beautiful.\n");
    jewel->set_weight(3);
    jewel->set_value(random(1000) + 2000);
    transfer(jewel, box_obj);

    note = clone_object("obj/treasure");
    note->set_id("note");
    note->set_alias("short note");
    note->set_short("A short note");
    note->set_long("A note.\nPerhaps you should read it...\n");
    note->set_read(
"Lovely Vivian,\nI love you with all my heart and all my soul.\n"+
"You are my life, my breath, my love....\n"+
"(and it keeps going like this for half a page)\n"+
"       With Love,\n             Thomes\n\n"+
"ps          Remember, the pen is mightier than the sword.\n"+
"(a hint: DON'T be greedy before you get what you want, be greedy after)\n");
    note->set_weight(1);
    note->set_value(0);
    transfer(note, box_obj);
    return 1;
  }
}
