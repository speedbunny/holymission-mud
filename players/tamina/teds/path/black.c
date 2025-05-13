inherit "room/room";

#include "/players/tamina/defs.h"

object horn;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

  set_light(1);
  short_desc = "Black pavilion";
  long_desc =
    "A midnight black pavilion sits in a clearing to one side\n"+
    "of the path. A massive oak holds the trophies of some evil\n"+
    "and powerful champion. Its branches are adorned with Human Heads!\n";

  dest_dir = ({
    CROOMS + "draw_bridge", "north",
    TPATH + "path9","south",
    });

    items = ({
      "pavilion","A large round tent. It's blackness is quite impressive",
      "oak","The rotting heads of many knights hang from the branches",
      "heads","These heads are rotting and worm eaten"
    });

    horn = present("Black Horn");
    if (!horn)
    {
      horn = CLO("obj/thing");

      horn->set_name("Black Horn");
      horn->set_alias("horn");
      horn->set_long(
"A large black horn, carved and inlaid with mother of pearl\n\n"+
"A small plaque reads:\n\n            Blow horn to challenge Knight\n");
      horn->set_can_get(0);

      MO(horn, TO);
    }
}

void init()
{
  ::init();
  AA("_blow", "blow");
}

int _blow(string str)
{
  object knight, ring, sword;

  if (str == "horn" && present("Black Horn") && !present("Black Knight")) 
  {
    write("The Black Knight storms out of his pavilion !!\n");
    say(TPN+" blows the Black Horn.\n"+
        "The Black Knight storms out of his pavilion !!\n");
 
    knight = CLO("obj/monster");
    ring   = CLO(COBJ + "light_ring");
    sword  = CLO(TWP + "avenger");
 
    knight->set_name("Black Knight");
    knight->set_alias("knight");
    knight->set_race("human");
    knight->set_gender(1);
    knight->set_long(
     "This is a renegade knight from King Arthur's powerful Round Table.\n"+
     "He is very muscularly built, and very imposing in his black armour,\n"+
     "wielding an ominous black sword...\n");
    knight->set_level(22);
    knight->set_spell_mess2(
  "The Black Knight's Avenger makes an evil swing !!\n");
    knight->set_spell_mess1(
  "The Black Knight shows his prowess in battle.\n");
    knight->set_spell_damage(25);
    knight->set_chance(11);
    knight->set_al(-750);
    knight->set_ac(13);
    knight->set_wc(29);
    knight->set_aggressive(1);
    knight->load_a_chat(27,
     ({"The Black Knight sneers at your puny attempts at combat.\n",
       "The Black Knight says: You cannot defeat Morgan le Fey !!\n",
       "The Black Knight says: Lady Morgan will defeat Arthur.\n",
       "The Black Knight deftly side-steps your weak thrust.\n",
       "The Black Knight prepares to sing your Death Lament...\n"}) );
 
    ring->set_name("ring of light");
    ring->set_type("ring");
    ring->set_short("Ring of Light");
    ring->set_long(
      "When you look at the ring, it seems to glow brightly, and \n"+
      "warm to your touch.\n");
    ring->set_ac(1);
    ring->set_arm_light(3);
    ring->set_weight(1);
    ring->set_value(900);
 
    TR(ring, knight);
    TR(sword, knight);

    command("wield avenger", knight);
    command("wear ring", knight);

    move_object(knight, E(TP));
    knight->attack_object(TP);
 
    destruct(horn);
    return 1;
  }
}

